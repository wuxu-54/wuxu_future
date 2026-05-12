# anr排查方法

- StrictMode

```kotlin
    //可以在application中添加
    if (BuildConfig.DEBUG) {
        StrictMode.setThreadPolicy(
            StrictMode.ThreadPolicy.Builder()
                .detectAll()
                .penaltyLog()
                .build()
        )
    }
```

- looper监听

```kotlin
class MainLooperMonitor : Printer {
private var lastTime = 0L

override fun println(x: String?) {
    if (x?.startsWith(">>>>> Dispatching to") == true) {
        lastTime = System.currentTimeMillis()
    } else if (x?.startsWith("<<<<< Finished to") == true) {
        val duration = System.currentTimeMillis() - lastTime
        if (duration > 1000) { // 卡顿阈值设为1秒
            Log.w("MainLooperMonitor", "主线程卡顿：${duration}ms")
        }
    }
}
}

// 在 Application 初始化时注册
Looper.getMainLooper().setMessageLogging(MainLooperMonitor())
```

- systrace
- profiler  cpu查看主线程具体调用栈确定哪些方法耗时
- log 或是通过aop封装，在方法调用前后打印时间，查看耗时

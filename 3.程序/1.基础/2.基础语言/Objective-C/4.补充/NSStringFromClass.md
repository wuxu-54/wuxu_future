# NSStringFromClass

在Objective-C中，`class_getName`是一个函数，用于获取类的名称。这个函数返回一个指向类名的C字符串（即`const char *`类型）。`class_getName`是Objective-C运行时的一部分，可以用来在调试、日志记录或任何需要引用类名的地方获取类名。

使用`class_getName`的例子：

```objc
Class myClass = [NSString class];
const char *className = class_getName(myClass);
NSLog(@"The class name is: %s", className);
```

`NSStringFromClass`是另一个类似的函数，但它接受一个类的实例（`id`类型）作为参数，并返回该实例所属类的名称。`NSStringFromClass`返回的是一个`NSString`对象，而不是C字符串。

使用`NSStringFromClass`的例子：

```objc
NSString *myString = @"Hello, World!";
NSString *className = NSStringFromClass([myString class]);
NSLog(@"The class name is: %@", className);
```

在这两个例子中，`class_getName`和`NSStringFromClass`都用于获取类的名称，但它们返回不同类型的结果。`class_getName`返回一个C字符串，而`NSStringFromClass`返回一个`NSString`对象。在Objective-C中，`NSStringFromClass`更常用，因为它直接返回一个`NSString`，可以很方便地用于字符串操作和输出。

# HTML5兼容性处理

## 添加元信息，让浏览器处于最优渲染模式

```html
<!-- 设置IE总是使用最新的文档模式进行渲染 -->
<meta http-equiv="X-UA-Compatible" content="IE-Edge">
<!-- 优先使用 webkit（chromium）内核渲染，针对360等浏览器 -->
<meta name="renderer" content="webkit">
```

## 使用`html5shiv`让低浏览器认识H5的语义化标签

通过这个js，可以将h5的内容在低版本浏览器转换为可以处理的内容

```html
<!--[if lt ie 9]>
<script src="../sources/js/html5shiv.js"></script>
<![endif]-->
```

* lt 小于
* lte 小于等于
* gt 大于
* gte 大于等于
* ! 逻辑非

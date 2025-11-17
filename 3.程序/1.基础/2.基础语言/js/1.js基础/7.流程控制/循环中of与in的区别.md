# in 和 of 的区别

在 JavaScript 中，`for...in` 和 `for...of` 是两种不同的循环语法，核心区别在于 **遍历的目标、内容和适用场景**，具体如下：

## 一、遍历目标不同

- **`for...in`**：用于遍历 **对象的可枚举属性（包括自身属性和继承的原型链属性）**，本质是“遍历键名”。  
  可枚举属性指的是通过 `Object.defineProperty` 定义时 `enumerable: true` 的属性（默认定义的属性均为可枚举）。  

- **`for...of`**：用于遍历 **可迭代对象（iterable object）的元素**，本质是“遍历值”。  
  可迭代对象是指实现了 **迭代器接口（`Symbol.iterator`）** 的对象，包括：数组（`Array`）、字符串（`String`）、`Map`、`Set`、`arguments` 对象、`NodeList` 等。  

## 二、遍历内容不同

- **`for...in`**：循环变量是 **对象的“键名”**（对于数组，键名是索引字符串；对于普通对象，键名是属性名）。  
- **`for...of`**：循环变量是 **可迭代对象的“元素值”**（直接获取值，无需通过键名访问）。  

## 三、是否遍历原型链

- **`for...in`**：会遍历对象自身的可枚举属性 **以及原型链上的可枚举属性**（可能导致意外结果，需谨慎使用）。  
- **`for...of`**：仅遍历对象自身的元素，**不涉及原型链**（更安全，避免意外遍历无关属性）。  

## 四、适用场景不同

| 循环方式   | 适用场景                                  | 不适用场景                          |
|------------|-------------------------------------------|-----------------------------------|
| `for...in` | 调试/检查对象的属性（如遍历普通对象的属性名） | 不适合遍历数组（可能遍历非数字索引的属性） |
| `for...of` | 遍历数组、字符串、`Map`、`Set` 等的元素    | 不能直接遍历普通对象（普通对象不可迭代） |  

## 五、代码示例对比

### 1. 遍历数组

```javascript
const arr = [10, 20, 30];

// for...in：遍历的是数组的索引（字符串类型），且可能遍历原型链属性
console.log("for...in 遍历数组：");
for (const key in arr) {
  console.log(key, typeof key, arr[key]); // 0 string 10；1 string 20；2 string 30
}

// for...of：遍历的是数组的元素值（直接获取值）
console.log("for...of 遍历数组：");
for (const value of arr) {
  console.log(value); // 10；20；30
}
```

### 2. 遍历普通对象

```javascript
const obj = { name: "张三", age: 20 };

// for...in：遍历对象的属性名（包括可能的原型链属性）
console.log("for...in 遍历对象：");
for (const key in obj) {
  // 推荐用 hasOwnProperty 过滤原型链属性
  if (obj.hasOwnProperty(key)) {
    console.log(key, obj[key]); // name 张三；age 20
  }
}

// for...of：不能直接遍历普通对象（普通对象不可迭代，会报错）
try {
  for (const value of obj) {
    console.log(value); 
  }
} catch (e) {
  console.error(e); // 报错：obj is not iterable
}
```

### 3. 遍历字符串（可迭代对象）

```javascript
const str = "abc";

// for...in：遍历索引（字符串的索引是键名）
for (const key in str) {
  console.log(key, str[key]); // 0 'a'；1 'b'；2 'c'
}

// for...of：遍历字符（直接获取值）
for (const char of str) {
  console.log(char); // 'a'；'b'；'c'
}
```

### 4. 遍历 `Map`（可迭代对象）

```javascript
const map = new Map();
map.set("name", "李四");
map.set("age", 25);

// for...in：遍历 Map 的属性名（非键值对，无意义）
for (const key in map) {
  console.log(key); // 输出 Map 的内置属性（如 'size'），非键值对
}

// for...of：遍历 Map 的键值对（默认迭代器返回 [key, value]）
for (const [key, value] of map) {
  console.log(key, value); // name 李四；age 25
}
```

## 总结：核心区别表

| 特性               | `for...in`                          | `for...of`                          |
|--------------------|-------------------------------------|-------------------------------------|
| 遍历目标           | 对象的可枚举属性（键名）            | 可迭代对象的元素（值）              |
| 循环变量含义       | 键名（字符串类型，如数组索引）      | 元素值（直接获取值）                |
| 是否遍历原型链     | 是（需用 `hasOwnProperty` 过滤）    | 否（仅遍历自身元素）                |
| 适用对象           | 普通对象（检查属性）                | 数组、字符串、`Map`、`Set` 等可迭代对象 |
| 能否遍历普通对象   | 能                                  | 不能（普通对象不可迭代）            |

**最佳实践**：  

- 遍历对象的属性时用 `for...in`，并配合 `hasOwnProperty` 过滤原型链属性。  
- 遍历数组、字符串等可迭代对象的元素时，优先用 `for...of`（更简洁、安全）。

/**
 * ES5、ES3 中，迭代器使用 for..of 报错，所以就有了生成器
 * 
 * 目标为 ECMAScript 2015 或更高
 * 当目标为兼容ECMAScipt 2015的引擎时，编译器会生成相应引擎的for..of内置迭代器实现方式。
 * 
 * 生成器：向下兼容，将表达式转换为可用代码
 */

//编译器会生成一个简单的for循环做为for..of循环，比如：
let numbers = [1, 2, 3];
for (let num of numbers) {
    console.log(num);
}
// 生成的代码为：
// var numbers2 = [1, 2, 3];
// for (var _i = 0; _i < numbers.length; _i++) {
//     var num = numbers[_i];
//     console.log(num);
// }
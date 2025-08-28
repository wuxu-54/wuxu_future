/**
 * 迭代器
 * 
 * c++中的解释是：提供一种方法，可以遍历容器元素，而又不暴露容器内部表示方式。 每个容器都有自己的迭代器。 ts中同样如此。是一种设计思想，用于解耦
 * 
 * 可迭代性:
 *      当一个对象，实现了Symbol.iterator属性，认为是可迭代的。
 *      一些内置的类型如 Array，Map，Set，String，Int32Array，Uint32Array等都已经实现了各自的Symbol.iterator。
 */



let listTest = [4, 5, 6];

for (let i in listTest) {//for..of  取得是键
    console.log(i); // "0", "1", "2",
}

for (let i of listTest) {//for..of  取得是值
    console.log(i); // "4", "5", "6"
}
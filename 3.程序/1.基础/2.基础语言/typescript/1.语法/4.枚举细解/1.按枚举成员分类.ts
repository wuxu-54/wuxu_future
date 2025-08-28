/**
 * 枚举 ，一种特别的对象
 * 声明：enum 枚举名{属性}
 * 
 * 按枚举成员分类，可以分为：
 * 数字、字符串、异构
 */

/**
 * 数字枚举
 */
enum Num{ // 默认是数字枚举。数字枚举属性会自增，A = 0，B在A基础上+1
    A,//0
    B,//1
    C//2
}

//数字枚举 具有 反向映射
console.log(Num["A"] === 0); 
console.log(Num[0] === "A");//这就是反向映射

/** 
 *  反向映射 js中的代码
 
    var Enum;
    (function (Enum) {
        Enum[Enum["A"] = 0] = "A";//空对象，生成了俩索引：A、0
    })(Enum || (Enum = {}));
    var a = Enum.A;
    var nameOfA = Enum[a]; // "A"
 */



/**
 * 字符串枚举
 */
enum Num1{ // 值为字符串，无自增
    A = "A",
    B = "B",
    C = "C"
}


/**
 * 异构枚举
 * 
 * 值的类型可以是字符串或数字
 */
enum Num2{ // 值为字符串，无自增
    A = "A",
    B = 1,
}

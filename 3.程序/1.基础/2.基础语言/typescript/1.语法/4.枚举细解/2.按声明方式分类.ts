/**
 * 按声明方式区分枚举类型
 * 
 * 运行时枚举、const枚举、外部枚举、外部常量枚举
 */

/**
 * 运行时枚举，也是普通枚举
 * 
 * 成员可以通过计算获得
 * 注意：
 * 1.枚举是在运行时真正存在的对象。
 * 2.其普通成员在一开始就可以确定，但计算成员，需要运行时才能确定值
 * 3.计算成员必须在普通成员后面，因为数字型普通枚举有自增性，会报错
 */

enum Enum1{
    X,Y,Z = "123".length  //Z是计算出来的，是计算成员，必须在最后
}

enum Enum2{
    X,
    Y,
    Z = "123".length  //Z是算出来的，必须在最后
    // I//报错，Z在运行时才会知道值，因自增性 I无法确定值， 
}

/**
 * 常数枚举
 * 
 * 定义：const enum 枚举名{属性}
 * 
 * 与普通枚举区别就是，其会在编译阶段删除，只会将值赋给变量。所以不能有计算成员
 */

const enum Directions {
    Up,
    Down,
    Left,
    Right
}
 
let directions = [Directions.Up, Directions.Down, Directions.Left, Directions.Right];
//以上会被编译为： var directions = [0 /* Up */, 1 /* Down */, 2 /* Left */, 3 /* Right */];  由此可见，最终只会保留对应数据，而不是一个正常的对象属性


/**
 * 外部枚举
 * 
 * 定义：declare enum 枚举名{属性}
 * 
 * 用法：本地可以使用外部枚举，作为占位，当编译后，会真正指向外部的对象（外部同名、同属性对象），如果这个对象不存在，会报错。
 */
declare enum ChineseZodiac {
    rat = 1,
    cattle,
    tiger,
    rabbit,
    dragon
  }
  console.log(ChineseZodiac)
  console.log(ChineseZodiac.rat)

/**
 * 外部常量枚举
 * 
 * 定义：declare const enum 枚举名{属性}
 * 
 * 这个枚举类型和 const 枚举类型并没有什么区别，只是会提示是否有枚举命名冲突和成员冲突，该枚举类型不会生成反向映射
 */

declare const enum ChineseZodiac2 {
    rat = 1,
    cattle,
    tiger,
    rabbit,
    dragon
  }
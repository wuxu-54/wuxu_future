/**
 * 交叉类型
 * 定义：A & B & C
 * 个人理解：取交集，也就是一个类型同时含有 A、B、C 三种类型结构
 */
class T1 {
    name: string;
}
class T2 {
    age: number;
}

let T3: T1 & T2 = {//T3 是T1和T2的交集类型，同时拥有两者的属性
    name: "11",
    age: 1,
    // os:true //报错，不存在
}


/**
 * 联合类型
 * A | B
 * 
 * 个人理解：取并集，可以是A与B 成员的并集
 */
let T4: T1 | T2 = {//T4 是T1、T2中的并集
    name: "",
    age: 1,
}

interface I1 {
    fly();
    run();
}

interface I2 {
    fly2();
    run();
}

class C1 implements I1 {
    fly() {

    }

    run() {

    }
}
let f3: I1 | I2;
f3 = {
    fly2() { },
    fly() { },
    run() { }
}


function testF(): I1 | I2 {
    return f3;
}

testF().run();//当属于联合类型时，只能访问共有成员

/**
 * 如何区分类型？
 * 
 * 遇到联合类型或父类、any类型，我们如何区分具体类型呢？
 */
//断言
(<I1>f3).fly();
(f3 as I1).fly();


/**
 * 类型保护
 * 开发中，避免编译或是调用出现问题，可以使用类型保护，提前判断具体类型
 * 
 * 1.自定义，通过类型谓词 is，在方法返回值处定义
 * 2.typeof 关键字  获取成员具体类型， 对象是object
 * 3.instanceof  判断超类或接口被某个子类实现
 */

//类型谓词  is ,是个布尔类型，表示是否是某个类型
function tF(f: I1 | I2): f is I1 {//经过测试，普通变量或表达式中无法使用，只有返回值这里可以使用 is
    return (f as I1) !== undefined;
}

//typeof ， 判断f3 是一个对象不
if ((typeof f3) === "object") { }


//instanceof ，超类或接口被实现
let c1: I1 = new C1();

if (c1 instanceof C1) {
    //这里c1 就可以断言，转换为C1类型
    (<C1>c1).fly();
}

/**
 * null 和 undefined
 * 
 * 这俩类型是其他类型的子类，所以在js中可以赋值给任何类型除了 void
 * 严格模式中（vs中的 --strictNullChecks） 编译器会检查，null不能赋值给其他类型，除非他允许null类型
 */
// let s0 :string  = null;//报错，严格模式，不允许赋值null
let s1: string | null = null;//这是可以的

//可选属性、可选参数，严格模式中会默认加上 |undefined ，避免编译报错
function f(x: number, y?: number) {
    return x + (y || 0);
}
f(1, 2);
f(1);
f(1, undefined);
// f(1, null);//报错，可选参数不允许赋空，因为 y的类型是： y:number|undefined


/**
 * 类型别名
 * 
 * 对某个类型起一个 外号，其他什么都一样
 * 定义：type
 */

type NewName = string;
type NewName2 = string | number | null; //可以随便写类型
type NewName3<T> = T & { name: NewName3<T> }; // 也可以加上泛型

let typeTest: NewName2 = null;
typeTest = "1";
typeTest = 1;

let typeTest3: NewName3<number>;//古怪的类型，根本没法用，但就是可以创建，了解就行

type P = "1" | "2" | "3"; //可以这样起别名，效果类似枚举
type P2 = 1 | 2 | 3;


/**
 * this类型
 * 
 *  this指向调用者本身。类或构造函数调用者就是实例对象，箭头函数指向外部调用者
 * 
 * 可以用来做链式编程
 */
class This {
    t1(): this {
        return this;
    }
    t2(): this {
        return this;
    }
}

class ChildThis extends This {
    t1(): this {//重写，this指向 ChildThis对象
        return this;
    }
}
let thisTest = new This();
thisTest.t1().t2();



/**
 * 索引类型
 * 
 * keyof ，确定某个数组或是对象的索引类型
 */
function pluck<T, K extends keyof T>(o: T, names: K[]): T[K][] {
    return names.map(n => o[n]);
}

interface Person {
    name: string;
    age: number;
}
let person: Person = {
    name: 'Jarid',
    age: 35
};
let strings: string[] = pluck(person, ['name']); // ok, string[]

let personProps: keyof Person; // 这里类型就是 Person的属性名的联合类型 'name' | 'age'

/**
 * 映射类型
 * js也有
 * 
 * [P in keyof T]:T[P] 
 * 
 * 个人理解，将一个对象或数组，中的索引及value各自取出，生成一个新的对象。所谓的映射就是取索引
 */
interface P00{
    name:string;
    age:number;
}
// 通过映射类型，将其属性变为可选或可读，可以用下面这种写法
// T是传入的对象或是数组
type Partial00<T> = {[p in keyof T]?:T[p]}//属性变为可选,这里生成了一个新对象，里面的属性变成了可选
type ReadOnly00<T> = {readonly [p in keyof T]:T[p]}//属性变为只读,这里生成了一个新对象，里面的属性变成了只读



/**
 * 预定义的有条件类型
 * 
 * TypeScript 2.8在lib.d.ts里增加了一些预定义的有条件类型：
      Exclude<T, U> -- 从T中剔除可以赋值给U的类型。
      Extract<T, U> -- 提取T中可以赋值给U的类型。
      NonNullable<T> -- 从T中剔除null和undefined。
      ReturnType<T> -- 获取函数返回值类型。
      InstanceType<T> -- 获取构造函数类型的实例类型。
 */

type T00 = Exclude<"a" | "b" | "c" | "d", "a" | "c" | "f">;  // "b" | "d"
type T01 = Extract<"a" | "b" | "c" | "d", "a" | "c" | "f">;  // "a" | "c"
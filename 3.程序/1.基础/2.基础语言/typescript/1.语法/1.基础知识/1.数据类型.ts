//!! ts中的基础数据类型与js相同

//1.布尔类型
let isDone:boolean = false;

//2.数字类型 ，可以表示多种进制
let num :number = 12;
let hex :number = 0xf00d;//16进制
let binary :number = 0b1010;//二进制
let octal:number = 0o744;//8进制

//3.字符串, 双引号或单引号表示。``符号可以用于数据嵌入，也叫模版字符串
let str1 :string = "1";
let str2 :string = '2';
let str3 :string = `内嵌表达式 > ${num}`;//${} 是内嵌表达式，可以写代码，与字符串拼接

//4.数组
let list :number[]= [1,2,3];
let array:Array<number> = [1,2,3];//使用数组泛型

//5.元组（元组类型允许表示一个已知元素数量和类型的数组，各元素的类型不必相同。）
let x :[string,number,number|string];//number|string 是联合类型
x = ['hello',10,'11'];
// x = [10,'hello'];//报错，顺序必须一样

// 访问元素，编译器可直接识别类型
console.log(x[0].substring(1));
// console.log(x[1].substring(1));//报错，number没有substring方法
//访问越界元素，编译器无法识别具体类型，会识别为 并集，如x识别是  string|number（这个叫联合类型）
//  x[3] = 'world';// 报错，当前ts版本不支持越界元素了~，上面描述是学习文档中的，过时了

//6.枚举 ，ts新增.  跟c相同，默认值是0 开始，依次累加，可以指定值，然后从指定值累加
enum color{Red,Green=2,Blue}//指定Green=2，Blue就是3
let c :color =color.Blue
console.log(c);

//7.Any ts新增，任意类型，跟kotlin一样，当不清楚元素具体类型，可以用Any接收。编译器不会报错
//与Object区别，any类型的数据可以调用当前元素类型方法
let notSure:any = 4;
notSure--;//notSure被赋值为数字类型，可当做number类型使用
notSure = "any is string";
notSure.substring(1);//notSure被赋值为字符串类型，可以使用字符串类型的方法
notSure = false;
//8.void ts新增， 不代表任何类型
function test():void{
    //指明返回值为void类型，表示没有返回值
}
let unusable : void = undefined;//可以赋值undefined，没啥用啊

//9.null、undefined  是所有类型的子类型，可以赋值给其他基础类型
//注意：当你指定了--strictNullChecks标记（严格模式，vscode设置可以），null和undefined只能赋值给void和它们各自
let undefinedValue;//未标明类型，默认是 undefined
console.log(undefinedValue);//打印undefined

//10.never 类型表示的是那些永不存在的值的类型。

//never类型是任何类型的子类型，也可以赋值给任何类型；然而，没有类型是never的子类型或可以赋值给never类型（除了never本身之外）。 即使 any也不可以赋值给never。

// 返回never的函数必须存在无法达到的终点
function error(message: string): never {
    throw new Error(message);
}

// 推断的返回值类型为never
function fail() {
    return error("Something failed");
}

// 返回never的函数必须存在无法达到的终点
function infiniteLoop(): never {
    while (true) {
    }
}

//11.object 除基础类型外的类型，也就是除number，string，boolean，symbol，null或undefined之外的类型。
let obj1:object = {name:"name"};//是个对象

//12.类型断言， 强制告诉编译器具体类型。java的类型转换

let anyValue :any = 1;
console.log(<number>anyValue);//方式一 泛型： <number>anyValue
console.log(anyValue as number);//方式二 as： anyValue as number

const rootView = document.querySelector("html")
const newView = document.createElement('div')
newView.style.width='200px'
newView.style.height ='200px'
newView.style.backgroundColor="red"
rootView?.appendChild(newView)


/**
 * 13.Symbols ECMAScript 2015起，symbol成为了一种新的原生类型，就像number和string一样。
 * 
 * Symbols 核心定义是：
 * 1.不可修改
 * 2.全局单例
 * 3.像字符串一样，可以用作对象属性的键
 * 4.可以作为方法的名字
 * 
 * 还有其他的使用方式：https://www.tslang.cn/docs/handbook/symbols.html
 */
let sym1 = Symbol("key");
let sym2 = Symbol("key");

console.log(sym1 === sym2);//输出false 

let obj = {"string":"a",sym1:"b",[sym2] :"c"};//sym1 可以作为键
obj.sym1.length
obj[sym2].length //俩方法都行

class TestSymbol{
    [sym1](){//Symbol 可以作为这个函数的名字
    }
}
const obj2:TestSymbol =new TestSymbol();
obj2[sym1]();//通过这样方式调用
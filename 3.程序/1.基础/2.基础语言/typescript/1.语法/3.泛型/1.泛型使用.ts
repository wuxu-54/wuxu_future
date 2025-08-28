/**
 * 泛型，创建代码模版，避免类似逻辑代码重复
 * 
 *  定义泛型:  <泛型名>
 */

/**
 * 函数泛型
 **/
function  add<T>(x:T):T{//函数泛型定义
    return x;
}


let value = add<number>(1);//注意这里是指定了类型
let value2 = add(1);//这个是编译器可以动态推导出类型，所以泛型没有强制指定，会根据传入值推导出返回值类型


/**
 * 泛型变量的使用
 * 1.泛型变量可以是任意类型，所以某些特定属性是无法调用的。
 * 2.使用extends可以添加泛型类型的约束
 */
function testFun1<T>(t:T){
    // t.length;//报错，因为T可以是任意类型，如number没有length属性，所以没办法做到通用
}

function testFun2<T>(t:T[]){
     t.length;//正确，因为t形参是个数组，所以有length属性
}

function testFun3<T extends string>(t:T){
    t.length;//正确，使用 extends 约束T的类型是string 或 string子类，所以t可以使用string的所有属性
}

/**
 * 泛型类型
 * 
 * 泛型可以作为类型
 */
let addFun : <T>(t:T)=>T ;//addFun是个函数类型，T作为泛型，赋值函数结构必须符合
addFun = function<T>(i :T):T{//这个函数结构与上面相同，所以可以赋值给addFun变量
    return i;
}
addFun(1);



function getProperty<T extends Object,K extends string>(obj: T, key: K) {
    return obj[key as string];
}

let x = { a: 1, b: 2, c: 3, d: 4 };

getProperty(x, "a"); // okay
getProperty(x, "m"); // error: Argument of type 'm' isn't assignable to 'a' | 'b' | 'c' | 'd'.
/**
 * 类泛型
 * 
 * 类中增加泛型（接口设置泛型也一样）
 * 定义：类名<泛型名>
 */
class ClsTest<T>{
    name:T;
}
let test = new ClsTest<string>();
// test.name = 1;//报错
test.name="1";//正确

//泛型使用类类型
abstract class Animal{
    name:string = "Animal";
    abstract testFun():void;
}

class A1 extends Animal{
    testFun(): void {
        console.log("A1")
    }
}

class A2 extends Animal{
    testFun(): void {
        console.log("A2")
    }
}
//可以作为factory 批量创建某一类型数据
function create<T extends Animal> (c:new()=>T):T{ //重点！，这里是采用接口对类结构描述的形式；new()=>T T类型的类，也就是类类型；写法2 {new():T} ；
    return new c();
}

create(A1).testFun();
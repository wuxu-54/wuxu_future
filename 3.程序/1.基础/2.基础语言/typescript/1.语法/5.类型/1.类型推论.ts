/**
 * 编译器会根据值的类型推出变量的类型
 * 
 * 1.编译器推导类型，会找出最佳的类型
 */
let x = 3; // 自动推论得出，x是number类型

let x1 = [0,1,null];//编译器会考虑所有元素的类型，x1是其并集。  此处x1类型是 (number|null)[]
let x2 :(number|null)[] = x1;


/**
 * 推论可能不是我们想要的，此时就要指明具体类型 
 */

class P{}
class C1 extends P{}
class C2 extends P{}

let x3 = [new C1(),new C2()];//这里x3编译器推导是 (C1|C2)[] 类型，编译器无法推断出P[] ,但我们需要P类型，此时就要写明了
let x4:P[] = [new C1(),new C2()];//写明具体类型


/**
 * 方法多个参数时，如果不声明类型，参数名会绑定到对应位置的参数类型上
*/

window.onmousedown = function(mouseEvent) {//这里mouseEvent 没有声明类型，所以他的类型编译器认为是方法的第一个，也就是上下文类型
    console.log(mouseEvent.button);  //<- Error，上下文类型，没有button
};

window.onmousedown = function(mouseEvent:any) {//这里mouseEvent 声明类型，编译器会将其匹配到类型相同的参数上，所以这里是真正的event对象
    console.log(mouseEvent.button);  //正确
};

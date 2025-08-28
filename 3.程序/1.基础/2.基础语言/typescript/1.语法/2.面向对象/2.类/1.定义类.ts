// ts中类的定义、结构，跟java一样
class A{
    //属性
    name:string;
    age:number;

    //构造函数，当类的实例声明后会立刻调用构造函数
    constructor(name:string){
        this.name = name;//this 指当前类
    }

    //函数
    fun():void{

    }
}

//使用A
const a = new A("1");
console.log(a.name);
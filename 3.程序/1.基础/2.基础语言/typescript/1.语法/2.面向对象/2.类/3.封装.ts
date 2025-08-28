//封装，指的是在面向对象过程中，类可以将某些成员私有，避免外部访问。

/**
 * 修饰符
 * public 公开（默认就是） 
 * protected 保护，这个是只有派生类可以访问 
 * private 私有，只有当前类可以访问，派生类也不行
 * 
 * readonly  只读，只允许读值不允许赋值。ts特有
 */

class Person{
    public name:string;
    protected age:number;
    private sex:string;

    public readonly t:string;//声明时初始化或构造器中初始化

    constructor(t:string){
        this.t = t;
    }
}

class P1 extends Person{
    test(){
        console.log(this.age);//可以访问父类age
    }
}

const p1 = new P1("ttt");
p1.test();
p1.name;//外部使用，只能访问public修饰的


/**
 * ts 的抽象类跟java相同，可以父类声明子类实现
 * 
 * abstract 关键字修饰类及抽象函数
 * 
 * 1.抽象函数跟接口中的函数一样，子类实现
 * 2.抽象类不能有实例
 * 3.抽象类可以作为属性类型
 */
abstract class AbsPerson{
    abstract  absFun():void;//必须abstract修饰
}

class Son extends AbsPerson{//
    absFun(): void {
        console.log("")
    }
}

let son = new Son();
// let child1 = new AbsPerson();//报错，抽象类不能创建实例对象
let son2:AbsPerson = new Son();//抽象类可以作为属性类型，编译时会隐式类型转换
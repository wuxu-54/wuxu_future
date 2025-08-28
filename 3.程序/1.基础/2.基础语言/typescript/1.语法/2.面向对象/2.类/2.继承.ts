//继承，关键字是 extends。 继承可以让一个类 完全继承另一个父类的成员，避免代码冗余

//父类也叫超类
class Parent{
     name:string;
}

//子类也叫派生类
class Child extends Parent{

}

const child = new Child();

child.name = "1";//子类对象继承了父类成员
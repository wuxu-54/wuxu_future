//多态  类继承后，可以重写父类方法，实现多样性的目的。
class Animal{
    run(){}
}

class Dog extends Animal{
   run() {
       //重写父类方法
       console.log("dog run");
   }
}

class Cat extends Animal{
    run() {
        //重写父类方法
        console.log("cat run");
    }
 }

const dog = new Dog();
const cat = new Cat();

dog.run();
cat.run();
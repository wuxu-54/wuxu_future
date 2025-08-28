/**
 * 静态属性  看文档，ts的静态属性跟 java 一样，类名.成员名
 * 
 * static 修饰
 * 
 * 跟正常实例不同，静态属性存在于类本身，而不是类对象上。
 */
class Grid{
    static origin = {x:0,y:1}; //静态成员

    test(){
        console.log(Grid.origin.x);//类名.成员名
    }
}

const grid  = new Grid();
grid.test();

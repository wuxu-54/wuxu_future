
/**
 * 同名的命名空间代码，编译时会合并，模块不会。
 * 相当于在同一文件中编写，ts编译成js代码时，可以看到是多个js文件顺序引入文件中
 */



/**
 * 别名，方便简写调用
 */
namespace Shapes {
    export namespace Polygons {
        export class Triangle { }
        export class Square { }
    }
}

import polygons = Shapes.Polygons;
let sq = new polygons.Square(); // Same as "new Shapes.Polygons.Square()"


/**
 * 外部空间
 * 
 * 流行的程序库D3在全局对象d3里定义它的功能。
 *  因为这个库通过一个 <script>标签加载（不是通过模块加载器），它的声明文件使用内部模块来定义它的类型。
 *  为了让TypeScript编译器识别它的类型，我们使用外部命名空间声明。
 *  比如，我们可以像下面这样写
 */
declare namespace D3 {
    export interface Selectors {
        select: {
            (selector: string): Selection;
            (element: EventTarget): Selection;
        };
    }

    export interface Event {
        x: number;
        y: number;
    }

    export interface Base extends Selectors {
        event: Event;
    }
}

declare var d3: D3.Base;
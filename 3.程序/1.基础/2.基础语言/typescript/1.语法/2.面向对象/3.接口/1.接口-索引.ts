interface IArray{
    [index:number]:string;//定义索引类型是number，返回值是string
    // [index:string]:string;
}

let arr :IArray;
arr = ["1","2"];
let value:string = arr[0];//string类型
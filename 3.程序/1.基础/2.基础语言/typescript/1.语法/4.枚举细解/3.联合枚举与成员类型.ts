/**
 * 当声明枚举后，作为参数类型使用时，枚举类型相当于 其内部成员的联合类型
 */
enum P{ //P相当于  A|B|C
    A,B,C
}

function testFun(p:P){//P相当于  A|B|C
    if(p === P.A){
        console.log("A");
    }else if(p === P.B){
        console.log("B");
    }else{
        console.log("C");
    }
}

testFun(P.A);
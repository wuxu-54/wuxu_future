#include <stdio.h>

/**
 * wuxu
 * 1.scanf
 * 2.getChar
 * 3.putChar
 * 4.gets()
 * 5.puts()
 */

void inputString()
{
    char inputS[100];
    printf("please input string: \n");
    scanf("%s", inputS); // inputs 0 位置默认就是其内存地址
    printf("you input string is %s \n", inputS);
}

void inputInt()
{
    int d = 0;
    printf("please input int: \n");
    scanf("%d", &d); // 保存在内存中，所以需要取地址符
    printf("you input int is %d \n", d);
}

/**
 * !!! 输入遇到的一个奇怪问题及原因：arr c语言不会检验数组越界，因为末尾结束符 会占用到int内存，；
 */
void inputProblem()
{
    while (1)
    {
        char arr[4];
        int count;
        printf("please input arr: \n");
        scanf("%s", &arr);
        
        printf("please input int: \n");
        scanf("%d", &count);

        printf("you input int is %d \n", count);
        printf("you input string is %s \n", arr);
    }
}

int main()
{
    // inputString();
    // printf("===============\n");
    // inputInt();
    inputProblem();
}
#include<stdio.h>
#include<stdlib.h>

/**
 * 1.输入班级人数
 * 2.输入每个学生编号，存放到变量
 * 3.输出学生编号
 * 4.输入插班生人数
 * 5.输入插班生编号
 * 6.输出学生编号
*/
int main(){
    int count;

    printf("输入班级人数:");
    scanf("%d",&count);


    int* num_pointer = malloc(sizeof(int) * count);
    int i;
    for ( i = 0; i < count; i++)
    {
        printf("输入第%d学生编号:",i+1);
        scanf("%d",num_pointer+i);
    }

      for ( i = 0; i < count; i++)
    {
        printf("第%d学生编号是:%d\n",i+1,*(num_pointer+i));
    }


    int increment;
    printf("输入插班生人数:");
    scanf("%d",&increment);

    realloc(num_pointer,sizeof(int) * (count+increment));

    for (i = count; i < count+increment; i++)
    {
        printf("输入第%d学生编号:",i+1);
        scanf("%d",num_pointer+i);
    }
    

    for ( i = 0; i < (count+increment); i++)
    {
        printf("第%d学生编号是:%d\n",i+1,*(num_pointer+i));
    }

    
    free(num_pointer);
}
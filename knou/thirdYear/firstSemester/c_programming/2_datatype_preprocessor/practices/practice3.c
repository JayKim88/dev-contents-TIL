// 변수의 초기화
#include <stdio.h>

void main()
{
    int i, sum;
    for (i = 1; i <= 10; i++)
        sum = sum + i;
    printf("1부터 10까지의 합=%d\n", sum);
}

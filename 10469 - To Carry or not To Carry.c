#include<stdio.h>

int main(void)
{
    int pierwsza,druga,suma = 0,maska = 1;

    while( scanf("%d %d",&pierwsza,&druga) == 2 )
    {

        printf("%d\n",pierwsza ^ druga);

    }

    return 0;
}

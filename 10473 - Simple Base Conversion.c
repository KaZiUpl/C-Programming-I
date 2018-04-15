#include<stdio.h>
#include<stdlib.h>


int main(void)
{
    char bufor[13];
    int liczba;

    fgets(bufor,13,stdin);
    while(bufor[0] != '-')
    {
        if(bufor[1] == 'x')
        {
            liczba = strtol(bufor,NULL,16);
            printf("%d\n",liczba);
        }
        else
        {
            liczba = strtol(bufor,NULL,10);

            printf("0x%X\n",liczba);
        }

        fgets(bufor,13,stdin);
    }

    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char napis[30];
    int test_cases,cyfra,pierwszy_znak;
    unsigned long long int suma,waga=1;
    scanf("%d\n",&test_cases);

    while(test_cases--)
    {
        suma = 0;
        fgets(napis, 30, stdin);
        pierwszy_znak = strlen(napis);
        int i;

        for(i=pierwszy_znak;i>=0;--i)
        {
            if(napis[i] == 'A') cyfra = 0;
            else if(napis[i] == 'C') cyfra = 1;
            else if(napis[i] == 'G') cyfra = 2;
            else if(napis[i] == 'T') cyfra = 3;
            else cyfra = 8;
            /*printf("Cyfra: %d %c|\n",cyfra,napis[i]);*/

            if(cyfra != 8)
            {
                suma = suma + waga*cyfra;
                waga = waga*4;
            }
        }
        printf("Case %d: (%d:%lld)\n",test_cases,strlen(napis),suma);

    }

    return 0;
}

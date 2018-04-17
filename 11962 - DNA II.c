#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char napis[50];
    int test_cases,curr_case,cyfra;
    unsigned long long suma,waga;
    int i;
    scanf("%d\n",&test_cases);
    curr_case = 1;
    while(curr_case <= test_cases)
    {
        suma = 0;
        waga = 1;
        fgets(napis, 50, stdin);

        for(i=strlen(napis)-1;i>=0;--i)
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
        printf("Case %d: (%d:%llu)\n",curr_case,strlen(napis)-1,suma);
        curr_case++;
    }

    return 0;
}

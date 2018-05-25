#include<stdio.h>
#include<math.h>

#define maksymalna pow(10,7)
int licznik;

int czy_pierwsza()
{
    int prime_test = licznik;
    licznik++;

    int i,flaga=1;
    for(i=2 ; i*i<=prime_test ; ++i)
    {
        if(prime_test%i == 0 && prime_test != 2)
        {
            flaga = 0;
            break;
        }
    }
    if(flaga == 1) printf("%d\n",prime_test);
}

int main(void)
{
    int i;
    licznik = 2;
    while(licznik < maksymalna)
    {
        czy_pierwsza();
    }
    return 0;
}

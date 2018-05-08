#include<stdio.h>


int main(void)
{
    int liczba_jedynek=0,znacznik;
    long int liczba,maska=1,cokolwiek;
    scanf("%d",&liczba);
    while(liczba != 0)
    {
        char liczba_bin[32];
        int i;
        for(i=0;i<32;++i)
        {
            liczba_bin[i] = '0';
        }
        znacznik = 31;
        while(maska <= liczba && maska!=0)
        {
            /*printf("maska %ld %ld\n",maska,maska&liczba);*/
            cokolwiek = liczba&maska;
            if(cokolwiek > 0 )
            {
                liczba_jedynek++;
                liczba_bin[znacznik] = '1';
                znacznik--;
            }

            maska = maska<<1;
        }

        printf("The parity of ");
        for(i=znacznik+1;i<32;++i)
        {
            printf("%c",liczba_bin[i]);
        }
        printf(" is %d (mod 2).\n",liczba_jedynek);
        maska = 1;
        liczba_jedynek = 0;
        scanf("%d",&liczba);
    }

    return 0;
}

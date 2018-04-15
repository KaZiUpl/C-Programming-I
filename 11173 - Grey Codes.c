#include<stdio.h>

int main(void)
{
    int ilosc_testow,dlugosc_kodu,ktora_liczba,liczba_do_dodania,poczatek,koniec,suma;
    int liczba_jedynek;

    scanf("%d",&ilosc_testow);
    while(ilosc_testow--)
    {
        scanf("%d %d",&dlugosc_kodu,&ktora_liczba);
        liczba_jedynek = 0;
        poczatek = 0;
        koniec = (1<<dlugosc_kodu)-1;
        liczba_do_dodania = 1<<(dlugosc_kodu-1);
        suma = 0;
        liczba_jedynek = 0;
        while(liczba_do_dodania>0)
        {
            /**
            printf("Do dodania: %d\n",liczba_do_dodania);
            printf("poczatek: %d\n",poczatek);
            printf("koniec: %d\n\n",koniec);
            */
            if(ktora_liczba > (poczatek+koniec)/2)
            {
                poczatek = (poczatek+koniec)/2;
                if(liczba_jedynek%2 == 0)
                {
                    suma = suma+liczba_do_dodania;
                    liczba_jedynek++;
                }
            }
            else
            {
                koniec = (poczatek+koniec)/2;
                if(liczba_jedynek%2 == 1)
                {
                    suma = suma+liczba_do_dodania;
                    liczba_jedynek++;
                }
            }
            liczba_do_dodania = liczba_do_dodania/2;
        }
        printf("%d\n",suma);
    }


    return 0;
}

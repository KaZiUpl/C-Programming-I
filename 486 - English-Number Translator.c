#include<stdio.h>
#include<string.h>
int porownaj(char pierwszy[10],char * drugi)
{
    char *pierwszy_prim = pierwszy;
    if(strcmp(pierwszy_prim,drugi) == 0) return 1;
    return 0;
}
int porownaj_ptr(char * pierwszy, char* drugi)
{
    if(strcmp(pierwszy,drugi) == 0) return 1;
    return 0;
}
int znajdz(char klucz[32][10],int wartosc[32], char* wyraz)
{
    int i;
    for(i=0;i<32;++i)
    {
        if(porownaj(klucz[i],wyraz)) return wartosc[i];
    }
    return (int)NULL;
}

int main(void)
{

    int wartosc[] = {
        -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19,
        20, 30, 40, 50, 60, 70, 80, 90,
        100, 1000, 1000000
    };
    char klucz[32][10] = {
        "negative", "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
        "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
        "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety",
        "hundred", "thousand", "million"
    };


    char liczba_slowa[120];
    while(fgets(liczba_slowa,120,stdin) != NULL)
    {
        int suma = 0, pomoc=0, znak=1;
        char * nastepne_slowo = (char *) strtok(liczba_slowa," \t\n");
        while(nastepne_slowo != NULL)
        {
            /*
            printf("Slowo: %s\n",nastepne_slowo);
            printf("Pomoc: %d\n",pomoc);
            */
            if(porownaj_ptr(nastepne_slowo,"negative")) znak = -1;
            else if(porownaj_ptr(nastepne_slowo,"million"))
            {
                suma += pomoc*1000000;
                pomoc = 0;
            }
            else if(porownaj_ptr(nastepne_slowo,"thousand"))
            {
                suma += pomoc*1000;
                pomoc = 0;
            }
            else if(porownaj_ptr(nastepne_slowo,"hundred"))
            {
                pomoc = pomoc * 100;
            }
            else
            {
                pomoc += znajdz(klucz,wartosc,nastepne_slowo);
            }
            /*
            printf("Pomoc: %d\n",pomoc);
            printf("Suma: %d\n",suma);
            */
            nastepne_slowo = (char *) strtok(NULL," \t\n");
        }
        suma += pomoc;
        if(znak == -1) printf("-%d\n",suma);
        else printf("%d\n",suma);
    }

    return 0;
}

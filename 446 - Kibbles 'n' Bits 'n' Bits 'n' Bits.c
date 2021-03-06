#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

#define FOR(i,a,b) for(i=a;i<b;++i)
#define FORd(i,a,b) for(i=a;i>b;--i)
#define FOReq(i,a,b) for(i=a;i<=b;++i)
#define FORdeq(i,a,b) for(i=a;i>=b;--i)
#define print printf
#define scan scanf

void wypisz_binarnie(char * liczba)
{
    int dlugosc = strlen(liczba);
    int i;
    print("0");
    FOR(i,0,3-dlugosc)
    {
        print("0000");
    }
    FOR(i,0,dlugosc)
    {
        if(liczba[i] == '0') print("0000");
        else if(liczba[i] == '1') print("0001");
        else if(liczba[i] == '2') print("0010");
        else if(liczba[i] == '3') print("0011");
        else if(liczba[i] == '4') print("0100");
        else if(liczba[i] == '5') print("0101");
        else if(liczba[i] == '6') print("0110");
        else if(liczba[i] == '7') print("0111");
        else if(liczba[i] == '8') print("1000");
        else if(liczba[i] == '9') print("1001");
        else if(liczba[i] == 'A') print("1010");
        else if(liczba[i] == 'B') print("1011");
        else if(liczba[i] == 'C') print("1100");
        else if(liczba[i] == 'D') print("1101");
        else if(liczba[i] == 'E') print("1110");
        else if(liczba[i] == 'F') print("1111");
    }
}

int main(void)
{

    int test_cases;
    char dzialanie[15],*pierwsze,*znak,*drugie;
    int pierwsza_dec,druga_dec, wynik;
    scan("%d\n",&test_cases);
    while(test_cases--)
    {
        wynik = 0;
        fgets(dzialanie,15,stdin);
        pierwsze = (char *) strtok(dzialanie," \t\n");
        znak = (char *) strtok(NULL," \t\n");
        drugie = (char *) strtok(NULL," \t\n");

        pierwsza_dec = strtol(pierwsze,NULL,16);
        druga_dec = strtol(drugie,NULL,16);
        if(znak[0] == '+') wynik = pierwsza_dec + druga_dec;
        else wynik = pierwsza_dec - druga_dec;

        wypisz_binarnie(pierwsze);
        print(" %s ",znak);
        wypisz_binarnie(drugie);
        print(" = %d\n",wynik);
    }

    return 0;
}

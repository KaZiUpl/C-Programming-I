#include<stdio.h>
#include<math.h>

#define FOR(i,a,b) for(i=a;i<b;++i)
#define FORd(i,a,b) for(i=a;i>b;--i)
#define FOReq(i,a,b) for(i=a;i<=b;++i)
#define FORdeq(i,a,b) for(i=a;i>=b;--i)
#define print printf
#define scan scanf

int main(void)
{
    int test_cases,i;
    double odleglosc,dlugosc_liny;
    double Pi = 2*acos(0), wynik;

    scan("%d",&test_cases);

    FOR(i,0,test_cases)
    {
        scan("%lf %lf",&odleglosc,&dlugosc_liny);

        wynik = Pi * (odleglosc/2 + (dlugosc_liny-odleglosc)/2) * sqrt( pow(dlugosc_liny/2,2) - pow(odleglosc/2,2) );

        print("%.3f\n",wynik);
    }

    return 0;
}

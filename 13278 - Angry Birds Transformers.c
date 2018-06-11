#include<stdio.h>
#include<stdlib.h>

#define FOR(i,a,b) for(i=a;i<b;++i)
#define FORd(i,a,b) for(i=a;i>b;--i)
#define FOReq(i,a,b) for(i=a;i<=b;++i)
#define FORdeq(i,a,b) for(i=a;i>=b;--i)
#define print printf
#define scan scanf

int main(void)
{
    int test_cases, i,l;
    int x,y;
    int licznik,maks;


    scan("%d",&test_cases);
    FOR(l,0,test_cases)
    {
        licznik = 0;
        maks = 0;
        int starts[10001 + 1002],ends[10001 + 1002];
        FOR(i,0,10001+1002)
        {
            starts[i] = 0;
            ends[i] = 0;
        }
        FOR(i,0,test_cases)
        {
            scan("%d %d",&x,&y);
            starts[501 + x - y]++;
            ends[501 + x + y]++;
        }

        FOR(i,0,10001 + 1002)
        {
            licznik += starts[i];
            if(licznik > maks) maks = licznik;
            licznik -= ends[i];
        }

        print("---------------------------------------------------------------------\t%d\n",maks);

        scan("%d", &test_cases);
    }



    return 0;
}

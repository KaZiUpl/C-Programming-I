#include<stdio.h>

#define FOR(i,a,b) for(i=a;i<b;++i)
#define FORd(i,a,b) for(i=a;i>b;--i)
#define FOReq(i,a,b) for(i=a;i<=b;++i)
#define FORdeq(i,a,b) for(i=a;i>=b;--i)
#define print printf
#define scan scanf

int main(void)
{
    int N;
    int i,j,pomoc,ktory_mecz;
    while(scan("%d",&N) == 1)
    {
        scan("%d %d",&i,&j);
        ktory_mecz = 0;
        if(i>j)
        {
            pomoc = i;
            i = j;
            j = pomoc;
        }
        while(i < j)
        {
            i= i/2 + i%2;
            j= j/2 + j%2;
            ktory_mecz++;
        }
        print("%d\n",ktory_mecz);

    }
    return 0;
}

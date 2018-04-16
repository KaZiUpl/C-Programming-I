#include<stdio.h>

int main(void)
{
    int liczba_par,promien,punkty_w_ksztalcie=0;
    double x,y;
    scanf("%d %d",&liczba_par,&promien);
    while(liczba_par != 0 && promien != 0)
    {
        int i;
        for(i=0;i<liczba_par;++i)
        {
            scanf("%lf %lf",&x,&y);
            if( x*x + y*y <= promien*promien &&
                (x-promien)*(x-promien)+y*y <= promien*promien &&
                (x-promien)*(x-promien)+(y-promien)*(y-promien) <= promien*promien &&
                x*x + (y-promien)*(y-promien) <= promien*promien )
                {
                    punkty_w_ksztalcie++;
                }
        }
        printf("%.5lf\n",(double)punkty_w_ksztalcie*promien*promien/liczba_par);

        punkty_w_ksztalcie=0;
        scanf("%d %d",&liczba_par,&promien);
    }
    return 0;
}

#include<stdio.h>

struct wektor
{
    double x,y;

};

double dlugosc_do_kwadratu(struct wektor pierwszy,struct wektor drugi)
{
    return (pierwszy.x-drugi.x)*(pierwszy.x-drugi.x)+(pierwszy.y-drugi.y)*(pierwszy.y-drugi.y);
}

int main(void)
{
    struct wektor w1,w2,w3,w4;

    while(scanf("%lf %lf",&w1.x,&w1.y) == 2)
    {
        scanf("%lf %lf",&w2.x,&w2.y);
        scanf("%lf %lf",&w3.x,&w3.y);
        scanf("%lf %lf",&w4.x,&w4.y);

        if(w1.x == w3.x && w1.y == w3.y)
        {
            printf("%.3lf %.3lf\n",w2.x+w4.x-w1.x,w2.y+w4.y-w1.y);
        }
        else if(w1.x == w4.x && w1.y == w4.y)
        {
            printf("%.3lf %.3lf\n",w2.x+w3.x-w1.x,w2.y+w3.y-w1.y);
        }
        else if(w2.x == w3.x && w2.y == w3.y)
        {
            printf("%.3lf %.3lf\n",w1.x+w4.x-w2.x,w1.y+w4.y-w2.y);
        }
        else if(w2.x == w4.x && w2.y == w4.y)
        {
            printf("%.3lf %.3lf\n",w1.x+w3.x-w2.x,w1.y+w3.y-w2.y);
        }

    }



    return 0;
}

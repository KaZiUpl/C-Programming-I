#include<stdio.h>
struct punkt
{
    double x,y;
};
struct prosta
{
    int a,b,c;
};

int main(void)
{
    struct prosta p1,p2;
    struct punkt wspol_1,wspol_2;

    scanf("%d %d %d",&p1.a,&p1.b,&p1.c);
    scanf("%d %d %d",&p2.a,&p2.b,&p2.c);
    while(p1.a != 0 || p1.b != 0 || p1.c != 0 || p2.a != 0 || p2.b != 0 || p2.c != 0)
    {
        double wyznacznik = p1.a * p2.b - p2.a * p1.b;

        if(wyznacznik != 0)
        {
            wspol_1.x = (double) ((p1.c*p2.b - p2.c*p1.b) / wyznacznik);
            if(wspol_1.x == -0) wspol_1.x = 0;
            wspol_1.y = (double) ((p1.a*p2.c - p2.a*p1.c) / wyznacznik);
            if(wspol_1.y == -0) wspol_1.y = 0;
            printf("The fixed point is at %.02lf %.02lf.\n",wspol_1.x,wspol_1.y);
        }
        else printf("No fixed point exists.\n");

        scanf("%d %d %d",&p1.a,&p1.b,&p1.c);
        scanf("%d %d %d",&p2.a,&p2.b,&p2.c);
    }
    return 0;
}

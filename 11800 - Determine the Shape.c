#include<stdio.h>
#include<math.h>

#define inf pow(2,31);
#define KWADRAT "Square"
#define PROSTOKAT "Rectangle"
#define ROMB "Rhombus"
#define ROWNOLEGLOBOK "Parallelogram"
#define TRAPEZ "Trapezium"
#define INNY "Ordinary Quadrilateral"

typedef struct
{
    int x,y;
} Punkt;
typedef struct
{
    Punkt start,koniec;
    int A,B,C;
} Odcinek;

Punkt stworz_punkt(int a,int b)
{
    Punkt punkt;
    punkt.x = a;
    punkt.y = b;
    return punkt;
}
void przypisz_wartosci_odcinka(Odcinek *odcinek, int start_a,int start_b,int koniec_a,int koniec_b)
{
    odcinek->start.x = start_a;
    odcinek->start.y = start_b;
    odcinek->koniec.x = koniec_a;
    odcinek->koniec.y = koniec_b;
}
void wyliczWspolczynniki(Odcinek *prosta)
{
    prosta->A = prosta->start.y - prosta->koniec.y;
    prosta->B = prosta->koniec.x - prosta->start.x;
    prosta->C = (prosta->start.x * prosta->koniec.y) - (prosta->koniec.x * prosta->start.y);
}
Odcinek polacz_punkty(Punkt a,Punkt b)
{
    Odcinek _temp;
    _temp.start.x = a.x;
    _temp.start.y = a.y;
    _temp.koniec.x = b.x;
    _temp.koniec.y = b.y;
    wyliczWspolczynniki(&_temp);
    return _temp;
}
void wypisz_punkt(Punkt punkt)
{
    printf("%d %d\n",punkt.x,punkt.y);
}
void wypisz_odcinek(Odcinek odcinek)
{
    printf("%d %d -----> %d %d\n",odcinek.start.x,odcinek.start.y,odcinek.koniec.x,odcinek.koniec.y);
}

void zamien_miejscami(Punkt *pierwszy,Punkt *drugi)
{
    Punkt _temp;
    _temp.x = pierwszy->x;
    _temp.y = pierwszy->y;
    pierwszy->x = drugi->x;
    pierwszy->y = drugi->y;
    drugi->x = _temp.x;
    drugi->y = _temp.y;
}
int z_ktorej_strony(Punkt x,Punkt y,Punkt z)
{
    int value = (y.y - x.y)*(z.x - y.x) - (z.y - y.y)*(y.x - x.x);
    if(value == 0) return 0;
    if(value > 0 ) return 1;
    return -1;
}
double dlugosc(Odcinek odcinek)
{
    return pow(odcinek.koniec.x-odcinek.start.x,2)+pow(odcinek.koniec.y-odcinek.start.y,2);
}
int czy_prostopadle(Odcinek pierwszy,Odcinek drugi)
{
    return pierwszy.A*drugi.A + pierwszy.B*drugi.B == 0;
}
int czy_rownolegle(Odcinek pierwszy,Odcinek drugi)
{
    return pierwszy.A*drugi.B - drugi.A*pierwszy.B == 0;
}
int czy_przecinaja_sie(Odcinek pierwszy,Odcinek drugi)
{
    return (z_ktorej_strony(pierwszy.start,pierwszy.koniec,drugi.start)*z_ktorej_strony(pierwszy.start,pierwszy.koniec,drugi.koniec) == -1
            && z_ktorej_strony(drugi.start,drugi.koniec,pierwszy.start)*z_ktorej_strony(drugi.start,drugi.koniec,pierwszy.koniec) == -1);
}

int main(void)
{
    int test_cases, test_counter = 1;
    Punkt a,b,c,d;
    Odcinek odc,odc2,odc3,odc4;
    char *figura;

    scanf("%d",&test_cases);
    for(test_counter; test_counter<=test_cases; ++test_counter)
    {
        scanf("%d %d",&a.x,&a.y);
        scanf("%d %d",&b.x,&b.y);
        scanf("%d %d",&c.x,&c.y);
        scanf("%d %d",&d.x,&d.y);

        if(z_ktorej_strony(a,b,c) == z_ktorej_strony(a,b,d)) /* jesli c i d leza po jednej stronie AB*/
        {
            Odcinek pierwsza = polacz_punkty(a,d),druga = polacz_punkty(b,c); /* teoretyczne przekatne to AD i BC, jesli sie przecinaja to zamien C i D*/
            if(czy_przecinaja_sie(pierwsza, druga))
            {
                zamien_miejscami(&c,&d);
            }
        }
        else zamien_miejscami(&b,&c); /* inaczej zamien b i c*/

        odc = polacz_punkty(a,b);
        odc2 = polacz_punkty(b,c);
        odc3 = polacz_punkty(c,d);
        odc4 = polacz_punkty(d,a);

        if(dlugosc(odc) == dlugosc(odc3) && dlugosc(odc2) == dlugosc(odc4)) /* pray bokow sa takiej samej dlugosci*/
        {
            if(dlugosc(odc) == dlugosc(odc2) || dlugosc(odc) == dlugosc(odc4)) /* sasiednie boki sa takie same, czyli wszystkie sa takie same*/
            {
                if(czy_prostopadle(odc,odc2)) figura = KWADRAT;
                else figura = ROMB;
            }
            else
            {
                if(czy_prostopadle(odc,odc2) && czy_prostopadle(odc3,odc4)) figura = PROSTOKAT;
                else figura = ROWNOLEGLOBOK;
            }
        }
        else if((czy_rownolegle(odc, odc3) && !czy_rownolegle(odc2, odc4)) || (!czy_rownolegle(odc, odc3) && czy_rownolegle(odc2, odc4)))
        {
            figura = TRAPEZ;
        }
        else figura = INNY;

        printf("Case %d: %s\n",test_counter,figura);
    }
    return 0;
}

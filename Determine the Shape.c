#include<stdio.h>
#include<math.h>

struct Punkt { int x,y; };
struct Odcinek { Punkt start,koniec; };

void zamien_miejscami(struct Punkt &pierwszy,struct Punkt &drugi)
{
  Punkt _temp;
  _temp.x = pierwszy.x;
  _temp.y = pierwszy.y;
  pierwszy.x = drugi.x;
  pierwszy.y = drugi.y;
  drugi.x = _temp.x;
  drugi.y = _temp.y;
}
int z_ktorej_strony(){return 1;}
double dlugosc(struct Odcinek &odcinek) return sqrt(odcinek.x*odcinek.x+odcinek.y*odcinek.y);
int czy_prostopadle(){return 1;}
int czy_rownolegle(){return 1;}
int czy_przecinaja_sie(){return 1;}

/*
sa rownolegle, gdy maja taki sam wspolczynnik kierunkowy: pierwszy
sa prostopadle, gdy

*/

int main(void)
{

  return 0;
}

#include<stdio.h>
#define IMIE "Jan"
#define NAZWISKO "Kowalski"

#define LOOP

int main(void)
{
    printf("Moje imie: %s\n", IMIE);
    printf("Moje nazwisko: %s\n", NAZWISKO);

    #ifdef LOOP
    int j=1,i=1;
    for(i ; i<4 ; ++i)
    {
        j *= i;
    }
    printf("%d",j);
    #endif // LOOP


    return 0;
}

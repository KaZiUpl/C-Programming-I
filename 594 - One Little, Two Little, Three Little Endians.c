#include<stdio.h>

union Liczba
{
    int l_int;
    char l_char[4];
};

int main(void)
{
    union Liczba l_do_zamiany;
    while(scanf("%d",&l_do_zamiany.l_int) == 1)
    {
        printf("%d converts to ",l_do_zamiany.l_int);
        char pomoc = l_do_zamiany.l_char[0],
            pomoc2 = l_do_zamiany.l_char[1];

        l_do_zamiany.l_char[0] = l_do_zamiany.l_char[3];
        l_do_zamiany.l_char[1] = l_do_zamiany.l_char[2];
        l_do_zamiany.l_char[3] = pomoc;
        l_do_zamiany.l_char[2] = pomoc2;

        printf("%d\n",l_do_zamiany.l_int);
    }


    return 0;
}

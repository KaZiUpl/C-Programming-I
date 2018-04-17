#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char napis[60],wyraz[60];
    int znacznik_wyrazu=0,czy_spacja = 0;

    fgets(napis, 60, stdin);
    while(strlen(napis) != 1 && napis[0]!='#')
    {
        int i;
        for(i=0 ; i<strlen(napis) ; ++i)
        {
            if(isalpha(napis[i]) || isspace(napis[i])) printf("%c",napis[i]);
        }

        fgets(napis, 60, stdin);
    }

    return 0;
}

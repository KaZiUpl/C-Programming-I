#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char napis[60],wyraz[60];
    int znacznik_wyrazu=0,czy_myslnik = 0;

    fgets(napis, 60, stdin);
    while(strlen(napis) != 2 || napis[0]!='#')
    {
        int i;
        for(i=0;i<strlen(napis);++i)
        {
            if(isalpha(napis[i])) /** jesli to litera to ja zapisz */
            {
                wyraz[znacznik_wyrazu] = napis[i];
                znacznik_wyrazu++;
            }
            else
            {
                if(napis[i]=='-') /** jesli to myslnik to zapisz wyraz i pobierz nastepna litere */
                {
                    czy_myslnik=1;
                    break;
                }
                else if(isspace(napis[i])) /** jesli to spacja*/
                {
                    int j;
                    for(j=0;j<znacznik_wyrazu;++j) /**wypisz wszystkie litery z wyrazu*/
                    {
                        printf("%c",wyraz[j]);
                    }
                    if(czy_myslnik)
                    {
                        printf("\n");
                        czy_myslnik = 0;
                    }
                    znacznik_wyrazu = 0;
                    printf("%c",napis[i]);
                }
            }

        }
        fgets(napis, 60, stdin);
    }

    return 0;
}

#include<stdio.h>
#include<math.h>
#include<pthread.h>

#define maksymalna pow(10,7)
#define ilosc_watkow 8
int licznik;

/* Blokada gwarantujaca wzajemne wykluczanie */
pthread_mutex_t mutex;

void* czy_pierwsza(void *arg)
{
    int numer_watku = (int) arg;
    int prime_test;
    int i,flaga;
    do
    {
        flaga = 1;
        pthread_mutex_lock(&mutex);
        prime_test = licznik;
        licznik++;
        pthread_mutex_unlock(&mutex);

        for(i=2 ; i*i<=prime_test ; ++i)
        {
            if(prime_test%i == 0 && prime_test != 2)
            {
                flaga = 0;
                break;
            }
        }
        if(flaga == 1) printf("%d {watek: %d}\n ",prime_test,numer_watku);
        /*if(flaga == 1) printf("%d {watek: %d}\n ",prime_test,numer_watku);*/

    }while(prime_test <= maksymalna);


    return NULL;
}

int main(void)
{
    int i;
    pthread_t thread[ilosc_watkow];
    licznik = 2;

    /* Inicjalizacja blokady */
	pthread_mutex_init(&mutex,NULL);

    /* Stworzenie i uruchomienie watkow */
	for(i=0;i<ilosc_watkow;++i){
		if(pthread_create(&thread[i],NULL,czy_pierwsza,(void*)i) != 0){
			printf("pthread_create error\n");
			return 1;
		}
	}

    /* Oczekiwanie na zakonczenie dzialania przez watki */
	for(i=0;i<ilosc_watkow;++i){
		pthread_join(thread[i],NULL);
	}

	/* Usuniecie blokady */
	pthread_mutex_destroy(&mutex);

    return 0;
}

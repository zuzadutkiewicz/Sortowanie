#include <iostream>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <cstdio>
#include <ctime>

// ////////////////////////////////
// tablice z rozna liczba elementow
// ////////////////////////////////

using namespace std;

typedef struct struct_wymiar_tablicy
{
    int size_tab;
    int *tab;
    char nazwa[20];
} struct_wymiar_tablicy;

typedef struct struct_typ_tablicy
{
    void (* funkcja)(int tab[], int size);
    char nazwa[20];
} struct_typ_tablicy;

typedef struct struct_funkcja_sortujaca
{
    void (*funkcja)(int tab[], int size);
    char nazwa[20];
} struct_funkcja_sortujaca;


void wypelnijAksztaltnieTablice(int tab[], int tab_size);
void wypelnijMalejacoTablice(int tab[], int tab_size);
void wypelnijLosowoTablice(int tab[], int tab_size);
void wypelnijRosnocoTablice (int tab[], int tab_size);
void wypelnijStalaTablice (int tab[], int tab_size);
void generuj_dane(int size_wymiar_tablicy,struct_wymiar_tablicy tab_wymiar_tablicy[],
                  int size_typ_tablicy, struct_typ_tablicy tab_typ_tablicy[],
                  int size_funkcja_sortujaca, struct_funkcja_sortujaca tab_funckja_sortujaca[]);
void drukujTablice(int tab[], int tab_size);
void insertionSort(int tab[], int tab_size );
void shellSort(int tab[],int tab_size);
void selectionSort(int tab[], int tab_size);
void heapSort(int tab[], int tab_size);
void makeheap(int tab[], int tab_size);
void sortheap(int tab[], int tab_size);
void quickSortIter(int tab[],int tab_size);
void quickSortRecur(int tab[], int tab_size);
void quicksort (int a[], int tab_size );
void quickSort(int *arr, int elements);
void quickSortIterPrawy(int tab[],int tab_size);
void quickSortRecurPrawy(int tab[], int tab_size);
void quicksortPrawy(int a[], int tab_size );
void quickSortPrawy(int *arr, int elements);
int wylosujPivot();
void quicksort(int arr[], int left, int right);
int compare (const void * a, const void * b);
void quickSortC(int tabp[], int tab_size);

int main ()
{
#define TAB_1_SIZE 10000
#define TAB_2_SIZE 20000
#define TAB_4_SIZE 40000
#define TAB_8_SIZE 80000
#define TAB_16_SIZE 160000
#define TAB_32_SIZE 320000
#define TAB_64_SIZE 640000
#define TAB_128_SIZE 1280000
#define TAB_256_SIZE 2560000
#define TAB_MAX_SIZE 2560000


    int tab_xx[TAB_MAX_SIZE];

    int size_wymiar_tablicy = 9;



    struct_wymiar_tablicy tab_wymiar_tablicy[size_wymiar_tablicy];

// wypelnienie tablicy

    tab_wymiar_tablicy[0].size_tab = TAB_1_SIZE;
    tab_wymiar_tablicy[0].tab = tab_xx;
    strcpy(tab_wymiar_tablicy[0].nazwa, "10_tys");

    tab_wymiar_tablicy[1].size_tab = TAB_2_SIZE;
    tab_wymiar_tablicy[1].tab = tab_xx;
    strcpy(tab_wymiar_tablicy[1].nazwa, "20_tys");

    tab_wymiar_tablicy[2].size_tab = TAB_4_SIZE;
    tab_wymiar_tablicy[2].tab = tab_xx;
    strcpy(tab_wymiar_tablicy[2].nazwa, "40_tys");

    tab_wymiar_tablicy[3].size_tab = TAB_8_SIZE;
    tab_wymiar_tablicy[3].tab = tab_xx;
    strcpy(tab_wymiar_tablicy[3].nazwa, "80_tys");

      tab_wymiar_tablicy[4].size_tab = TAB_16_SIZE;
    tab_wymiar_tablicy[4].tab = tab_xx;
    strcpy(tab_wymiar_tablicy[4].nazwa, "160_tys");

    tab_wymiar_tablicy[5].size_tab = TAB_32_SIZE;
    tab_wymiar_tablicy[5].tab = tab_xx;
    strcpy(tab_wymiar_tablicy[5].nazwa, "320_tys");

    tab_wymiar_tablicy[6].size_tab = TAB_64_SIZE;
    tab_wymiar_tablicy[6].tab = tab_xx;
    strcpy(tab_wymiar_tablicy[6].nazwa, "640_tys");

    tab_wymiar_tablicy[7].size_tab = TAB_128_SIZE;
    tab_wymiar_tablicy[7].tab = tab_xx;
    strcpy(tab_wymiar_tablicy[7].nazwa, "128_tys");

    tab_wymiar_tablicy[8].size_tab = TAB_256_SIZE;
    tab_wymiar_tablicy[8].tab = tab_xx;
    strcpy(tab_wymiar_tablicy[8].nazwa, "256_tys");




// /////////////////////////////////////
// tablica funkcji generujacej dane w tablicy do sortowania
// ////////////////////////////////////

    int size_typ_tablicy = 5;



    struct struct_typ_tablicy tab_typ_tablicy[size_typ_tablicy];

// wypelnienie tablicy

    tab_typ_tablicy[0].funkcja=wypelnijLosowoTablice;
    strcpy(tab_typ_tablicy[0].nazwa,"losowa");

    tab_typ_tablicy[1].funkcja=wypelnijRosnocoTablice;
    strcpy(tab_typ_tablicy[1].nazwa,"rosnaca");

    tab_typ_tablicy[2].funkcja=wypelnijMalejacoTablice;
    strcpy(tab_typ_tablicy[2].nazwa,"malejaca");

    tab_typ_tablicy[3].funkcja=wypelnijStalaTablice;
    strcpy(tab_typ_tablicy[3].nazwa,"stala");

    tab_typ_tablicy[4].funkcja=wypelnijAksztaltnieTablice;
    strcpy(tab_typ_tablicy[4].nazwa,"aksztal");

// ///////////////////////////////////
// tablica funkcji sortujacych
// ///////////////////////////////////

    int size_funkcja_sortujaca = 2;


    struct_funkcja_sortujaca tab_funkcja_sortujaca[size_funkcja_sortujaca];
/*
    tab_funkcja_sortujaca[0].funkcja = insertionSort;
    strcpy(tab_funkcja_sortujaca[0].nazwa, "insertionSort");

    tab_funkcja_sortujaca[1].funkcja = shellSort;
    strcpy(tab_funkcja_sortujaca[1].nazwa, "shellSort");

    tab_funkcja_sortujaca[2].funkcja = selectionSort;
    strcpy(tab_funkcja_sortujaca[2].nazwa, "selectionSort");

    tab_funkcja_sortujaca[3].funkcja = heapSort;
    strcpy(tab_funkcja_sortujaca[3].nazwa, "heapSort");

    tab_funkcja_sortujaca[4].funkcja = quickSortIter;
    strcpy(tab_funkcja_sortujaca[4].nazwa, "quickSortIter");

    tab_funkcja_sortujaca[5].funkcja = quickSortRecur;
    strcpy(tab_funkcja_sortujaca[5].nazwa, "quickSortRecur");

    tab_funkcja_sortujaca[6].funkcja = quickSortIterPrawy;
    strcpy(tab_funkcja_sortujaca[6].nazwa, "quickSortIterPrawy");
*/
    tab_funkcja_sortujaca[1].funkcja = quickSortRecurPrawy;
    strcpy(tab_funkcja_sortujaca[1].nazwa, "quickSortRecurPrawy");

    tab_funkcja_sortujaca[0].funkcja = quickSortC;
    strcpy(tab_funkcja_sortujaca[0].nazwa, "quickSortC");

    srand( time( NULL ) );

    generuj_dane(size_wymiar_tablicy,  tab_wymiar_tablicy,
                 size_typ_tablicy,  tab_typ_tablicy,
                 size_funkcja_sortujaca, tab_funkcja_sortujaca);
    getch();

}

void wypelnijLosowoTablice(int tab[], int tab_size)
{

    for(int i = 0; i < tab_size; i++)
    {
        // tab[i] = rand() % tab_size;
        tab[i]=1;
    }
}

void wypelnijMalejacoTablice(int tab[], int tab_size)
{

    for(int i = 0; i < tab_size; i++)
    {
        tab[i] = tab_size - i;
    }
}

void wypelnijAksztaltnieTablice(int tab[], int tab_size)
{
    int srodek = tab_size / 2 ;
    for(int i = 0; i < tab_size; i++)
    {
        if(i < srodek)
        {
            tab[i] = 2*i + 1;
        }
        else
        {
            tab[i] = 2*(tab_size - i -1);
        }
    }
}

void wypelnijRosnocoTablice (int tab[], int tab_size)
{
    for(int i = 0; i < tab_size; i++)
    {
        tab[i] = i;
    }
}

void wypelnijStalaTablice (int tab[], int tab_size)
{
    for(int i = 0; i < tab_size; i++)
    {
        tab[i] = 1;
    }
}

void generuj_dane(int size_wymiar_tablicy,struct_wymiar_tablicy tab_wymiar_tablicy[],
                  int size_typ_tablicy, struct_typ_tablicy tab_typ_tablicy[],
                  int size_funkcja_sortujaca, struct_funkcja_sortujaca tab_funckja_sortujaca[])
{
    int i=0;
    int j=0;
    int k=0;
    printf("Poczatek generuj_dane()\n");
    char buf[100];
    fstream plik;
    plik.open("plik.csv", ios::out);
    for (i=0; i < size_wymiar_tablicy; i++)
    {
        for (j=0; j < size_typ_tablicy; j++)
        {
            for (k=0; k < size_funkcja_sortujaca; k++)
            {

                // printf("Dane dla wymiar: %s, typ: %s, funkcja: %s\n",
                // tab_wymiar_tablicy[i].nazwa,
                // tab_typ_tablicy[j].nazwa,
                // tab_funckja_sortujaca[k].nazwa);
                tab_typ_tablicy[j].funkcja(tab_wymiar_tablicy[i].tab,tab_wymiar_tablicy[i].size_tab);
                // drukujTablice(tab_wymiar_tablicy[i].tab,tab_wymiar_tablicy[i].size_tab);
                clock_t start=clock();
                tab_funckja_sortujaca[k].funkcja(tab_wymiar_tablicy[i].tab,tab_wymiar_tablicy[i].size_tab);
                // printf("Czas wykonywania: %lu ms\n",((1000*(clock()-start))/CLOCKS_PER_SEC));
                printf("Wynik wymiar: %s, typ: %s, funkcja: %s czas: %lu ms\n",
                       tab_wymiar_tablicy[i].nazwa,
                       tab_typ_tablicy[j].nazwa,
                       tab_funckja_sortujaca[k].nazwa,
                       ((1000*(clock()-start))/CLOCKS_PER_SEC));
                sprintf(buf,"%s;%s;%s;%lu", tab_wymiar_tablicy[i].nazwa,
                        tab_typ_tablicy[j].nazwa,
                        tab_funckja_sortujaca[k].nazwa,
                        ((1000*(clock()-start))/CLOCKS_PER_SEC));
                plik << buf << endl;
                // drukujTablice(tab_wymiar_tablicy[i].tab,tab_wymiar_tablicy[i].size_tab);
            }
        }
    }
    plik.close();
    printf("Koniec generuj_dane()\n");

}

void drukujTablice(int tab[], int tab_size)
{
    for(int i = 0; i < tab_size; i++)
    {
        printf("tab[%d]=%d\n", i, tab[i]);
    }

}


void insertionSort(int tab[], int tab_size )// sortowanie przez wstawianie
{
    int temp, j;

    for( int i = 1; i < tab_size; i++ )
    {
        temp = tab[ i ]; // wez dowolny element i stwórz tablice posortowana

        for( j = i - 1; j >= 0 && tab[ j ] > temp; j-- ) // porownaj element wziety z elementem ktory jest w tablicy
            tab[ j + 1 ] = tab[ j ]; // wstaw element w miejsce ktore pasuje

        tab[ j + 1 ] = temp; //weź kolejny element
    }
}


void shellSort(int tab[],int tab_size) // sortowania przez wstawianie elementów w pewnej odleg³oœci od siebie
{
    int h,i,j;
    float t;
    for(h = 1; h <= tab_size/9; h = h*3+1) // wyznaczenie odleg³oœci od kolejnych elementów sortowanych
        ;
    while(h > 0) // dopóki odstep jest wiekszy od 0 zostan przy sortowaniu
    {
        for(i=h; i<tab_size; i++) // elementy oddalone od siebie o te sama odleglosc, sortuj przez wstawienia
        {
            t = tab[i];
            j = i-h;
            while ((j>=0) && (tab[j]>t))
            {
                tab[j+h] = tab[j];
                j-=h;
            }
            tab[j+h] = t;
        }
        h /= 3; // zmniejszaj odleglosc kolejnych elementow od sibeie sortowanych
    }
}

void selectionSort(int tab[], int tab_size) // sortowanie przez wybieranie
{
    int pos_min,temp;

    for (int i=0; i < tab_size-1; i++) // wybierz element minimalny  z tablicy nieposortowanej
    {
        pos_min = i; // wstaw go na pierwsza pozycje

        for (int j=i+1; j < tab_size; j++) // znajdz element rowny albo wiekszy o 1 i wstaw na kolejna pozycje
        {

            if (tab[j] < tab[pos_min])
                pos_min=j;
        }
        if (pos_min != i)
        {
            temp = tab[i];
            tab[i] = tab[pos_min];
            tab[pos_min] = temp;
        }
    }
}

void heapSort(int tab[], int tab_size) // sortowanie przez kopcowanie
{

   makeheap(tab, tab_size); //swtorz kopiec
   sortheap(tab, tab_size); // rozbierz kopiec

}


void makeheap ( int tab[ ], int tab_size )
//stworz kopiec w ktorym beda zachowane odpowiednie relacje miedzy kolejnymi galeziami kopca,
//najwiekszy element zawsze musi znajdowac siê na szczycie kopca a kolejne elementy
// znajduja sie pod nim polaczone w taki sposob ze najwiekszy zawsze jest wyzej
{
    int i, val, s, f ;
    for ( i = 1 ; i < tab_size ; i++ )
    {
        val = tab[i] ;
        s = i ;
        f = ( s - 1 ) / 2 ;
        while ( s > 0 && tab[f] < val )
        {
            tab[s] = tab[f] ;
            s = f ;
            f = ( s - 1 ) / 2 ;
        }
        tab[s] = val ;
    }
}
void sortheap ( int tab[ ], int tab_size )
// rozbierz kopiec, rozbieranie kopca nastepuje przez wyjecie najwiekszego elementu z gory, ustawieniu go na koncu
//posortowanej tablicy a nastepnie ustawieniu na gorze kopca nowego elementu o najwiekszej wartosci i ponowne wziecie
//go z kopca az do wyczerpania elementow
{
    int i, s, f, ivalue ;
    for ( i = tab_size - 1 ; i > 0 ; i-- )
    {
        ivalue = tab[i] ;
        tab[i] = tab[0] ;
        f = 0 ;

        if ( i == 1 )
            s = -1 ;
        else
            s = 1 ;

        if ( i > 2 && tab[2] > tab[1] )
            s = 2 ;

        while ( s >= 0 && ivalue < tab[s] )
        {
            tab[f] = tab[s] ;
            f = s ;
            s = 2 * f + 1 ;

            if ( s + 1 <= i - 1 && tab[s] < tab[s + 1] )
                s++ ;
            if ( s > i - 1 )
                s = -1 ;
        }
        tab[f] = ivalue ;
    }
}


void quickSortIter(int arr[], int elements)
// sortowanie szybkie
{

#define  MAX_LEVELS  110000

    int  piv, beg[MAX_LEVELS], end[MAX_LEVELS], i=0, L, R, swap ;

    beg[0]=0;
    end[0]=elements;
    while (i>=0)
    {
        L=beg[i];
        R=end[i]-1;
        if (L<R)
        {
            int randx = (rand()%(R-L+1)+L);
            piv=arr[randx]; // losowe wyznaczenie liczby piwota
            while (L<R)
            {
                while (arr[R]>=piv && L<R) R--;
                if (L<R) arr[L++]=arr[R];
                while (arr[L]<=piv && L<R) L++;
                if (L<R) arr[R--]=arr[L];
            }
            arr[L]=piv;
            beg[i+1]=L+1;
            end[i+1]=end[i];
            end[i++]=L;
            if (end[i]-beg[i]>end[i-1]-beg[i-1])
            {
                swap=beg[i];
                beg[i]=beg[i-1];
                beg[i-1]=swap;
                swap=end[i];
                end[i]=end[i-1];
                end[i-1]=swap;
            }
        }
        else
        {
            i--;
        }
    }
}

void quickSortRecur (int tab[], int tab_size)
{
    int i, j, p, t;
    int index = 0;
    if (tab_size < 2) // sprawdzenie czy tablica zawiera wiêcej niz jeden elemnet
        return;
    index = rand()%tab_size; // losowe wybranie elementu piwota
    p = tab[index];
    for (i = 0, j = tab_size - 1;; i++, j--) // w petli przechodzenie przez kolejne elementy tablicy
    {
        while (tab[i] < p)
            i++;
        while (p < tab[j])
            j--;
        if (i >= j)
            break;
        t = tab[i];
        tab[i] = tab[j]; // przypisanie elementu w odpowiednie miejsce do tablicy
        tab[j] = t;
    }
    quickSortRecur(tab, i);
    quickSortRecur(tab + i, tab_size - i); // sortowanie gornej polowy i dolnej polowy
}



void quickSortIterPrawy(int arr[], int elements)
{

#define  MAX_LEVELS  110000

    int  piv, beg[MAX_LEVELS], end[MAX_LEVELS], i=0, L, R, swap ;

    beg[0]=0;
    end[0]=elements;
    while (i>=0)
    {
        L=beg[i];
        R=end[i]-1;
        if (L<R)
        {
            piv=arr[R]; // podziel tablice i zapamietaj punkt podzialu
            while (L<R)
            {
                while (arr[R]>=piv && L<R) R--;
                if (L<R) arr[L++]=arr[R];
                while (arr[L]<=piv && L<R) L++;
                if (L<R) arr[R--]=arr[L];
            }
            arr[L]=piv;
            beg[i+1]=L+1;
            end[i+1]=end[i];
            end[i++]=L;
            if (end[i]-beg[i]>end[i-1]-beg[i-1])
            {
                swap=beg[i];
                beg[i]=beg[i-1];
                beg[i-1]=swap;
                swap=end[i];
                end[i]=end[i-1];
                end[i-1]=swap;
            }
        }
        else
        {
            i--;
        }
    }
}


void quickSortRecurPrawy(int tab[], int tab_size)
{
    quicksort(tab, 0, tab_size - 1);
}

void quicksort(int arr[], int left, int right)
{
    int i = left, j = right;
    int tmp;
    int pivot = arr[left];

    /* partition */
    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

    /* recursion */
    if (left < j)
        quicksort(arr, left, j);

    if (i < right)
        quicksort(arr, i, right);
}

void quickSortC(int tab[], int tab_size) {

    qsort(tab, tab_size, sizeof(int), compare);
}

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

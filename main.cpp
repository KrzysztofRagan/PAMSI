#include <iostream>
#include <ctime>
using namespace std;

#define MAX_RANDOM_VALUE 1000 //ustawiamy maksymalną wartość liczby losowej - domyślnie 100

#include "functions.h" //funkcje pomocnicze takie jak createArray, fillRandomly itd...
#include "quicksort.h" //sortowanie szybkie
#include "mergesort.h" //sortowanie przez scalanie
#include "introspectivesort.h" //sortowanie introspektywne hybrydowe

#define TYP int
#define SIZE 1000000 //wielkość tablicy
#define COUNT 100 //ilość powtórzeń
#define PREC 0  //wartość 0 dla pierwszego przypadku, czyli tablicy całkowicie losowej
                //wartość inna dla PREC procent początkowo uporządkowanych elementów (25,50,75....)
                //dla tworzenia tablicy uporządkowanej w odwrotnej kolejności PREC wynosi 0
                //dla tworzenia tablicy uporządkowanej w normalnej kolejności PREC ma dowolną wartość poza 0

#define fillArray(x,y,z) fillRandomly(x,y,z)        //funkcja wypełniająca tablicę w sposób losowy
                                                    //lub wypełniająca tablicę w sposób losowy z PREC procent uporządkowanych elementów
                                                    //w przypadku generowania tablicy w sposób uporządkowany należy zakomentować tą linię
//#define fillArray(x,y,z) fillRandomlyInOrder(x,y,z)   //w przypadku generowania tablicy w sposób losowy należy zakomentować tą linię
int main()
{
    clock_t start;
    long czas1=0,czas2=0,czas3=0;
    int nieUdane1=0,nieUdane2=0,nieUdane3=0;

    cout<<"Czas wykonywania algorytmow sortowania dla "<<COUNT<<" tablic o wielkosci "<<SIZE<<" elementow:"<<endl;

    srand(static_cast<unsigned int>(time(nullptr)));

    TYP *tablica = createArray<TYP>(SIZE);
    TYP *tablica1 =createArray<TYP>(SIZE);
    TYP *tablica2 =createArray<TYP>(SIZE);
    TYP *tablica3 =createArray<TYP>(SIZE);

    for (int i=0;i<COUNT;++i)
    {
        fillArray(tablica,SIZE,PREC);
        if(SIZE<30)
            displayArray(tablica,SIZE);

        copyArray(tablica,tablica1,SIZE);
        copyArray(tablica,tablica2,SIZE);
        copyArray(tablica,tablica3,SIZE);

        start = clock();
        quickSort<TYP>(tablica1,SIZE);
        czas1+=clock()-start;
        if(!checkArrayOrder(tablica1,SIZE))
        {
            cout<<"Sortowanie szybkie nieudane!"<<endl;
            nieUdane1++;
        }
        start = clock();
        mergeSort<TYP>(tablica2,SIZE);
        czas2+=clock()-start;
        if(!checkArrayOrder(tablica2,SIZE))
        {
            cout<<"Sortowanie przez scalanie nieudane!"<<endl;
            nieUdane2++;
        }

        start = clock();
        introspectiveSort<TYP>(tablica3,SIZE);
        czas3+=clock()-start;
        if(!checkArrayOrder(tablica3,SIZE))
        {
            cout<<"Sortowanie introspektywne nieudane!"<<endl;
            nieUdane3++;
        }
    }

    cout<<"Sortowanie przez scalanie: sredni czas wykonywania: "<<1000.0*czas2/CLOCKS_PER_SEC/COUNT<<"ms,\t";
    if(nieUdane2)
        cout<<"niepoprawnie posortowano: "<<nieUdane2<<"!"<<endl;
    else
        cout<<"wszystkie tablice posortowano poprawnie."<<endl;

    cout<<"Sortowanie szybkie:        sredni czas wykonywania: "<<1000.0*czas1/CLOCKS_PER_SEC/COUNT<<"ms,\t";
    if(nieUdane1)
        cout<<"niepoprawnie posortowano: "<<nieUdane1<<"!"<<endl;
    else
        cout<<"wszystkie tablice posortowano poprawnie."<<endl;


    cout<<"Sortowanie introspektywne: sredni czas wykonywania: "<<1000.0*czas3/CLOCKS_PER_SEC/COUNT<<"ms,\t";
    if(nieUdane3)
        cout<<"niepoprawnie posortowano: "<<nieUdane3<<"!"<<endl;
    else
        cout<<"wszystkie tablice posortowano poprawnie."<<endl;


    return 0;
}

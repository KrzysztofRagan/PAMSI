#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#ifndef MAX_RANDOM_VALUE
    #define MAX_RANDOM_VALUE 100 //You must to redefine this constant if You would like to generate diffriend max random value
#endif
#include <algorithm>

using namespace std;
template <class Item>
Item* createArray(int size)
{
    if(size<1)
        throw "Table size must be greater than 1 element";
    Item *array=new Item[size];
    return array;
}
template <class Item>
void copyArray(Item * array, Item *arrayCopy, int size)
{
    if(size<1)
        throw "Table size must be greater than 1 element";
    copy(array,array+size,arrayCopy);
}
template <class Item>
void fillRandomly(Item * array, int size, double precentage)
{
    if(size<1)
        throw "Table size must be greater than 1 element";
    if(precentage<0 || precentage>100)
        throw "Precentage must be positive and lower than 100";
    int rightOrderCount=static_cast<int>(precentage*size/100);
    for(int i=0;i<size;++i)
        array[i]=rand()%MAX_RANDOM_VALUE;
    sort(array,array+rightOrderCount);

}
template <class Item>
void fillRandomlyInOrder(Item * array, int size, double order=0) // 0 for revers order
{
    if(size<1)
        throw "Table size must be greater than 1 element";
    for(int i=0;i<size;++i)
        array[i]=rand()%MAX_RANDOM_VALUE;
    sort(array,array+size);
    if(static_cast<int>(order)==0)
        reverse(array,array+size);
}

template <class Item>
void displayArray(Item * array, int size)
{
    if(size<1)
        throw "Table size must be greater than 1 element";
    for(int i=0;i<size;++i)
        cout << array[i] << " ";
    cout<<endl;
}
template <class Item>
bool checkArrayOrder(Item * array, int size)
{
    if(size<1)
        throw "Table size must be greater than 1 element";
    for(int i=0;i<size-1;++i)
        if(array[i]>array[i+1])
            return false;
    return true;
}
#endif // FUNCTIONS_H

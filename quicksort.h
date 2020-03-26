#ifndef QUICKSORT_H
#define QUICKSORT_H
//http://www.algorytm.edu.pl/algorytmy-maturalne/quick-sort.html

template <class Item>
void quickSortRange(Item *array, int left, int right)
{
    if(right <= left) return;

    int i = left - 1, j = right + 1,
    pivot = array[(left+right)/2];

    while(1)
    {
        while(pivot>array[++i]);
        while(pivot<array[--j]);
        if( i <= j)
            swap(array[i],array[j]);
        else
            break;
    }
    if(j > left)
    quickSortRange(array, left, j);
    if(i < right)
    quickSortRange(array, i, right);
}
#endif // QUICKSORT_H
template <class Item>
void quickSort(Item *array, int size)
{
    quickSortRange(array,0,size-1);
}

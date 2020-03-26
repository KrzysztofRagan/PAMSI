#ifndef MERGESORT_H
#define MERGESORT_H
//http://www.algorytm.edu.pl/algorytmy-maturalne/sortowanie-przez-scalanie.html

template <class Item>
void merge(Item *tab, int left, int mean, int right, Item *temp)
{
    int i, j;
    for(i = mean + 1; i>left; i--)
        temp[i-1] = tab[i-1];
    for(j = mean; j<right; j++)
        temp[right+mean-j] = tab[j+1];
    for(int k=left;k<=right;k++)
        if(temp[j]<temp[i])
            tab[k] = temp[j--];
        else
            tab[k] = temp[i++];
}

template <class Item>
void mergeSortRange(Item *array,int left, int right, Item *temp)
{
    if(right<=left) return;

    int mean = (right+left)/2;

    mergeSortRange(array, left, mean, temp);
    mergeSortRange(array, mean+1, right, temp);

    merge(array, left, mean, right, temp);
}

template <class Item>
void mergeSort(Item *array,int size)
{
    Item *temp=new Item[size];
    mergeSortRange(array,0,size-1,temp);
    free(temp);
}

#endif // MERGESORT_H

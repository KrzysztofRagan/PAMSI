#ifndef INTROSPECTIVESORT_H
#define INTROSPECTIVESORT_H
#include<cmath>
//https://pl.wikipedia.org/wiki/Sortowanie_introspektywne

template <class Item>
void exchange (Item *array, long i, long j)
{
  Item temp;
  temp=array[i];
  array[i]=array[j];
  array[j]=temp;
}
template <class Item>
void heapify (Item *array, long i, long N)
{
  long j;
  while (i<=N/2)
  {
    j=2*i;
    if (j+1<=N && array[j+1]>array[j])
      j=j+1;
    if (array[i]<array[j])
      exchange(array,i,j);
    else break;
    i=j;
  }
}
template <class Item>
void insertionSort (Item *array, long N)
{
  long i, j;
  Item temp;
  for (i=1; i<N; ++i)
  {
    temp=array[i];
    for (j=i; j>0 && temp<array[j-1]; --j)
      array[j]=array[j-1];
    array[j]=temp;
  }
}

template <class Item>
void heapSort (Item *array, long N)
{
  long i;
  for (i=N/2; i>0; --i)
    heapify(array-1,i,N);
  for (i=N-1; i>0; --i)
  {
    exchange(array,0,i);
    heapify(array-1,1,i);
  }
}
template <class Item>
void medianOfThree (Item *array, long &L, long &R)
{
  if (array[++L-1]>array[--R])
    exchange(array,L-1,R);
  if (array[L-1]>array[R/2])
    exchange(array,L-1,R/2);
  if (array[R/2]>array[R])
    exchange(array,R/2,R);
  exchange(array,R/2,R-1);
}
template <class Item>
long partition (Item *array, long L, long R)
{
  long i, j;
  if (R>=3)
    medianOfThree(array,L,R);
  for (i=L, j=R-2; ; )
  {
    for ( ; array[i]<array[R-1]; ++i);
    for ( ; j>=L && array[j]>array[R-1]; --j);
    if (i<j)
      exchange(array,i++,j--);
    else break;
  }
  exchange(array,i,R-1);
  return i;
}
template <class Item>
void introSort (Item *array, long N, int M)
{
  long i;
  if (M<=0)
  {
    heapSort(array,N);
    return;
  }
  i=partition(array,0,N);
  if (i>9)
    introSort(array,i,M-1);
  if (N-1-i>9)
    introSort(array+i+1,N-1-i,M-1);
}

template <class Item>
void introspectiveSort (Item *array, long N)
{
  introSort(array,N,static_cast<int>(floor(2*log(N)/M_LN2)));
  insertionSort(array,N);
}












#endif // INTROSPECTIVESORT_H

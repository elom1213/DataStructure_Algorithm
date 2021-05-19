#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define SENTINEL 999999

/*
 * CLRS 2.3 30p Designing algorithms
 * MeargSort
 * */

void printall(int array[], int size);

void merge(int array[], int left, int mid, int right)
{
	int Lsize = mid-left+1;
	int Rsize = right-mid;
	int Larray[Lsize+1];
	int Rarray[Rsize+1];
	memcpy(Larray, &array[left], Lsize*sizeof(int));
	memcpy(Rarray, &array[mid+1], Rsize*sizeof(int));
	Larray[Lsize] = SENTINEL;
	Rarray[Rsize] = SENTINEL;

	printall(Larray, Lsize);
	printall(Rarray, Rsize);

	int Lidx = 0;
	int Ridx = 0;

	for(int i=left;i<=right;i++)
	{
		if(Larray[Lidx] < Rarray[Ridx])
			array[i] = Larray[Lidx++];
		else
			array[i] = Rarray[Ridx++];
	}

	printall(array, MAX);
	printf("\n");
}

void mergesort(int array[], int left, int right)
{
	if(left < right)
	{
		int mid = (left + right)/2;
		mergesort(array, left, mid);
		mergesort(array, mid+1, right);
		merge(array, left, mid, right);
	}
}

void printall(int array[], int size)
{
	for(int i=0;i<size;i++)
		printf("%4d",array[i]);
	printf("\n");
}

int main()
{
	int array[MAX] = {6, 95, 22, 54, 6, 3, 65, 47, 1, 9};
	printall(array, MAX);
	mergesort(array, 0, MAX-1);
	printall(array, MAX);
}


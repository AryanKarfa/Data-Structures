#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int portion(int arr[], int l, int h){
	int u, d;
	u = h;
	d = l;
	int p;
	p = l;
	while (d < u){
		while (arr[u] > arr[p] && u > l)
			--u;
		while (arr[d] < arr[p] && d < h)
			++d;
		if (d < u)
			swap(&arr[d], &arr[u]);
	}
	swap(&arr[p], &arr[u]);
	return u;
}

void quicksort(int arr[], int l, int h){
	if (l < h){
		int p;
		p = portion(arr, l , h);
		quicksort(arr, l, p-1);
		quicksort(arr, p+1, h);
	}
}

int main()
{
	int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int a[n];

    for (i = 0; i < n; i++){
    	printf("Enter %d elements : ", i+1);
        scanf("%d", &a[i]);
	}
	
	printf("The Unsorted array is --- :\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    quicksort(a, 0, n-1);

    printf("The Sorted array is --- :\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}

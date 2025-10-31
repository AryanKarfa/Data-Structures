#include <stdio.h>
#include <stdlib.h>


void shellsort(int arr[], int n){
	int gap, i, j, temp;
	for (gap = n/2; gap > 0; gap = gap/2)
	{
		for (i=gap; i<n; i++)
		{
			temp = arr[i];
			for (j=i-gap; j>=0 && arr[j]>temp; j -= gap)
			{
				arr[j+gap] = arr[j];
			}
			arr[j+gap] = temp;
		}
	}
}


int main()
{
	int n;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	
	int i, arr[n];
	
	for (i=0; i<n; i++){
		printf("Enter %d element: ", i+1);
		scanf("%d", &arr[i]);
	}
	
	printf("The unsorted original  array is --- \n");
	for (i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	
	shellsort(arr, n);
	
	printf("\n\n");
	printf("The sorted array is --- \n");
	for (i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	
	return 0;
}

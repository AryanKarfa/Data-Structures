#include <stdio.h>

void countingSort(int a[], int b[], int n) {
    int i, max = a[0];
    int c[100];

    for (i = 1; i < n; i++) {
        if (a[i] > max)
            max = a[i];
    }

    for (i = 0; i <= max; i++) {
        c[i] = 0;
    }

    for (i = 0; i < n; i++) {
        c[a[i]]++;
    }

    for (i = 1; i <= max; i++) {
        c[i] += c[i - 1];
    }

    for (i = n-1; i >= 0; i--) {
        b[c[a[i]]] = a[i];
        --c[a[i]];
    }
}

int main() {
    int n, i;
    int a[100], b[100];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
    	printf("Enter %d element : ", i+1);
        scanf("%d", &a[i]);
    }
    
    printf("The Unsorted array is ---:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    countingSort(a, b, n);

    printf("The Sorted array is ---:\n");
    for (i = 1; i <= n; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");

    return 0;
}


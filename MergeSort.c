#include<stdio.h>
void mergeSort(int a[] , int l , int h);
void merging(int a[] , int l ,int m , int h);

int main()
{
    int n , i;
    printf("Enter no. of elements : ");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements : \n");
    for(i=0;i<n;++i)
        scanf("%d",&a[i]);

    mergeSort(a,0,n-1);
    printf("Sorted array : ");
    for(i=0;i<n;++i)
        printf("%d\t",a[i]);
}

void mergeSort(int a[] , int l , int h)
{
    int m;
    if(h<=l)
        return ;
    
    else
    {
        m = (l+h)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,h);
        merging(a,l,m,h);
    }
}

void merging(int a[] , int l ,int m , int h)
{
    int i,j,k,b[100];
    for(i=l , j= m+1 ,k=l ; i<=m && j<=h;)
    {
        if(a[i]<a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    while(i<=m)
        b[k++] = a[i++];

    while(j<=h)
        b[k++] = a[j++];

    for(k=l ; k<=h ; ++k)
        a[k] = b[k];
}


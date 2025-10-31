#include<stdio.h>

void towerOfHanoi(int n, int SOURCE, int TARGET, int INTERMEDIATE) {
    if (n == 1) {
        printf("\n Move disk 1 from rod %c to rod %c", SOURCE, TARGET);
        return;
    }
    
    towerOfHanoi(n - 1, SOURCE, INTERMEDIATE, TARGET);
    
    printf("\n Move disk %d from rod %c to rod %c", n, SOURCE, TARGET);
    
    towerOfHanoi(n - 1, INTERMEDIATE, TARGET, SOURCE);
}

int main() 
{
   int n,SOURCE, INTERMEDIATE, TARGET;
    
	printf("\nEnter the no. of disks: ");
    scanf("%d",&n);
    printf("\nEnter Source of tower: ");
    scanf("%d",&SOURCE);
    printf("\nEnter Target of tower: ");
    scanf("%d",&TARGET);
    printf("\nEnter Intermediate of tower: ");
    scanf("%d",&INTERMEDIATE);
    
    towerOfHanoi(n, 'A', 'C', 'B'); 
    
    return 0;
}


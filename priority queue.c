#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int a[MAX];
    int rear;
} pq;

void enqueue(pq *ptr, int val) {
    if (ptr->rear == MAX - 1) {
        printf("Queue full!\n");
        return;
    }
    ptr->rear++;
    int i = ptr->rear;
    ptr->a[i] = val;
    while (i > 0 && ptr->a[(i - 1) / 2] > ptr->a[i]) {
        int temp = ptr->a[i];
        ptr->a[i] = ptr->a[(i - 1) / 2];
        ptr->a[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
    printf("%d enqueued\n", val);
}

int dequeue(pq *ptr) {
    if (ptr->rear == -1) {
        printf("Queue is empty!\n");
        return -9999;
    }
    int t = ptr->a[0];
    ptr->a[0] = ptr->a[ptr->rear];
    --ptr->rear;
    int p = 0;
    while (1) {
        int c = 2 * p + 1;
        if (c > ptr->rear)
            break;
        if (c + 1 <= ptr->rear && ptr->a[c + 1] < ptr->a[c])
            c = c + 1;

        if (ptr->a[c] < ptr->a[p]) {
            int temp = ptr->a[p];
            ptr->a[p] = ptr->a[c];
            ptr->a[c] = temp;
            p = c;
        } else {
            break;
        }
    }
    return t;
}

void display(pq *ptr) {
	int i;
    if (ptr->rear == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Priority Queue Elements: ");
    for (i = 0; i <= ptr->rear; i++) {
        printf("%d ", ptr->a[i]);
    }
    printf("\n");
}

int main() {
    pq myPQ;
    myPQ.rear = -1;
    int choice, val;

    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(&myPQ, val);
                break;

            case 2:
                val = dequeue(&myPQ);
                if (val != -9999)
                    printf("Dequeued: %d\n", val);
                break;

            case 3:
                display(&myPQ);
                break;

            case 0:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


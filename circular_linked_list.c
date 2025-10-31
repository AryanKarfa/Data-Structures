#include <stdio.h>
#include <stdlib.h>

typedef struct dll {
    int data;
    struct dll *next, *prev;
} node;

node* createNode(int val) {
    node *tmp = (node*)malloc(sizeof(node));
    tmp->data = val;
    tmp->next = tmp;
    tmp->prev = tmp;
    return tmp;
}

void enqueue(node **pstart, node **ptend, int val) {
    append(pstart, ptend, val);
    printf("%d enqueued\n", val);
}

void dequeue(node **pstart, node **ptend) {
    if (*pstart == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    node *tmp = *pstart;
    if (*pstart == *ptend) {
        *pstart = *ptend = NULL;
    } else {
        *pstart = (*pstart)->next;
        (*pstart)->prev = (*ptend);
        (*ptend)->next = *pstart;
    }
    printf("%d dequeued\n", tmp->data);
    free(tmp);
}

int peek(node *start) {
    if (start == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    return start->data;
}

int isEmpty(node *start) {
    return start == NULL;
}

int main() {
    node *start = NULL, *end = NULL;
    int choice, val;

    do {
        
        printf("1. Enqueue (Queue Insert)\n");
        printf("2. Dequeue (Queue Delete)\n");
        printf("3. Peek (Queue Front)\n");
        printf("4. Check if Empty\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(&start, &end, val);
                break;
            case 2:
                dequeue(&start, &end);
                break;
            case 3:
                val = peek(start);
                if (val != -1) printf("Front of Queue: %d\n", val);
                break;
            case 4:
                if (isEmpty(start))
                    printf("List/Queue is empty.\n");
                else
                    printf("List/Queue is NOT empty.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }while (1);

    return 0;
}


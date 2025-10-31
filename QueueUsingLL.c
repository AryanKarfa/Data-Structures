#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node* front = NULL;
Node* rear = NULL;

Node* createNode(int data) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void enqueue(int data) {
    Node *newnode = createNode(data);
    if (rear == NULL) {
        front = rear = newnode;
        rear->next = front;
        return;
    }
    rear->next = newnode;
    rear = newnode;
    rear->next = front;
}

int dequeue() {
    if (front == NULL) {
        printf("Queue is Empty\n");
        return -1;
    }
    int value;
    if (front == rear) {
        value = front->data;
        free(front);
        front = rear = NULL;
        return value;
    }
    Node *temp = front;
    value = temp->data;
    front = front->next;
    rear->next = front;
    free(temp);
    return value;
}

int peek() {
    if (front == NULL) {
        printf("Queue is Empty\n");
        return -1;
    }
    return front->data;
}

int main() {
    int choice, data, val;
    do {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek Front Element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                val = dequeue();
                break;
            case 3:
                val = peek();
                if (val != -1)
                    printf("Front element is %d\n", val);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, try again\n");
        }
    } while (choice != 4);
    return 0;
}

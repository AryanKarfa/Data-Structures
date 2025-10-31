#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct nbde *next;
} node;

node *head = NULL;

node* create_Node(int value) {
    node *newNode = (node*) malloc (sizeof(node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insert_At_Beginning(node **head, int value) {
    node *newNode = create_Node(value);
    newNode -> next = *head;
    *head = newNode;
    printf("Inserted %d at the beginning.\n", value);
}

void insert_At_End(node **head, int value) {
    node *newNode = create_Node(value);
    if (*head == NULL) {
        *head = newNode;
        printf("Inserted %d at the end.\n", value);
        return;
    }
    node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Inserted %d at the end.\n", value);
}

void insert_At_Position(node **head, int value, int position) {
    if (position == 0) {
        insert_At_Beginning(head, value);
        return;
    }
    node *newNode = create_Node(value);
    node *temp = *head;
    int count = 0;
    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        printf("Position out of range.\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d.\n", value, position);
}

void delete_At_End(node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if ((*head)->next == NULL) {
        printf("Deleted %d from end.\n", (*head)->data);
        free(*head);
        *head = NULL;
        return;
    }
    node *temp = *head, *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    printf("Deleted %d from end.\n", temp->data);
    free(temp);
    prev->next = NULL;
}

void delete_At_Beg(node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    node *temp = *head;
    printf("Deleted %d from beginning.\n", temp->data);
    *head = (*head)->next;
    free(temp);
}

void delete_At_Position(node **head, int position) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (position == 0) {
        delete_At_Beg(head);
        return;
    }
    node *temp = *head;
    int count = 0;
    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range.\n");
        return;
    }
    node *toDelete = temp->next;
    printf("Deleted %d from position %d.\n", toDelete->data, position);
    temp->next = toDelete->next;
    free(toDelete);
}

void display_list(node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
	node *pthead = NULL;
    int choice, value, position;
    node *found;
    do {
        printf("\n--- Please enter your choice --- \n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at End\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at Position\n");
        printf("7. Display List\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insert_At_Beginning(&head, value);
            break;
        case 2:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insert_At_End(&head, value);
            break;
        case 3:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            printf("Enter position: ");
            scanf("%d", &position);
            insert_At_Position(&head, value, position);
            break;
        case 4:
            delete_At_End(&head);
            break;
        case 5:
            delete_At_Beg(&head);
            break;
        case 6:
            printf("Enter position to delete: ");
            scanf("%d", &position);
            delete_At_Position(&head, position);
            break;
        case 7:
            display_list(head);
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (1);
    
    return 0;
}

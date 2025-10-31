#include <stdio.h>
#include <stdlib.h>

typedef struct doubly {
	int data;
	struct doubly *next, *prev;
}node;

node *createNode(int val){
	node *tmp = (node*)malloc(sizeof(node));
	tmp -> data = val;
	tmp -> next = NULL;
	tmp -> prev = NULL;
	return tmp;
}

void add_Begin(node **ptstart, int val){
	node *tmp = createNode(val);
	tmp -> next = *ptstart;
	tmp -> prev = NULL;
	if (*ptstart != NULL){
		(*ptstart) -> prev = tmp;
	}
	*ptstart = tmp;
}

void append(node **ptstart, node **ptend, int val){
	node *tmp = createNode(val);
	tmp -> prev = *ptend;
	tmp -> next = NULL;
	if (*ptend == NULL){
		*ptstart = tmp;
	}
    else{
		(*ptend) -> next = tmp;
	}
    *ptend = tmp;
}

void del_Begin(node **pstart, node **ptend){
    if (*pstart == NULL) 
		return;
    node *tmp = *pstart;
    *pstart = (*pstart) -> next;
    if (*pstart != NULL) 
		(*pstart) -> prev = NULL;
    else 
		*ptend = NULL;
    free(tmp);
}

void del_End(node **pstart, node **ptend) 
{
    if (*ptend == NULL) 
		return;
    node *tmp = *ptend;
    *ptend = (*ptend) -> prev;
    if (*ptend != NULL) 
		(*ptend)->next = NULL;
    else 
		*pstart = NULL;
    free(tmp);
}

void display_Forward(node *start){
    node *p = start;
    printf("Forward: ");
    while (p != NULL) {
        printf("%d  ->>  ", p -> data);
        p = p -> next;
    }
    printf("NULL\n");
}

void display_Backward(node *end){
    node *p = end;
    printf("Backward ");
    while (p != NULL) {
        printf("%d  <<-  ", p -> data);
        p = p -> prev;
    }
    printf("NULL\n");
}



int main() 
{
    node *start = NULL, *end = NULL;
    int choice, val;
    
    do {
        printf("\n--- Doubly Linked List ---\n");
        printf("1. Add at beginning\n");
        printf("2. Append at end\n");
        printf("3. Delete from beginning\n");
        printf("4. Delete from end\n");
        printf("5. Display forward\n");
        printf("6. Display backward\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to add at beginning: ");
                scanf("%d", &val);
                add_Begin(&start, val);
                if (end == NULL) end = start;
                break;
            case 2:
                printf("Enter value to append at end: ");
                scanf("%d", &val);
                append(&start, &end, val);
                break;
            case 3:
                del_Begin(&start, &end);
                printf("Deleted from beginning.\n");
                break;
            case 4:
                del_End(&start, &end);
                printf("Deleted from end.\n");
                break;
            case 5:
                display_Forward(start);
                break;
            case 6:
                display_Backward(end);
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
        
    }while (1);
    
    return 0;
}

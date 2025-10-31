#include <stdio.h>
#include <stdlib.h>

typedef struct bst {
    int data;
    struct bst *left, *right;
} node;

node* create_node(int val) {
    node* new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = val;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void insert(node **ptroot, int val) {
    if (*ptroot == NULL) {
        *ptroot = create_node(val);
    } else if (val < (*ptroot)->data) {
        insert(&((*ptroot)->left), val);
    } else if (val > (*ptroot)->data) {
        insert(&((*ptroot)->right), val);
    } else {
        printf("Duplicate value %d not inserted.\n", val);
    }
}

node* binary_search(node *ptr, int val) {
    if (ptr == NULL || ptr->data == val) {
        return ptr;
    }
    if (val < ptr->data)
        return binary_search(ptr->left, val);
    else
        return binary_search(ptr->right, val);
}

node* find_min(node* ptr) {
    while (ptr && ptr->left != NULL) {
        ptr = ptr->left;
    }
    return ptr;
}

void delnode(node **ptroot, int val) {
    if (*ptroot == NULL) {
        printf("Value %d not found.\n", val);
        return;
    }

    if (val < (*ptroot)->data) {
        delnode(&((*ptroot)->left), val);
    } else if (val > (*ptroot)->data) {
        delnode(&((*ptroot)->right), val);
    } else {
        node *tmp = *ptroot;
        if ((*ptroot)->left == NULL) {
            *ptroot = (*ptroot)->right;
            free(tmp);
        } else if ((*ptroot)->right == NULL) {
            *ptroot = (*ptroot)->left;
            free(tmp);
        } else {
            node* min_right = find_min((*ptroot)->right);
            (*ptroot)->data = min_right->data;
            delnode(&((*ptroot)->right), min_right->data);
        }
        printf("Deleted %d successfully.\n", val);
    }
}

void inorder(node *ptr) {
    if (ptr != NULL) {
        inorder(ptr->left);
        printf("%d ", ptr->data);
        inorder(ptr->right);
    }
}

int main() {
    node *root = NULL;
    int choice, val;
    node *found;

    while (1) {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display (Inorder Traversal)\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insert(&root, val);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                delnode(&root, val);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &val);
                found = binary_search(root, val);
                if (found != NULL)
                    printf("Element %d found in the tree.\n", val);
                else
                    printf("Element %d not found.\n", val);
                break;

            case 4:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}


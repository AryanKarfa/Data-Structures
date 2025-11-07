#include <stdio.h>
#include <stdlib.h>

#define MAX 200

typedef struct {
	int arr[MAX];
	int rear, front;
}fifoq;

void init (fifoq *ptq){
	ptq->rear = ptq->front = -1;
}

int isFull(fifoq *ptq){
	return ((ptq->rear + 1) % MAX == ptq->front);
}

int isEmpty(fifoq *ptq){
	return (ptq->rear == -1 && ptq->front == -1);
}

int peek(fifoq *ptq){
	if(isEmpty(ptq)){
		printf("Queue is full!\n");
		return -999;
	}
	return ptq->arr[ptq->front];
}

void enqueue(fifoq *ptq, int item) {
    if (isFull(ptq)) {
        printf("Queue is full. Cannot enqueue %d\n", item);
        return;
    }
    if (ptq->front == -1){
        ptq->front = ptq->rear = 0;
    }
    else{
        ptq->rear = (ptq->rear + 1) % MAX;
	}
    ptq->arr[ptq->rear] = item;
}

int dequeue(fifoq *ptq) {
    if (isEmpty(ptq)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -999;
    }
    int tmp = ptq->arr[ptq->front];
    if (ptq->front == ptq->rear){
        ptq->front = ptq->rear = -1;
    }
    else{
    	ptq->front = (ptq->front + 1) % MAX;
	}
    return tmp;
}

void bfs(int n, int adj[MAX][MAX], int start) {
    int t[MAX] = {0}, i;
    fifoq q;
    init(&q);
    t[start] = 1;
    enqueue(&q, start);
    printf("\nBFS traversal starting from node %d:\n", start);
    while (!isEmpty(&q)) {
        int node = dequeue(&q);
        printf("%d ", node);
        for (i = 0; i < n; i++) {
            if (adj[node][i] == 1 && !t[i]) {
                t[i] = 1;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

int main() {
    int n, i, j;
    int adj[MAX][MAX];
    int start;

    printf("Enter the number of nodes in the graph: ", MAX);
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    printf("\nEnter the adjacency matrix (%d x %d):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
        	printf("Enter the %d%d elememt: ", i, j);
            scanf("%d", &adj[i][j]);
        }
    }

    printf("\nEnter the starting node (0 to %d): ", n - 1);
    scanf("%d", &start);

    if (start < 0 || start >= n) {
        printf("Invalid start node.\n");
        return 1;
    }

    bfs(n, adj, start);

    return 0;
}

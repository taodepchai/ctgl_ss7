#include <stdio.h>
#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue *queue) {
    queue->front = 0;
    queue->rear = -1;
}

int isEmpty(Queue *queue) {
    return queue->front > queue->rear;
}

int isFull(Queue *queue) {
    return queue->rear == MAX_SIZE - 1;
}

void enqueue(Queue *queue, int value) {
    if (!isFull(queue)) {
        queue->data[++queue->rear] = value;
    } else {
        printf("hang doi day\n");
    }
}

void printQueue(Queue *queue) {
    if (!isEmpty(queue)) {
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->data[i]);
        }
        printf("\n");
    } else {
        printf("hang doi rong\n");
    }
}

int main() {
    Queue queue;
    initQueue(&queue);

    int n, value;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(&queue, value);
    }

    printQueue(&queue);

    return 0;
}

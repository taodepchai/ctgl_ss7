#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 5
#define MAX_TASK_NAME_LENGTH 100

typedef struct {
    int priority;
    char taskName[MAX_TASK_NAME_LENGTH];
} QueueElement;

typedef struct {
    QueueElement elements[MAX_SIZE];
    int size;
} PriorityQueue;

void initQueue(PriorityQueue *queue) {
    queue->size = 0;
}

int isEmpty(PriorityQueue *queue) {
    return queue->size == 0;
}

void enqueue(PriorityQueue *queue, int priority, const char *taskName) {
    if (queue->size == MAX_SIZE) {
        printf("Hang doi day\n");
        return;
    }

    QueueElement newElement;
    newElement.priority = priority;
    strncpy(newElement.taskName, taskName, MAX_TASK_NAME_LENGTH);

    int i = queue->size - 1;
    while (i >= 0 && queue->elements[i].priority < priority) {
        queue->elements[i + 1] = queue->elements[i];
        i--;
    }
    queue->elements[i + 1] = newElement;
    queue->size++;

    printf("Them phan tu (%d, %s): Hang doi khong rong", priority, taskName);
}

char* dequeue(PriorityQueue *queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong\n");
        return NULL;
    }

    char* highestPriorityTask = queue->elements[0].taskName;

    for (int i = 1; i < queue->size; i++) {
        queue->elements[i - 1] = queue->elements[i];
    }
    queue->size--;

    return highestPriorityTask;
}

int main() {
    PriorityQueue queue;
    initQueue(&queue);

    int n, priority;
    char data[MAX_TASK_NAME_LENGTH];
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &priority);
        fgets(data,sizeof(data),stdin);
        enqueue(&queue, priority, data);
    }


    printf("Phan tu uu tien cao nhat: %s (uu tien %d)\n", queue.elements[0].taskName, queue.elements[0].priority);
    printf("Lay ra phan tu:%s\n", dequeue(&queue));

    printf("Phan tu uu tien cao nhat: %s (uu tien %d)\n", queue.elements[0].taskName, queue.elements[0].priority);
    printf("Lay ra phan tu: %s\n", dequeue(&queue));

}

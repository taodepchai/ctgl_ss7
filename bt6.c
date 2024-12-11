#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Deque;

void initDeque(Deque *deque) {
    deque->front = -1;
    deque->rear = -1;
}

int isEmpty(Deque *deque) {
    return deque->front == -1;
}

int isFull(Deque *deque) {
    return (deque->rear + 1) % MAX_SIZE == deque->front;
}

void addFront(Deque *deque, int data) {
    if (isFull(deque)) {
        printf("Hang doi da day\n");
        return;
    }
    
    if (isEmpty(deque)) {
        deque->front = deque->rear = 0;
    } else {
        deque->front = (deque->front - 1 + MAX_SIZE) % MAX_SIZE;
    }
    deque->data[deque->front] = data;
    
    printf("Them phan tu vao dau: %d\n", data);
}

void addRear(Deque *deque, int data) {
    if (isFull(deque)) {
        printf("Hang doi da day\n");
        return;
    }
    
    if (isEmpty(deque)) {
        deque->front = deque->rear = 0;
    } else {
        deque->rear = (deque->rear + 1) % MAX_SIZE;
    }
    deque->data[deque->rear] = data;
    
    printf("Them phan tu vao cuoi: %d\n", data);
}

int removeFront(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Hang doi rong\n");
        return -1;
    }

    int data = deque->data[deque->front];
    if (deque->front == deque->rear) {
        deque->front = deque->rear = -1;
    } else {
        deque->front = (deque->front + 1) % MAX_SIZE;
    }

    return data;
}

int removeRear(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Hang doi rong\n");
        return -1;
    }

    int data = deque->data[deque->rear];
    if (deque->front == deque->rear) {
        deque->front = deque->rear = -1;
    } else {
        deque->rear = (deque->rear - 1 + MAX_SIZE) % MAX_SIZE;
    }

    return data;
}

void printDeque(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Hang doi rong\n");
        return;
    }

    printf("Hang doi hien tai: [");
    int i = deque->front;
    while (i != deque->rear) {
        printf("%d, ", deque->data[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d]\n", deque->data[deque->rear]);
}

int main() {
    Deque deque;
    initDeque(&deque);

    int n, value;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        printf("Hang doi khong du kha nang chua %d phan tu.\n", MAX_SIZE);
        return 0;
    }

    printf("Nhap %d phan tu:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu %d: ", i + 1);
        scanf("%d", &value);
        if (i % 2 == 0) {
            addFront(&deque, value);
        } else {
            addRear(&deque, value); 
        }
    }

    printDeque(&deque);

    printf("Lay ra phan tu tu dau: %d\n", removeFront(&deque));
    printDeque(&deque);

    printf("Lay ra phan tu tu cuoi: %d\n", removeRear(&deque));
    printDeque(&deque);

    return 0;
}

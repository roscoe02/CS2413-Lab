// 232. Implement Queue using Stacks
#define MAX_SIZE 100

typedef struct {
    int inputStack[MAX_SIZE];
    int outputStack[MAX_SIZE];
    int inputTop;
    int outputTop;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->inputTop = -1;
    queue->outputTop = -1;
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    if (obj->inputTop < MAX_SIZE - 1) {
        obj->inputStack[++obj->inputTop] = x;
    }
}

void transferIfNeeded(MyQueue* obj) {
    if (obj->outputTop == -1) {
        while (obj->inputTop != -1) {
            obj->outputStack[++obj->outputTop] = obj->inputStack[obj->inputTop--];
        }
    }
}

int myQueuePop(MyQueue* obj) {
    transferIfNeeded(obj);
    if (obj->outputTop != -1) {
        return obj->outputStack[obj->outputTop--];
    }
    return -1;
}

int myQueuePeek(MyQueue* obj) {
    transferIfNeeded(obj);
    if (obj->outputTop != -1) {
        return obj->outputStack[obj->outputTop];
    }
    return -1;
}

bool myQueueEmpty(MyQueue* obj) {
    return (obj->inputTop == -1 && obj->outputTop == -1);
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}



// 225. Implement Stack using Queues
#define STACK_SIZE 100

typedef struct {
    int elements[STACK_SIZE];
    int topIndex;
} MyStack;

MyStack* myStackCreate() {
    MyStack *newStack = (MyStack*)malloc(sizeof(MyStack));
    newStack->topIndex = -1;
    return newStack;
}

void myStackPush(MyStack* obj, int x) {
    if (obj->topIndex >= STACK_SIZE - 1) {
        return;
    }
    obj->elements[++obj->topIndex] = x;
}

int myStackPop(MyStack* obj) {
    if (obj->topIndex == -1) {
        return -1;
    }
    return obj->elements[obj->topIndex--];
}

int myStackTop(MyStack* obj) {
    if (obj->topIndex == -1) {
        return -1;
    }
    return obj->elements[obj->topIndex];
}

bool myStackEmpty(MyStack* obj) {
    return obj->topIndex == -1;
}

void myStackFree(MyStack* obj) {
    free(obj);
}

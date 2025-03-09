struct Node {
    int val;
    struct Node* next;
};
struct Node* createNode(int val) {
    struct Node* new = malloc(sizeof(struct Node));
    new->val = val;
    return new;
}
typedef struct {
    struct Node* front;
    struct Node* rear;
} Queue;
Queue* createQueue() {
    Queue* q = malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}
Queue* push(Queue* q, int val) {
    if(q==NULL)
    return NULL;
    struct Node* new = createNode(val);
    if(q->rear==NULL){
        q->front=new;
        q->rear=new;
    }
    else{
    q->rear->next = new;
    q->rear=new;
    }
    return q;
}
int pop(Queue* q) {
    if (q == NULL || q->front == NULL) {
        printf("Queue Empty!\n");
        return 0;
    }
    struct Node* p = q->front;
    int popval = p->val;
    q->front=q->front->next;
    free(p);
    return q->rear->val;
    if(q->front==NULL)
    q->rear==NULL;
    free(p);
    return popval;
}
int top(Queue* q) {
    if (q == NULL || q->front == NULL) {
        printf("Queue Empty!\n");
        return 0;
    }
    return q->rear->val;
}
typedef struct {
    Queue* q;
} MyStack;
MyStack* myStackCreate() {
    MyStack* stack = malloc(sizeof(MyStack));
    stack->q = createQueue();
    return stack;
}

void myStackPush(MyStack* obj, int x) { push(obj->q, x); }
int myStackPop(MyStack* obj) { return pop(obj->q); }

int myStackTop(MyStack* obj) { return top(obj->q); }
bool myStackEmpty(MyStack* obj) {
   return obj->q->front==NULL;
}
void myStackFree(MyStack* obj) { free(obj); }

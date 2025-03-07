struct Node{
    int val;
    struct Node* next;
};
typedef struct{
    struct Node* top;
}Stack;
struct Node* createNode(int val){
    struct Node* new = malloc(sizeof(struct Node));
    new->val=val;
    new->next==NULL;
    return new;
}
Stack* createStack(){
    Stack* stack = malloc(sizeof(Stack));
    stack->top=NULL;
    return stack;
}
typedef struct {
    Stack *stack1;
    Stack *stack2;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue *q = malloc(sizeof(MyQueue));
    q->stack1 = createStack();
    q->stack2 = createStack();
    return q;
}
void push(Stack *stack,int val){
    struct Node* new = createNode(val);
    new->next = stack->top;
    stack->top = new;
}
int empty(Stack *stack){
    return stack->top==NULL;
}
int pop(Stack *stack){
    if(stack==NULL){
        printf("Stack empty\n");
        return 0;
    }
    struct Node *pop = stack->top;
    int popval = pop->val;
    stack->top = stack->top->next;
    free(pop);
    return popval;
}
int peek(Stack *stack){
        if(stack==NULL){
        printf("Stack empty\n");
        return 0;
    }
    return stack->top->val;
}
void myQueuePush(MyQueue* obj, int x) {
    push(obj->stack1,x);
}

int myQueuePop(MyQueue* obj) {
    if(empty(obj->stack2))
    {
        while(!empty(obj->stack1)){
            int data = pop(obj->stack1);
            push(obj->stack2,data);        
            }
    }
    if(empty(obj->stack2)){
        printf("Queue Empty!\n");
        return 0;
    }
    return pop(obj->stack2);
}

int myQueuePeek(MyQueue* obj) {
        if(empty(obj->stack2))
    {
        while(!empty(obj->stack1)){
            int data = pop(obj->stack1);
            push(obj->stack2,data);        
            }
    }
    if(empty(obj->stack2)){
        printf("Queue Empty!\n");
        return 0;
    }
    return peek(obj->stack2);
}

bool myQueueEmpty(MyQueue* obj) {
    if(obj->stack1 == NULL && obj->stack2 == NULL)
    return true;
    return false;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

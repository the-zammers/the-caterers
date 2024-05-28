#ifndef STACK_H
#define STACK_H

struct StackNode { //This is the struct for each node of the stack, which references the next node in the stack
    double data;
    struct StackNode* next;
};

struct Stack { //This is to refer to each individual stack as a whole, all it needs is the top node.
    struct StackNode* top;
};

struct Stack* createStack();
<<<<<<< HEAD
int push(Stack* stack, double ingredient);
double pop(struct Stack* stack); //Returns the data of node that is popped.
double peek(struct Stack* stack);
void randomizeStack(struct Stack* stack);
int isEmpty(struct Stack* stack);
=======
int push(struct Stack* stack, double ingredient);
void pushNSpacesDown(struct Stack* stack, double ingredient, int n); //Unique to the chef language I believe
double pop(struct Stack* stack); //Returns the data of node that is popped.
double peek(struct Stack* stack);
int countElements(struct Stack* stack);
void randomizeStack(struct Stack* stack);
>>>>>>> bd91c605d76ef075881078ca1aa3e16a814ae2bc

#endif // STACK_H

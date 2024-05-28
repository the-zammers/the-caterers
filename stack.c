#include <stdio.h>  // FILE, fgets, fopen, printf
#include <stdlib.h> // strol
#include <string.h> // strncmp, strlen, strchr, strncpy, strcspn
#include <time.h> // for the randomization function
#include "stack.h" // Implementation of stacks into C

struct Stack* createStack() {
  struct Stack* stack = malloc(sizeof(struct Stack));
  stack->top = NULL;
  return stack;
}

void deleteStack(struct Stack* stack) {
  while (countElements(stack) != 0) {
    pop(stack);
  }
  free(stack);
}

struct StackNode* createStackNode(struct Ingredient ingredient) {
  struct StackNode* newNode = malloc(sizeof(struct StackNode));
  newNode->data = ingredient;
  newNode->next = NULL;
  return newNode;
}

void push(struct Stack* stack, struct Ingredient ingredient) {
  struct StackNode* newNode = createStackNode(ingredient);
  newNode->next = stack->top;
  stack->top = newNode;
}

void pushNSpacesDown(struct Stack* stack, struct Ingredient ingredient, int n) {
  if (n == 0) {
    push(stack, ingredient);
    return;
  }

  struct StackNode* current = stack->top;
  for (int i = 0; i < n - 1; i++) {
    if (current == NULL) {
      fprintf(stderr, "Stack does not have %d elements\n", n);
      exit(EXIT_FAILURE);
    }
    current = current->next;
  }

  struct StackNode* newNode = createStackNode(ingredient);
  newNode->next = current->next;
  current->next = newNode;
}

struct Ingredient pop(struct Stack* stack) {
  struct StackNode* temp = stack->top;
  struct Ingredient poppedData = temp->data;
  stack->top = temp->next;
  free(temp);
  return poppedData;
}

struct Ingredient peek(struct Stack* stack) {
  return stack->top->data;
}

int countElements(struct Stack* stack) {
  int count = 0;
  struct StackNode* current = stack->top;
  return count;
}

double* getStackElements(struct Stack* stack, int count) { // This function makes the stack into an array which can be rearranged (more easily)
  double* elements = (double*)malloc(countElements(stack));

  struct StackNode* current = stack->top;
  for (int i = 0; i < count; i++) {
    elements[i] = current->data;
    current = current->next;
  }
  return elements;
}

void randomizeStack(struct Stack* stack) {
  int count = countElements(stack);
  if (count < 2) {
    return; // No need to randomize if there are less than 2 (because then there's only one)
  }

  double* elements = getStackElements(stack, count);

  // Shuffle the elements array
  srand(time(NULL));
  for (int i = count - 1; i > 0; i--) {
    int j = rand() % (i + 1);
    double temp = elements[i];
    elements[i] = elements[j];
    elements[j] = temp;
  }

  // Rebuild the stack with the shuffled elements
  deleteStack(stack);
  stack = createStack();
  for (int i = 0; i < count; i++) {
    push(stack, elements[i]);
  }

  free(elements);
}

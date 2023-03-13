//needs a bit more work on making the output look better

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

// stack data structure
typedef struct {
  char items[MAX_STACK_SIZE];
  int top;
} stack;

// function prototypes
void initialize(stack *s);
int is_empty(stack *s);
int is_full(stack *s);
void push(stack *s, char c);
char pop(stack *s);
int check_validity(char *str);

int main() {
  char str[MAX_STACK_SIZE];

  printf("Enter a string of parenthesis: ");
  scanf("%s", str);

  if (check_validity(str)) {
    printf("Valid\n");
  } else {
    printf("Invalid\n");
  }

  return 0;
}

// initialize stack
void initialize(stack *s) {
  s->top = -1;
}

// check if stack is empty
int is_empty(stack *s) {
  return s->top == -1;
}

// check if stack is full
int is_full(stack *s) {
  return s->top == MAX_STACK_SIZE - 1;
}

// push an item onto the stack
void push(stack *s, char c) {
  if (is_full(s)) {
    printf("Error: stack is full\n");
    return;
  }
  s->items[++s->top] = c;
}

// pop an item from the stack
char pop(stack *s) {
  if (is_empty(s)) {
    printf("Error: stack is empty\n");
    return '\0';
  }
  return s->items[s->top--];
}

// check if the string of parenthesis is valid
int check_validity(char *str) {
  stack s;
  initialize(&s);

  for (int i = 0; i < strlen(str); i++) {
    char c = str[i];
    if (c == '(' || c == '[' || c == '{') {
      push(&s, c);
    } else if (c == ')') {
      if (pop(&s) != '(') {
        return 0;
      }
    } else if (c == ']') {
      if (pop(&s) != '[') {
        return 0;
      }
    } else if (c == '}') {
      if (pop(&s) != '{') {
        return 0;
      }
    }
  }

  return is_empty(&s);
}

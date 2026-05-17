#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

int contents[STACK_SIZE];
int top = 0;

void makeEmpty(void);
bool isEmpty(void);
bool isFull(void);
void push(int i);
int pop(void);
void stackOverflow(void);
void stackUnderflow(void);

int main(void) {
    char ch;
    int op1, op2, sol;

    for (;;) {
        makeEmpty();
        printf("Enter an RPN expression: ");

        do {
            scanf(" %c", &ch);
            switch (ch) {
                case '1': case '2': case '3': case '4': case '5':
                case '6': case '7': case '8': case '9': sol = ch - '0'; push(sol); break;
                case '+': op1 = pop(); op2 = pop(); sol = op2 + op1; push(sol); break;
                case '-': op1 = pop(); op2 = pop(); sol = op2 - op1; push(sol); break;
                case '*': op1 = pop(); op2 = pop(); sol = op2 * op1; push(sol); break;
                case '/': op1 = pop(); op2 = pop(); sol = op2 / op1; push(sol); break;
                case '=': printf("Value of expression: %d\n", contents[top - 1]); break;
                default: exit(EXIT_SUCCESS);
            }
        } while (ch != '=');
    }
}

void makeEmpty(void) {
    top = 0;
}

bool isEmpty(void) {
    return top == 0;
}

bool isFull(void) {
    return top == STACK_SIZE;
}

void push(int i) {
    if (isFull()) {
        stackOverflow();
    }
    else
        contents[top++] = i;
}

int pop(void) {
    if (isEmpty())
        stackUnderflow();
    else
        return contents[--top];
}

void stackOverflow(void) {
    printf("Expression is too complex.");
    exit(EXIT_SUCCESS);
}

void stackUnderflow(void) {
    printf("Not enough operands in expression.");
    exit(EXIT_SUCCESS);
}
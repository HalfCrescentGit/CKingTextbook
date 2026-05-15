#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

char contents[STACK_SIZE];
int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char i);
char pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main(void) {
    char ch;
    bool correct;

    make_empty();
    printf("Enter parentheses and/or braces: ");

    do {
        ch = getchar();
        if (ch == '(' || ch == '{')
            push(ch);
        else if (ch == ')') {
            if (pop() == '(')
                correct = true;
            else
                correct = false;
        }
        else if (ch == '}') {
            if (pop() == '{')
                correct = true;
            else
                correct = false;
        }
    } while (ch != '\n');

    if (correct)
        printf("Parentheses/braces are nested properly.");
    else
        printf("Parentheses/braces are not nested properly.");
}

void make_empty(void) {
    top = 0;
}

bool is_empty(void) {
    return top == 0;
}

bool is_full(void) {
    return top == STACK_SIZE;
}

void push(char i) {
    if (is_full()) {
        stack_overflow();
    }
    else
        contents[top++] = i;
}

char pop(void) {
    if (is_empty())
        stack_underflow();
    else
        return contents[--top];
}

void stack_overflow(void) {
    printf("Stack overflow");
    exit(EXIT_SUCCESS);
}

void stack_underflow() {
    printf("Parentheses/braces are not nested properly.");
    exit(EXIT_SUCCESS);
}
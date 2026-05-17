#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

char contents[STACK_SIZE];
int top = 0;

void makeEmpty(void);
bool isEmpty(void);
bool isFull(void);
void push(char i);
char pop(void);
void stackOverflow(void);
void stackUnderflow(void);

int main(void) {
    char ch;
    bool correct;

    makeEmpty();
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

void makeEmpty(void) {
    top = 0;
}

bool isEmpty(void) {
    return top == 0;
}

bool isFull(void) {
    return top == STACK_SIZE;
}

void push(char i) {
    if (isFull()) {
        stackOverflow();
    }
    else
        contents[top++] = i;
}

char pop(void) {
    if (isEmpty())
        stackUnderflow();
    else
        return contents[--top];
}

void stackOverflow(void) {
    printf("Stack overflow");
    exit(EXIT_SUCCESS);
}

void stackUnderflow(void) {
    printf("Parentheses/braces are not nested properly.");
    exit(EXIT_SUCCESS);
}
//
// Created by lenovo on 2024/1/1.
//

#include <stdlib.h>
#include <stdio.h>

typedef int ElementType;
typedef struct
{
    ElementType *array; //存放栈数据
    int top;	 		//栈顶
    int capacity;  		//容量
} SeqStack;

SeqStack* createStack(int capacity);
int push(SeqStack *S, ElementType x);
int pop(SeqStack *S);
ElementType top(SeqStack *S);
int evaluation(SeqStack *S, char str[]);

//给定一个后缀表达式，计算该表达式的值。为了简化问题，给定的后缀表达式中，所有的数均为个位数，所有运算均为整数运算，运算有+ - * /。
int main() {
    char c;
    int i = 0;
    char str[100];
    SeqStack* S = createStack(100);

    while ((c = getchar()) != '\n') {
        str[i++] = c;
    }
    str[i] = '\0';

    printf("%d\n", evaluation(S, str));

    free(S);
    return 0;
}

int evaluation(SeqStack *S, char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            int num1 = top(S);
            pop(S);
            int num2 = top(S);
            pop(S);
            int num = 0;
            if (str[i] == '+') num = num2 + num1;
            if (str[i] == '-') num = num2 - num1;
            if (str[i] == '*') num = num2 * num1;
            if (str[i] == '/') num = num2 / num1;
            push(S, num);
        } else if ('0' <= str[i] && str[i] <= '9') {
            push(S, str[i] - '0');
        }
    }
    return top(S);
}

SeqStack* createStack(int capacity) {
    SeqStack* stk = (SeqStack*) malloc(sizeof (SeqStack));
    stk->capacity = capacity;
    stk->top =  -1;
    stk->array = (ElementType*) malloc(capacity * sizeof (ElementType));
    return stk;
}

int push(SeqStack *S, ElementType x) {
    if (S->top + 1 < S->capacity) {
        S->array[++S->top] = x;
        return 1;
    }
    return 0;
}

int pop(SeqStack *S) {
    if (S->top != -1) {
        S->top--;
        return 1;
    }
    return 0;
}

ElementType top(SeqStack *S) {
    return S->array[S->top];
}

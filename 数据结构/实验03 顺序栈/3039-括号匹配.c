//
// Created by lenovo on 2024/1/1.
//

#include <stdlib.h>
#include <stdio.h>

typedef char ElementType;
typedef struct
{
    ElementType *array; //存放栈数据
    int top;	 		//栈顶
    int capacity;  		//容量
} SeqStack;

SeqStack* createStack(int capacity);
int empty(SeqStack *S);
int push(SeqStack *S, ElementType x);
int pop(SeqStack *S);
ElementType top(SeqStack *S);
int match(SeqStack *S, char str[]);

//假设一个算术表达式中可以包含三种括号：圆括号"(" 和")"，方括号"["和"]"和花括号"{"和"}"，
//且这三种括号可按任意的次序嵌套使用，如：[{}[]][]()。
//给定一个括号序列，请判定该括号序列是否合法。
int main()
{
    char str[1000];
    SeqStack* S =  createStack(1000);

    scanf("%s", str);

    if (match(S, str) == 1) {
        printf("yes\n");
    } else printf("no\n");

    free(S);
    return 0;
}

int match(SeqStack *S, char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] =='{') {
            push(S, str[i]);
        } else {
            if (empty(S)) return 0;
            if (str[i] == ')' && top(S) != '(') return 0;
            if (str[i] == ']' && top(S) != '[') return 0;
            if (str[i] == '}' && top(S) != '{') return 0;
            pop(S);
        }
    }
    return empty(S);
}

SeqStack* createStack(int capacity) {
    SeqStack* stk = (SeqStack*) malloc(sizeof (SeqStack));
    stk->capacity = capacity;
    stk->top =  -1;
    stk->array = (ElementType*) malloc(capacity * sizeof (ElementType));
    return stk;
}

int empty(SeqStack *S) {
    return S->top == -1;
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
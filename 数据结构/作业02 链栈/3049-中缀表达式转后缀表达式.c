//
// Created by lenovo on 2024/1/3.
//

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct Node
{
    ElementType data;
    struct Node *next;
} Node, *LinkStack;

LinkStack createStack();
int push(LinkStack S, ElementType x);
int empty(LinkStack S);
int pop(LinkStack S);
ElementType getTop(LinkStack S);
void destroyStack(LinkStack S);
int isOp(char c);
char *change(LinkStack S, char str[]);

int main() {
    LinkStack S = createStack();
    char str[100];

    scanf("%s", str);

    char *res;
    res = change(S, str);

    for (int i = 0; res[i] != '\0'; i++) {
        if (res[i + 1] == '\0') printf("%c", res[i]);
        else printf("%c ", res[i]);
    }
    printf("\n");

    free(res);
    destroyStack(S);
    return 0;
}

int isOp(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '(') {
        return 3;
    } else if (c == ')') {
        return 4;
    } else return 0;
}

char *change(LinkStack S, char str[]) {
    int j = 0;
    char *res;
    res = (char *) malloc(100);
    for (int i = 0; str[i] != '\0'; i++) {
        if (isOp(str[i])) {
            if (empty(S)) {
                push(S, str[i]);
                continue;
            }
            if (isOp(str[i]) > isOp(getTop(S))) {
                if (isOp(str[i]) != 4) {
                    push(S, str[i]);
                } else {
                    while (isOp(getTop(S)) != 3) {
                        res[j++] = getTop(S);
                        pop(S);
                    }
                    pop(S);
                }
            } else {
                if (isOp(getTop(S)) == 3) {
                    push(S,str[i]);
                } else {
                    while (!empty(S) && (isOp(str[i]) <= isOp(getTop(S))) && (isOp(getTop(S)) != 3)) {
                        res[j++] = getTop(S);
                        pop(S);
                    }
                    push(S, str[i]);
                }
            }
        } else if ('0' <= str[i] && str[i] <= '9') {
            res[j++] = str[i];
        }
    }
    while (!empty(S)) {
        res[j++] = getTop(S);
        pop(S);
    }
    res[j] = '\0';
    return res;
}

LinkStack createStack() {
    LinkStack S = (Node*) malloc(sizeof (Node));
    S->next = NULL;
    return S;
}

int push(LinkStack S, ElementType x) {
    Node *node = (Node*) malloc(sizeof (Node));
    if (!node) return 0;
    node->data = x;
    node->next = S->next;
    S->next = node;
    return 1;
}

int empty(LinkStack S) {
    return S->next == NULL;
}

int pop(LinkStack S) {
    if (empty(S))return 0;
    Node *node = S->next;
    S->next = node->next;
    free(node);
    return 1;
}

ElementType getTop(LinkStack S) {
    return S->next->data;
}

void destroyStack(LinkStack S) {
    Node *p = S, *q = S->next;
    free(S);
    while (q) {
        p = q;
        q = q->next;
        free(p);
    }
}
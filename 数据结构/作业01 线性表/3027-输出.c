//
// Created by lenovo on 2023/12/31.
//

#include <stdio.h>

typedef struct Node
{
    int  coef;	//系数(coefficient)
    int  exp;	//指数(exponent)
    struct Node *next;
} PolyNode, *PolyList;

void printList(PolyList L);

int main()
{
    /*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。
    */
    return 0;
}
/*你的提交的代码将被添加在此处，请完成题目所要求的函数的定义*/

void printList(PolyList L) {
    PolyNode* node = L->next;
    if (node != NULL) {
        if (node->exp == 0) {
            printf("%d", node->coef);
        } else if (node->exp == 1) {
            if (node->coef == -1) {
                printf("-x");
            } else if (node->exp == 1) {
                printf("x");
            } else {
                printf("%dx", node->coef);
            }
        } else {
            if (node->coef == -1) {
                printf("-x^%d", node->exp);
            } else if (node->coef == 1) {
                printf("x^%d", node->exp);
            } else {
                printf("%dx^%d", node->coef,node->exp);
            }
        }
        node = node->next;
    } else {
        printf("0");
    }
    while (node) {
        if (node->coef > 0) {
            if (node->exp == 0) {
                printf("+%d", node->coef);
            } else if (node->exp == 1) {
                if (node->coef == 1) {
                    printf("+x");
                } else {
                    printf("+%dx", node->coef);
                }
            } else {
                if (node->coef == 1) {
                    printf("+x^%d", node->exp);
                } else {
                    printf("+%dx^%d", node->coef,node->exp);
                }
            }
        } else {
            if (node->exp == 0) {
                printf("%d", node->coef);
            } else if (node->exp == 1) {
                if (node->coef == -1) {
                    printf("-x");
                } else {
                    printf("%dx", node->coef);
                }
            } else {
                if (node->coef == -1) {
                    printf("-x^%d", node->exp);
                } else {
                    printf("%dx^%d", node->coef,node->exp);
                }
            }
        }
        node = node->next;
    }
    printf("\n");
}
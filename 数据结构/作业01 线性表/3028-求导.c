//
// Created by lenovo on 2023/12/31.
//

#include <stdlib.h>

typedef struct Node
{
    int  coef;	//系数(coefficient)
    int  exp;	//指数(exponent)
    struct Node *next;
} PolyNode, *PolyList;

void derivative(PolyList L);

int main()
{
    /*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。
    */
    return 0;
}
/*你的提交的代码将被添加在此处，请完成题目所要求的函数的定义*/

void derivative(PolyList L) {
    PolyNode *node = L;
    PolyNode *p = NULL;
    PolyNode *n = NULL;
    while (node->next) {
        p = node;
        node = node->next;
        if (node->exp == 0) {
            n = node;
            break;
        }
        node->coef = node->coef * node->exp;
        node->exp = node->exp - 1;
    }
    if (n) {
        p->next = NULL;
        free(n);
    }
}

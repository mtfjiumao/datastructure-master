//
// Created by lenovo on 2023/12/30.
//

typedef int ElementType;
typedef struct{
    ElementType *array; //存放数据的指针
    int length;	 		//已有数据个数
    int capacity;  		//容量
}SeqList;

void mergeList(SeqList *LA, SeqList *LB, SeqList *LC);

int main()
{
    /*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。
    */
    return 0;
}
/*你的提交的代码将被添加在此处，请完成题目所要求的函数的定义*/

void mergeList(SeqList *LA, SeqList *LB, SeqList *LC) {
    int i = 0, j = 0, k = 0;
    while (i < LA->length && j < LB->length) {
        if (LA->array[i] < LB->array[j]) {
            LC->array[k++] = LA->array[i++];
        } else {
            LC->array[k++] = LB->array[j++];
        }
    }
    if (i == LA->length) {
        while (j < LB->length) {
            LC->array[k++] = LB->array[j++];
        }
    } else {
        while (i < LA->length) {
            LC->array[k++] = LA->array[i++];
        }
    }
    LC->length = LA->length + LB->length;
}
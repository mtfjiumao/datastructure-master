//
// Created by lenovo on 2024/1/3.
//

typedef int ElementType;
typedef struct{
    ElementType *array;
    int front;      //队首位置
    int rear;       //尾指下一个位置
    int length;     //长度
    int capacity;   //总容量
}SeqQueue;

void clearQueue(SeqQueue *Q);

int main()
{
    /*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。
    */
    return 0;
}
/*你的提交的代码将被添加在此处，请完成题目所要求的函数的定义*/

void clearQueue(SeqQueue *Q) {
    while (Q->front != Q->rear) {
        Q->front = (Q->front + 1) % Q->capacity;
        --Q->length;
    }
}
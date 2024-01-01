//
// Created by lenovo on 2024/1/1.
//

typedef int ElementType;
typedef struct
{
    ElementType *array; //存放栈数据
    int top;	 		//栈顶
    int capacity;  		//容量
} SeqStack;

void clearStack(SeqStack *S);

int main()
{
    /*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。
    */
    return 0;
}

void clearStack(SeqStack *S) {
    S->top = -1;
}
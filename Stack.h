
#pragma once
#define MAX 100
#define DEFAULT_SZ 3

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>


//
//静态栈
//typedef int DataType;
//#define MAX 10
//typedef struct Stack
//{
//	DataType *data[MAX];
//	int top;//栈顶
//};

//typedef struct pos
//{
//	int _row;
//	int _col;
//}pos;

//typedef pos DataType;
typedef int DataType;

typedef struct Stack
{
	DataType*data;//栈的数组
	int top;//栈顶
	int capacity;//容量

}Stack;

void InitStack(Stack *ps);//初始化栈
void DistoryStack(Stack *ps);//销毁栈

void StackPush(Stack*ps,DataType d);//入栈
void StackPop(Stack *ps);//出栈

DataType StackTop(Stack *ps);//查找栈顶的元素
int StackEmpty(Stack*ps);//栈是否为空
int StackSize(Stack *ps);//栈的大小
void PrintStack(Stack *ps);//打印栈

void test();

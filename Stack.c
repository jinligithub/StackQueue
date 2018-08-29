
#include"Stack.h"
void InitStack(Stack *ps)//初始化栈
{
	assert(ps != NULL);
	ps->top = 0;//栈顶
	ps->data = (DataType*)malloc(sizeof(DataType)*DEFAULT_SZ);
	ps->capacity = DEFAULT_SZ;
}
void DistoryStack(Stack *ps)//销毁栈,栈不能为空
{
	assert(ps != NULL);
	if (ps->data != NULL)
	{
		free(ps->data);
		ps->data = NULL;
		ps->top = ps->capacity = 0;
	}
	printf("栈销毁成功\n");
}
void StackPush(Stack*ps, DataType d)//入栈
{
	assert(ps != NULL);
	if (ps->top == ps->capacity)
	{
		ps->data = (DataType*)realloc(ps->data, sizeof(DataType)*(ps->capacity * 2));
		//判断增容成功的第一种写法
		assert(ps->data);
		//第二中写法
		/*if (ps == ps->capacity)
		{
		perror("use realloc");
		exit(EXIT_FAILURE);
		}*/
		ps->capacity *= 2;
	}
	//放数据的第一种写法
	ps->data[ps->top] = d;
	ps->top++;
}
void StackPop(Stack *ps)//出栈
{

	assert(ps);//保证栈里面有数据
	if (ps->top == 0)
	{
		return;
	}
	ps->top--;
}
DataType StackTop(Stack *ps)//
{
	assert(ps);
	assert(&ps->top > 0);
	return ps->data[ps->top-1];
}
int StackEmpty(Stack*ps)//栈是否为空
{
	assert(ps != NULL);
	return ps->top == 0 ? 0 : 1;//比较运算，空为0，非空为1。若果栈顶ps->top==0说明栈为空
}
int StackSize(Stack *ps)//栈的大小
{
	assert(ps != NULL);
	//第一种方法
	/*int count = 0;
	Stack *cur = ps;
	while (cur->top)
	{
		count++;
		cur--;
		
	}
	return count;*/
	//第二种
	return ps->top;
}
void PrintStack(Stack *ps)//打印栈
{
	assert(ps!=NULL);
	Stack *cur = ps;
	while (cur->top)
	{
		printf("%d ", cur->top);
		cur->top--;
	}
	printf("\n");
}
//#if 0
void test()
{
	Stack s;
	int pos = 0;
	InitStack(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);

	pos = StackTop(&s);
	if (pos == 0)
	{
		printf("为空\n");
	}
	else
	{
		printf("不为空,%d \n", pos);
	}
	PrintStack(&s);
	//StackPop(&s);

	//PrintStack(&s);



	/*pos=SatckEmpty(&s);
	if (pos = 0)
	{
	printf("为空\n");
	}
	else
	{
	printf("不为空\n");
	}*/
	//pos = StackSize(&s);
	//if (pos = 0)
	//{
	//	printf("为空\n");
	//}
	//else
	//{
	//	printf("%d \n",pos);
	//}
	//PrintStack(&s);

	DistoryStack(&s);
}
//#endif


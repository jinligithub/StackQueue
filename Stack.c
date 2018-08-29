
#include"Stack.h"
void InitStack(Stack *ps)//��ʼ��ջ
{
	assert(ps != NULL);
	ps->top = 0;//ջ��
	ps->data = (DataType*)malloc(sizeof(DataType)*DEFAULT_SZ);
	ps->capacity = DEFAULT_SZ;
}
void DistoryStack(Stack *ps)//����ջ,ջ����Ϊ��
{
	assert(ps != NULL);
	if (ps->data != NULL)
	{
		free(ps->data);
		ps->data = NULL;
		ps->top = ps->capacity = 0;
	}
	printf("ջ���ٳɹ�\n");
}
void StackPush(Stack*ps, DataType d)//��ջ
{
	assert(ps != NULL);
	if (ps->top == ps->capacity)
	{
		ps->data = (DataType*)realloc(ps->data, sizeof(DataType)*(ps->capacity * 2));
		//�ж����ݳɹ��ĵ�һ��д��
		assert(ps->data);
		//�ڶ���д��
		/*if (ps == ps->capacity)
		{
		perror("use realloc");
		exit(EXIT_FAILURE);
		}*/
		ps->capacity *= 2;
	}
	//�����ݵĵ�һ��д��
	ps->data[ps->top] = d;
	ps->top++;
}
void StackPop(Stack *ps)//��ջ
{

	assert(ps);//��֤ջ����������
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
int StackEmpty(Stack*ps)//ջ�Ƿ�Ϊ��
{
	assert(ps != NULL);
	return ps->top == 0 ? 0 : 1;//�Ƚ����㣬��Ϊ0���ǿ�Ϊ1������ջ��ps->top==0˵��ջΪ��
}
int StackSize(Stack *ps)//ջ�Ĵ�С
{
	assert(ps != NULL);
	//��һ�ַ���
	/*int count = 0;
	Stack *cur = ps;
	while (cur->top)
	{
		count++;
		cur--;
		
	}
	return count;*/
	//�ڶ���
	return ps->top;
}
void PrintStack(Stack *ps)//��ӡջ
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
		printf("Ϊ��\n");
	}
	else
	{
		printf("��Ϊ��,%d \n", pos);
	}
	PrintStack(&s);
	//StackPop(&s);

	//PrintStack(&s);



	/*pos=SatckEmpty(&s);
	if (pos = 0)
	{
	printf("Ϊ��\n");
	}
	else
	{
	printf("��Ϊ��\n");
	}*/
	//pos = StackSize(&s);
	//if (pos = 0)
	//{
	//	printf("Ϊ��\n");
	//}
	//else
	//{
	//	printf("%d \n",pos);
	//}
	//PrintStack(&s);

	DistoryStack(&s);
}
//#endif


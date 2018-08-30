#include"BinaryTree.h"
#include"Stack.h"
#include"Queue.h"
BTNode* BuyBTNode(BTDataType x)//����һ���������ڵ�
{
	BTNode* Node = (BTNode *)malloc(sizeof(BTNode));//����һ���ڵ��С�Ŀռ��Node
	Node->left = NULL;
	Node->right = NULL;
	Node->data = x;//��data ��ֵ
	return Node;
}
BTNode* BinaryTreeCreate(BTDataType* a, int n, int *pi)//������������a�����ַ����飬n�����ַ����ȣ�pi��������ƶ���ָ��
{
	if (a[*pi] != '#')//#����NULL��ֻҪ��Ϊ�գ�������ƶ����ݹ鷽��
	{
		BTNode* root = BuyBTNode(a[*pi]);
		++(*pi);
		root->left = BinaryTreeCreate(a, n, pi);
		++(*pi);
		root->right = BinaryTreeCreate(a, n, pi);
		return root;
	}
	else
	{
		return NULL;
	}
}

void BinaryTreeDestory(BTNode** root)//���ٶ��������ݹ�
{
	if (root == NULL||*root==NULL)//root==NULL˵��root��û������Ϊ�գ�*root==NULL˵��һ��ָ��*root�Ҳ�������ָ��
		return;
	if ((*root)->left != NULL)
		BinaryTreeDestory(&(*root)->left);
	if ((*root)->right != NULL)
		BinaryTreeDestory(&(*root)->right);
	free(root);
	root = NULL;//��ֹ����Ұָ��
	printf("���������ٳɹ�\n");

}
int BinaryTreeSize(BTNode* root)//����ڵ����
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;//�������֣�������������������
}
int BinaryTreeLeafSize(BTNode* root)//����Ҷ�ӽڵ㣬Ҷ�ӽڵ�����������������Ϊ�ա�
{
	if (root == NULL)
		return 0;
	if (root->left->data == '#'&&root->right->data == '#')//��root->left->data���ַ��Ƚ�
		return 1;
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
int BinaryTreeLevelKSize(BTNode* root, int k)//�����K��Ľڵ�������ݹ�ֽ�ΪK-1�� ������
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
void BinaryTreePrevOrder(BTNode* root)//ǰ�����,������������������
{
	if (root == NULL)
		return;
	printf("%c ", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}
void BinaryTreeInOrder(BTNode* root)//���������������������������
{
	if (root == NULL)
		return;
	BinaryTreeInOrder(root->left);
	printf("%c ", root->data);
	BinaryTreeInOrder(root->right);
}
void BinaryTreePostOrder(BTNode* root)//���������������������������
{
	if (root == NULL)
		return;
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c ", root->data);
}


BTNode* BinaryTreeFind(BTNode*root, BTDataType x)//����һ���ڵ�
{
	BTNode* ret = NULL;
	if (root == NULL||(root->data == x))//��root->data��x�Ƚ�
		return root;
	ret = BinaryTreeFind(root->left, x);
	if (ret->data == x)
		return ret;
	ret = BinaryTreeFind(root->right, x);
	if (ret->data == x)
		return ret;
	return NULL;
}
void BinaryTreeLevelOrder(BTNode* root)//������� A  BC  DCE
{
	Queue q;
	QueueInit(&q);//��ʼ�����У�����Ϊ��
	if (root)//��������Ϊ��
		QueuePush(&q, root);//�Ѹ��ڵ�ŵ�������ȥ
	while (QueueEmpty(&q) != 0)
	{
		QUDataType front = QueueFront(&q);//�����ͷ����
		printf("%c ", front->data);
		QueuePop(&q);//��ͷ��ջ
		if (front->left)//���ʸ��ڵ��������
		{
			QueuePush(&q, front->left);
		}
		if (front->right)//���ʸ��ڵ��������
		{
			QueuePush(&q, front->right);
		}
	}
	printf("\n");
}
int BinaryTreeComplete(BTNode* root)//�ж��ǲ�����ȫ���������Ƿ���0�����Ƿ���-1
//��ȫ�������ַ������ֶ������ŵģ����ȫΪ�ա�������ֿպ���ֳ����ַ���˵��������ȫ������
{
	Queue q;
	QueueInit(&q);
	if (root != NULL)
		QueuePush(&q, root);
	while (QueueEmpty(&q) != 0)//�Ȱ����нڵ���ջ
	{
		QUDataType front = QueueFront(&q);
		QueuePop(&q);
		if (front)
		{
			QueuePush(&q, front->left);
			QueuePush(&q, front->right);
		}
		else
		{
			break;
		}
	}
	while (QueueEmpty(&q) != 0)
		//��ȫ�������ַ������ֶ������ŵģ����ȫΪ�ա�������ֿպ���ֳ����ַ���˵��������ȫ������
	{
		BTNode* front = QueueFront(&q);
		if (front)
		{
			QueueDestory(&q);
			return -1;
		}
		else
		{
			QueuePop(&q);
		}
	}
	return 0;
}

void BinaryTreePrevOrderNoR(BTNode* root)//ǰ�����
{
	Stack s;
	BTNode* cur = root;
	BTNode* top = NULL;
	InitStack(&s);
	while (cur || StackEmpty(&s) != 0)
	{
		while (cur)
		{
			printf("%c ", cur->data);
			StackPush(&s, cur);
			cur = cur->left;
		}
		top = StackTop(&s);
		StackPop(&s);
		cur = top->right;
	}
	printf("\n");
}
void BinaryTreeInOrderNoR(BTNode* root)//���������������������������
{
	Stack s;
	BTNode* cur = root;
	BTNode* top = NULL;
	InitStack(&s);
	while (cur || StackEmpty(&s) != 0)
	{
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->left;
		}
		top = StackTop(&s);
		printf("%c ", top->data);
		StackPop(&s);
		cur = top->right;
	}
	printf("\n");
}
void BinaryTreePostOrderNoR(BTNode* root)//���������������������������
{
	Stack s;
	BTNode*cur = root;
	BTNode*top = NULL;
	BTNode*prev = NULL;
	InitStack(&s);
	while (cur || StackEmpty(&s) != 0)
	{
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->left;
		}
		top = StackTop(&s);
		if (top->right==NULL|| top->right == prev)//��Ϊ�գ�����һ���ڵ�Ϊ�������ĸ�
		{
			printf("%c ", top->data);
			prev = top;
			StackPop(&s);
		}
		else
		{
			cur = top->right;
		}
	}
	printf("\n");
}
void TestBianryTree()
{
	char arr[] = { 'A', 'B', 'D', '#', '#', 'X','#','#', 'C', 'E', '#', '#', 'F', '#', '#' };
	int i = 0;
	int pos = 0;
	BTNode* tree = BinaryTreeCreate(arr, sizeof(arr) / sizeof(BTDataType), &i);
	BinaryTreePrevOrder(tree);
	printf("\n");
	BinaryTreeInOrder(tree);
	printf("\n");
	BinaryTreePostOrder(tree);
	printf("\n");
	BinaryTreeLevelOrder(tree);
	printf("\n");

	pos=BinaryTreeComplete(tree);
	printf("%d \n",pos);
	BinaryTreePrevOrderNoR(tree);
	BinaryTreeInOrderNoR(tree);
	BinaryTreePostOrderNoR(tree);

}
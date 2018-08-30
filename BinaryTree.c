#include"BinaryTree.h"
#include"Stack.h"
#include"Queue.h"
BTNode* BuyBTNode(BTDataType x)//创建一个二叉树节点
{
	BTNode* Node = (BTNode *)malloc(sizeof(BTNode));//开辟一个节点大小的空间给Node
	Node->left = NULL;
	Node->right = NULL;
	Node->data = x;//给data 赋值
	return Node;
}
BTNode* BinaryTreeCreate(BTDataType* a, int n, int *pi)//创建二叉树，a代表字符数组，n代表字符长度，pi代表向后移动的指针
{
	if (a[*pi] != '#')//#代表NULL，只要不为空，就向后移动。递归方法
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

void BinaryTreeDestory(BTNode** root)//销毁二叉树，递归
{
	if (root == NULL||*root==NULL)//root==NULL说明root里没有数据为空，*root==NULL说明一级指针*root找不到二级指针
		return;
	if ((*root)->left != NULL)
		BinaryTreeDestory(&(*root)->left);
	if ((*root)->right != NULL)
		BinaryTreeDestory(&(*root)->right);
	free(root);
	root = NULL;//防止生成野指针
	printf("二叉树销毁成功\n");

}
int BinaryTreeSize(BTNode* root)//计算节点个数
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;//分三部分，根，左子树，右子树
}
int BinaryTreeLeafSize(BTNode* root)//计算叶子节点，叶子节点左子树和右子树都为空。
{
	if (root == NULL)
		return 0;
	if (root->left->data == '#'&&root->right->data == '#')//用root->left->data和字符比较
		return 1;
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
int BinaryTreeLevelKSize(BTNode* root, int k)//计算第K层的节点个数，递归分解为K-1层 的问题
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
void BinaryTreePrevOrder(BTNode* root)//前序遍历,根，左子树，右子树
{
	if (root == NULL)
		return;
	printf("%c ", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}
void BinaryTreeInOrder(BTNode* root)//中序遍历。左子树，根，右子树
{
	if (root == NULL)
		return;
	BinaryTreeInOrder(root->left);
	printf("%c ", root->data);
	BinaryTreeInOrder(root->right);
}
void BinaryTreePostOrder(BTNode* root)//后序遍历。左子树，右子树，根
{
	if (root == NULL)
		return;
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c ", root->data);
}


BTNode* BinaryTreeFind(BTNode*root, BTDataType x)//查找一个节点
{
	BTNode* ret = NULL;
	if (root == NULL||(root->data == x))//用root->data和x比较
		return root;
	ret = BinaryTreeFind(root->left, x);
	if (ret->data == x)
		return ret;
	ret = BinaryTreeFind(root->right, x);
	if (ret->data == x)
		return ret;
	return NULL;
}
void BinaryTreeLevelOrder(BTNode* root)//层序遍历 A  BC  DCE
{
	Queue q;
	QueueInit(&q);//初始化队列，队列为空
	if (root)//二叉树不为空
		QueuePush(&q, root);//把根节点放到队列中去
	while (QueueEmpty(&q) != 0)
	{
		QUDataType front = QueueFront(&q);//保存对头数据
		printf("%c ", front->data);
		QueuePop(&q);//队头出栈
		if (front->left)//访问根节点的左子树
		{
			QueuePush(&q, front->left);
		}
		if (front->right)//访问根节点的右子树
		{
			QueuePush(&q, front->right);
		}
	}
	printf("\n");
}
int BinaryTreeComplete(BTNode* root)//判断是不是完全二叉树。是返回0，不是返回-1
//完全二叉树字符，数字都是连着的，最后全为空。如果出现空后边又出现字符，说明不是完全二叉树
{
	Queue q;
	QueueInit(&q);
	if (root != NULL)
		QueuePush(&q, root);
	while (QueueEmpty(&q) != 0)//先把所有节点入栈
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
		//完全二叉树字符，数字都是连着的，最后全为空。如果出现空后边又出现字符，说明不是完全二叉树
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

void BinaryTreePrevOrderNoR(BTNode* root)//前序遍历
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
void BinaryTreeInOrderNoR(BTNode* root)//中序遍历。左子树，根，右子树
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
void BinaryTreePostOrderNoR(BTNode* root)//后序遍历。左子树，右子树，根
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
		if (top->right==NULL|| top->right == prev)//右为空，或上一个节点为右子树的根
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
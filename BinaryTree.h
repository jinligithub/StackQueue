#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>
typedef char BTDataType;
typedef struct BTNode
{
	BTDataType data;
	struct BTNode* left;
	struct BTNode* right;
}BTNode;
BTNode* BuyBTNode(BTDataType x);//创建一个二叉树节点
BTNode* BinaryTreeCreate(BTDataType* a, int n, int *pi);//创建二叉树
void BinaryTreeDestory(BTNode** root);//销毁二叉树
int BinaryTreeSize(BTNode* root);//计算节点个数
int BinaryTreeLeafSize(BTNode* root);//计算叶子节点
int BinaryTreeLevelKSize(BTNode* root, int k);//计算第K层的节点个数
BTNode* BinaryTreeFind(BTNode*root, BTDataType x);//查找一个节点


// 遍历  递归&非递归
void BinaryTreePrevOrder(BTNode* root);//前序遍历
void BinaryTreeInOrder(BTNode* root);//中序遍历。左子树，根，右子树
void BinaryTreePostOrder(BTNode* root);//后序遍历。左子树，右子树，根

//&非递归
void BinaryTreePrevOrderNoR(BTNode* root);//前序遍历
void BinaryTreeInOrderNoR(BTNode* root);//中序遍历。左子树，根，右子树
void BinaryTreePostOrderNoR(BTNode* root);//后序遍历。左子树，右子树，根


void BinaryTreeLevelOrder(BTNode* root);//层序遍历 A  BC  DCE
int BinaryTreeComplete(BTNode* root);//判断是不是完全二叉树


void TestBianryTree();






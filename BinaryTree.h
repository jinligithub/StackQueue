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
BTNode* BuyBTNode(BTDataType x);//����һ���������ڵ�
BTNode* BinaryTreeCreate(BTDataType* a, int n, int *pi);//����������
void BinaryTreeDestory(BTNode** root);//���ٶ�����
int BinaryTreeSize(BTNode* root);//����ڵ����
int BinaryTreeLeafSize(BTNode* root);//����Ҷ�ӽڵ�
int BinaryTreeLevelKSize(BTNode* root, int k);//�����K��Ľڵ����
BTNode* BinaryTreeFind(BTNode*root, BTDataType x);//����һ���ڵ�


// ����  �ݹ�&�ǵݹ�
void BinaryTreePrevOrder(BTNode* root);//ǰ�����
void BinaryTreeInOrder(BTNode* root);//���������������������������
void BinaryTreePostOrder(BTNode* root);//���������������������������

//&�ǵݹ�
void BinaryTreePrevOrderNoR(BTNode* root);//ǰ�����
void BinaryTreeInOrderNoR(BTNode* root);//���������������������������
void BinaryTreePostOrderNoR(BTNode* root);//���������������������������


void BinaryTreeLevelOrder(BTNode* root);//������� A  BC  DCE
int BinaryTreeComplete(BTNode* root);//�ж��ǲ�����ȫ������


void TestBianryTree();






#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30
//���ڵ�Ķ���
typedef struct _ArcNode
{
	int tailVex, headVex;   //��ͷ����β�±�����
	struct _ArcNode* tLink;//ͬ��β����һ�����ڵ��ָ�� 
	struct _ArcNode* hLink;//ͬ��ͷ����һ�����ڵ��ָ��
}ArcNode;
//����ڵ�Ķ���
typedef struct _VexNode
{
	char name[50];        //����ı�־��Ϣ
	ArcNode* firstIn;     //ָ���һ���Ըö���Ϊ��ͷ�Ļ�
	ArcNode* firstOut;    //ָ���һ���Ըö���Ϊ��β�Ļ�
	int in_degree;        //���
	int out_degree;       //����

}VexNode;
//ʮ������Ķ���
typedef struct
{
	VexNode nodes[N]; //��������
	int vexNum, arcNum;   //������������
}orthoList;
<<<<<<< HEAD
int ReadFile(orthoList& e);
int toplogical_sort_forward(orthoList e, int* sorted, int* sorted_size);
void toplogical_sort_backward(orthoList e, int* sorted, int* sorted_size);
void writeFile(orthoList e);
int find(orthoList e, char* name);
void creatFile();
void add_edge(orthoList& e);
void deleteEdge(orthoList &e,int tailVex, int headVex,int VVV);
void addVertex(orthoList &e);
void deleteVertex(orthoList &e);
void menu();
=======
int ReadFile(orthoList& e,char* FILEname);
int toplogical_sort_forward(orthoList e, int* sorted, int* sorted_size);
void toplogical_sort_backward(orthoList e, int* sorted, int* sorted_size);
void writeFile(orthoList e, char* FILEname);
int find(orthoList e, char* name);
void creatFile();
void add_edge(orthoList& e, char* FILEname);
void deleteEdge(orthoList &e, char* FILEname, int tailVex, int headVex,int VVV);
void addVertex(orthoList &e, char* FILEname);
void deleteVertex(orthoList &e, char* FILEname);
>>>>>>> dc1b5ca53f8ceef120c86c6f3b22249f59be0fc2

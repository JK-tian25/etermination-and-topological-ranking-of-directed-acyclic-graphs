#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30
//弧节点的定义
typedef struct _ArcNode
{
	int tailVex, headVex;   //弧头，弧尾下标的序号
	struct _ArcNode* tLink;//同弧尾的下一个弧节点的指针 
	struct _ArcNode* hLink;//同弧头的下一个弧节点的指针
}ArcNode;
//顶点节点的定义
typedef struct _VexNode
{
	char name[50];        //顶点的标志信息
	ArcNode* firstIn;     //指向第一个以该顶点为弧头的弧
	ArcNode* firstOut;    //指向第一个以该顶点为弧尾的弧
	int in_degree;        //入度
	int out_degree;       //出度

}VexNode;
//十字链表的定义
typedef struct
{
	VexNode nodes[N]; //顶点数组
	int vexNum, arcNum;   //顶点数，弧数
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

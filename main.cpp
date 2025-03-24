//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define N 30
#include"graph.h"
////弧节点的定义
//typedef struct _ArcNode
//{
//	int tailVex,headVex;   //弧头，弧尾下标的序号
//	struct _ArcNode* tLink;//同弧尾的下一个弧节点的指针 
//	struct _ArcNode* hLink;//同弧头的下一个弧节点的指针
//}ArcNode;
////顶点节点的定义
//typedef struct _VexNode
//{
//	char name[50];        //顶点的标志信息
//	ArcNode* firstIn;     //指向第一个以该顶点为弧尾的弧
//	ArcNode* firstOut;    //指向第一个以该顶点为弧头的弧
//	int in_degree;        //入度
//	int out_degree;       //出度
//   
//}VexNode;
////十字链表的定义
//typedef struct
//{
//	VexNode nodes[N];     //顶点数组
//	int vexNum, arcNum;   //顶点数，弧数
//}orthoList;
//int ReadFile(orthoList &e)
//{
//	char FILEname[100];
//	printf("请选择要检验的图的文件名：\n");
//	scanf("%s", &FILEname);
//	FILE* fp = fopen(FILEname, "r");
//	if (!fp)
//	{
//		perror("无法打开文件");
//		return 0;
//	}
//	fscanf(fp, "%d ", &e.vexNum);
//	for (int i = 0; i < e.vexNum; i++)
//	{
//		fscanf(fp, "%s ", e.nodes[i].name);
//		e.nodes[i].firstIn = NULL;
//		e.nodes[i].firstOut = NULL;
//		e.nodes[i].in_degree = 0;
//		e.nodes[i].out_degree = 0;
//	}
//	fscanf(fp, "%d ", &e.arcNum);
//	for (int i = 0; i < e.arcNum; i++)
//	{
//		char arcTail[50], arcHead[50];
//		ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode));
//		fscanf(fp, "%s %s ", arcTail, arcHead);
//		for (int j = 0; j < e.vexNum; j++)
//		{
//			if (!strcmp(e.nodes[j].name,arcTail))
//				p->tailVex = j;
//			if (!strcmp(e.nodes[j].name,arcHead))
//				p->headVex = j;
//		}
//		p->tLink = e.nodes[p->tailVex].firstOut;
//		e.nodes[p->tailVex].firstOut = p;
//		e.nodes[p->tailVex].out_degree++;
//		p->hLink = e.nodes[p->headVex].firstIn;
//		e.nodes[p->headVex].firstIn = p;
//		e.nodes[p->headVex].in_degree++;
//	}
//	fclose(fp);
//	return 1;
//}
//int toplogical_sort_forward(orthoList e,int* sorted,int *sorted_size)
//{
//	int queue[N];
//	int front = 0, rear = 0;
//	*sorted_size=0;
//	for (int i = 0; i < e.vexNum; i++)
//	{
//		if (e.nodes[i].in_degree == 0)
//		{
//			queue[rear++] = i;
//		}
//	}
//	while (front < rear)
//	{
//		int u = queue[front++];
//		sorted[(*sorted_size)++] = u;
//		for (ArcNode* edge = e.nodes[u].firstOut; edge; edge = edge->tLink)
//		{
//			int v = edge->headVex;
//			if (--e.nodes[v].in_degree == 0)
//			{
//				queue[rear++] = v;
//
//			}
//		}
//	}
//	if (e.vexNum == *sorted_size)
//	{
//		return 1;
//	}
//	else
//		return 0;
//}
//void toplogical_sort_backward(orthoList e, int* sorted,int *sorted_size)
//{
//	int queue[N];
//	int front = 0, rear = 0;
//	for (int i = 0; i < e.vexNum; i++)
//	{
//		if (e.nodes[i].out_degree == 0)
//		{
//			queue[rear++] = i;
//		}
//	}
//	while (front < rear)
//	{
//		int u = queue[front++];
//		sorted[(*sorted_size)++] = u;
//		for (ArcNode* edge = e.nodes[u].firstIn; edge; edge = edge->hLink)
//		{
//			int v = edge->tailVex;
//			if (--e.nodes[v].out_degree == 0)
//			{
//				queue[rear++] = v;
//			}
//		}
//	}
//
//}
//void writeFile() {
//	char FILEname[100];
//	printf("请选择要创建的文件名：\n");
//	scanf("%s", &FILEname);
//	FILE* fp = fopen(FILEname, "w");
//	if (!fp) {
//		perror("无法打开文件");
//		return;
//	}
//	printf("请输入顶点总数：");
//	int vertex_count;
//	scanf("%d", &vertex_count);
//	fprintf(fp, "%d\n", vertex_count);
//	printf("请输入每个顶点的名称（用空格分隔）：\n");
//	for (int i = 0; i < vertex_count; i++) {
//		char name[50];
//		scanf("%s", name);
//		fprintf(fp, "%s\n", name);
//	}
//	printf("请输入边的总数：");
//	int arc_count;
//	scanf("%d", &arc_count);
//	fprintf(fp, "%d\n", arc_count);
//	printf("请输入每条边的起点和终点（用空格分隔）：\n");
//	for (int i = 0; i < arc_count; i++) {
//		char u_name[50], v_name[50];
//		scanf("%s %s", u_name, v_name);
//		fprintf(fp, "%s %s\n", u_name, v_name);
//	}
//
//	fclose(fp);
//	printf("图已保存到文件 %s\n", FILEname);
//}
int main()
{
	while (1)
	{
		int choice;
		printf("选项1：选择图进行检验。\n");
		printf("选项2：创建一个新的图。\n");
		printf("选项3：选择图进行添加边。\n");
		printf("选项4：选择图进行删除边。\n");
		printf("选项5：选择图进行添加点。\n");
		printf("选项6：选择图进行删除点。\n");
		scanf("%d", &choice);

		if (choice == 1)
		{
			orthoList image;
			char FILEname[100];
			printf("请选择要检验的图的文件名：\n");
			scanf("%s", FILEname);
			if (ReadFile(image,FILEname))
			{
				int sorted[N], sorted_size;
				int is_acyclic = toplogical_sort_forward(image, sorted, &sorted_size);
				if (is_acyclic)
				{
					printf("该有向图无环。\n");
					printf("拓扑排序为：\n");
					for (int i = 0; i < sorted_size; i++)
						printf("%s ", image.nodes[sorted[i]].name);
					printf("\n");
				}
				else
				{
					printf("该有向图存在环。\n");
					printf("构成环的顶点为：");
					int is_processed[N] = { 0 };
					toplogical_sort_backward(image, sorted, &sorted_size);
					for (int i = 0; i < sorted_size; i++)
					{
						is_processed[sorted[i]] = 1;
					}
					for (int u = 0; u < image.vexNum; u++)
					{
						if (!is_processed[u])
						{
							printf("%s ", image.nodes[u].name);
						}
					}
					printf("\n");
				}
			}
		}
		else if (choice == 2)
			creatFile();
		else if (choice == 3)
		{
			orthoList image;
			char FILEname[100];
			printf("请选择要增加边的图的文件名：\n");
			scanf("%s", FILEname);
			if (ReadFile(image,FILEname))
			{
				add_edge(image,FILEname);
			}
		}
		else if (choice == 4)
		{
			orthoList image ;
			char FILEname[100];
			int num = 0;
			printf("请选择要删除边的图的文件名：\n");
			scanf("%s", FILEname);
			if (ReadFile(image, FILEname))
			{
				char hname[50], tname[50];
				printf("请输入弧头：\n");
				scanf("%s", hname);
				printf("请输入弧尾：\n");
				scanf("%s", tname);
				int tailVex = find(image, tname);
				int headVex = find(image, hname);
				deleteEdge(image, FILEname, tailVex, headVex,num);
			}
		}
		else if (choice == 5)
		{
			orthoList image;
			char FILEname[100];
			printf("请选择要增加点的图的文件名：\n");
			scanf("%s", FILEname);
			if (ReadFile(image, FILEname))
			{
				addVertex(image, FILEname);
			}
		}
		else
		{
			orthoList image;
			char FILEname[100];
			printf("请选择要删除点的图的文件名：\n");
			scanf("%s", FILEname);
			if (ReadFile(image, FILEname))
			{
				deleteVertex(image, FILEname);
			}
		}
	}
}


//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define N 30
#include"graph.h"
////���ڵ�Ķ���
//typedef struct _ArcNode
//{
//	int tailVex,headVex;   //��ͷ����β�±�����
//	struct _ArcNode* tLink;//ͬ��β����һ�����ڵ��ָ�� 
//	struct _ArcNode* hLink;//ͬ��ͷ����һ�����ڵ��ָ��
//}ArcNode;
////����ڵ�Ķ���
//typedef struct _VexNode
//{
//	char name[50];        //����ı�־��Ϣ
//	ArcNode* firstIn;     //ָ���һ���Ըö���Ϊ��β�Ļ�
//	ArcNode* firstOut;    //ָ���һ���Ըö���Ϊ��ͷ�Ļ�
//	int in_degree;        //���
//	int out_degree;       //����
//   
//}VexNode;
////ʮ������Ķ���
//typedef struct
//{
//	VexNode nodes[N];     //��������
//	int vexNum, arcNum;   //������������
//}orthoList;
//int ReadFile(orthoList &e)
//{
//	char FILEname[100];
//	printf("��ѡ��Ҫ�����ͼ���ļ�����\n");
//	scanf("%s", &FILEname);
//	FILE* fp = fopen(FILEname, "r");
//	if (!fp)
//	{
//		perror("�޷����ļ�");
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
//	printf("��ѡ��Ҫ�������ļ�����\n");
//	scanf("%s", &FILEname);
//	FILE* fp = fopen(FILEname, "w");
//	if (!fp) {
//		perror("�޷����ļ�");
//		return;
//	}
//	printf("�����붥��������");
//	int vertex_count;
//	scanf("%d", &vertex_count);
//	fprintf(fp, "%d\n", vertex_count);
//	printf("������ÿ����������ƣ��ÿո�ָ�����\n");
//	for (int i = 0; i < vertex_count; i++) {
//		char name[50];
//		scanf("%s", name);
//		fprintf(fp, "%s\n", name);
//	}
//	printf("������ߵ�������");
//	int arc_count;
//	scanf("%d", &arc_count);
//	fprintf(fp, "%d\n", arc_count);
//	printf("������ÿ���ߵ������յ㣨�ÿո�ָ�����\n");
//	for (int i = 0; i < arc_count; i++) {
//		char u_name[50], v_name[50];
//		scanf("%s %s", u_name, v_name);
//		fprintf(fp, "%s %s\n", u_name, v_name);
//	}
//
//	fclose(fp);
//	printf("ͼ�ѱ��浽�ļ� %s\n", FILEname);
//}
int main()
{
	while (1)
	{
		int choice;
		printf("ѡ��1��ѡ��ͼ���м��顣\n");
		printf("ѡ��2������һ���µ�ͼ��\n");
		printf("ѡ��3��ѡ��ͼ������ӱߡ�\n");
		printf("ѡ��4��ѡ��ͼ����ɾ���ߡ�\n");
		printf("ѡ��5��ѡ��ͼ������ӵ㡣\n");
		printf("ѡ��6��ѡ��ͼ����ɾ���㡣\n");
		scanf("%d", &choice);

		if (choice == 1)
		{
			orthoList image;
			char FILEname[100];
			printf("��ѡ��Ҫ�����ͼ���ļ�����\n");
			scanf("%s", FILEname);
			if (ReadFile(image,FILEname))
			{
				int sorted[N], sorted_size;
				int is_acyclic = toplogical_sort_forward(image, sorted, &sorted_size);
				if (is_acyclic)
				{
					printf("������ͼ�޻���\n");
					printf("��������Ϊ��\n");
					for (int i = 0; i < sorted_size; i++)
						printf("%s ", image.nodes[sorted[i]].name);
					printf("\n");
				}
				else
				{
					printf("������ͼ���ڻ���\n");
					printf("���ɻ��Ķ���Ϊ��");
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
			printf("��ѡ��Ҫ���ӱߵ�ͼ���ļ�����\n");
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
			printf("��ѡ��Ҫɾ���ߵ�ͼ���ļ�����\n");
			scanf("%s", FILEname);
			if (ReadFile(image, FILEname))
			{
				char hname[50], tname[50];
				printf("�����뻡ͷ��\n");
				scanf("%s", hname);
				printf("�����뻡β��\n");
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
			printf("��ѡ��Ҫ���ӵ��ͼ���ļ�����\n");
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
			printf("��ѡ��Ҫɾ�����ͼ���ļ�����\n");
			scanf("%s", FILEname);
			if (ReadFile(image, FILEname))
			{
				deleteVertex(image, FILEname);
			}
		}
	}
}


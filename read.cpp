#include "graph.h"
int ReadFile(orthoList& e,char *FILEname)
{
	
	FILE* fp = fopen(FILEname, "r");
	if (!fp)
	{
		perror("无法打开文件");
		return 0;
	}
	fscanf(fp, "%d ", &e.vexNum);
	for (int i = 0; i < e.vexNum; i++)
	{
		fscanf(fp, "%s ", e.nodes[i].name);
		e.nodes[i].firstIn = NULL;
		e.nodes[i].firstOut = NULL;
		e.nodes[i].in_degree = 0;
		e.nodes[i].out_degree = 0;
	}
	fscanf(fp, "%d ", &e.arcNum);
	for (int i = 0; i < e.arcNum; i++)
	{
		char arcTail[50], arcHead[50];
		ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode));
		fscanf(fp, "%s %s ", arcTail, arcHead);
		for (int j = 0; j < e.vexNum; j++)
		{
			if (!strcmp(e.nodes[j].name, arcTail))
				p->tailVex = j;
			if (!strcmp(e.nodes[j].name, arcHead))
				p->headVex = j;
		}
		p->tLink = e.nodes[p->tailVex].firstOut;
		e.nodes[p->tailVex].firstOut = p;
		e.nodes[p->tailVex].out_degree++;
		p->hLink = e.nodes[p->headVex].firstIn;
		e.nodes[p->headVex].firstIn = p;
		e.nodes[p->headVex].in_degree++;
	}
	fclose(fp);
	return 1;
}
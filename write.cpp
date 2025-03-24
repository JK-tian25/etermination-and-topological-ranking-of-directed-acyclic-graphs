#include "graph.h"
void writeFile(orthoList e,char* FILEname) {
	FILE* fp = fopen(FILEname, "w");
	if (!fp)
	{
		perror("无法打开文件");
		return;
	}
	fprintf(fp, "%d\n", e.vexNum);
	for (int i = 0; i < e.vexNum; i++) {
		fprintf(fp, "%s\n", e.nodes[i].name);
	}
	fprintf(fp, "%d\n", e.arcNum);
	for (int i = 0; i < e.vexNum; i++)
	{
		for (ArcNode* edge = e.nodes[i].firstOut; edge; edge = edge->tLink)
		{
			fprintf(fp, "%s %s\n", e.nodes[edge->tailVex].name, e.nodes[edge->headVex].name);
		}
	}
	fclose(fp);
	printf("图已保存到文件 %s\n", FILEname); 
}
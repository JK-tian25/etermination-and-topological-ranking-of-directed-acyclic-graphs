#include "graph.h"
<<<<<<< HEAD
void writeFile(orthoList e) {
	FILE* fp = fopen("ifo.txt", "w");
=======
void writeFile(orthoList e,char* FILEname) {
	FILE* fp = fopen(FILEname, "w");
>>>>>>> dc1b5ca53f8ceef120c86c6f3b22249f59be0fc2
	if (!fp)
	{
		perror("�޷����ļ�");
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
<<<<<<< HEAD
	printf("ͼ�ѱ��浽�ļ� %s\n"); 
=======
	printf("ͼ�ѱ��浽�ļ� %s\n", FILEname); 
>>>>>>> dc1b5ca53f8ceef120c86c6f3b22249f59be0fc2
}
#include "graph.h"
void deleteVertex(orthoList &e,char* FILEname) {
    char name[50];
    printf("�����붥������֣�\n");
    scanf("%s", name);
    int num = 1;
    int vexIndex = find(e,name);
    if (vexIndex < 0 || vexIndex >= e.vexNum) {
        printf("Invalid vertex index!\n");
        return;
    }

    // ɾ�������Ըö���Ϊ��β�ı�
    ArcNode* currOut = e.nodes[vexIndex].firstOut;
    while (currOut != NULL) {
        int headVex = currOut->headVex;
        ArcNode* nextOut = currOut->tLink;
        deleteEdge(e, FILEname,vexIndex, currOut->headVex,num);
        currOut = nextOut;
    }

    // ɾ�������Ըö���Ϊ��ͷ�ı�
    ArcNode* currIn = e.nodes[vexIndex].firstIn;
    while (currIn != NULL) {
        int tailVex = currIn->tailVex;
        ArcNode* nextIn = currIn->hLink;
        deleteEdge(e, FILEname, currIn->tailVex, vexIndex,num);
        currIn = nextIn;
    }

    // �ƶ������������ȱ
    for (int i = vexIndex; i < e.vexNum - 1; i++) {
        e.nodes[i] = e.nodes[i + 1];
    }
    for (int i = 0; i < e.vexNum; i++) {
        ArcNode* currOut = e.nodes[i].firstOut;
        while (currOut != NULL) {
            // ���� tailVex����� tailVex > vexIndex���� 1
            if (currOut->tailVex > vexIndex) {
                currOut->tailVex--;
            }
            // ���� headVex����� headVex > vexIndex���� 1
            if (currOut->headVex > vexIndex) {
                currOut->headVex--;
            }
            currOut = currOut->tLink;
        }
    }
    e.vexNum--;

    writeFile(e,FILEname);
}
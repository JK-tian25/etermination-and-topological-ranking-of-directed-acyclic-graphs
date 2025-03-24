#include "graph.h"
void addVertex(orthoList &e, char* FILEname) {
    char name[50];
    printf("请输入需要添加的点的名字：\n");
    scanf("%s",name);
    if (e.vexNum >= N) {
        printf("Graph is full, cannot add more vertices!\n");
        return;
    }

    strcpy(e.nodes[e.vexNum].name, name);
    e.nodes[e.vexNum].firstIn = NULL;
    e.nodes[e.vexNum].firstOut = NULL;
    e.nodes[e.vexNum].in_degree = 0;
    e.nodes[e.vexNum].out_degree = 0;
    e.vexNum++;

    writeFile(e,FILEname);
}
#include "graph.h"
<<<<<<< HEAD
void deleteVertex(orthoList &e) {
=======
void deleteVertex(orthoList &e,char* FILEname) {
>>>>>>> dc1b5ca53f8ceef120c86c6f3b22249f59be0fc2
    char name[50];
    printf("请输入顶点的名字：\n");
    scanf("%s", name);
    int num = 1;
    int vexIndex = find(e,name);
    if (vexIndex < 0 || vexIndex >= e.vexNum) {
        printf("Invalid vertex index!\n");
        return;
    }

    // 删除所有以该顶点为弧尾的边
    ArcNode* currOut = e.nodes[vexIndex].firstOut;
    while (currOut != NULL) {
        int headVex = currOut->headVex;
        ArcNode* nextOut = currOut->tLink;
<<<<<<< HEAD
        deleteEdge(e,vexIndex, currOut->headVex,num);
=======
        deleteEdge(e, FILEname,vexIndex, currOut->headVex,num);
>>>>>>> dc1b5ca53f8ceef120c86c6f3b22249f59be0fc2
        currOut = nextOut;
    }

    // 删除所有以该顶点为弧头的边
    ArcNode* currIn = e.nodes[vexIndex].firstIn;
    while (currIn != NULL) {
        int tailVex = currIn->tailVex;
        ArcNode* nextIn = currIn->hLink;
<<<<<<< HEAD
        deleteEdge(e, currIn->tailVex, vexIndex,num);
=======
        deleteEdge(e, FILEname, currIn->tailVex, vexIndex,num);
>>>>>>> dc1b5ca53f8ceef120c86c6f3b22249f59be0fc2
        currIn = nextIn;
    }

    // 移动后续顶点填补空缺
    for (int i = vexIndex; i < e.vexNum - 1; i++) {
        e.nodes[i] = e.nodes[i + 1];
    }
    for (int i = 0; i < e.vexNum; i++) {
        ArcNode* currOut = e.nodes[i].firstOut;
        while (currOut != NULL) {
            // 调整 tailVex：如果 tailVex > vexIndex，减 1
            if (currOut->tailVex > vexIndex) {
                currOut->tailVex--;
            }
            // 调整 headVex：如果 headVex > vexIndex，减 1
            if (currOut->headVex > vexIndex) {
                currOut->headVex--;
            }
            currOut = currOut->tLink;
        }
    }
    e.vexNum--;

<<<<<<< HEAD
    writeFile(e);
=======
    writeFile(e,FILEname);
>>>>>>> dc1b5ca53f8ceef120c86c6f3b22249f59be0fc2
}
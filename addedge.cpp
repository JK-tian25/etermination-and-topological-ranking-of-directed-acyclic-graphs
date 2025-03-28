#include "graph.h"
<<<<<<< HEAD
void add_edge(orthoList& e) {
=======
void add_edge(orthoList& e, char* FILEname) {
>>>>>>> dc1b5ca53f8ceef120c86c6f3b22249f59be0fc2
        char hname[50], tname[50];
        ArcNode* newArc = (ArcNode*)malloc(sizeof(ArcNode));
        printf("请输入弧头：\n");
        scanf("%s", hname);
        printf("请输入弧尾：\n");
        scanf("%s", tname);
        int tailVex = find(e, tname);
        int headVex = find(e, hname);
        if (tailVex < 0 || tailVex >= e.vexNum || headVex < 0 || headVex >= e.vexNum) {
                printf("Invalid vertex index!\n");
                return;
        }
        newArc->tailVex = tailVex;
        newArc->headVex = headVex;
        newArc->tLink = e.nodes[tailVex].firstOut;
        newArc->hLink = e.nodes[headVex].firstIn;
        e.nodes[tailVex].firstOut = newArc;
        e.nodes[headVex].firstIn = newArc;
        e.nodes[tailVex].out_degree++;
        e.nodes[headVex].in_degree++;   
        e.arcNum++;
<<<<<<< HEAD
        writeFile(e);
=======
        writeFile(e,FILEname);
>>>>>>> dc1b5ca53f8ceef120c86c6f3b22249f59be0fc2
        printf("添加成功。\n");
        /*return;*/
    
}
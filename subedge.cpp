#include "graph.h"
void deleteEdge(orthoList &e,char *FILEname, int tailVex, int headVex,int VVV) {
    
    if (tailVex < 0 || tailVex >= e.vexNum || headVex < 0 || headVex >= e.vexNum) {
        printf("Invalid vertex index!\n");
        return;
    }

    ArcNode* prevOut = NULL;
    ArcNode* currOut = e.nodes[tailVex].firstOut;
    while (currOut != NULL && currOut->headVex != headVex) {
        prevOut = currOut;
        currOut = currOut->tLink;
    }

    if (currOut == NULL) {
        printf("Edge not found!\n");
        return;
    }

    if (prevOut == NULL) {
        e.nodes[tailVex].firstOut = currOut->tLink;
    }
    else {
        prevOut->tLink = currOut->tLink;
    }

    ArcNode* prevIn = NULL;
    ArcNode* currIn = e.nodes[headVex].firstIn;
    while (currIn != NULL && currIn->tailVex != tailVex) {
        prevIn = currIn;
        currIn = currIn->hLink;
    }

    if (prevIn == NULL) {
        e.nodes[headVex].firstIn = currIn->hLink;
    }
    else {
        prevIn->hLink = currIn->hLink;
    }

    free(currOut);
    e.nodes[tailVex].out_degree--;
    e.nodes[headVex].in_degree--;
    e.arcNum--;
    if(!VVV)
  writeFile(e,FILEname);
}
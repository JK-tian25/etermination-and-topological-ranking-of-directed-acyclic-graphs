#include "graph.h"
void toplogical_sort_backward(orthoList e, int* sorted, int* sorted_size)
{
	int queue[N];
	int front = 0, rear = 0;
	for (int i = 0; i < e.vexNum; i++)
	{
		if (e.nodes[i].out_degree == 0)
		{
			queue[rear++] = i;
		}
	}
	while (front < rear)
	{
		int u = queue[front++];
		sorted[(*sorted_size)++] = u;
		for (ArcNode* edge = e.nodes[u].firstIn; edge; edge = edge->hLink)
		{
			int v = edge->tailVex;
			if (--e.nodes[v].out_degree == 0)
			{
				queue[rear++] = v;
			}
		}
	}

}
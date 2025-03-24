#include "graph.h"
int toplogical_sort_forward(orthoList e, int* sorted, int* sorted_size)
{
	int queue[N];
	int front = 0, rear = 0;
	*sorted_size = 0;
	for (int i = 0; i < e.vexNum; i++)
	{
		if (e.nodes[i].in_degree == 0)
		{
			queue[rear++] = i;
		}
	}
	while (front < rear)
	{
		int u = queue[front++];
		sorted[(*sorted_size)++] = u;
		for (ArcNode* edge = e.nodes[u].firstOut; edge; edge = edge->tLink)
		{
			int v = edge->headVex;
			if (--e.nodes[v].in_degree == 0)
			{
				queue[rear++] = v;

			}
		}
	}
	if (e.vexNum == *sorted_size)
	{
		return 1;
	}
	else
		return 0;
}
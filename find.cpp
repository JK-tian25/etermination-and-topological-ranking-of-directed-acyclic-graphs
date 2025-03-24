#include "graph.h"
int find(orthoList e,char *name)
{
	for (int i = 0; i < e.vexNum; i++)
	{
		if (strcmp(name, e.nodes[i].name) == 0)
			return i;
	}
}
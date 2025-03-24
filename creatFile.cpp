#include "graph.h"
void creatFile() {
	char FILEname[100];
		printf("请选择要创建的文件名：\n");
		scanf("%s", FILEname);
		FILE* fp = fopen(FILEname, "w");
		if (!fp) {
			perror("无法打开文件");
			return;
		}
		printf("请输入顶点总数：");
		int vertex_count;
		scanf("%d", &vertex_count);
		fprintf(fp, "%d\n", vertex_count);
		printf("请输入每个顶点的名称（用空格分隔）：\n");
		for (int i = 0; i < vertex_count; i++) {
			char name[50];
			scanf("%s", name);
			fprintf(fp, "%s\n", name);
		}
		printf("请输入边的总数：");
		int arc_count;
		scanf("%d", &arc_count);
		fprintf(fp, "%d\n", arc_count);
		printf("请输入每条边的起点和终点（用空格分隔）：\n");
		for (int i = 0; i < arc_count; i++) {
			char u_name[50], v_name[50];
			scanf("%s %s", u_name, v_name);
			fprintf(fp, "%s %s\n", u_name, v_name);
		}

		fclose(fp);
		printf("图已保存到文件 %s\n", FILEname);
}
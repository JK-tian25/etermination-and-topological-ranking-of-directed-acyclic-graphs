#include "graph.h"
void creatFile() {
	char FILEname[100];
		printf("��ѡ��Ҫ�������ļ�����\n");
		scanf("%s", FILEname);
		FILE* fp = fopen(FILEname, "w");
		if (!fp) {
			perror("�޷����ļ�");
			return;
		}
		printf("�����붥��������");
		int vertex_count;
		scanf("%d", &vertex_count);
		fprintf(fp, "%d\n", vertex_count);
		printf("������ÿ����������ƣ��ÿո�ָ�����\n");
		for (int i = 0; i < vertex_count; i++) {
			char name[50];
			scanf("%s", name);
			fprintf(fp, "%s\n", name);
		}
		printf("������ߵ�������");
		int arc_count;
		scanf("%d", &arc_count);
		fprintf(fp, "%d\n", arc_count);
		printf("������ÿ���ߵ������յ㣨�ÿո�ָ�����\n");
		for (int i = 0; i < arc_count; i++) {
			char u_name[50], v_name[50];
			scanf("%s %s", u_name, v_name);
			fprintf(fp, "%s %s\n", u_name, v_name);
		}

		fclose(fp);
		printf("ͼ�ѱ��浽�ļ� %s\n", FILEname);
}
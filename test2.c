#include <stdio.h>
#include <Windows.h>
#pragma warning(disable:4996)

// ʵ��my_printf
void my_printf(const char* str){
	const char* p = str;
	while (*p){
		fputc(*p, stdout);
		p++;
	}
}
int main3(){
	FILE* fp = fopen("my.txt", "w");
	if (NULL == fp){
		printf("fopen error\n");
		return 1;
	}
	int i = 3;
	my_printf("hello world!\n");
	// ���� printf("%d abc %c abc %f\n", i, c, pi) �ɱ�����б�
	// ��һ������ֵ���ַ��� whileѭ������ ֻҪ������% �͵���fputc, ����%, �ٰ�p++, ָ����%����
	// ����%������d, �����ʹ����һ������ ��������whileѭ�������case���, 
	printf("hello %d anc", i);// ��ӡ���� hello 3 anc

	fclose(fp);
	system("pause");
	return 0;
}

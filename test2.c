#include <stdio.h>
#include <Windows.h>
#pragma warning(disable:4996)

// 实现my_printf
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
	// 但是 printf("%d abc %c abc %f\n", i, c, pi) 可变参数列表
	// 第一个参数值是字符串 while循环遍历 只要不遇到% 就调用fputc, 遇到%, 再把p++, 指到了%后面
	// 若在%后碰到d, 以整型打出第一个参数 理论上是while循环里加了case语句, 
	printf("hello %d anc", i);// 打印的是 hello 3 anc

	fclose(fp);
	system("pause");
	return 0;
}

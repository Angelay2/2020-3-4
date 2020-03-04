#include <stdio.h>
#include <Windows.h>
#pragma warning(disable:4996)

// int fprintf (FILE* stream, const char* format, ...)
// 向特定文件进行格式化输出
// int printf(const char* format, ...) 第一个参数为字符指针 '...'为C可变参数(了解栈帧)
int main6(){
	FILE* fp = fopen("my.txt", "w");
	if (NULL == fp){
		return 1;
	}

	int a = 10;
	double b = 20;
	//fprintf(stdout, "%d, %f\n", a, b);
	fprintf(fp, "%d, %f\n", a, b);
	//printf("%d, %f\n", a, b);// 但是printf 不能往文件里打

	fclose(fp);
	system("pause");
	return 0;
}
// 把童鞋们的姓名, 学号, 性别打到文件里
int main7(){
	FILE* fp = fopen("my.txt", "w");
	if (NULL == fp){
		return 1;
	}
	char name[32];
	int age = 0;
	char sex[32];
	char tel[18];
	int i = 2;
	while (i--){
		printf("Please Enter Your Name: ");
		scanf("%s", &name);
		printf("Please Enter Your Age: ");
		scanf("%d", &age);
		printf("Please Enter Your Sex: ");
		scanf("%s", &sex);
		printf("Please Enter Your Telphone: ");
		scanf("%s", &tel);
		fprintf(fp, "| %s | %d | %s | %s |\n", name, age, sex, tel);// 写到文件里
		//fprintf(stdout, "| %s | %d | %s | %s |\n", name, age, sex, tel);// 输完就显示在显示器上
	}

	fclose(fp);
	system("pause");
	return 0;
}
// 把信息从文件里读出来
int main(){
	FILE* fp = fopen("my.txt", "r");
	if (NULL == fp){
		return 1;
	}
	char name[32];
	int age = 0;
	char sex[32];
	char tel[18];
	int i = 2;
	while (i--){
		fscanf(fp, "| %s | %d | %s | %s |\n", name, &age, sex, tel);
	}

	fclose(fp);
	system("pause");
	return 0;
}

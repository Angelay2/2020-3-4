#include <stdio.h>
#include <Windows.h>
#pragma warning(disable:4996)

// int fprintf (FILE* stream, const char* format, ...)
// ���ض��ļ����и�ʽ�����
// int printf(const char* format, ...) ��һ������Ϊ�ַ�ָ�� '...'ΪC�ɱ����(�˽�ջ֡)
int main6(){
	FILE* fp = fopen("my.txt", "w");
	if (NULL == fp){
		return 1;
	}

	int a = 10;
	double b = 20;
	//fprintf(stdout, "%d, %f\n", a, b);
	fprintf(fp, "%d, %f\n", a, b);
	//printf("%d, %f\n", a, b);// ����printf �������ļ����

	fclose(fp);
	system("pause");
	return 0;
}
// ��ͯЬ�ǵ�����, ѧ��, �Ա���ļ���
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
		fprintf(fp, "| %s | %d | %s | %s |\n", name, age, sex, tel);// д���ļ���
		//fprintf(stdout, "| %s | %d | %s | %s |\n", name, age, sex, tel);// �������ʾ����ʾ����
	}

	fclose(fp);
	system("pause");
	return 0;
}
// ����Ϣ���ļ��������
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

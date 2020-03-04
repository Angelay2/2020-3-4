#include <stdio.h>
#include <Windows.h>
#pragma warning(disable:4996)


// �ļ����Բ���
// int fputc(int character, FILE* stream) ��һ���ض����ļ���д��һ���ַ�
// ���ļ���д26 ����ĸ
int main2(){
	FILE* fp = fopen("my.txt", "w");
	if (NULL == fp){
		printf("fopen error\n");
		return 1;
	}

	char c = 'A';
	int i = 0;
	for (; i < 26; i++){
		fputc(c + i, fp);
		// ����ʾ����д 
		// C����Ĭ������ʱ����������������(�ļ�), �ֱ��Ǳ�׼����, ��׼���, ��׼����, 
		// ��Ӧ���豸�ļ��Ǽ���, ��ʾ��, ��ʾ��, ��Ӧ��FILE*��stdin, stdout , stderr;
		// fflush(stdout) ����������ʾ��ˢ��
		// ��printf������: ������һ��, printf�Ǻ���,����һ����һ������ʱ��stdout�ϴ�
		// stdout��FILE*����, ��ʾ�Ѿ������ļ�, ����ʾ����д�������ļ���д ���ȵô�(ϵͳ�򿪵�)
		fputc(c + i, stdout);
		printf("%c", c + i);
	}

	fclose(fp);
	system("pause");
	return 0;
}
// scanfҲ�ǴӼ��̶�, ʵ�ʶ������Ǵ�stdin����ļ�ָ����� 

// int fgetc (FILE* stream) ���ļ���һ�ζ�һ���ַ�, �������ַ�ͨ������ֵ�õ� 
// ����EOF(�� ֵΪ -1) => �����ļ���β

// ���ļ����ж�һ���ַ� ��ʱ����ֵΪʲô����char?
// fgetc �Ǻ��� �п��ܵ���ʧ��, �������ֵ��char �޷���ʾʧ�� ��������� ֻ�еͰ�λ 
// �����ʾ���� ����ʹ�õͰ�λ���ϵ�λ 
int main4(){
	FILE* fp = fopen("my.txt", "r");
	if (NULL == fp){
		printf("fopen error!\n");
		return 1;
	}

	char c;
	while ((c = fgetc(fp)) != EOF){
		// fputc, fputs��printf������
		// ��Ƚ�printf��˵ ǰ�����ǰ���ʾ����дʲô����ʾʲô ��printf�Ǹ�ʽ����� %d������������滻�� 	
		// �ȴ��ļ� ��fgetc ���ļ��е����ݶ�����,�ŵ�c��,cû�е���β ����fputc���ȵ����ݴﵽ��ʾ���� 
		fputc(c, stdout);
	}

	fclose(fp);
	system("pause");
	return 0;
}
// char* fgets(char* str, int num, FILE* stream)
// fgets �Ǵ��ض��������ж�ȡһ���ַ��� ���뻺������ ��������num���ֽڴ�, 
int  main5(){
	char buf[16];
	// ��stdin���� �ļ�ָ�� �Ϳ��Դ�һ���ļ����ȡ�ַ���
	//fgets(buf, sizeof(buf), stdin); // �Ӽ��̶��ַ�������СΪ16��buf��
	FILE* fp = fopen("C:\\Users\\Administrator\\Desktop\\my.txt", "r");
	if (NULL == fp){
		return 1;
	}
	fgets(buf, sizeof(buf), fp);
	fputs(buf, stdout);//  �Ѹ�������ַ����ִ���ʾ����


	system("pause");
	return 0;
}
#include <stdio.h>
#include <Windows.h>
#pragma warning(disable:4996)


// 文件属性操作
// int fputc(int character, FILE* stream) 向一个特定的文件中写入一个字符
// 往文件里写26 个字母
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
		// 往显示器里写 
		// C程序默认运行时会打开三个输入输出流(文件), 分别是标准输入, 标准输出, 标准错误, 
		// 对应的设备文件是键盘, 显示器, 显示器, 对应的FILE*是stdin, stdout , stderr;
		// fflush(stdout) 把数据往显示器刷新
		// 和printf的区别: 参数不一样, printf是函数,里面一定有一个函数时往stdout上打
		// stdout是FILE*类型, 表示已经打开了文件, 往显示器里写就是往文件里写 首先得打开(系统打开的)
		fputc(c + i, stdout);
		printf("%c", c + i);
	}

	fclose(fp);
	system("pause");
	return 0;
}
// scanf也是从键盘读, 实际读数据是从stdin这个文件指针读的 

// int fgetc (FILE* stream) 从文件里一次读一个字符, 读到的字符通过返回值拿到 
// 读到EOF(宏 值为 -1) => 读到文件结尾

// 从文件流中读一个字符 此时返回值为什么不是char?
// fgetc 是函数 有可能调用失败, 如果返回值是char 无法表示失败 正常情况下 只有低八位 
// 如果表示错误 可以使用低八位往上的位 
int main4(){
	FILE* fp = fopen("my.txt", "r");
	if (NULL == fp){
		printf("fopen error!\n");
		return 1;
	}

	char c;
	while ((c = fgetc(fp)) != EOF){
		// fputc, fputs和printf的区别
		// 相比较printf来说 前两个是把显示器上写什么就显示什么 但printf是格式化输出 %d被后面的内容替换掉 	
		// 先打开文件 用fgetc 将文件中的内容读出来,放到c中,c没有到结尾 利用fputc将度的内容达到显示器上 
		fputc(c, stdout);
	}

	fclose(fp);
	system("pause");
	return 0;
}
// char* fgets(char* str, int num, FILE* stream)
// fgets 是从特定的流当中读取一个字符串 放入缓冲区里 缓冲区有num个字节大, 
int  main5(){
	char buf[16];
	// 把stdin换成 文件指针 就可以从一个文件里读取字符串
	//fgets(buf, sizeof(buf), stdin); // 从键盘读字符串到大小为16的buf中
	FILE* fp = fopen("C:\\Users\\Administrator\\Desktop\\my.txt", "r");
	if (NULL == fp){
		return 1;
	}
	fgets(buf, sizeof(buf), fp);
	fputs(buf, stdout);//  把刚输入的字符串又打到显示器上


	system("pause");
	return 0;
}
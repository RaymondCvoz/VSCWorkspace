#include <stdio.h>
int main()
{
	int i = 0;
	for (i = 0; i < 379; i++) //每次向缓冲区内写三个字符
	{
		if (i >= 100)
			fprintf(stdout, "%d", i);
		else if (i >= 10)
			fprintf(stdout, "0%d", i);
		else if (i >= 0)
			fprintf(stdout, "00%d", i);
	}
	while (1)
		; //强制执行，如果取消，程序结束时将会输出所有字符，看不到效果了。
}

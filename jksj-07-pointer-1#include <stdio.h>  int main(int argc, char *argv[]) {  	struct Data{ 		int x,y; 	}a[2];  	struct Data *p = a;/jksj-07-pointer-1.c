#include <stdio.h>

int main(int argc, char *argv[])
{

	struct Data{
		int x,y;
	}a[2];

	struct Data *p = a;
	// 初始化a[1]
	a[1].x = 1;
	a[1].y = 2;

	printf("%p\n", &a[1].x);
	printf("%p\n", p+1);
	printf("%p\n", &(*(p+1)).x);
	printf("%p\n", &(p+1)->x);

	printf("%p\n", &p[1]);
	printf("%p\n", &p[1].x);





}

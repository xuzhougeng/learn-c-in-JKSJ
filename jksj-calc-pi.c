#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 通过概率的方法计算pi值
** 对于一个半径(r=1)的圆，它的面积是 π * r ^2
** 而对应的正方形则是, (2r)^2
** 随机一次实验，落入圆内的概率是 π * r ^2 / (2r)^2 = π / 4
**
** 随机产生一个x在0-1, y在0-1之间的坐标,
** 计算 x*x + y*y <=1 (判断点是否落在圆内)
** 计算落在圆内/ 实验次数， 即 π / 4
**
*/


int main()
{
    srand(time(0));
	int i;
	int times = 10000000;
	int m = 0;
	double x,y;
	for (i = 0 ; i < times; i++){
		x = 1.0 * rand() / RAND_MAX;
		y = 1.0 * rand() / RAND_MAX;
		if ( x*x + y*y <= 1.0) m +=1 ;
	}

	printf("m:%d \n", m);

	double pi = 4.0 * m / times;
	printf("pi:%f \n", pi);
	return 0;

}

#include <stdio.h>

/*
 * 给定一个日期, 和一个数字X, 求出X天后的日期是什么
 * 实例:
 *     1989 11 20
 *     20
 *     1989 12 10
 */


int main ()
{

	int year, month, day;
	int X;
	int flag = 1;

	printf("please enther the start day in format year month day: \n");
	scanf("%d %d %d", &year, &month, &day);
	// 检查输入是否符合规范
	while (flag){	
		switch (month){
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				if (day > 31){
					printf("illegal format!\n");
					printf("please enther the start day in format year month day: \n");
					scanf("%d %d %d", &year, &month, &day);
					break;
				} else {
					flag = 0;
					break;
				}
			case 4:
			case 6:
			case 9:
			case 11:
				if (day > 30){
					printf("illegal format!\n");
					printf("please enther the start day in format year month day: \n");
					scanf("%d %d %d", &year, &month, &day);
					break;
				} else {
					flag = 0;
					break;
				}
				//能被400整除 x % 400 = 0
				//能被4整除，但不能被100整除 x % 4 = 0, x %100 !=0
			case 2:
				if ( (year % 400 == 0) || (year % 4 == 0 && year % 100 !=0) ){
					if (day > 29){
						printf("illegal format!\n");
						printf("please enther the start day in format year month day: \n");
						scanf("%d %d %d", &year, &month, &day);
						break;
					} else {
						flag = 0;
						break;
					}
				} else {
					if (day > 28){
						printf("illegal format!\n");
						printf("please enther the start day in format year month day: \n");
						scanf("%d %d %d", &year, &month, &day);
						break;
					} else {
						flag = 0;
						break;
					}
				} 
			default :
				printf("illegal format!\n");
				printf("please enther the start day in format year month day: \n");
				scanf("%d %d %d", &year, &month, &day);
				break;
		}
	}
	printf("Start day: %d-%d-%d\n", year, month, day);
	printf("How many days passed?\n");
	scanf("%d", &X);

	// 每次循环的时候减少日期
	// 后缀--表示，先返回X和0进行比较
	// 然后让X自减1
	while ( X-- > 0){
		day = day + 1;
		/* 根据月份进行判断, 是否日期超过了每个月的日期数
		   如果超过了, 则月份增加, 然后日期回归到1日
		   同时，如果月份增加，则需要判断是否超过了12
		   如果超过了12，那么年份增加
		   */
		switch (month){
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
				if (day > 31){
					month++;
					day = 1;
					break;
				} else{
					break;
				}
			case 12:
				if (day > 31){
					month = 1;
					day = 1;
					year++ ; 
					break;
				} else{
					break;
				}
			case 4:
			case 6:
			case 9:
			case 11:
				if (day > 30){
					month++;
					day = 1;
					break;
				} else{
					break;
				}
				//能被400整除 x % 400 = 0
				//能被4整除，但不能被100整除 x % 4 = 0, x %100 !=0
			case 2:
				if ( (year % 400 == 0) | (year % 4 == 0 & year % 100 !=0) ){
					if (day > 29){
						month++;
						day = 1;
						break;
					} else{
						break;
					}
				} else {
					if (day > 28){
						month++;
						day = 1;
						break;
					} else{
						break;
					}
				} 
		}
	}

	printf("End day: %d-%d-%d\n", year, month, day);
}

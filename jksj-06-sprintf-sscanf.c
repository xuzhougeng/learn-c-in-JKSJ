#include <stdio.h>                                  
/* 题目                                             
 * 输入一个小数和保留位数                           
 * 输出保留后的小数                                 
 */                                                 

/* 知识点:
 * 1. 格式输入中, 为了表示一个%, 需要用%%
 * 2. sprintf: 将原本输出到屏幕的内容，保存到变量中
 * 3. sscanf: 将原本从屏幕接受的字符串输入，从字符串数组中读取
 * 4. 字符串数组需要以'\0'表示字符串的结束
 */


int main(int argc, char *argv[])                                          
{                                                   
    // how many digit to keep                       
    int n;                                          
    // input number                                 
    double num;                                     
                                                    
    // character array to store input               
    char str[100];                                  
                                                    
    printf("Please enter your number: ");           
    scanf("%lf", &num);                             
    printf("How many digits do you want to keep: ");
    scanf("%d", &n);                                
                                                    
    // format the str to num                        
    sprintf(str,"%%.%dlf\n", n);                    
    printf(str, num);                               
                                                    
}                                                   

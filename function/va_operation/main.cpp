/**************************************************************
* auther:   MarkWang
* date:     20190506
* desc: the usage of va_start, va_arg, va_end. 
*
*typedef char* va_list;
*void va_start ( va_list ap, prev_param );
*type va_arg ( va_list ap, type ); 
*void va_end ( va_list ap );
***************************************************************/
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <stdarg.h>

void stack_based_test(int cnt, ...)
{
    int *temp = &cnt;
    printf("%s %d\n",__func__,__LINE__);
    printf("&cnt = %p,cnt = %d\n",&cnt,cnt);
    temp++;
    
    for(int i =0;i<cnt;i++)
    {
        printf("serial %d value %d addr %p\n",i,*temp,temp);
        temp++;
    }

}

void arg_based_test(int cnt ,...)
{

    printf("%s %d\n",__func__,__LINE__);
    va_list arg_ptr;

    va_start(arg_ptr,cnt);
    //int temp_int = 0;
    char temp_char = 0;
    printf("&cnt = %p\n",&cnt);

    for(int i = 0;i< cnt;i++)
    {
       //temp_int = va_arg(arg_ptr,int); 
       temp_char = va_arg(arg_ptr,int); 
       //printf("serial %d value %d addr %p\n",i,temp_int,arg_ptr);
       printf("serial %d value %c addr %p\n",i,temp_char,arg_ptr);
    }
    va_end(arg_ptr);
    printf("arg_ptr = %p\n",arg_ptr);
}


void arg_test(int i,...)
{
    int j = 0;
    va_list arg_ptr;
    printf("%s %d\n",__func__,__LINE__);
    va_start(arg_ptr,i);
    printf("&i=%p\n",&i);
    printf("arg_ptr = %p\n",arg_ptr);
    j = *((int *)arg_ptr);
    printf("i = %d j = %d\n",i,j);
    j = va_arg(arg_ptr,int);
    printf("arg_ptr = %p\n",arg_ptr);
    va_end(arg_ptr);
    printf("i = %d, j = %d\n",i,j);
    printf("arg_ptr = %p\n",arg_ptr);

}

int main(int,char**)
{

    printf("****************************************************\n");
    arg_test(2,3,4,5);
    printf("****************************************************\n");
    int a = 3;
    int b = 4;
    int c = 5;
    int d = 6;
    stack_based_test(4,a,b,c,d);
    printf("****************************************************\n");
   // arg_based_test(5,a,b,c,d);
    arg_based_test(5,'a','b','c','d');
    printf("****************************************************\n");
    return 0;
    
}



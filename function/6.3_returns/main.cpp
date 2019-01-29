#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;


int arr1[10] = {0,1,2,3,4,5,6,7,8,9};
int arr2[10] = {1,2,3,4,5,6,7,8,9,0};

char &get_val(string &str,string::size_type ix)
{
    return str[ix];
}

typedef int arrT[10];
arrT* func1(int i)
{
    printf("类型别名\n");
    return (i%2)?&arr1:&arr2; 

}


int (*func3(int i))[10]
{

    printf("返回数组指针\n");
    return (i%2)?&arr1:&arr2; 

}


//尾置返回类型，trailing return type
auto func4(int i)->int(*)[10]
{
    printf("尾置返回类型\n");
    return (i%2)?&arr1:&arr2; 
    
}   



int odd[]={1,3,5,7,9};
int even[]={0,2,4,6,8};

decltype(odd) *func5(int i)
{
    printf("using decltype \n");
    return (i%2)?&odd:&even;
}
int main(void *)
{
    //1. 引用返回为左值
    printf("****************************************************\n");
    string s("a value");
    cout << s << endl;
    //引用返回为左值，可以直接赋值
    get_val(s,0) = 'A';
    cout << s << endl;
    

    //
    int (*p1)[5];
    int (*p2)[10];

    printf("****************************************************\n");
    printf("the addr of the arr1 %x\n",&arr1);
    printf("the addr of the arr2 %x\n",&arr2);
    printf("****************************************************\n");
    p2 = func1(0);
    printf("the addr of the p2 %x\n",p2);
//   func2(0);
    printf("****************************************************\n");
    p2 = func3(1);
    printf("the addr of the p2 %x\n",p2);
    printf("****************************************************\n");
    p2 = func4(0);
    printf("the addr of the p2 %x\n",p2);
    printf("****************************************************\n");
    p1 = func5(1);
    printf("the addr of the odd %x\n",&odd);
    printf("the addr of the even %x\n",&even);

    printf("****************************************************\n");
    printf("the addr of the p1 %x\n",p1);
    printf("****************************************************\n");

    
    //2.返回数据指针
    return 0;
    
}



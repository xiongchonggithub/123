a) 一个整型数 
int a;
b) 一个指向整型数的指针 
int a;
int *p=&a
c) 一个指向指针的的指针，它指向的指针是指向一个整型 
int a;
int *p=&a;
int **q=&p;
d) 一个有 10 个整型数的数组 
int a[10]={0};
e) 一个有 10 个指针的数组，该指针是指向一个整型数的 
int (*p)[10];
f) 一个指向有 10 个整型数数组的指针 
int *p[10];
g) 一个指向函数的指针，该函数有一个整型参数并返回一个整型数\ 
int (*p)(int );
h) 一个有 10 个指针的数组，该指针指向一个函数，该函数有一个整型参数并返回一个整型数 
int (*a[10])(int );
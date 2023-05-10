#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define NUM 1000

typedef struct gene{
	char data;
	int set;
	int cnt;
	struct gene *A;
	struct gene *T;
	struct gene *C;
	struct gene *G;
}Hash,*HASH;

int compar(const void *p1,const void* p2)
{
	//修改数据类型
	const int *left  = p1;
	const int *right = p2;
	
	/* if( *left < *right)
		return 0;//返回逻辑假  left和right不进行交换
	else 
		return 1;//返回逻辑真  left和right进行交换 */
	
	if( *left > *right)
		return 0;
	else 
		return 1;
}


HASH ponit_1(HASH h,int i);

//建立二维数组存储NUM*4的基因片段
int **get_arr()
{
	int **arr = (int **)calloc(NUM, sizeof(int*));
	for(int k=0;k<NUM;k++)
	{
		arr[k]=calloc(4,sizeof(int));
	}
	if(arr==NULL)
	{
		printf("calloc NUM failed\n");
		return NULL;
	}
	int i,j;
	for(i=0;i<NUM;i++)
	{
		for(j=0;j<4;j++)
		{
			arr[i][j] = rand()%4;
		}
	}
	return arr;
}


//char转int
int change_char_int(char a)
{
	int b;
	switch(a)
	{
		case 'A' :b=0;break;
		case 'T' :b=1;break;
		case 'C' :b=2;break;
		case 'G' :b=3;break;
	
	}
	return b;
}


//int转char
char change_int_char(int a)
{
	char b = 0;
	if(a==0)
		b='A';
	else if(a==1)
		b='T';
	else if(a==2)
		b='C';
	else if(a==3)
		b='G';
	return b;
}

//创建基因指向
void  cont(int *a,HASH head,int j)
{
	int i=0;
	HASH node=NULL;
	HASH p= head;
	for(i=1;i<4;i++)
	{
		node = malloc(sizeof(Hash));
		if(node == NULL)
		{
			printf("malloc failed\n");
			return ;
		}
		node->data = a[i];//存入数值
		node->set  = j;//存入位置
		node->A = NULL;//指向空 
		node->T = NULL;//指向空 
		node->G = NULL;//指向空 
		node->C = NULL;//指向空 
		switch(a[i])
		{
			case 0:
					if(p->A!=NULL)
					{
						p=p->A;
					}
					else
					{
						p->A=node;
						p=node;
					}
					p->cnt++;
					break;
			case 1:
					if(p->T!=NULL)
					{
						p=p->T;
					}
					else
					{
						p->T=node;
						p=node;
					}
					p->cnt++;
					break;
			case 2:	
					if(p->G!=NULL)
					{
						p=p->G;
					}
					else
					{
						p->G=node;
						p=node;
					}
					p->cnt++;
					break;
			case 3:
					if(p->C!=NULL)
					{
						p=p->C;
					}
					else
					{
						p->C=node;
						p=node;
					}
					p->cnt++;
					break;
		}
	}
	
	
}

//创建哈希表
HASH * create_hash(int **arr)
{
	HASH * h = calloc(4, sizeof(HASH));
	
	int i,j,k,m;
	for(i=0;i<4;i++)
	{
		h[i] = malloc(sizeof(Hash));
		h[i]->A=NULL;
		h[i]->T=NULL;
		h[i]->C=NULL;
		h[i]->G=NULL;
	}
	HASH node = NULL;
	
	char key;
	
	for(i=0;i<NUM;i++)
	{
		m=1;
		k=arr[i][0];
		cont(arr[i],h[k],i);
	}
	printf("OK\n");
	
	return h;
}


//显示函数
void show(int i,int j,int m,int n,HASH h)
{
	char *data = malloc(sizeof(char )*5);
	data[0]=change_int_char(i);
	data[1]=change_int_char(j);
	data[2]=change_int_char(m);
	data[3]=change_int_char(n);
	HASH p=h;
	if(p==NULL)
		return;
	p=ponit_1(p,j);
	if(p==NULL)
		return;
	p=ponit_1(p,m);
	if(p==NULL)
		return;
	p=ponit_1(p,n);
	if(p==NULL)
		return;
	printf("[%s] 出现%d次\n",data,p->cnt);
}

//使用i判断h所需要的指向
HASH ponit_1(HASH h,int i)
{
	switch(i)
	{
		case 0:
			return h->A;break;
		case 1:
			return h->T;break;
		case 2:
			return h->G;break;
		case 3:
			return h->C;break;
	}
	return NULL;
}

int main()
{
	srand(time(NULL));
	int i=0,j=0,m=0,n=0;
	int **arr=get_arr();
	
	HASH *h = create_hash(arr);	
	for(i=0;i<4;i++)	
	{
		for(j=0;j<4;j++)
		{
			for(m=0;m<4;m++)
			{
				for(n=0;n<4;n++)
				{
						show(i,j,m,n,h[i]);
				}
			}
		}
	}
	
	return 0;
}
















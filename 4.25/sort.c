#include <stdio.h>

void swap(int *a,int *b)
{
	int p=*a;
	*a=*b;
	*b=p;
}

void mao(int *a,int len)
{
	int i=0,j=0,k=0;
	for(i=0;i<len-1;i++)
	{
		for(j=0;j<len-k-1;j++)
		{
			if(a[j]>a[j+1])
			{
				swap(&a[j+1],&a[j]);
			}
		}
		k++;
	}

}

void charu(int *a , int len )
{
	int i=0,j=0;
	for(i;i<len-1;i++)
	{
		for(j=i+1;j>0;j--)
		{
			if(a[j-1]>a[j])
			{
				swap(&a[j],&a[j-1]);
			}
		}
	}
}

void xuanze(int *a,int len)
{
	int i=0,j=0,k=0;
	int *p=NULL;
	for(i=0;i<len-1;i++)
	{
		p=&a[0];
		for(j=0;j<len-i;j++)
		{
			if(*p<a[j])
			{
				p=&a[j];
			}
		}
		k=*p;
		*p=a[len-i-1];
		a[len-i-1]=k;
	}

}

void kuaipai(int *a,int i,int j)
{
	if(i>=j)
	{
		return ;
	}
	int key=a[i];
	int letf=i;
	int right=j;
	
	while(letf<right)
	{
		while(a[right]>key&&letf<right)
			right--;
			a[letf]=a[right];
		while(a[letf]<key&&letf<right)
			letf++;
			a[right]=a[letf];

	}
	a[letf]=key;
	
	
	
	kuaipai(a,i,letf-1);
	kuaipai(a,right+1,j);
	
}

void show(int *a,int len)
{
	for(int i=0;i<len;i++)
	{
		printf("-%d-",a[i]);
	}
	printf("\n");
}

int main()
{
	int ll=1;int qq=2;
	int a[10]={7,1,5,6,8,9,3,0,4,2};
	int b[10]={7,1,5,6,8,9,3,0,4,2};
	int c[10]={7,1,5,6,8,9,3,0,4,2};
	int d[10]={7,1,5,6,8,9,3,0,4,2};
	show(a,10);
	mao(a,10);
	show(a,10);
	charu(b,10);
	show(b,10);
	xuanze(c,10);
	show(c,10);
	kuaipai(d,0,9);
	show(d,10);

	
	return 0;
}
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

void change(int *a,int *b)
{
	int p=*a;
	*a=*b;
	*b=p;
}

void maopao(int *a,int len)
{
	int i=0,j=0,k=0;
	for(i=0;i<len-1;i++)
	{
		for(j=0;j<len-1-k;j++)
		{
			if(a[j]>a[j+1])
			{
				change(&a[j],&a[j+1]);
			}
		}
		k++;
	}
}

void xuanze(int *a,int len)
{
	int i=0,j=0;
	int *p=NULL;
	for(i=0;i<len;i++)
	{
		p=&a[0];
		for(j=0;j<len-i;j++)
		{
			if(*p<a[j])
			{
				p=&a[j];
			}
		}
		change(p,&a[len-i-1]);
	}
}

void charu(int *a,int len)
{
	int i=0,j=0;
	for(i=0;i<len-1;i++)
	{
		for(j=i+1;j>0;j--)
		{
			if(a[j-1]>a[j])
			{
				change(&a[j-1],&a[j]);
			}
		}
	}
}

void guibing(int *a , int l ,int m,int r)
{
	int i,j,k;
	int left_size=m-l;
	int right_size=r-m+1;
	int left[left_size];
	int right[right_size];
	for(i=l;i<m;i++)
	{
		left[i-l]=a[i];
	}
	for(i=m;i<=r;i++)
	{
		right[i-m]=a[i];
	}
	i=0;j=0;k=l;
	while(i<left_size&&j<right_size)
	{
		if(left[i]<right[j])
		{
			a[k]=left[i];
			k++;
			i++;
		}
		else
		{
			a[k]=right[j];
			k++;
			j++;
		}
	}
	while(i<left_size)
	{
		a[k]=left[i];
		k++;
		i++;
	}
	while(j<right_size)
	{
		a[k]=right[j];
		k++;
		j++;
	}
}

void guibingsort(int *a , int l,int r)
{
	if(r==l)
	{
		return ;
	}
	int m=(l+r)/2;
	guibingsort(a,l,m);
	guibingsort(a,m+1,r);
	guibing(a,l,m+1,r);

}

void kuaisu(int *a,int low,int high)
{
	int *a=&a[low];
	int *b=&a[high];
	int key = *b;
	while()
	
	
	
	
	
	
	
}





void show(int *a,int len)
{
	for(int i=0;i<len ;i++)
	{
		printf("-%d-",a[i]);
	}
	printf("\n");
}


int main()
{
	int a[10]={7,9,5,2,4,3,1,6,0,8};
	show(a,10);
	//xuanze(a,10);
	//charu(a,10);
	//maopao(a,10);
	//guibingsort(a,0,9);

	show(a,10);
}



















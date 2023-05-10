#include <stdio.h>

void show(int *arr,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("-%d-",arr[i]);
	printf("\n");
}

//arr是数列首地址，n表示元素个数
void guibing_sort(int *arr,int n)
{
	//当需要排序的数列小于等于1个元素时,就不需要再递归下去
	if(n<=1)
		return ;
	
	int len = n/2;
	
	guibing_sort(arr,len);  //元素  arr[0]~ arr[len-1];
	guibing_sort(arr+len,n-len); //元素   arr[len] ~  arr[n-1];
	
	//当递归函数结束后，有两个有序数列:  arr     arr+len;
	//定义两个指针指向两个有序数列
	int *a = arr;
	int *b = arr+len;
	
	//定义缓冲区，用来保存合并后的有序数列
	int k[n];
	int i=0;//表示数组a的下标
	int j=0;//表示数组b的下标
	
	//合并两个有序数列
	//因为两个有序数列都是从小到大排序，那么可以从第1个数值开始存入
	while(i<len && j<n-len)
	{
		if( a[i] < b[j])
		{
			k[i+j] = a[i];
			i++;
		}
		else if( a[i] > b[j])
		{
			k[i+j] = b[j];
			j++;
		}
	}
	
	//如果b序列已经存入完毕，那么此时i!=len-1
	while(i<len)
	{
		k[i+j] = a[i];
		i++;
	}
	
	//如果a序列已经存入完毕，那么此时j!=n-len
	while(j<n-len)
	{
		k[i+j] = b[j];
		j++;
	}
	
	//最后得到的k缓冲区中的就是有序数列，把他们放回到arr中
	for(i=0;i<n;i++)
		arr[i] = k[i];
	
	//打印排序完毕的序列
	show(arr,n);
}



int main()
{
	int arr[10] = {5,6,4,9,7,3,8,1,2,0};
	guibing_sort(arr,10);
	
	show(arr,10);
}
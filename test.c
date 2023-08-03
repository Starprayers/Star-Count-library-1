#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int arr[] = { 1,2,7,7,7,7,7,7,7,7 };
//int arr[] = { 1,2,3,4,5,6,7,8,9,10 };

int rt = 0;//数组元素下标位
int i = 0;
int n = 0;

int main()
{
	int c = 0;//用于截取Basic()函数中数组读取的个数
	scanf("%d", &n);
	i= Basic(rt);
	printf("test:%d\n",i);

	int optimize_left = Optimize_left(i);
	printf("test_left:%d\n",optimize_left);

	c = i;//防止i变化，从而影响下面i变量发生变化，起到固定作用

	int optimize_right = Optimize_right(i);
	printf("test_right:%d\n", optimize_right);

	int sum = optimize_left + optimize_right+c;

	printf("共存在：%d", sum);
	printf("位\n");
}
int Basic(mid)
{

	int sz = sizeof(arr) / sizeof(arr[0]);
	int left = 0;//左下标
	int right = sz - 1;//右下标
	int k = n;


	while (left <= right)
	{
		int mid = (right + left) / 2;//int整型直接取小数前部分，后部分直接省略
		if (arr[mid] > k)
		{
			right = mid - 1;
		}
		else if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else
		{
			printf("HAVE FOUND:%d\n", mid);
			rt = mid;
			return rt;
			break;
		}
	}
	if (left > right)
	{
		printf("NO FOUND\n");
		return 0;
	}
	//return 0;
}

int Optimize_left(i)
{
	int k = n;
	int q = 0;
	int JiShu1 = 0;
	//向左查询
	q = i;
	if (q != 0)
	{
		while (k == arr[i])
		{
			i = i - 1;
			if (k == arr[i])
			{
				printf("HAVE FOUND_left:%d\n", i);
				JiShu1 = JiShu1 + 1;
			}
			else
			{
				i++;//因while循环最终一次判断需在减一次
				if (q != i)
				{
					break;
				}
				else
				{
					printf("左边暂无数据\n");
					break;
				}
			}
		}
		return JiShu1;
	}
	else
	{
		return 0;
	}
}

int Optimize_right(i)
{
	int k = n;
	int q = 0;
	int JiShu2 = 0;
	//向右查询
	q = i;
	if (q != 0)
	{
		while (k == arr[i])
		{
			i = i + 1;
			if (k == arr[i])
			{
				printf("HAVE FOUND_right:%d\n", i);
				JiShu2 = JiShu2 + 1;
			}
			else
			{
				i--;//因while循环最终一次判断需在加一次
				if (q != i)
				{
					break;
				}
				else
				{
					printf("右边暂无数据\n");
					break;
				}
			}
		}
		return JiShu2;
	}
	else
	{
		return 0;
	}
}

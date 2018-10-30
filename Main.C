#include <stdio.h>
#include <math.h>
//递归
int df(int num,int num2)
{
	if (!num)//0
		return num2;
	return df( num/10,num2*10+num%10);
}//迭代
int diedai(int num)
{
	int ncount = 0;
	int num2 = num;
	int tem=0;
	while (num2)
	{
		ncount++;
		num2 /= 10;
	}
	while (ncount)
	{
		tem += pow(10, ncount-1) * (num % 10);
		num /= 10;
		ncount--;
	}
	return tem;
}

void swap(int *p1, int *p2)
{
	if (*p1 == *p2)
		return;
	*p1 = *p1^*p2;
	*p2 = *p1^*p2;
	*p1 = *p1^*p2;
}
void quickSort(int *arrp,int start,int end)
{
	int t = 0;
	int k = 1;
	int u = 0;
	if ((end - start + 1) <= 1)
		return;
	for (k=1; k<end; k++)
	{
		if (arrp[k - 1] > arrp[end - 1])
		{
			for (t = k + 1; t < end; t++)
			{
				if (arrp[t - 1] < arrp[end - 1])
				{
					u++;
					swap(&arrp[t-1], &arrp[k - 1]);
					break;
				}
			}
		}
		else
		{
			u++;
		}
	}
	swap(&arrp[u+1-1], &arrp[end-1]);
	quickSort(arrp, 1, u);
	quickSort(arrp, u+1+2, end);

}
int main()
{
	int arr[] = { 7,6,5,4,3,2,1};//2 1 4 3 
	int a1 = 1, a2 = 2;
	quickSort(arr, 1, 7);
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"



void PrintArray(int * a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);

	}
	printf("\n");
}

void InsertSort(int * a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}

}


void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = (gap / 3 + 1);
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}
void Swap(int* p1,int * p2)

{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void SelectSort(int * a, int n)
{
	int left = 0, right = n - 1;
	while (left < right)
	{
		int minIndex = left, maxIndex = right;
		for (int i = left; i < right; i++)
		{
			if (a[i] < a[minIndex])
				minIndex = i;
			if (a[i] > a[maxIndex])
				maxIndex = i;
		}
		Swap(&a[left], &a[minIndex]);
		if (left == maxIndex)
		{
			maxIndex = minIndex;
		}
		Swap(&a[right], &a[maxIndex]);
		++left;
		++right;
	}
}

void AdjustDwon(int * a, int n, int root)
{
	int child = root * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}
		if (a[child] > a[root])
		{
			Swap(&a[child], &a[root]);
			root = child;
			child = root * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int * a, int n)
{
	//建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		--end;
	}
}


void BubbleSort(int * a, int n)
{
	////one
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 1; j < n - i; j++)
	//	{
	//		if (a[j - 1]>a[j])
	//			Swap(&a[j - 1], &a[j]);
	//	}
	//}
	//two
	for (int end = n; end > 0; end--)
	{
		int exchange = 0;
		for (int i = 1; i < end; i++)
		{
			if (a[i - 1]>a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}
		if (exchange == 0)
		{
			break;
		}
	}
}



//三数取中，可以优化有序数列的情况。但当其元素都相等的时候，就无法进行优化。
int GetMidIndex(int *a, int left, int right)
{
	int mid = (left + right) >> 1;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left]>a[right])
		{
			return left;
		}
		else
		{
			return right;
		}

	}
	else
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}
int PartSort1(int * a, int left, int right)
{
	int minIndex = GetMidIndex(a, left, right);
	Swap(&a[left], &a[minIndex]);
	int keyi = left;
	while (left < right)
	{
		//找小
		while (left < right&&a[right] >= a[keyi])
			--right;
		//找大
		while (left < right&& a[left] <= a[keyi])
			++left;
		Swap(&a[right], &a[left]);
	}
	Swap(&a[keyi], &a[left]);
	return left;
}

int PartSort2(int * a, int left, int right)
{
	int key = a[left];
	while (left < right)
	{
		//找小
		while (left < right && a[right] >= key)
		{
			--right;
		}
		//放到左边的坑位，右边形成新的坑位。
		a[left] = a[right];
		while (left < right && a[left] <= key);
		{
			++left;
		}
		a[right] = a[left];
	}
	a[left] = key;
	return left;
}
int PartSort3(int * a, int left, int right)
{
	//int keyi =left, prev = left, cur = prev + 1;
	//while (cur <= right)
	//{
	//	//if (cur > right)
	//	//	break;
	//	//while (cur<right && a[cur] >= a[keyi])//找小
	//	//{
	//	//	++cur;
	//	//}
	//	if (a[cur] < a[keyi] && ++prev != cur)
	//	{
	//		Swap(&a[cur], &a[prev]);
	//	}
	//	++cur;	
	//}
	//Swap(&a[prev], &a[keyi]);
	//return prev;
	int keyi = left;
	int prev = left, cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		++cur;
	}

	Swap(&a[keyi], &a[prev]);

	return prev;






}

void QuickSort(int * a, int begin, int end)
{
	if (begin >= end)
		return;
	//如果子区间数据较多，继续选择key单趟，分割子区间分治递归
	//如果这个子区间数据较少，不再去分治。
	if (end - begin > 20)
	{
		int keyi = PartSort3(a, begin, end);
		QuickSort(a, begin, keyi - 1);
		QuickSort(a, keyi + 1, end);
	}
	else
	{
		HeapSort(a + begin, end - begin + 1);

	}
	//int keyi = PartSort(a, begin, end);
	//QuickSort(a, begin, keyi - 1);
	//QuickSort(a, keyi + 1, end);
}
#include "stack.h"

void QuickSortNonR(int * a, int begin, int end)
{
	Stack st;
	StackInit(&st,100);
	StackPush(&st, begin);
	StackPush(&st, end);
	
	while (!StackEmpty(&st))
	{
		int left, right;
		right = StackTop(&st);
		StackPop(&st);

		left = StackTop(&st);
		StackPop(&st);

		int keyi = PartSort1(a, left, right);
		if (left < keyi - 1)
		{
			StackPush(&st, left);
			StackPush(&st, keyi - 1);

		}
		if (keyi + 1 < right)
		{
			StackPush(&st, keyi + 1);
			StackPush(&st, right);
		}
	}

	StackDestory(&st);


}


void _MergeSort(int * a, int left, int right, int * tmp)
{
	if (left >= right)
		return;
	int mid = (left + right) >> 1;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = left;

	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[i++] = a[begin1++];
		else
			tmp[i++] = a[begin2++];
	}
	for (int j = left; j <= right; ++j)
	{
		a[j] = tmp[j];
	}
}

void MergeSort(int * a, int n)
{
	int * tmp = (int *)malloc(sizeof(int)*n);
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}


//void Merge(int* a, int begin, int mid, int end, int * tmp)
//{
//	int begin1 = begin;
//	int end1 = mid;
//	int begin2 = end1 + 1;
//	int end2 = end;
//	int i = begin;
//	while (begin1 <= end1 && begin2 <= end2)
//	{
//		if (a[begin1] <= a[begin2])
//			tmp[i++] = a[begin1++];
//		else
//			tmp[i++] = a[begin2++];
//	}
//	//判断是否有未合并的元素
//	if (begin1 < end1)
//	{
//		memcpy(tmp + i, a + begin1, sizeof(int)*(end1 - begin1 + 1));
//	}
//	if (begin2 < end2)
//	{
//		memcpy(tmp + i, a + begin2, sizeof(int)*(end2 - begin2 + 1));
//	}
//
//	//合并后拷贝到原数组中
//	memcpy(a + begin, tmp + begin, sizeof(int)*(end - begin) + 1);
//
//}

void _Merge(int* a, int* tmp, int begin1, int begin2, int end1, int end2)
{
	int i = begin1;
	int j = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[i++] = a[begin1++];
		else
			tmp[i++] = a[begin2++];

	}
	while (begin1 <= end1)
		tmp[i++] = a[begin1++];
	while (begin2 <= end2)
		tmp[i++] = a[begin2++];

	for (; j <= end2; ++j)
		a[j] = tmp[j];
}

void MergeSortNonR(int * a, int n)
{

	int * tmp = (int *)malloc(sizeof(int)*n);
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	int step = 1;
	while (step < n)
	{
		for (int i = 0; i < n; i += 2 * step)
		{
			/*int begin = i;
			int mid = i + step - 1;
			if (mid >= n - 1)
				continue;
			int end = i + 2 * step - 1;
			if (end >= n)
				end = n - 1;
			Merge(a, begin, mid, end, tmp);*/
			int begin1 = i, end1 = i + step - 1, begin2 = i + step, end2 = i + 2 * step - 1;
			//如果第二个小区间不存在，就不需要归并了，结束本次循环
			if (begin2 >= n)
				break;

			//如果第二个小区间存在，但是第二个小区间不够gap个，结束位置越界了，需要修正一下
			if (end2 >= n)
				end2 = n - 1;
			_Merge(a, tmp, begin1, begin2, end1, end2);
		}
		step *= 2;
	}
	free(tmp);
}


//int * CountSort(int* a, int n,int max)
//{
//	int index = 0;
//	int * tmpArr = (int*)malloc(max*sizeof(int));
//	int * result = (int*)malloc(max*sizeof(int));
//	for (int k = 0; k < max; k++)
//	{
//		tmpArr[k] = 0;
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		tmpArr[a[i]]++;
//	}
//	
//	for (int j = 0; j < max; j++)
//	{
//		while (tmpArr[j])
//		{
//			result[index++] = j;
//			tmpArr[j]--;
//		}
//	}
//	free(tmpArr);
//	tmpArr = NULL;
//	return result;
//}


void CountSort(int* a, int n)
{
	int max = a[0], min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i]>max)
			max = a[i];
		if (a[i < min])
			min = a[i];
	}
	int range = max - min + 1;
	int * count = (int*)malloc(sizeof(int)*range);
	memset(count, 0, sizeof(int)*range);
	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}
	int i = 0;
	for (int j = 0; j < range; ++j)
	{
		while (count[j]--)
		{
			a[i++] = j + min;
		}
	}
	free(count);
}
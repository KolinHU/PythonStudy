// 各类排序代码（C++）
//

#include "stdafx.h"
#include<iostream> 
#include <vector>

using  namespace std;


void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

//快速排序

int partition(vector<int> &vi, int low, int up)
{
	int pivot = vi[up];
	int i = low - 1;
	for (int j = low; j < up; j++)
	{
		if (vi[j] <= pivot)
		{
			i++;
			swap(vi[i], vi[j]);
		}
	}
	swap(vi[i + 1], vi[up]);
	return i + 1;
}

void quickSort(vector<int> &vi, int low, int up)
{
	if (low < up)
	{
		int mid = partition(vi, low, up);
		quickSort(vi, low, mid - 1);
		quickSort(vi, mid + 1, up);
	}
}

//冒泡排序
void BubbleSort(vector<int> &vi)
{
	for (int i = 0; i < vi.size() ; i++)
	{
		for (int j = 1; j < vi.size() - i; j++)
		{
			if (vi[j] < vi[j - 1])
			{
				swap(vi[j], vi[j - 1]);
			}
		}
	}
}

// 冒泡排序（改进版）
void BubbleSort(vector<int> &vi)
{
	int lastExchangeIndex=0; //记录最后一次交换的位置

    int sortBorder=vi.size()-1; //无序数列的边界，边界后的元素以及排好序，无需比较

	for (int i = 0; i < vi.size() ; i++)
	{
		bool isSorted=true; //默认有序排列

		for (int j = 0; j < sortBorder; j++)
		{
			if (vi[j] < vi[j + 1])
			{
				swap(vi[j], vi[j + 1]);
				isSorted=false;//产生元素交换，不是有序排列
				lastExchangeIndex=j; //把无序数列的边界更新为最后一次交换元素的位置
			}
		}

		sortBorder=lastExchangeIndex;

		if(isSorted)
		{
			break;
		}
	}
}


//鸡尾酒排序（双向冒泡排序）
void CockTailSort(vector<int> &vi)
{
	int isSorted=false;
	//双向同时进行
	for(int i=0;i<vi.size()/2;i++)
	{
		isSorted=false;
		//升序排列
		for(int j=i;j<vi.size()-i-1;j++)
		{
			if(vi[j]>vi[j+1])
			{
				swap(vi[j], vi[j + 1]);
				isSorted=true;
			}
		}

		//降序排列
		for(int j=vi.size()-i-1;j>i;j--)
		{
			if(vi[j] < vi[j-1])
			{
				swap(vi[j], vi[j - 1]);
				isSorted=true;
			}
		}
        //中间排序结果输出
        for (auto x : vi)
			cout << x << " ";
		cout << endl;

		if(isSorted==false)
		{
			break;
		}
	}


}


//直接插入排序

void InsertSort(vector<int> &vi)
{
	for(int i=1;i<vi.size();i++) 
	{
		int temp=vi[i];
		int j;
		for(j=i-1;j>=0&&temp<vi[j];j--)
		{
			vi[j+1]=vi[j]；     //将较大元素后移
		}

		vi[j+1]=temp;        //temp插入正确的位置

	}
}

// 二分插入排序

void BinInsertSort(vector<int> &vi)
{
	for(int i=1;i<vi.size();i++)
	{
		int left=0;
		int right=i-1;
		int temp=vi[i]
		while(left<=right)
		{
			int mid=(left+right)/2; //二分区域
			if(vi[mid]>temp)
			{
				right=mid-1;       //向左缩小区域
			}
			else
			{
				left=mid+1;        //向右缩小区域
			}
		
		}

		for(int j=i-1;j>left;j--)  //vi[left,i-1]的元素整体后移
		{
			vi[j+1]=vi[j];
		}
		vi[left]=temp;
	}
}


//希尔排序

void ShellSort(vector<int> &vi)
{
	int j, gap;
	for(gap=vi.size()/2;gap>0;gap/=2)
	{
		for(j=gap;j<vi.size();j++)
		{
			if(vi[j]<vi[j-gap]) //组内元素进行直接插入排序
			{
				int temp=vi[j];
				int k=j-gap;
				while(k>=0 && vi[k]>temp)
				{
					vi[k+gap]=vi[k];
					k-=gap;
				}
				vi[k+gap]=temp;
			}
		}
	}
}


//选择排序
void SelectSort(vector<int> &a)
{
	for (int i = 0; i<a.size(); i++)
	{
		int min = a[i];

		for (int j = i + 1; j<a.size(); j++)
		{
			if (min>a[j])
			{
				swap(min, a[j]);
			}
		}
		a[i] = min;

		for (auto x : a)
			cout << x << " ";
		cout << endl;
	}
}

// 堆排序

void HeapAdjust(vector<int> &a, int i, int len)
{
	int left, right, j;
	while ((left = 2 * i + 1) <= len) //判断当前父节点有无左节点（有无孩子节点）
	{
		right = left + 1;          //右节点
		j = left;
		if (j<len && a[left]<a[right])
		{
			j++;
		}
		if (a[i]<a[j])
		{
			swap(a[i], a[j]);
		}
		else
		{
			break;     //父节点比孩子节点都大
		}
		i = j;           //交换位置后，对子节点继续进行判断
	}
}

void HeapSort(vector<int> &a)
{
	int len = a.size() - 1;
	for (int i = len / 2 - 1; i >= 0; i--) //构造堆
	{
		HeapAdjust(a, i, len);

		//中间排序过程输出
		for (auto x : a)
			cout << x << " ";
		cout << endl;
	}
	cout<<"堆构造完成！"<< endl;
	//堆排序
	while (len >= 0)
	{
		swap(a[0], a[len--]);  //首尾元素交换，长度减一，尾部元素最大
	    HeapAdjust(a, 0, len);

		//中间排序过程输出
		for (auto x : a)
			cout << x << " ";
		cout << endl;
	}
}


// 并归排序
void Merge(vector<int> &a, int left, int mid, int right)
{

	int len1 = mid - left + 1;
	int len2 = right - mid;

	int *l1 = new int[len1];
	int *l2 = new int[len2];

	for (int i = 0; i<len1; ++i)
	{
		l1[i] = a[left + i];
	}
	for (int j = 0; j<len2; ++j)
	{
		l2[j] = a[j + mid + 1];
	}

	//比较两个序列
	int i = 0, j = 0;
	while (i<len1 && j<len2)
	{
		if (l1[i]<l2[j])
		{
			a[left++] = l1[i++];
		}
		else
		{
			a[left++] = l2[j++];
		}
	}

	//两序列剩余部分分别放于尾部
	while (i<len1)
	{
		a[left++] = l1[i++];
	}
	while (j<len2)
	{
		a[left++] = l2[j++];
	}

	delete[]l1;
	delete[]l2;

}

void  MergeSort(vector<int> &a, int left, int right)
{
	if (left<right)
	{
		int mid = (left + right) / 2;  //分区
		MergeSort(a, left, mid);
		MergeSort(a, mid + 1, right);
		Merge(a, left, mid, right);  //合并

        //排序过程输出
		for (auto x : a)
			cout << x << " ";
		cout << endl;
	}
}


// 计数排序
void CountSort(vector<int> &a)
{
	int min = a[0];
	int max = a[0];

	for (int i = 0; i<a.size(); i++)
	{
		if (a[i]<min)
		{
			min = a[i];
			continue;
		}
		if (a[i]>max)
		{
			max = a[i];
		}
	}

	vector<int> B(a.size());
	vector<int> C(max - min +1);

	for (int i = 0; i<a.size(); i++)
	{
		C[a[i] - min]++;
	}

	//原版计数排序
    for(int index = 1; index < C.size(); index++)
	{
		C[index] = C[index] + C[index - 1];
	}
	for(int index = a.size() - 1; index > -1; index--)
	{
		B[C[a[index] - min] - 1] = a[index];
		C[a[index] - min]--;
	}
    for(int index = 0; index < a.size(); index++)
	{
		a[index] = B[index];
	}

	//空间优化版计数排序

	int n = 0;
	for (int i = 0; i<C.size(); i++)
	{
		for (int count = 0; count<C[i]; count++)
		{
			a[n++] = i + min;
		}
	}
}

// 基数排序

int getMax(vector<int> &a, int n)
{
	int max = a[0];
	for (int i = 0; i<n; i++)
	{
		if (a[i]>max)
		{
			max = a[i];
		}
	}
	return max;
}

//   按位数对数组a进行排序
void countSort(vector<int> &a, int n, int exp)
{
	int *output=new int[n];
	int i, buckets[10] = { 0 };

	//将数据出现的次数存储在buckets[]中
	for (i = 0; i<n; i++)
	{
		buckets[(a[i] / exp) % 10]++;
	}
	//更改buckets[i]。目的是让更改后的buckets[i]的值，是该数据在output[]中的位置。
	for (i = 1; i<10; i++)
	{
		buckets[i] += buckets[i - 1];
	}
	// 将数据存储到临时数组output[]中
	for (i = n - 1; i >= 0; i--)
	{
		output[buckets[(a[i] / exp) % 10] - 1] = a[i];
		buckets[(a[i] / exp) % 10]--;
	}

	// 将排序好的数据赋值给a[]
	for (i = 0; i < n; i++)
	{
		a[i] = output[i];
	}

	//中间结果输出
	for (auto x : a)
		cout << x << " ";
	cout << endl;
}

void RadixSort(vector<int> &a, int n)
{
	int exp;      //指数位
	int max = getMax(a, n);  //获取最大值

							 // 从个位开始，对数组a按"指数"进行排序
	for (exp = 1; max / exp>0; exp *= 10)
	{
		countSort(a, n, exp);
	}
}

//桶排序

void BucketSort(vector<int> &a,int n)
{
	double **p=new  double*[10];  //十个指针，代表十个桶
	for(int i=0;i<10;i++)
	{
		p[i]=new double[100];   //每个桶包含100个元素
	}
	int count[10]={0}; 
	for(int i=0;i<n;i++)
	{
		double temp=a[i];
		p[flag][count[flag]]=temp;  //将元素放入对应桶中
		
		int j=count[flag]++;       //对应桶计数加1

		//在桶内进行排序（插入排序）
		for(;j>0 && temp<p[flag][j-1];j--)
		{
			p[flag][j]=p[flag][j-1];
		}
		p[flag][j]=temp;
	}

	//将全部元素在桶内进行排序后，进行重新连接
	int k=0;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<count[i];j++)
		{
			a[k++]=p[i][j];
		}
	}

	//释放内存
	for(int i=0;i<10;i++)
	{
		delete p[i];
		p[i]=Null;
	}
	delete []p;
	p=Null;
}


int main()
{
	int a[] = { 3,5,7,9,2,3,1,0,7,5,4 };
	vector<int> va(a, a + 11);

	cout << "Before quicksort:\n";
	for (auto x : va)
		cout << x << " ";
	cout << endl;

	//quickSort(va,0,va.size()-1);
	HeapSort(va);

	cout << "After quicksort:\n";
	for (auto x : va)
		cout << x << " ";
	cout << endl;

	system("pause");
	return 0;
}





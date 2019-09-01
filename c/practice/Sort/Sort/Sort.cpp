// Sort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include <vector>

using  namespace std;



//快速排序

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

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


// 冒泡排序
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


//int main()
//{
//	int a[] = { 3,5,7,9,2,3,1,0,7,5,4 };
//	vector<int> va(a, a + 11);
//
//	cout << "Before quicksort:\n";
//	for (auto x : va)
//		cout << x << " ";
//	cout << endl;
//
//	//quickSort(va,0,va.size()-1);
//	BubbleSort(va);
//
//	cout << "After quicksort:\n";
//	for (auto x : va)
//		cout << x << " ";
//	cout << endl;
//
//
//
//	system("pause");
//	return 0;
//}



int modifyvalue()
{
	//return(x += 10);
	return 0;
}
int changevalue(int x)
{
	return(x += 1);
}
//void main()
//{
//	/*int x = 10;
//	x++;
//	changevalue(x);
//	x++;
//	modifyvalue();
//	printf("First output:%d \n", x);
//	x++;
//	changevalue(x);
//	printf("Second output:%d \n", x);
//	modifyvalue();
//	printf("Thirdoutput:%d \n", x);*/
//
//
//	char *ptr;
//	if ((ptr = (char *)malloc(0)) == NULL)
//		puts("Gota null pointer");
//	else
//		puts("Gota valid pointer");
//}



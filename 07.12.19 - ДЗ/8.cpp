//Напишите программу, находящую k - ую порядковую статистику.Программа должна работать за время O(n) в среднем.

#include <iostream>
using namespace std;

//Функция слияния массива

void merge(int* A, int first, int last)
{
	int middle, start, final, j;
	int* mas = new int[100];
	middle = (first + last) / 2;
	start = first;
	final = middle + 1;
	for (j = start; j <= last; j++)
		if ((first <= middle) && ((final > last) || (A[start] < A[final])))
		{
			mas[j] = A[start];
			start++;
		}
		else
		{
			mas[j] = A[final];
			final++;
		}
	for (j = first; j <= last; j++) A[j] = mas[j];
};

// Функция сортировки массива

void mergesort(int* arr, int start, int finish)
{
	{
		if (start < finish)
		{
			mergesort(arr, start, (start + finish) / 2);
			mergesort(arr, (start + finish) / 2 + 1, finish);
			merge(arr, start, finish);
		}
	}
};

int main() {
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	mergesort(arr, 1, n);
	int k;
	cin >> k;
	for (int i = 1; i <= n; i++) {
		if (i == k) cout << arr[k];
	}
	return 0;
}
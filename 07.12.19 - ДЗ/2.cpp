// Напишите программу на основе разделяй и властвуй позволяющую эффективно проверять принадлежность пары значений массиву.Например, пара(2, 3) принадлежит массиву[1, 2, 3, 5, 7, 11, 13, 17], а пара(3, 4) - нет.Можно считать, что количество запросов многократно превышает размер массива.В комментариях напишите, почему перебор - эффективное


#include <iostream>
using namespace std;

//Поиск элементов в массиве с помощью бинарного поиска:

int Bin_search(int *arr, int left, int right, int key) {
	int mid = 0;
	int search = -1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (key == arr[mid]) {
			search = mid;
			break;           
		}
		if (key < arr[mid]) {
			right = mid - 1;
		}
		else if (key > arr[mid]) {
			left = mid + 1;
		}
	}
	if (search == -1) return -1;
	else return search;
}

int main() {
	int n;
	cin >> n;
	int* arr;
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int a, b;
	cin >> a >> b;
	if (Bin_search(arr, 0, n, a) == -1 || Bin_search(arr, 0, n, b) == -1) {
		cout << "NO";
	}
	else cout << "YES";
	return 0;
}
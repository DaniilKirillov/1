//Напишите эффективную функцию, выписывающую из массива длины n все элементы, у которых количество двоек в троичной записи меньше k. Функция должна возвращать общее количество двоек в троичной записи всех чисел массива. В комментариях напишите, почему перебор - эффективный

#include <iostream>
using namespace std;

// Функция, вычисляющая кол-во двоек в записи числа
int amount(int n) {
	int s = 0;
	while (n / 3 != 0) {
		if (n % 3 == 2) {
			s = s + (n % 3);
		}
		n = n / 3;
	}
	if (n % 3 == 2) {
		s = s + 2;
	}
	return s / 2;
}

// Функция, выписывающая из массива все элементы и вычисляющая общее кол-во двоек в троичной записи
int tns(int n, int k, int *arr) {
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (amount(arr[i]) < k) cout << arr[i] << " ";
		sum = sum + amount(arr[i]);
	}
	return sum;
}

int main() {
	int n;
	int k;
	cin >> n;
	int* arr;
	arr = new int[n];
	cin >> k;
	tns(n, k, arr);
	return 0;
}
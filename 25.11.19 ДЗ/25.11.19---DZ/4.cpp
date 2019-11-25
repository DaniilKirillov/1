// Напишите эффективную процедуру, выписывающую из массива длины n все элементы, у которых произведение ненулевых цифр больше k. В комментариях напишите, почему перебор - эффективный

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, * arr, k;
	cin >> n;
	cin >> k;
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		int num = arr[i];
		int multipl = 1;
		while (num != 0) {
			if (num % 10 != 0) {
				multipl = multipl * (num % 10);
			}
			num = num / 10;
		}
		if (multipl > k) cout << arr[i] << " ";
	}
	return 0;
}
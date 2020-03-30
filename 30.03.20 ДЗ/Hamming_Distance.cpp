#include <iostream>
using namespace std;

int Hamming_Distance(const char*first, const char*second) 
{
	int count = 0;
	if (strlen(first) != strlen(second)) 
	{
		cout << "ERROR" << endl;
		return -1;
	}
	else for (int i = 0; i < strlen(first); i++) 
	{
		if (first[i] != second[i]) count++;
	}
	return count;
}

int main() {
	setlocale(LC_ALL, "ru");
	char first[1000] = {};
	char second[1000] = {};
	cout << "Enter first word:" << endl;
	cin >> first;
	cout << "Enter second word:" << endl;
	cin >> second;
	cout << "Расстояние Хэмминга:\t" << Hamming_Distance(first, second);
	return 0;
}
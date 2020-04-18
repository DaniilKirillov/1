#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int k, n;
	cout << "Введите кол-во буферов:\t"; cin >> k;
	cout << "Введите кол-во Байт:\t"; cin >> n;
	int size = k * n;
	char** arr = new char* [k];

	for (int i = 0; i < k; i++)
	{
		arr[i] = new char[n * 8];
	}

	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n * 8; j++)
		{
			arr[i][j] = char(rand() % 256);
		}
	}
	cout << endl;
	cout << "Ваши данные:\t" << endl;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n * 8; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
	char* sum = new char[n * 8];
	for (int i = 0; i < n * 8; i++)
	{
		for (int j = 0; j < k; j++)
		{
			sum[i] ^= arr[j][i];
		}
	}
	cout << endl;
	cout << "Контрольные суммы:" << endl;
	for (int i = 0; i < n * 8; i++)
	{
		cout << sum[i];
	}
	cout << endl << endl;

	int line;
	cout << "Введите номер строки, которую желаете удалить:\t";
	cin >> line;
	char** newarr = new char*[k];
	for (int i = 0; i < k; i++)
	{
		newarr[i] = new char[n * 8];
	}
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n * 8; j++)
		{
			if (i + 1 != line) newarr[i][j] = arr[i][j];
		}
	}

	cout << endl;
	cout << "Повреждённые данные:" << endl;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n * 8; j++)
		{
			cout << newarr[i][j];
		}
		cout << endl;
	}

	char* sum2 = new char[n * 8];
	for (int i = 0; i < n * 8; i++)
	{
		for (int j = 0; j < k; j++)
		{	
			if (j + 1 != line) sum2[i] ^= newarr[j][i];
		}
	}
	for (int i = 0; i < n * 8; i++)
	{
		newarr[line - 1][i] = sum2[i] ^ sum[i];
	}
	cout << endl << endl;

	cout << "Восстановление данных..." << endl;

	cout << endl;
	cout << "Восстановленные данные:" << endl;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n * 8; j++)
		{
			cout << newarr[i][j];
		}
		cout << endl;
	}
}
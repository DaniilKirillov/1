#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int LevensteinDistance(string &s1, string &s2, int costReplace, int costDelete, int costEnter)
{
	//Преобразование будет допускать, если "получаемая" строка больше данной.
	if (s1.size() > s2.size()) 
		return LevensteinDistance(s2, s1, costReplace, costDelete, costEnter);

	int min_size = s1.size();
	int max_size = s2.size();
	vector <int> lev_distance(min_size + 1);

	lev_distance[0] = 0;
	for (int i = 1; i <= min_size; i++)
	{
		lev_distance[i] = lev_distance[i - 1] + costDelete;
	}

    for (int j = 1; j <= max_size; ++j) 
    {
        int previous_diagonal = lev_distance[0], previous_diagonal_save;
        lev_distance[0] = lev_distance[0] + costEnter;

        for (int i = 1; i <= min_size; ++i) 
        {
            previous_diagonal_save = lev_distance[i];
            if (s1[i - 1] == s2[j - 1]) 
            {
                lev_distance[i] = previous_diagonal;
            }

            else 
            {
                lev_distance[i] = min(min(lev_distance[i - 1] + costDelete, lev_distance[i] + costEnter), previous_diagonal + costReplace);
            }
            previous_diagonal = previous_diagonal_save;
        }
    }

    return lev_distance[min_size];
}




int main()
{
    setlocale(LC_ALL, "ru");
    int costReplace;
    int costDelete;
    int costEnter;
    cout << "Введите цену вставки:\t"; cin >> costEnter; cout << endl;
    cout << "Введите цену удаления:\t"; cin >> costDelete; cout << endl;
    cout << "Введите цену замены:\t"; cin >> costReplace; cout << endl;

    string s1;
    string s2;
    cout << "Введите первую строку:\t" << endl; cin >> s1; cout << endl;
    cout << "Введите вторую строку:\t" << endl; cin >> s2; cout << endl;

    cout << LevensteinDistance(s1, s2, costReplace, costDelete, costEnter);
}
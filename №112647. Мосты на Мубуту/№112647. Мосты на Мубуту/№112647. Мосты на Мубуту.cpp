#include <iostream>
using namespace std;

int main()
{
	int single = 0, motley = 0;
	int n;
	cin >> n;
	string* isle = new string[n]; //массив для названий островов
	int** arr = new int* [n]; //массив для мостов

	for (int i = 0; i < n; ++i) {
		arr[i] = new int[n];
		for (int j = 0; j < n; ++j) cin >> arr[i][j];
	}

	for (int i = 0; i < n; i++) cin >> isle[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1) {
				if (isle[i] == isle[j]) {
					++single;
					arr[j][i] = 0;
				}
				else {
					++motley;
					arr[j][i] = 0;
				}

			}
		}
	}
	cout << single << " " << motley;
}

//0 1 1 1 0    у первого острова есть мост со вторым, третьим и четвертым
//1 0 1 0 1    у второго острова есть мост с первым, третьим и пятым
//1 1 0 1 0    у третьего острова есть мост с первым, вторым и четвертым
//1 0 1 0 1    у четвертого острова есть мост с первым, третим и пятым
//0 1 0 1 0    у пятого острова есть мост со вторым и четвертым 
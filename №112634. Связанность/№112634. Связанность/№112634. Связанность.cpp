#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<vector<int>> arr(N, vector<int>(N));
	vector<bool> check(N);
	check[0] = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> arr[i][j];
	}

	for (int x = 0; x < 2; x++) {
		for (int k = 0; k < N; k++) {
			for (int i = 0, j = k; i < N; i++) if (check[i] && arr[i][j]) check[i] = true; //для строк
			for (int i = k, j = 0; j < N; j++) if (check[i] && arr[i][j]) check[j] = true; //для столбцов
		}
	}

	for (int i = 0; i < N; i++)
		if (!check[i]) {
			cout << "NO";
			return 0;
		}
	cout << "YES";
}


#include <iostream>
#include <vector>
using namespace std;

void sort(vector<pair<int, int>>& mas) {
	int n = mas.size();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (mas[i].first < mas[j].first || (mas[i].first == mas[j].first && mas[i].second < mas[j].second))
				swap(mas[i], mas[j]);
}

int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> arr(n - 1);
	int** map = new int*[n];
	int* color = new int[n];
	for (int i = 0; i < n; i++) {
		if (i > 0) arr[i - 1] = make_pair(-1, -1);
		color[i] = i;
		map[i] = new int[n];
		for (int j = 0; j < n; j++) cin >> map[i][j];
	}

	int x, i_col, j_col;
	for (int k = 0; k < n - 1; k++) {
		x = INT32_MAX;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (map[i][j] != 0 && color[i] != color[j] && map[i][j] < x) {
					x = map[i][j];

					arr[k].first = i;
					arr[k].second = j;

					i_col = color[i];
					j_col = color[j];
				}
		if (arr[k].first > arr[k].second)
			swap(arr[k].first, arr[k].second);
		for (int i = 0; i < n; i++)
			if (color[i] == j_col) color[i] = i_col;
	}

	sort(arr);
	for (int i = 0; i < n - 1; i++)
		cout << arr[i].first + 1 << ' ' << arr[i].second + 1 << endl;
}
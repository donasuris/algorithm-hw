#include <iostream>
using namespace std;

int arr[9][9];
int way[9];
int best_way[9];
int n, k, best;
bool mas[9];

void cycles(int start, int cur, int hop) {
	if (hop == 1) {
		if (arr[cur][start] != 0) {
			way[k] = start;
			int prev = start, len = 0;
			for (int i = 1; i <= k; len += arr[prev][way[i]], prev = way[i], i++);
			if (len < best) {
				best = len;
				for (int i = 0; i <= k; i++)
					best_way[i] = way[i];
			}
		}
		return;
	}
	mas[cur] = true;
	for (int i = start + 1; i <= n; i++)
		if (!mas[i] && arr[cur][i] != 0) {
			way[k - hop + 1] = i;
			cycles(start, i, hop - 1);
		}
	mas[cur] = false;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	cin >> k;
	best = INT32_MAX;

	for (int i = 1; i <= n; i++) {
		way[0] = i;
		cycles(i, i, k);
	}

	if (best == INT32_MAX) 
		cout << 0 << endl;
	else {
		cout << best << endl;
		for (int i = 0; i <= k; i++)
			cout << best_way[i] << " ";
		cout << endl;
	}
}
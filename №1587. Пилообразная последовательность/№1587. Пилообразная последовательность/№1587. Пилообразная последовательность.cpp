#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> arr;
	int n, val;
	cin >> n;
	int del = 0;
	int cur = 0;
	for (int i = 0; i < n; i++) {
		cin >> val;
		arr.push_back(val);
		cur++;

		if (arr.size() > 2) {
			const int prev = arr.size() - 3;
			const int mid = arr.size() - 2;
			const int next = arr.size() - 1;

			if ((arr[prev] < arr[mid] and (arr[mid] > arr[next]))) continue;
			if ((arr[prev] > arr[mid]) and (arr[mid] < arr[next])) continue;
			arr.erase(arr.begin() + mid);
			del++;
			continue;
		}
	}

	if ((cur == n) and (arr.size() == 2) and (arr[0]) == arr[1]) {
		del++;
		cout << del;
		return 0;
	}

	if (n == 1) {
		cout << 0;
		return 0;
	}

	cout << del;
}

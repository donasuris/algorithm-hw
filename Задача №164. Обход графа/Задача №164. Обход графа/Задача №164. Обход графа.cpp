#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int k = 1;
	int n, s;
	cin >> n >> s;
	stack<int> mas;
	int** arr = new int* [n];
	for (int i = 0; i < n; ++i) {
		arr[i] = new int[n];
		for (int j = 0; j < n; ++j) cin >> arr[i][j];
	}

	--s;
	for (int i = 0; i < n; ++i) {
		if (arr[s][i] == 1) mas.push(i); //имеем стек [2, 1]
	}

	arr[s][s] = 1;
	while (!mas.empty()) {
		int s = mas.top();
		mas.pop();
		if (arr[s][s] != 1) {
			for (int i = 0; i < n; ++i) if (arr[s][i] == 1) mas.push(i);
			++k;
			arr[s][s] = 1;
		}
	}
	cout << k;
}

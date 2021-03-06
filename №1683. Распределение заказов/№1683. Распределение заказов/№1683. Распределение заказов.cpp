﻿#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector < vector <int>> g; //вектор в котором в каждой вершине хранится список куда мы можем пойти из неё g[i] где i номер вершины
vector <int> used; //посещенные 
map <int, int> par; //словарь (вектор пар(пары типа инт инт)) (ключ и значение) 

bool dfs(int v) {
	if (used[v]) return false; //если заходим в посещеную вершину то возвр
	used[v] = 1; //посетили
	for (int u : g[v]) { //перебор передаем u значение g[0], g[1], ... ,g[v] перебираем строчку вектора 
		if (par[u + 1] == 0 || dfs(par[u + 1] - 1)) { //если для такой вершины мы ещё не подобрали пару, если возвр 0, то не подобрали. u+1 чтобы 0 вершина стала 1 и чтоб 0 имел значение "не найдено" 
			par[u + 1] = v + 1; // если значение не найдено, то устанавливаем значение v+1
			return true; //
		}
	}
	return false;
}

//dfs(par[u + 1] - 1) проверяем может ли решать эту задачу кто-то другой, если не может то взрв false

int main()
{
	int n, s;
	cin >> n >> s; //s строк по n чисел
	g.resize(n + s); // резервируем память до s+n
	for (int i = 0; i < s; i++) { 
		for (int j = 0, now; j < n; j++) { 
			cin >> now; 
			if (now == 1) { //может ли i работник решить j задачу 
				g[i].push_back(s + j); 
				g[s + j].push_back(i); 
			}
		}
	}

	/*
	вход 1 1 1
		 1 1 1

		 получаем 
		 0 0 1 1 1 
		 0 0 1 1 1 первые s строк работники (есть ли путь из работника в задачу)
		 1 1 0 0 0 следующие s строк задачи (есть ли путь из задачи в работника) 
		 1 1 0 0 0 
		 1 1 0 0 0 
	*/

	for (int i = 0; i < n + s; i++) {
		used.clear(); //очищаем посещеные врешины 
		used.resize(n + s, 0); //
		dfs(i); //запускаем dfs для каждого i
	}

	int k = 0;
	for (auto _ : par) k += 1; //поочередно в _ присваем пару (задача работник) (работник задача) и считаем склько таких пар
	cout << k / 2;
}

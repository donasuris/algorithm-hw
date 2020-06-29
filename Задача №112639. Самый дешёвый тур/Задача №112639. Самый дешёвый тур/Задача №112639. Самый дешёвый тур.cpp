#include <iostream>
using namespace std;

int W[9][9]; //карта смежности тк n<=8
int way[9]; //путь тк n<=8
int bestWay[9]; //лучший путь тк n<=8
int N, K, best;//
bool Vizit[9];//посещена или нет тк n<=8

void fu(int start, int cur, int remains) {
	if (remains == 1) { //если остался один перелёт
		if (W[cur][start] != 0) { //если можем попасть в стартовую вершину
			way[K] = start; //way [i] это там где оказались после i перелетов, way[k] это где мы после k перелетов и она должна быть start по условию 
			int prev = start, len = 0;  //вершина из которой мы идем 
			for (int i = 1; i <= K; i++) { //
				len += W[prev][way[i]]; //длина увеличивается на расстояние откуда вылетели в куда 
				prev = way[i]; //смещаем вперед 
			}
			if (len < best) {  //если лен лучше бест (самый дешевый) 
				best = len;
				for (int i = 0; i <= K; i++) bestWay[i] = way[i]; //переписываем от way[0] из найденного way в best way
			}
		}
		return;
	}
	Vizit[cur] = true; // мы там уже были и туда не пойдем (без повторов) 
	for (int i = start + 1; i <= N; i++) { //оптимизация эмпирическим путём 
		if (!Vizit[i] && W[cur][i] != 0) { //если мы тут не были И существует дорога
			way[K - remains + 1] = i; //получаем индекс для way[k]
			fu(start, i, remains - 1); //повторяем её до пока remains == 1
		}
	}
	Vizit[cur] = false; //когда перебрали вершину обнуляем вершину тк её прошли 
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) //рудиментарое проявление предыдущего кода 
		for (int j = 1; j <= N; j++) cin >> W[i][j];

	cin >> K;
	best = INT32_MAX;

	for (int i = 1; i <= N; i++) {
		way[0] = i; // текущий путь, устанавливаем вершину из которой мы уходим и должны будем в неё вернуться 
		fu(i, i, K);  //номер вершины, с которой стартуем, номер в которой мы сейчас и сколько перелётов осталось сделать 
	}
	if (best == INT32_MAX) cout << 0 << '\n';

	else {
		cout << best << '\n';
		for (int i = 0; i <= K; i++) cout << bestWay[i] << ' ';
		cout << endl;
	}
	return 0;
}
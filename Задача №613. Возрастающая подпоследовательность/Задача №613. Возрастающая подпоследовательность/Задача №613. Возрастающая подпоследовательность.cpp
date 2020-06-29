#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void largest_ascending_sequence(deque<int> const& num, deque<int>& sub) {
	int size = num.size(); //передаваемое N
	deque<int> seq_lens(size, 1); //дек длинной N заполненный единицами 
	deque<int> prev_indexes(size); //
	int max_len = 1; //максимальная длина подпоследовательности на начальный момент
	int last_ind = 0;

	for (int i = 1; i < size; i++) { //пробегает от 1 до n
		for (int j = 0; j < i; j++) { //пробегает от 0 до i 
			if (num[j] < num[i] && seq_lens[j] + 1 > seq_lens[i]) { //является ли предыдущее меньшем следующего И проверяем какова длина длина будет если подставить числа ближе 1 2 0 3 (наиб 1 2 3)
				seq_lens[i] = seq_lens[j] + 1; //меняем педыдущую длину на новую
				prev_indexes[i] = j; // меняем данный индекс на новый найденный 
				if (seq_lens[i] > max_len) { //если нынешняя подпослед. оказалось самой длинной
					max_len = seq_lens[i]; //обновляем наиб длину
					last_ind = i; // и сохраняем индекс послед элемента, тк зная индекс последнего элемента мы можем восстановить всю послед
				}
			}
		}
	}
	// восстановляем 
	while (sub.size() < max_len) { //пока мы записали меньше чисел чем в самой найденой подпослед
		sub.push_front(num[last_ind]); //запихиваем в саб сами числа из намберс, пуш фрон пушто идем с конца
		last_ind = prev_indexes[last_ind]; //смещаем последний запомненный индекс элемента 
	}
}

int main()
{
	int N, X;
	deque<int> num;
	deque<int> sub;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> X;
		num.push_back(X);
	}
	
	largest_ascending_sequence(num, sub);
	cout << sub.size() << endl;

	for (int i = 0; i < sub.size(); i++) cout << sub[i] << " ";

	return 0;
}
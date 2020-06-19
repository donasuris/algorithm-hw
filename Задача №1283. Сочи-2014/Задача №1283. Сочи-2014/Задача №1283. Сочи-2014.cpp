#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const
int MAXN = 1000;
int MAXK = 1000;
double Eps = 1e-10;
double Infinity = 1E+10;

class TEvent {
public:
	double Time;
	int Object, Firm;
	TEvent(double time, int object, int firm) {
		Time = time;
		Object = object;
		Firm = firm;
	};
	void Print() {
		printf("%.20lf %d %d\n", Time, Object, Firm);
	}
};

bool operator < (const TEvent& a, const TEvent& b) {
	return (a.Time - b.Time < -Eps);
}

class TObject {
public:
	int Number;
	double S;
	TObject(int number, int s) {
		Number = number;
		S = s;
	}
};

bool operator < (const TObject& a, const TObject& b) {
	return (a.S - b.S > Eps);
}


class TFirm {
public:
	int Number;
	double V;
	TFirm(int number, double v) {
		Number = number;
		V = v;
	}
};

bool operator < (const TFirm& a, const TFirm& b) {
	return (a.V - b.V > Eps);
}

class TProblem {
public:
	int N, K;
	vector <TObject> Objects;
	vector <TFirm> Firms;
	vector <TEvent> Events;

	TProblem() {
		Answer = 0;
		ReadData();
		Normalization();
	}

	TProblem(const TProblem& problem) {
		Answer = 0;
		N = problem.N;
		K = problem.K;
		Objects = problem.Objects;
		Firms = problem.Firms;

	}

	void Solve(bool writeTime) {
		while (Objects.size() > 0) {
			double T = GetTimeForMove();
			MakeMove(T, !writeTime);
			Answer += T;
			Normalization();
			sort(Events.begin(), Events.end());
			for (int i = 0; i < Events.size(); ++i)
				Events[i].Print();
			Events.clear();

		}
		if (writeTime)
			printf("%.20lf\n", Answer);
	}

private:
	double Answer;

	void MakeMove(double time, double writeAnswer) {
		int groupI = 0;
		double groupV = Firms[0].V;

		for (int i = 1; i < N; ++i) {
			if (abs(Objects[i].S - Objects[i - 1].S) > Eps) {
				MakeMoveForGroup(groupI, i - 1, time, groupV / (i - groupI), writeAnswer);
				groupI = i;
				groupV = 0;
			}
			groupV += Firms[i].V;
		}

		MakeMoveForGroup(groupI, N - 1, time, groupV / (N - groupI), writeAnswer);
	}

	void MakeMoveForGroup(int i, int j, double time, double v, bool writeAnswer) {
		int count = j - i + 1;
		if (writeAnswer)
			for (int k = 0; k < count; ++k) {
				for (int l = i; l <= j; ++l)
					if (Firms[(l + k) <= j ? l + k : l + k - count].Number != 0)
						Events.push_back(*(new TEvent(Answer + k * time / count, Objects[l].Number, Firms[(l + k) <= j ? l + k : l + k - count].Number)));
			}
		for (int l = i; l <= j; ++l)
			Objects[l].S -= v * time;
	}

	double GetTimeForMove() {
		vector <double> GroupsS, GroupsV;
		vector <int> GroupsSize;

		GroupsS.push_back(0);
		GroupsV.push_back(0);
		GroupsSize.push_back(0);

		for (int i = 0; i < N; ++i) {
			if (i > 0 && abs(Objects[i - 1].S - Objects[i].S) > Eps) {
				GroupsS.push_back(0);
				GroupsV.push_back(0);
				GroupsSize.push_back(0);
			}
			GroupsS[GroupsS.size() - 1] += Objects[i].S;
			GroupsV[GroupsV.size() - 1] += Firms[i].V;
			GroupsSize[GroupsSize.size() - 1]++;
		}

		double T = Infinity;

		for (int i = 0; i < GroupsS.size(); ++i) {
			if (GroupsV[i] > Eps)
				T = min(T, GroupsS[i] / GroupsV[i]);
			if (i > 0) {
				double
					S1 = GroupsS[i] / GroupsSize[i],
					S2 = GroupsS[i - 1] / GroupsSize[i - 1],
					V1 = GroupsV[i] / GroupsSize[i],
					V2 = GroupsV[i - 1] / GroupsSize[i - 1];

				if (abs(V1 - V2) > Eps)
					T = min(T, (S1 - S2) / (V1 - V2));
			}
		}

		return T;

	}

	void ReadData() {
		cin >> N;

		for (int i = 0; i < N; ++i) {
			int s;
			cin >> s;
			Objects.push_back(*(new TObject(i + 1, s)));
		}
		cin >> K;
		for (int i = 0; i < K; ++i) {
			int v;
			cin >> v;
			Firms.push_back(*(new TFirm(i + 1, v)));
		}
	}
	void Sort() {
		sort(Objects.begin(), Objects.end());
		sort(Firms.begin(), Firms.end());
	}

	void Normalization() {
		Sort();
		while (Objects.size() > 0 && abs(Objects[Objects.size() - 1].S) < Eps)
			Objects.pop_back();

		N = Objects.size();
		for (int i = N; i < K; ++i)
			Firms.pop_back();
		for (int i = K; i < N; ++i)
			Firms.push_back(*(new TFirm(0, 0)));

		K = N;
	}
};


int main() {

	TProblem problem1;
	TProblem problem2(problem1);


	problem1.Solve(true);
	problem2.Solve(false);

	return 0;
}
// Copyright 2020 OPREA OLIVIA MARIA-MAGDALENA <opreaolivia73@gmail.com>
#include <bits/stdc++.h>

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first != b.first) {
		return a.first < b.first;
	}
	return a.second > b.second;
}

class Problema2 {
	vector<pair<int, int>> v;
	int n;
	int rez = 0;

 public:
	void read() {
		ifstream in("gard.in");
		in >> n;
		for (int i = 0; i < n; ++i) {
	    	int x1, x2;
	    	in >> x1 >> x2;
	    	v.push_back({x1, x2});
    	}
		in.close();
	}

	void solution() {
		sort(v.begin(), v.end(), cmp);
		int i = 0, j = 1;
		while (i < n && j < n) {
			if((v[i].first <= v[j].first) && (v[i].second >= v[j].second)) {
				++rez;
				++j;
			} else {
				i = j;
				++j;
			}
		}
	}

	void solve() {
		read();
		solution();
		print();
	}

	void print() {
		ofstream out("gard.out");
		out << rez << "\n";
		out.close();
	}
};

int main() {
	Problema2 *problema2 = new Problema2();
	problema2->solve();
	delete problema2;
	return 0;
}

// Copyright 2020 OPREA OLIVIA MARIA-MAGDALENA <opreaolivia73@gmail.com>
#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

class Problema3 {
	vector<pair<int, int>> v;
	int n, m;
	int rez = 0;

 public:
	void read() {
		ifstream in("bomboane.in");
		in >> n >> m;
		v.push_back({0, 0});  // pentru indexare de la 1
		for (int i = 1; i <= n; ++i) {
	    	int x1, x2;
	    	in >> x1 >> x2;
	    	v.push_back({x1, x2});
    	}
		in.close();
	}

	void solution() {
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
		dp[0][0] = 1;  // caz de baza

		for (int i = 1; i <= n; ++i) {  // elevii
			for (int k = v[i].first; k <= v[i].second; ++k) {  // intervalele
				for (int j = k; j <= m; ++j) {  // bomboanele
					dp[i][j] += dp[i - 1][j - k];
					dp[i][j] %= MOD;
				}
			}
		}

		rez = dp[n][m];
	}

	void solve() {
		read();
		solution();
		print();
	}

	void print() {
		ofstream out("bomboane.out");
		out << rez << "\n";
		out.close();
	}
};

int main() {
	Problema3 *problema3 = new Problema3();
	problema3->solve();
	delete problema3;
	return 0;
}

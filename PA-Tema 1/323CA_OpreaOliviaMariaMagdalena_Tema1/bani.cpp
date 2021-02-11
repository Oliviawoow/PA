// Copyright 2020 OPREA OLIVIA MARIA-MAGDALENA <opreaolivia73@gmail.com>
#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

class Problema1 {
	int type, n;  // tipul setului de instructiuni si nr de bacnote
	int rez = 0;  // rezultatul problemei

 public:
	void read() {
		ifstream in("bani.in");
		in >> type >> n;
		in.close();
	}

	void solution() {
		if (type == 1) {
			int aux = 1, base = 2, exponent = n - 1;
			if (n == 1) {  // caz in care exponent este 1 (caz de baza)
				rez = 5;
			} else {
		        while (exponent != 1) {
		            if (exponent % 2 == 0) {  // caz in care exponentul este par
		                base = (1LL * base * base) % MOD;
		                exponent /= 2;
		            } else {  // caz in care exponentul este impar
		                aux = (1LL * aux * base) % MOD;
		                --exponent;
		            }
		        }

		        rez = 5 * (1LL * aux * base) % MOD;
		    }
		} else {
			vector<long> pos_10(n, 0);
			vector<long> pos_50(n, 0);
			vector<long> pos_100(n, 0);
			vector<long> pos_200(n, 0);
			vector<long> pos_500(n, 0);

			pos_10[0] = 1;  // caz de baza
			pos_50[0] = 1;
			pos_100[0] = 1;
			pos_200[0] = 1;
			pos_500[0] = 1;

			for (long i = 1; i < n; ++i) {  // tinem cont de ce bacnote am folosit
				pos_10[i] = ((pos_50[i - 1] % MOD) + (pos_100[i - 1] % MOD)) % MOD;
				pos_50[i] = ((pos_10[i - 1] % MOD) + (pos_200[i - 1] % MOD)) % MOD;
				pos_100[i] = ((pos_10[i - 1] % MOD) + (pos_100[i - 1] % MOD)) % MOD;
				pos_200[i] = ((pos_50[i - 1] % MOD) + (pos_100[i - 1] % MOD) +
				 (pos_500[i - 1] % MOD)) % MOD;
				pos_500[i] = ((pos_200[i - 1] % MOD) + (pos_10[i - 1] % MOD)) % MOD;
			}

			rez = ((pos_10[n - 1] % MOD) + (pos_50[n - 1] % MOD) +
			 (pos_100[n - 1] % MOD) + (pos_200[n - 1] % MOD) +
			  (pos_500[n - 1]) % MOD) % MOD;
		}
	}

	void solve() {
		read();
		solution();
		print();
	}

	void print() {
		ofstream out("bani.out");
		out << rez << "\n";
		out.close();
	}
};

int main() {
	Problema1 *problema1 = new Problema1();
	problema1->solve();
	delete problema1;
	return 0;
}

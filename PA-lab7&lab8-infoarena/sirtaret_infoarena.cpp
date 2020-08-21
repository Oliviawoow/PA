#include <bits/stdc++.h>

#define NMAX 100010
using namespace std;

class Task {
public:
  void solve() {
    read_input();
    // get_result();
    print_output(get_result());
  }

private:
  // n = numar de noduri, m = numar de muchii
  int n, m;

  // adj[node] lista de adiacenta a nodului node
  vector<int> adj[NMAX];

  void read_input() {
      ifstream in("sortaret.in");
      in >> n >> m;
      for (int i = 1; i <= m; ++i) {
          int x, y;
			in >> x >> y;
			adj[x].push_back(y);
      }

      in.close();
  }

  void DFS(int nod, vector<int>& TopSort, vector<int>& used) {
      used[nod] = 1;
		for (int i : adj[nod]) {
			if (used[i]) continue;
			DFS(i, TopSort, used);
		}
		TopSort.push_back(nod);
  }

  vector<int> get_result() {
      vector<int> topsort;
      vector<int> used(n + 1, 0);

		for (int i = 1; i <= n; ++i){
			if (used[i]) continue;
			DFS(i, topsort, used);
		}

        // ma scuteste de stiva
		reverse(topsort.begin(), topsort.end());
		return topsort;

  }

  void print_output(vector<int> result) {
      ofstream out("sortaret.out");
      for (int i = 0; i < int(result.size()); i++) {
          out << result[i] << (i == n ? '\n' : ' ');
      }

      out.close();
  }
};

int main() {
  // din cauza ca fac redirectari, salvez starea lui cin si cout
  // auto cin_buff = cin.rdbuf();
  // auto cout_buff = cout.rdbuf();

  // las liniile urmatoare daca citesc din fisier
  // ifstream fin("in");
  // cin.rdbuf(fin.rdbuf()); // save and redirect

  // las liniile urmatoare daca afisez in fisier
  // ofstream fout("out");
  // cout.rdbuf(fout.rdbuf()); //save and redirect

  // aici este rezolvarea propriu-zisa
  Task *task = new Task();
  task->solve();
  delete task;

  // restore pentru cin si cout
  // cin.rdbuf(cin_buff);
  // cout.rdbuf(cout_buff);

  // obs. nu e nevoie sa inchid fisierele
  // cand se apeleaza destructorii pentru fin si fout se vor inchide

  return 0;
}

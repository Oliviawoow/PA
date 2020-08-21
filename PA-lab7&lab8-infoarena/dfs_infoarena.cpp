#include <bits/stdc++.h>

#define NMAX 100010
using namespace std;

class Task {
public:
  void solve() {
    read_input();
    get_result();
    print_output();
  }

private:
  // n = numar de noduri, m = numar de muchii
  int n, m;

  // nr componente conexe
  int conexe = 0;

  // adj[node] lista de adiacenta a nodului node
  vector<int> adj[NMAX];

  // vizitat[node] verifica daca nodul a fost vizitat sau nu
  bool vizitat[NMAX];

  void read_input() {
      ifstream in("dfs.in");
      in >> n >> m;

      for (int i = 1; i <= m; ++i) {
          int x, y;
          in >> x >> y;
          adj[x].push_back(y);
          adj[y].push_back(x);
      }

      in.close();
  }

  void parcurgereDFS(int x) {
    vizitat[x] = true;
    for (int i = 0; i < adj[x].size(); ++i) {
        if (!vizitat[adj[x][i]]) {
            parcurgereDFS(adj[x][i]);
        }
    }
}

  void get_result() {
      for (int i = 1; i <= n; ++i) {
          if (!vizitat[i]) {
              ++conexe;
              parcurgereDFS(i);
          }
      }
  }

  void print_output() {
      ofstream out("dfs.out");
      out << conexe;

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

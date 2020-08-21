#include <bits/stdc++.h>

#define NMAX 1000010
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
  int p;
  int viz = 0;

  // adj[node] lista de adiacenta a nodului node
  vector<int> adj[NMAX];
  vector<int> v;
  vector<int> visited;

  void read_input() {
      ifstream in("berarii2.in");
      in >> n >> m >> p;

      for (int i = 1; i <= m; ++i) {
          int x, y;
          in >> x >> y;
          // adj[x].push_back(y);
          adj[y].push_back(x);
      }

      for (int i = 1; i <= p; ++i) {
          int x;
          in >> x;
          v.push_back(x);
      }

      visited = vector<int>(n + 1, 0);

      in.close();
  }

  void dfs (int x) {
      ++viz;
      visited[x] = 1;

      for (auto i : adj[x]) {
          if (visited[i] == 0) {
              dfs(i);
          }
      }
      
  }

  void get_result() {
      for (auto i : v) {
          if (visited[i] == 0) {
              dfs(i);
          }
      }
  }

  void print_output() {
      ofstream out("berarii2.out");

      out << n - viz << "\n";
      
      for (int i = 1; i <= n; ++i) {
          if (visited[i] != 1) {
              out << i << "\n";
          }
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

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
  // n = numar de noduri, m = numar de muchii, source = sursa
  int n, m, source;

  // adj[node] lista de adiacenta a nodului node
  vector<int> adj[NMAX];

  queue<int> q;

  void read_input() {
      ifstream in("bfs.in");
      in >> n >> m >> source;

      for (int i = 1; i <= m; ++i) {
          int x, y;
          in >> x >> y;
          adj[x].push_back(y);
      }

      in.close();
  }

  vector<int> get_result() {
      vector<int> d(n + 1);
      // consider toate nodurile initial -1
      for (int i = 1; i <= n; ++i) {
          d[i] = -1;
      }

      q.push(source);
      d[source] = 0;
      while (!q.empty()) {
          int nod_curent = q.front();
          q.pop();
          for (int i : adj[nod_curent]) {
              if (d[i] == -1) {
                  d[i] = d[nod_curent] + 1;
                  q.push(i);
              }
          }
      }

      return d;
  }

  void print_output(vector<int> result) {
      ofstream out("bfs.out");
      for (int i = 1; i <= n; ++i) {
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

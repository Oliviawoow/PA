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
  int n, maxim;
  int sol[NMAX];

  // adj[node] lista de adiacenta a nodului node
  vector<int> adj[NMAX];
  queue<int> q;

  void read_input() {
      fstream in("darb.in");
      in >> n;

      for (int i = 1; i <= n; ++i) {
          int x, y;
          in >> x >> y;
          adj[x].push_back(y);
          adj[y].push_back(x);
      }

      in.close();
  }

  void BFS(int s) {
      int i, j, k;
      for(i = 1; i <= n; ++i)
      sol[i] = -1;
      sol[s] = 0;
      q.push(s);
      while(!q.empty()) {
        i = q.front();
        q.pop();
        for(k = 0; k < adj[i].size(); ++k) {
            j = adj[i][k];
            if(sol[j] == -1) {
                sol[j] = 1 + sol[i];
                q.push(j);
            }
        }
      }
  }

  void get_result() {
      int nod, i;
      BFS(1);
      maxim = 0;
      for(i = 1; i <= n; ++i)
        if(sol[i] > maxim) {
            maxim = sol[i];
            nod = i;
        }
      BFS(nod);
      for(i = 1; i <= n; ++i)
        maxim = max(maxim, sol[i]);
      maxim++;
  }

  void print_output() {
      ofstream out("darb.out");
      out << maxim << endl;
      
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

#include <bits/stdc++.h>

#define NMAX 105
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
  int n;

  // adj[node] lista de adiacenta a nodului node
  int d[NMAX][NMAX];
  int a[NMAX][NMAX];
 
  void read_input() {
      ifstream in("royfloyd.in");
      in >> n;
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            in >> a[i][j];
        }
      }
      
      in.close();
  }

  void get_result() {
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            d[i][j]=a[i][j];
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <=n; j++){
                if(i == j) continue;
                if(!d[i][k] || !d[k][j]) continue;
                if(!d[i][j] || d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j];
            }
  }

  void print_output() {
      ofstream out("royfloyd.out");
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            out << d[i][j] << ' ';
        }
        out << '\n';
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

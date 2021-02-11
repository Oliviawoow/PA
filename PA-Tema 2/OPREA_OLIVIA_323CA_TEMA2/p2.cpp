// Copyright 2020 OPREA OLIVIA MARIA-MAGDALENA <opreaolivia73@gmail.com>
#include <bits/stdc++.h>

#define NMAX 200020
#define oo (1 << 30)
#define NO_PARENT (-1)
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
  int sursa, destinatie;
  long rez;

  // adj[i] contine perechi de tipul : vecin , costul muchiei i -> vecin
  vector<pair<int, int>> adj[NMAX];
  queue<int> q;

  // d[i] = distanta minima de la de source la nodul i
  vector<int> d;
  // p[i] = parintele lui i de pe drumul minim de la source la nodul i
  vector<int> p;
  void read_input() {
    ifstream in("p2.in");
    in >> n >> m;
    in >> sursa >> destinatie;

    d.resize(n + 1);
    p.resize(n + 1);

    for (int i = 1; i <= m; ++i) {
      int x, y, e;
      in >> x >> y >> e;
      adj[x].push_back({y, e});
    }

    in.close();
  }

  void BellmanFord(int sursa, vector<int> &d, vector<int> &p) {
    for (int i = 1; i <= n; ++i) {
      // presupun ca nu am drum deci nici parinte
      d[i] = oo;
      p[i] = NO_PARENT;
    }
    // parintele lui source este 0 si distanta de la source la source e 0
    p[sursa] = 0;
    d[sursa] = 0;
    q.push(sursa);

    while (!q.empty()) {
      int node = q.front();
      q.pop();
      for (auto &edge : adj[node]) {
        int neighbour = edge.first;
        int cost_edge = edge.second;
        // daca obtinem un cost mai mic trecand prin node
        if (d[node] + cost_edge < d[neighbour]) {
          // salvam noua distanta
          d[neighbour] = d[node] + cost_edge;
          // noul parinte devine node
          p[neighbour] = node;
          // actualizez costul drumului de la sursa la vecin
          q.push(neighbour);
        }
      }
    }
  }

  void get_result() {
    BellmanFord(sursa, d, p);
    rez = d[destinatie];
  }

  void print_output() {
    ofstream out("p2.out");
    out << rez;

    out.close();
  }
};

int main() {
  Task *task = new Task();
  task->solve();
  delete task;
  return 0;
}

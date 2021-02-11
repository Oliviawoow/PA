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
  // n = numar de noduri, m = numar de muchii, e = energie
  int n, m;
  long e;
  int sursa, destinatie;
  double energie_finala = 1;

  // adj[i] contine perechi de tipul : vecin , costul muchiei i -> vecin
  vector<pair<int, long>> adj[NMAX];
  // min-heap ce contine perechi de tipul: distanta de la source la
  // nodul x, nodul x
  // folosit pentru e extrage la fiecare pas nodul care are costul
  // estimat minim fata de sursa
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 std::greater<pair<int, int>>> pq;
  // d[i] = distanta minima de la de source la nodul i
  vector<int> d;
  // p[i] = parintele lui i de pe drumul minim de la source la nodul i
  vector<int> p;

  void read_input() {
    ifstream in("p3.in");
    in >> n >> m >> e;
    sursa = 1;
    destinatie = n;
    energie_finala = e;
    d.resize(n + 1);
    p.resize(n + 1);

    for (int i = 1; i <= m; ++i) {
      int x, y, c;
      in >> x >> y >> c;
      adj[x].push_back({y, c});
    }

    in.close();
  }

  void Dijkstra(int source, vector<int> &d, vector<int> &p) {
    for (int i = 1; i <= n; ++i) {
      // presupun ca nu am drum deci nici parinte
      d[i] = oo;
      p[i] = NO_PARENT;
    }
    // parintele lui source este 0 si distanta de la source la source e 0
    p[source] = 0;
    d[source] = 0;
    pq.push({d[source], source});

    while (!pq.empty()) {
      // extragem nodul care are costul estimat minim fata de sursa
      auto entry = pq.top();
      pq.pop();
      int cost = entry.first;
      int node = entry.second;
      // daca intrarea curenta nu este up-to-date
      if (cost > d[node]) {
        continue;
      }
      for (auto &edge : adj[node]) {
        int neighbour = edge.first;
        int cost_edge = edge.second;
        // daca obtinem un costmai mic trecand prin node
        if (d[node] + cost_edge < d[neighbour]) {
          // salvam noua distanta
          d[neighbour] = d[node] + cost_edge;
          // noul parinte devine node
          p[neighbour] = node;
          // actualizez costul drumului de la sursa la vecin
          pq.push({d[neighbour], neighbour});
        }
      }
    }

    for (int i = 1; i <= n; ++i) {
      if (d[i] == oo) {
        d[i] = 0;
      }
    }
  }

  vector<int> rebuild_path(int node, vector<int> &p) {
    // nu exista drum de la source la node
    if (p[node] == NO_PARENT) {
      return {};
    }
    // path = {source, ..., node}
    vector<int> path;
    // rebuild node -> ... -> source (if exists)
    for (; node != 0; node = p[node]) {
      path.push_back(node);
    }
    reverse(path.begin(), path.end());

    return path;
  }

  void get_result() {
    Dijkstra(sursa, d, p);
    auto drum = rebuild_path(destinatie, p);
    for (auto &node : drum) {
      if (node != 1) {
        energie_finala = energie_finala *
        (1 - ((d[node] - d[p[node]]) / 100.0));
      }
    }
  }

  void print_output() {
    ofstream out("p3.out");
    auto drum = rebuild_path(destinatie, p);
    out << setprecision(5) << fixed << energie_finala << '\n';
    for (auto &node : drum) {
      out << node << ' ';
    }

    out.close();
  }
};

int main() {
  Task *task = new Task();
  task->solve();
  delete task;
  return 0;
}

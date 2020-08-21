#include <bits/stdc++.h>

#define NMAX 50005
#define NMAXX 250005
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
  int source = 1;

  // adj[node] lista de adiacenta a nodului node
  vector<pair<int, int>> adj[NMAX];
 
  void read_input() {
      ifstream in("bellmanford.in");
      in >> n >> m;

      for (int i = 1; i <= m; ++i) {
          int x, y, w;
          in >> x >> y >> w;
          adj[x].push_back(make_pair(y, w));
      }
      
      in.close();
  }

  vector<int> get_result() {
      vector<int> d(n + 1, NMAXX);
        d[source] = 0;
        vector<pair<pair<int, int>, int>> muchii;
        for(int i = 1; i <= n; i++)
            for(const pair <int, int>& traverse : adj[i]){
                int v = traverse.first;
                int weight = traverse.second;
                muchii.push_back(make_pair(make_pair(i, v), weight));
            }

        for(int i = 1; i <= n-1; i++)
            for(int j = 0; j < muchii.size(); j++){
                int x = muchii[j].first.first;
                int v = muchii[j].first.second;
                int weight = muchii[j].second;
                if(d[v] > d[x] + weight)
                    d[v] = d[x] + weight;
            }

        for(int j = 0; j < muchii.size(); j++){
            int x = muchii[j].first.first;
            int v = muchii[j].first.second;
            int weight = muchii[j].second;
            if(d[v] > d[x] + weight)
                return vector<int>();
        }

        for(int i = 1; i <= n; i++)
            if(d[i] == NMAXX)
                d[i] = -1;

        return d;
  }

  void print_output(vector<int> result) {
      ofstream out("bellmanford.out");
      if (result.size() == 0) {
            out << "Ciclu negativ!\n";
        } else {
            for (int i = 2; i <= n; i++) {
                out << result[i] << ' ';
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

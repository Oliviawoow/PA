#include <bits/stdc++.h>

#define NMAX 250010
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
  int source;

  // adj[node] lista de adiacenta a nodului node
  vector<pair<int, int>> adj[NMAX];
 
  void read_input() {
      ifstream in("dijkstra.in");
      in >> n >> m >> source;

      for (int i = 1; i <= m; ++i) {
          int x, y, w;
          in >> x >> y >> w;
          adj[x].push_back(make_pair(y, w));
      }
      
      in.close();
  }

  vector<int> get_result() {
      vector<int> d(n + 1, NMAX);
      set<pair<int, int>> tuplu; // inspirat de pe Geeks in loc de coada cu prioritati folosesc tupluri

      d[source] = 0;
      tuplu.insert(make_pair(d[source], source));

      while(!tuplu.empty()){
        int node = tuplu.begin()->second;
        tuplu.erase(tuplu.begin());
        for(const pair<int, int>& k : adj[node]){
        	int v = k.first;
        	int weight = k.second;
        	if(d[v] > d[node] + weight){
        	    tuplu.erase(make_pair(d[v],v));
        		d[v] = d[node] + weight;
        		tuplu.insert(make_pair(d[v],v));
        	}
        }
      }
      for(int i = 1; i <= n; ++i)
        if(d[i] == NMAX)
        	d[i] = -1;
      return d;	
  }

  void print_output(vector<int> result) {
      ofstream out("dijkstra.out");
      for (int i = 1; i <= n; ++i) {
        out << result[i] << " ";
      }
        out << "\n";

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

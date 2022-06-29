#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

void topsort(vector<set<int> > &arr, vector<int> &visited, vector<int> &order, int v){
    visited[v] = 1;
    for(auto u : arr[v]){
        if(visited[u] == 0){
            topsort(arr, visited, order, u);
        }
    }
    visited[v] = 2;
    order.push_back(v);
}

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    // ifstream fin("hamiltonian.in");
    // ofstream fout("hamiltonian.out");

    int n,m;
    fin >> n >> m;

    vector<set<int> > arr(n);

    int a,b;
    for(int i = 0; i < m; i++){
        fin >> a >> b;

        arr[a - 1].insert(b - 1);
    }

    vector<int> visited(n, 0);
    vector<int> order;

    for(int i = 0; i < n; i++){
        if(visited[i] == 0){
            topsort(arr, visited, order, i);
        }
    }

    bool has_path = true;
    for(int i = order.size() - 1; i >= 1; i--){
        int u = order[i];
        int v = order[i - 1];

        if(arr[u].count(v) == 0){
            fout << "NO";
            return 0;
        }
    }

    fout << "YES";

    return 0;
}
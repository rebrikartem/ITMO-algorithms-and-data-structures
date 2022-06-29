#include <iostream>
#include <fstream>
#include <vector>


using namespace std;


bool dfs
(
    int v,
    vector<bool>& used,
    vector<vector<int> >& g,
    vector<int>& mt
)
{
    if(used[v]) return false;
    used[v] = true;
    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        if(mt[to] == -1 || dfs(mt[to], used, g, mt)){
            mt[to] = v;
            return true;
        }
    }
    return false;
}


int main(){
    ifstream fin("matching.in");
    ofstream fout("matching.out");

    int n,m,k;
    fin >> n >> m >> k;
    vector<vector<int> > g(n);

    int a,b;
    for(int i = 0; i < k; i++){
        fin >> a >> b;

        g[a - 1].push_back(b - 1);
    }

    vector<int> mt(m, -1);
    vector<bool> used;

    int count = 0;
    for(int v = 0; v < n; v++){
        used.assign(n, false);
        if(dfs(v, used, g, mt)) count++;
    }

    fout << count << endl;

    return 0;
}
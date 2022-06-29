#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;


int dfs
(
    int u,
    int t,
    int c,
    vector<vector<int> >& cap,
    vector<bool>& used
)
{
    if(u == t) return c;
    used[u] = true;
    int n = cap.size();
    for(int v = 0; v < n; v++){
        if(!used[v] && cap[u][v] > 0){
            int d = dfs(v, t, min(c, cap[u][v]), cap, used);
            cap[v][u] += d;
            cap[u][v] -= d;
            if(d > 0){
                return d;
            }
        }
    }
    return 0;
}


int main(){
    ifstream fin("maxflow.in");
    ofstream fout("maxflow.out");
    // ifstream fin("input.txt");
    // ofstream fout("output.txt");

    int n,m;
    fin >> n >> m;
    vector<vector<int> > cap(n, vector<int>(n, 0));

    int a,b,c;
    for(int i = 0; i < m; i++){
        fin >> a >> b >> c;
        cap[a - 1][b - 1] = c;
    }

    int max_flow = 0;
    int d;
    vector<bool> used;
    do{
        used = vector<bool>(n, false);
        d = dfs(0, n - 1, 2147483647, cap, used);
        max_flow += d;
    }while(d != 0);

    fout << max_flow << endl;
    

    return 0;
}
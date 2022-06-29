#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;


struct Edge{
    int v;
    int u;
    long long w;  
};


long long INF = 9223372036854775807 / 3 * 2;


void dfs
(
    vector<vector<int> >& arr,
    vector<bool>& used,
    vector<bool>& NoShortestPath,
    int v
)
{
    used[v] = true;
    for(int i = 0; i < arr[v].size(); i++){
        NoShortestPath[arr[v][i]] = true;
        if(!used[arr[v][i]]){
            dfs(arr, used, NoShortestPath, arr[v][i]);
        }
    }
}


int main(){
    ifstream fin("path.in");
    ofstream fout("path.out");

    int n, m, s;
    fin >> n >> m >> s;

    vector<Edge> g(m);
    vector<vector<int> > arr(n);

    int a, b;
    long long c;
    for(int i = 0; i < m; i++){
        fin >> a >> b >> c;

        Edge tmp;
        tmp.u = a - 1;
        tmp.v = b - 1;
        tmp.w = c;

        g[i] = tmp;
        arr[a - 1].push_back(b - 1);
    }

    vector<long long> dist(n, INF);
    dist[s - 1] = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m; j++){
            int u = g[j].u;
            int v = g[j].v;
            long long w = g[j].w;
            
            if(dist[u] == INF){
                continue;
            }

            if(dist[v] > dist[u] + w){
                dist[v] = -INF > dist[u] + w ? -INF : dist[u] + w;
            }
        }
    }

    vector<bool> NoShortestPath(n, false);
    for(int j = 0; j < m; j++){
        int u = g[j].u;
        int v = g[j].v;
        long long w = g[j].w;
            
        if(dist[u] == INF){
            continue;
        }

        if(dist[v] > dist[u] + w){
            NoShortestPath[v] = true;
            dist[v] = -INF > dist[u] + w ? -INF : dist[u] + w;
        }
    }
    

    vector<bool> used(n, false);
    for(int i = 0; i < n; i++){
        if(!used[i] && NoShortestPath[i]){
            dfs(arr, used, NoShortestPath, i);
        }
    }

    for(int i = 0; i < n; i++){
        if(dist[i] == INF){
            fout << "*";
        }
        else if(NoShortestPath[i]){
            fout << "-";
        }
        else{
            fout << dist[i];
        }
        fout << endl;
    }

    return 0;
}
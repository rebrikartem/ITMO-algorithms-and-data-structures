#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void dfs1(vector<vector<int> > &g, vector<int> &visited, vector<int> &order, int v){
    visited[v] = 0;
    for(int i = 0; i < g[v].size(); i++){
        if(visited[g[v][i]] == -1){
            dfs1(g, visited, order, g[v][i]);
        }
    }
    order.push_back(v);
}

void dfs2(vector<vector<int> > &gr, vector<int> &visited, vector<int> &component, int v){
    visited[v] = 0;
    component.push_back(v);
    for(int i = 0; i < gr[v].size(); i++){
        if(visited[gr[v][i]] == -1){
            dfs2(gr, visited, component, gr[v][i]);
        }
    }
}

int main(){
    ifstream fin("cond.in");
    ofstream fout("cond.out");

    int n,m;
    fin >> n >> m;

    vector<vector<int> > g(n);
    vector<vector<int> > gr(n);
    vector<int> order;
    vector<int> component;
    vector<int> visited(n, -1);

    int a,b;
    for(int i = 0; i < m; i++){
        fin >> a >> b;

        g[a - 1].push_back(b - 1);
        gr[b - 1].push_back(a - 1);
    }

    for(int i = 0; i < n; i++){
        if(visited[i] == -1){
            dfs1(g,visited,order,i);
        }
    }

    vector<int> answer(n);
    int c = 0;
    visited.assign(n , -1);

    for(int i = 0; i < n; i++){
        int v = order[n - i - 1];
        if(visited[v] == -1){
            dfs2(gr, visited, component, v);
            c++;
            for(int j = 0; j < component.size(); j++){
                answer[component[j]] = c;
            }
            component.clear();
        }
    }

    fout << c << endl;
    for(int i = 0; i < answer.size(); i++){
        fout << answer[i] << " ";
    }

    return 0;
}
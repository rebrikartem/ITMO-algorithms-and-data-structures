#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int> >& arr, vector<int>& visited, vector<int>& parents, int v, int& c_st, int& c_end){
    visited[v] = 1;
    for(int i = 0; i < arr[v].size(); i++){
        if(visited[arr[v][i]] == 0){
            parents[arr[v][i]] = v;
            if(dfs(arr, visited, parents, arr[v][i], c_st, c_end)) return true;
        }
        else if(visited[arr[v][i]] == 1){
            c_st = arr[v][i];
            c_end = v;
            return true;
        }
    }
    visited[v] = 2;
    return false;
}

int main(){
    ifstream fin("cycle.in");
    ofstream fout("cycle.out");

    int n,m;
    fin >> n >> m;

    vector<vector<int> > arr(n);
    vector<int> parents(n, -1);
    vector<int> visited(n, 0);

    int a,b;
    for(int i = 0; i < m; i++){
        fin >> a >> b;
        arr[a - 1].push_back(b - 1);
    }

    int c_st = -1;
    int c_end = -1;

    for(int i = 0; i < n; i++){
        if(dfs(arr,visited,parents,i,c_st,c_end)) break;
    }

    if(c_st == -1){
        fout << "NO";
    }
    else{
        fout << "YES" << endl;

        vector<int> cycle;
        int v;
        for(v = c_end; v != c_st; v = parents[v]){
            cycle.push_back(v + 1);
        }
        cycle.push_back(v + 1);
        for(int i = cycle.size() - 1; i >= 0; i--){
            fout << cycle[i] << " ";
        }
    }

    return 0;
}
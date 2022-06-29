#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int> > &arr, vector<int> &colors, int v){
    for(int i = 0; i < arr[v].size(); i++){
        if(colors[arr[v][i]] == colors[v]) return false;
        else if(colors[arr[v][i]] == 0){
            colors[arr[v][i]] = colors[v] == 1 ? 2 : 1;
            if(!dfs(arr, colors, arr[v][i])) return false;
        }
    }
    return true;
}

int main(){
    ifstream fin("bipartite.in");
    ofstream fout("bipartite.out");

    int n,m;
    fin >> n >> m;

    vector<vector<int> > arr(n);
    vector<int> colors(n, 0);

    int a,b;
    for(int i = 0; i < m; i++){
        fin >> a >> b;

        arr[a - 1].push_back(b - 1);
        arr[b - 1].push_back(a - 1);
    }

    for(int i = 0; i < n; i++){
        if(colors[i] == 0){
            colors[i] = 1;
            if(!dfs(arr, colors, i)){
                fout << "NO";
                return 0;
            }
        }
    }

    fout << "YES";

    return 0;
}
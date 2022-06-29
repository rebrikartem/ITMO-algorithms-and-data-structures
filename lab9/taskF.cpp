#include <iostream>
#include <fstream>
#include <set>
#include <vector>

using namespace std;

void dfs(vector<set<int> > &arr, vector<int> &visited, vector<int> &topsort, int v){
    visited[v] = 1;
    
    for(auto u : arr[v]){
        if(visited[u] == 0){
            dfs(arr, visited, topsort, u);
        }
    }

    topsort.push_back(v);
}

int main(){
    // ifstream fin("input.txt");
    // ofstream fout("output.txt");
    ifstream fin("game.in");
    ofstream fout("game.out");

    int n,m,s;
    fin >> n >> m >> s;
    vector<set<int> > arr(n);

    int a,b;
    for(int i = 0; i < m; i++){
        fin >> a >> b;

        arr[a - 1].insert(b - 1);
    }

    vector<int> topsort;
    vector<int> visited(n,0);

    dfs(arr, visited, topsort, s - 1);

    vector<bool> marks(n,true);
    for(int i = 1; i < topsort.size(); i++){
        int v = topsort[i];
        for(auto u : arr[v]){
            if(marks[u]){
                marks[v] = false;
                break;
            }
        }
    }

    if(marks[s - 1] == false){
        fout << "First player wins";
    }
    else{
        fout << "Second player wins";
    }

    return 0;
}
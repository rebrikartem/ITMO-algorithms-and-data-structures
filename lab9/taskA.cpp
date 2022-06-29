#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

bool dfs(vector<vector<int> >& arr, vector<int>& visited, stack<int>& ans, int v){
    visited[v] = 0;
    for(int i = 0; i < arr[v].size(); i++){
        int next = arr[v][i];
        if(visited[next] == -1){
            if(dfs(arr,visited,ans,next)) return true;
        }
        else if(visited[next] == 0) return true;
    }
    visited[v] = 1;
    ans.push(v + 1);
    return false;
}

int main(){
    // ifstream fin("input.txt");
    // ofstream fout("output.txt");
    ifstream fin("topsort.in");
    ofstream fout("topsort.out");

    int n, m;
    fin >> n >> m;

    vector<vector<int> > arr(n);
    vector<int> visited(n,-1);
    stack<int> ans;

    int a, b;
    for(int i = 0; i < m; i++){
        fin >> a >> b;
        arr[a - 1].push_back(b - 1);
    }

    for(int i = 0; i < n; i++){
        if(visited[i] == -1){
            if(dfs(arr, visited, ans, i)){
                fout << -1 << endl;
                return 0;
            }
        }
    }

    for(int i = 0; i < n; i++){
        fout << ans.top() << " ";
        ans.pop();
    }

    return 0;
}
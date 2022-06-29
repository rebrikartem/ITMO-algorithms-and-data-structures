#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void solve(vector<vector<int> >& arr, int i, int j, int n, int m){
    if(i + 2 < n && j + 1 < m){
        arr[i + 2][j + 1] += 1;
        solve(arr, i + 2, j + 1, n, m);
    }

    if(i + 1 < n && j + 2 < m){
        arr[i + 1][j + 2] += 1;
        solve(arr, i + 1, j + 2, n, m);
    }   

    if(i - 1 >= 0 && j + 2 < m){
        arr[i - 1][j + 2] += 1;
        solve(arr, i - 1 , j + 2, n, m);
    }

    if(i + 2 < n && j - 1 >= 0){
        arr[i + 2][j - 1] += 1;
        solve(arr, i + 2, j - 1, n, m);
    }

    return;
}

int main(){
    ifstream fin("knight2.in");
    ofstream fout("knight2.out");

    int n,m;
    fin >> n >> m;
    vector<vector<int> > arr(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            arr[i].push_back(0);
        }
    }

    arr[0][0] = 1;

    solve(arr, 0, 0, n, m);

    fout << arr[n - 1][m - 1] << endl;

    return 0;
}
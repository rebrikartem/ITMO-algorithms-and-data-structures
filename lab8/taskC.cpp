#include<iostream>
#include<fstream>

using namespace std;

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, m;
    fin >> n >> m;

    int **arr = new int*[n];
    arr[0] = new int[n*n];
    for(int i = 1; i < n; i++){
        arr[i] = arr[i-1] + n;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            arr[i][j] = 0;
        }
    }

    bool is_parallel = false;
    int a,b;
    for(int i = 0; i < m; i++){
        fin >> a >> b;
        a--;
        b--;
        
        arr[a][b] += 1;
        arr[b][a] += 1;
        if(arr[a][b] == 2){
            is_parallel = true;
            break;
        }
    }
    if(is_parallel){
        fout << "YES";
    }
    else{
        fout << "NO";
    }

    return 0;
}
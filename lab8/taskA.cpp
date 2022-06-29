#include<iostream>
#include<fstream>

using namespace std;

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n,m;

    fin >> n >> m;

    int ** arr = new int *[n];
    arr[0] = new int[n*n];
    for(int i = 1; i < n; i++){
        arr[i] = arr[i-1] + n;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            arr[i][j] = 0;
        }
    }

    int a,b;
    for(int i = 0; i < m; i++){
        fin >> a >> b;
        arr[a-1][b-1] = 1;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            fout << arr[i][j] << " ";
        }
        fout << endl;
    }

    return 0;
}
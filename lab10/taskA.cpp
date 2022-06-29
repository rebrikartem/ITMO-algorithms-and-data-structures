#include <iostream>
#include <fstream>
#include <vector>


using namespace std;


int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n,m;
    fin >> n >> m;
    vector<int> degree(n, 0);

    int a,b;
    for(int i = 0; i < m; i++){
        fin >> a >> b;

        degree[a - 1]++;
        degree[b - 1]++;
    }

    for(int i : degree){
        fout << i << " ";
    }

    return 0;
}
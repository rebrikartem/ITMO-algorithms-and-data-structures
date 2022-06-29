#include <iostream>
#include <fstream>
#include <vector>


using namespace std;


int main(){
    ifstream fin("knapsack.in");
    ofstream fout("knapsack.out");

    int s,n;
    fin >> s >> n;

    vector<int> w;
    int c;
    for(int i = 0; i < n; i++){
        fin >> c;
        w.push_back(c);
    }

    bool d[n + 1][s + 1];
    for(int i = 0; i <= s; i++){
        d[0][i] = false;
    }
    d[0][0] = true;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= s; j++){
            d[i][j] = d[i - 1][j];

            if(j - w[i - 1] >= 0){
                d[i][j] = d[i - 1][j - w[i - 1]];
            }
        }
    }

    for(int i = s; i > 0; i--){
        if(d[n][i]){
            fout << i << endl;
            return 0;
        }
    }

    return 0;
}
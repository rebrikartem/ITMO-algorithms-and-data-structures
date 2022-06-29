#include <iostream>
#include <fstream>
#include <vector>
 
 
using namespace std;


int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");
 
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int dp[2002][2002];
 
    for (int i = 0; i < n; ++i) dp[i][i] = 1;
    for (int i = 0; i < n - 1; ++i) dp[i][i + 1] = 2 + (a[i] == a[i + 1]);
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = i + 2; j < n; ++j)
        {   
            dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] ) % 1000000000;
            if (a[i] == a[j]) dp[i][j] = (dp[i][j] + dp[i + 1][j - 1] + 1) % 1000000000;
        }
    }

    cout << ((dp[0][n - 1] % 1000000000) + 1000000000) % 1000000000  << endl;

    return 0;
}
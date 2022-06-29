#include <iostream>
#include <fstream>
#include <vector>


using namespace std;


void dfs
(
    vector<vector<int> >& arr, 
    vector<vector<int> >& dp,
    vector<bool>& used,
    int root
)
{
    used[root] = true;
    for(int i = 0; i < arr[root].size(); i++){
        int to = arr[root][i];
        if(!used[to]){
            dfs(arr, dp, used, to);
        }
    }

    int sum1 = 0;
    int sum2 = 0;

    for(int i = 0; i < arr[root].size(); i++){
        int to = arr[root][i];
        int max = dp[to][0] > dp[to][1] ? dp[to][0] : dp[to][1];
        sum2 += max;
        sum1 += dp[to][0];
    }

    dp[root][0] = sum2;
    dp[root][1] += sum1;
}


int main(){
    ifstream fin("selectw.in");
    ofstream fout("selectw.out");

    int n;
    fin >> n;

    vector<vector<int> > arr(n);
    vector<vector<int> > dp(n);
    // vector<int> c(n);
    int p, v, start;
    for(int i = 0; i < n; i++){
        fin >> p >> v;
        
        // c[i] = v;

        dp[i].push_back(0);
        if(v < 0){
            dp[i].push_back(0);
        }
        else{
            dp[i].push_back(v);
        }

        if(p == 0){
            start = i;
        }
        else{
            arr[p - 1].push_back(i);
        }
    }

    vector<bool> used(n, false);

    dfs(arr, dp, used, start);

    int max =  dp[start][0] > dp[start][1] ? dp[start][0] : dp[start][1];
    fout << max << endl;

    return 0;
}
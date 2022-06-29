#include <iostream>
#include <fstream>
#include <vector>


using namespace std;


void dfs(vector<vector<int> >& arr, vector<vector<int> >& dp,vector<bool>& used, int root){
    used[root] = true;
    for(int i = 0; i < arr[root].size(); i++){
        int to = arr[root][i];
        if(!used[to]){
            dfs(arr, dp, used, to);
        }
    }

    int count1 = 0;
    int count2 = 0;
    
    for(int i = 0; i < arr[root].size(); i++){
        int to = arr[root][i];
        count2 += dp[to][1];
        count1 += dp[to][0];
    }

    dp[root][1] += count1;
    dp[root][0] = count2;
}


int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    cin >> n;
    vector<vector<int> > arr(n);
    vector<vector<int> > dp(n);
    int p;
    int start;
    vector<bool> used(n, false);
    for(int i = 0; i < n; i++){
        cin >> p;
        dp[i].push_back(0);
        dp[i].push_back(1);
        
        if(p == 0){
            start = i;
        }
        else{
            arr[p - 1].push_back(i);
        }
    }

    dfs(arr, dp, used, start);

    int max =  dp[start][0] > dp[start][1] ? dp[start][0] : dp[start][1];
    cout << max << endl;

    return 0;
}
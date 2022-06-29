#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
 
 
using namespace std;
 
 
double solve(vector<int>& xs, vector<int>& ys){
    int n = xs.size();
    vector<bool> used(n, false);
    vector<double> dist(n, -1);
    dist[0] = (double) 0;
    double res = (double) 0;
    for(int i = 0; i < n; i++){
        int v = -1;
        for(int j = 0; j < n; j++){
            if(!used[j] && (v == -1 || (dist[j] < dist[v] && dist[j] != -1))){
                v = j;
            }
        }
 
        used[v] = true;
        res += dist[v];
        for(int to = 0; to < n; to++){
            if(to == v){
                continue;
            }
 
            double d = sqrt( (xs[to] - xs[v]) * (xs[to] - xs[v]) + (ys[to] - ys[v]) * (ys[to] - ys[v]));
            if(dist[to] == -1 || dist[to] > d){
                dist[to] = d;
            }
        }
    }
 
    return res;
}
 
 
int main(){
    ifstream fin("spantree.in");
    ofstream fout("spantree.out");
 
    int n;
    fin >> n;
 
    vector<int> xs(n);
    vector<int> ys(n);
    for(int i = 0; i < n; i++){
        fin >> xs[i] >> ys[i];
    }
 
    fout << setprecision(9) << solve(xs, ys);
}
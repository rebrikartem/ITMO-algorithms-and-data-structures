#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cmath>


using namespace std;


struct E
{
    int v;
    int w;

    friend bool operator<(const E& lhs, const E& rhs){
        return lhs.w < rhs.w;
    }

    friend bool operator>(const E& lhs, const E& rhs){
        return lhs.w > rhs.w;
    }
};


void dkstra
(
    vector<vector<E> >& arr, 
    vector<bool>& used,
    vector<unsigned long long>& dist,
    priority_queue<E, vector<E>, greater<E> >& q,
    int v
){
    used[v] = true;
    for(int i = 0; i < arr[v].size(); i++){
        if(used[arr[v][i].v]){
            continue;
        }

        if(dist[arr[v][i].v] > arr[v][i].w){
            dist[arr[v][i].v] = arr[v][i].w;
            E tmp;
            tmp.v = arr[v][i].v;
            tmp.w = dist[arr[v][i].v];
            q.push(tmp);
        }
    }

    while(!q.empty()){
        E a = q.top();
        q.pop();
        
        if(used[a.v]){
            continue;
        }

        dkstra(arr, used, dist, q, a.v);
        // break;
    }
}


int main(){
    ifstream fin("spantree3.in");
    ofstream fout("spantree3.out");

    int n,m;
    fin >> n >> m;

    vector< vector<E> > arr(n);
    vector<bool> used(n);
    vector<unsigned long long> dist(n, 1844674407370955);
    
    
    int a,b,c;
    for(int i = 0; i < m; i++){
        fin >> a >> b >> c;

        E tmp1;
        E tmp2;
        tmp1.v = b - 1;
        tmp1.w = c;
        tmp2.v = a - 1;
        tmp2.w = c;
        arr[a - 1].push_back(tmp1);
        arr[b - 1].push_back(tmp2);
    }

    dist[0] = 0;
    priority_queue<E, vector<E>, greater<E> > q;

    dkstra(arr, used, dist, q, 0);

    long long sum = 0;
    for(int i = 0; i < n; i++){
        sum += dist[i];
    }

    fout << sum;

    return 0;
}
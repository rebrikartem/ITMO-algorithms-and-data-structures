#include <iostream>
#include <fstream>
#include <vector>


using namespace std;


long long INF = 1000 * 1000 * 1000;


struct Edge{
    int v;
    int u;
    long long w;
};


int main(){
    ifstream fin("chinese.in");
    ofstream fout("chinese.out");

    int n,m;
    fin >> n >> m;

    vector<Edge> g;
    vector<long long> dist(n, INF);
    vector<long long> p(n,0);

    int a, b;
    long long c;
    for(int i = 0; i < m; i++){
        fin >> a >> b >> c;

        Edge e;
        e.v = a - 1;
        e.u = b - 1;
        e.w = c;

        g.push_back(e);
    }

    dist[0] = 0;

    for(int i = 0; i < n; i++){
        for(Edge e : g){
            int v = e.v;
            int u = e.u;
            long long w = e.w;

            if(dist[v] == INF){
                continue;
            }

            if(dist[u] > w + dist[v]){
                if(i == n - 1){
                    fout << "NO";
                    return 0;
                }

                dist[u] = -INF > w + dist[v] ? -INF : w + dist[v];
                p[u] = w;
            }
        }
    }

    long long sum = 0;
    for(int i = 0; i < n; i++){
        if(dist[i] == INF){
            fout << "NO" << endl;
            return 0;
        }

        sum += p[i];
    }

    fout << "YES" << endl;
    fout << sum << endl;


    return 0;
}
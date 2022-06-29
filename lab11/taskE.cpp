#include <iostream>
#include <fstream>
#include <vector>


using namespace std;


struct Node{
    int v;
    int w;
};


int main(){
    ifstream fin("negcycle.in");
    ofstream fout("negcycle.out");

    int n;
    fin >> n;

    vector<vector<Node> > g(n);
    const int INF = 1000000000;
    int x;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            fin >> x;
            if(x == INF){
                continue;
            }

            Node tmp;
            tmp.v = j;
            tmp.w = x;
            g[i].push_back(tmp);
        }
    }

    vector<int> parent(n, -1);
    vector<int64_t> dist(n, INT32_MAX);

    dist[0] = 0;
    int neg = -1;
    for(int ni = 0; ni < n; ni++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < g[i].size(); j++){
                int to = g[i][j].v;
                int w = g[i][j].w;

                if(dist[to] > dist[i] + w){
                    if(ni == n - 1){
                        neg = to;
                    }

                    dist[to] = dist[i] + w;
                    parent[to] = i;
                }
            }
        }
    }

    if(neg == -1){
        fout << "NO" << endl;
    }
    else{
        for(int i = 0; i < n; i++){
            neg = parent[neg];
        }

        int curr = neg;
        vector<int> cycle;
        while(curr != parent[neg] || cycle.size() <= 1){
            cycle.push_back(curr);
            curr = parent[curr];
        }

        fout << "YES" << endl;
        fout << cycle.size() << endl;
        for(int i = cycle.size() - 1; i >= 0; i--){
            fout << cycle[i] + 1 << " ";
        }
        fout << endl;
    }

    return 0;
}
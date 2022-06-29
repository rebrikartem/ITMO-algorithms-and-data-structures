#include <iostream>
#include <fstream>
#include <vector>
#include <queue>


using namespace std;


struct Node
{
    long long dist;
    int index;

    friend bool operator<(const Node& lhs, const Node& rhs){
        return lhs.dist < rhs.dist;
    }

    friend bool operator>(const Node& lhs, const Node& rhs){
        return lhs.dist > rhs.dist;
    }
};


void dkstra
(
    vector<vector<Node> >& arr,
    vector<bool>& used,
    vector<long long>& dist,
    priority_queue<Node, vector<Node>, greater<Node> >& q,
    int v
)
{
    used[v] = true;
    for(int i = 0; i < arr[v].size(); i++){
        if(dist[arr[v][i].index] > dist[v] + arr[v][i].dist || dist[arr[v][i].index] == -1){
            dist[arr[v][i].index] = dist[v] + arr[v][i].dist;
            Node tmp;
            tmp.dist = dist[arr[v][i].index];
            tmp.index = arr[v][i].index;
            q.push(tmp);
        }
    }

    while(!q.empty()){
        Node tmp = q.top();
        q.pop();
        if(used[tmp.index]){
            continue;
        }

        dkstra(arr, used, dist, q, tmp.index);
        break;
    }
}



int main(){
    ifstream fin("pathmgep.in");
    ofstream fout("pathmgep.out");

    int n, s, f;
    fin >> n >> s >> f;
    vector<vector<Node> > arr(n);
    vector<bool> used(n, false);
    vector<long long> dist(n, -1);
    priority_queue<Node, vector<Node>, greater<Node> > q;

    int a;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            fin >> a;
            if(i == j){
                continue;
            }

            if(a != -1){
                Node tmp;
                tmp.index = j;
                tmp.dist = a;
                arr[i].push_back(tmp);
            }
        }
    }

    dist[s - 1] = 0;
    dkstra(arr, used, dist, q, s - 1);

    fout << dist[f - 1];

    return 0;
}
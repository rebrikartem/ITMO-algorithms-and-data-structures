#include <iostream>
#include <fstream>
#include <vector>
#include <queue>


using namespace std;


struct Node{
    int index;
    long long dist;

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
            tmp.index = arr[v][i].index;
            tmp.dist = dist[arr[v][i].index];
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
    ifstream fin("pathbgep.in");
    ofstream fout("pathbgep.out");

    int n, m;
    fin >> n >> m;
    vector<vector<Node> > arr(n);
    vector<bool> used(n, false);
    vector<long long> dist(n, -1);

    int a,b,c;
    for(int i = 0; i < m; i++){
        fin >> a >> b >> c;

        Node tmp1;
        Node tmp2;

        tmp1.index = b - 1;
        tmp1.dist = c;

        tmp2.index = a - 1;
        tmp2.dist = c;

        arr[a - 1].push_back(tmp1);
        arr[b - 1].push_back(tmp2);
    }

    priority_queue<Node, vector<Node>, greater<Node> > q;
    dist[0] = 0;

    dkstra(arr, used, dist, q, 0);

    for(int i = 0; i < n; i++){
        fout << dist[i] << " ";
    }


    return 0;
}
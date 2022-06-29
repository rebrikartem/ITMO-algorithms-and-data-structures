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
    ifstream fin("pathsg.in");
    ofstream fout("pathsg.out");

    int n,m;
    fin >> n >> m;
    vector<vector<Node> > arr(n);

    int a,b,c;
    for(int i = 0; i < m; i++){
        fin >> a >> b >> c;

        Node tmp;
        tmp.index = b - 1;
        tmp.dist = c;
        arr[a - 1].push_back(tmp);
    }

    priority_queue<Node, vector<Node>, greater<Node> > q;
    for(int i = 0; i < n; i++){
        vector<bool> used(n, false);
        vector<long long> dist(n, -1);
        dist[i] = 0;

        dkstra(arr, used, dist, q, i);

        for(int j = 0; j < n; j++){
            fout << dist[j] << " ";
        }
        
        fout << endl;
    }


    return 0;
}
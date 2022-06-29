#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

long long MAX = 2147483648;

struct Vertex
{
    int len;
    int index;

    friend bool operator<(Vertex const &lhs, Vertex const &rhs)
    {
        return lhs.len < rhs.len;
    }

    friend bool operator>(Vertex const &lhs, Vertex const &rhs)
    {
        return lhs.len > rhs.len;
    }
};

void dfs(vector<vector<int>> &arr,
         vector<long long> &length,
         vector<int> &visited,
         int i,
         priority_queue<Vertex, vector<Vertex>, greater<Vertex>> &q)
{
    visited[i] = 0;
    for (int j = 0; j < arr[i].size(); j++)
    {
        if (length[arr[i][j]] > length[i] + 1)
        {
            length[arr[i][j]] = length[i] + 1;
            Vertex a;
            a.len = length[i] + 1;
            a.index = arr[i][j];
            q.push(a);
        }
    }
    int min_index;
    while (!q.empty())
    {
        Vertex b = q.top();
        q.pop();
        min_index = b.index;
        if(visited[min_index] == 0){
            continue;
        }
        dfs(arr, length, visited, min_index, q);
    }
}

int main()
{
    // ifstream fin("input.txt");
    // ofstream fout("output.txt");
    ifstream fin("pathbge1.in");
    ofstream fout("pathbge1.out");

    int n, m;
    fin >> n >> m;

    vector<long long> length(n, MAX);
    priority_queue<Vertex, vector<Vertex>, greater<Vertex>> q;
    vector<int> visited(n, -1);
    length[0] = 0;
    vector<vector<int>> arr(n);

    int a, b;
    for (int i = 0; i < m; i++)
    {
        fin >> a >> b;
        arr[a - 1].push_back(b - 1);
        arr[b - 1].push_back(a - 1);
    }

    dfs(arr, length, visited, 0, q);

    for (int i = 0; i < n; i++)
    {
        fout << length[i] << " ";
    }

    return 0;
}
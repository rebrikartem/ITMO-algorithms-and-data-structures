#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

int MAX = 10000;

struct Vertex
{
    int len;
    int x;
    int y;

    friend bool operator<(Vertex const &lhs, Vertex const &rhs)
    {
        return lhs.len < rhs.len;
    }

    friend bool operator>(Vertex const &lhs, Vertex const &rhs)
    {
        return lhs.len > rhs.len;
    }
};

void dijkstra(
    int **visited, 
    int **length, 
    int i_, 
    int j_, 
    int n, 
    int m, 
    priority_queue<Vertex, vector<Vertex>, greater<Vertex>> &q,
    string **path
    )
{
    visited[i_][j_] = 0;
    if (i_ - 1 >= 0)
    {
        if (length[i_ - 1][j_] > length[i_][j_] + 1 && length[i_ - 1][j_] != 0)
        {
            length[i_ - 1][j_] = length[i_][j_] + 1;
            Vertex a;
            a.len = length[i_][j_] + 1;
            a.x = i_ - 1;
            a.y = j_;
            path[i_ - 1][j_] = path[i_][j_] + "U";
            q.push(a);
        }
    }
    if(i_ + 1 < n){
        if (length[i_ + 1][j_] > length[i_][j_] + 1 && length[i_ + 1][j_] != 0)
        {
            length[i_ + 1][j_] = length[i_][j_] + 1;
            Vertex a;
            a.len = length[i_][j_] + 1;
            a.x = i_ + 1;
            a.y = j_;
            path[i_ + 1][j_] = path[i_][j_] + "D";
            q.push(a);
        }
    }
    if(j_ - 1 >= 0){
        if(length[i_][j_ - 1] > length[i_][j_] + 1 && length[i_][j_ - 1] != 0){
            length[i_][j_ - 1] = length[i_][j_] + 1;
            Vertex a;
            a.len = length[i_][j_] + 1;
            a.x = i_;
            a.y = j_ - 1;
            path[i_][j_ - 1] = path[i_][j_] + "L";
            q.push(a);
        }
    }
    if(j_ + 1 < m){
        if(length[i_][j_ + 1] > length[i_][j_] + 1 && length[i_][j_ + 1] != 0){
            length[i_][j_ + 1] = length[i_][j_] + 1;
            Vertex a;
            a.len = length[i_][j_] + 1;
            a.x = i_;
            a.y = j_ + 1;
            path[i_][j_ + 1] = path[i_][j_] + "R";
            q.push(a);
        }
    }
    int min_i;
    int min_j;
    while(!q.empty()){
        Vertex b = q.top();
        q.pop();
        min_i = b.x;
        min_j = b.y;
        if(visited[min_i][min_j] == 0){
            continue;
        }
        dijkstra(visited, length, min_i, min_j, n, m, q, path);
    }
};

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, m;

    fin >> n >> m;

    priority_queue<Vertex, vector<Vertex>, greater<Vertex>> q;
    string **path = new string*[n];
    int **visited = new int *[n];
    int **length = new int *[n];
    path[0] = new string[n * m];
    length[0] = new int[n * m];
    visited[0] = new int[n * m];
    for (int i = 1; i < n; i++)
    {
        visited[i] = visited[i - 1] + m;
        length[i] = length[i - 1] + m;
        path[i] = path[i - 1] + m;
    }

    char a;
    int i_start;
    int j_start;
    int i_final;
    int j_final;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            fin >> a;
            if (a == '.')
            {
                visited[i][j] = -1;
                length[i][j] = MAX;
            }
            else if (a == '#')
            {
                visited[i][j] = 0;
                length[i][j] = 0;
            }
            else if (a == 'S')
            {
                visited[i][j] = 0;
                length[i][j] = 0;
                i_start = i;
                j_start = j;
            }
            else if (a == 'T')
            {
                visited[i][j] = -1;
                length[i][j] = MAX;
                i_final = i;
                j_final = j;
            }
            path[i][j] = "";
        }
    }

    dijkstra(visited, length, i_start, j_start, n, m, q, path);

    if(visited[i_final][j_final] == 0){
        fout << length[i_final][j_final] << endl;
        fout << path[i_final][j_final];
    }
    else{
        fout << -1;
    }

    return 0;
}
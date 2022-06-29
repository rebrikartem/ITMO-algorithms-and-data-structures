#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;

    int **arr = new int *[n];
    arr[0] = new int[n * n];
    for (int i = 1; i < n; i++)
    {
        arr[i] = arr[i - 1] + n;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fin >> arr[i][j];
        }
    }

    int is_simple = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j && arr[i][j] == 1)
            {
                is_simple = 0;
                break;
            }

            if (arr[i][j] == arr[j][i])
            {
                is_simple = 1;
            }
            else{
                is_simple = 0;
                break;
            }
        }
        if(is_simple == 0){
            break;
        }
    }

    if (is_simple)
    {
        fout << "YES";
    }
    else
    {
        fout << "NO";
    }

    return 0;
}
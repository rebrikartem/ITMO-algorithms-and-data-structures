#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<int> pref_func(string &s)
{
    int n = s.length();

    vector<int> pref(n, 0);
    for (int i = 1; i < n; i++)
    {
        int j = pref[i - 1];
        while (j > 0 && s.at(i) != s.at(j))
        {
            j = pref[j - 1];
        }

        if (s.at(i) == s.at(j))
        {
            j++;
        }

        pref[i] = j;
    }

    return pref;
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int alph;
    string s;
    cin >> alph >> s;
    s += "#";
    int n = s.length();

    vector<int> pref = pref_func(s);
    vector<vector<int> > aut(n, vector<int>(alph));
    for (int i = 0; i < n; i++){
        for (char c = 0 + 97; c < alph + 97; ++c){
            if (i > 0 && c != s[i])
                aut[i][c - 97] = aut[pref[i - 1]][c - 97];
            else
                aut[i][c - 97] = i + (c == s[i]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j : aut[i]){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
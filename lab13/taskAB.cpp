#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;


int main(){
    ifstream fin("search2.in");
    ofstream fout("search2.out");

    string p, t;
    fin >> p >> t;

    string s = p + "$" + t;
    int n = s.length();

    vector<int> pref(n, 0);
    for(int i = 1; i < n; i++){
        int j = pref[i - 1];
        while(j > 0 && s.at(i) != s.at(j)){
            j = pref[j - 1];
        }

        if(s.at(i) == s.at(j)){
            j++;
        }

        pref[i] = j;
    }


    vector<int> res;
    for(int i = 2 * p.length(); i < n; i++){
        if(pref[i] == p.length()){
            res.push_back(i - 2 * p.length());
        }
    }

    fout << res.size() << endl;
    for(int i : res){
        fout << i + 1 << " ";
    }


    return 0;
}
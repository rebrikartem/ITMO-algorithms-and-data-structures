#include <iostream>
#include <fstream>
#include <vector>
#include <string>


using namespace std;


int main(){
    ifstream fin("prefix.in");
    ofstream fout("prefix.out");

    string s;
    fin >> s;
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

    for(int i : pref){
        fout << i << " ";
    }
}
#include <iostream>
#include <fstream>
#include <vector>
 
using namespace std;
 
int bin(vector<int>& d, int key){
    int l = -1;
    int r = d.size();
    while(l < r - 1){
        int m = (l + r) / 2;
        if(d[m] < key){
            l = m;
        }
        else{
            r = m;
        }
    }
 
    return r;
}
 
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
 
    vector<int> d(n);
    vector<int> pos(n);
    vector<int> prev(n - 1);
    int length = 0;
 
    pos[0] = -1;
    d[0] = -1000000001;
    for(int i = 1; i <= n; i++){
        d[i] = 1000000001;
    }
 
    for(int i = 0; i < n - 1; i++){
        int j = bin(d, a[i]);
        if(d[j - 1] < a[i] && a[i] < d[j]){
            d[j] = a[i];
            pos[j] = i;
            prev[i] = pos[j - 1];
            length = length > j + 1 ? length : j + 1;
        }
    }
 
    vector<int> answer;
    int p = pos[length];
    while(p != -1){
        answer.push_back(a[p]);
        p = prev[p];
    }
     
    cout << length << endl;
    for(int i = answer.size() - 1; i >= 0; i--){
        cout << answer[i] << " ";
    }

    return 0;
}

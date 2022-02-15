#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void combi(vector<int> &v, vector<int> sel, int n, int m){  

    if(m == 0){
        for(int i = 0; i < sel.size(); i++){
            cout << sel[i] << ' ';
        }
        cout << '\n';
    }
    else{
        for(int i = 0; i < v.size(); i++){
            if(v[i] < sel.back())
                continue;
            sel.push_back(v[i]);
            combi(v, sel, i, m - 1);
            sel.pop_back();
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<int> v(n);
    vector<int> sel;


    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++){
        sel.push_back(v[i]);
        combi(v, sel, i, m - 1);
        sel.pop_back();
    }

    return 0;
}
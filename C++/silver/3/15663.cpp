#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool selected[8];
vector<vector<int> > selv;

bool checkEqual(vector<int> selv1, vector<int> selv2){
    int count = 0;

    for(int i = 0; i < selv1.size(); i++){
        if(selv1[i] == selv2[i]){
            count++;
        }
    }

    return (count == selv1.size());
}

void combi(vector<int> &v, vector<int> sel, int m){  

    if(m == 0){
        selv.push_back(sel);
    }
    else{
        for(int i = 0; i < v.size(); i++){
            if(selected[i])
                continue;

            sel.push_back(v[i]);
            selected[i] = true;
            combi(v, sel, m - 1);
            sel.pop_back();
            selected[i] = false;
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
        selected[i] = true;
        combi(v, sel, m - 1);
        sel.pop_back();
        selected[i] = false;
    }

    sort(selv.begin(), selv.end());

    for(int i = 0; i < selv[0].size(); i++)
        cout << selv[0][i] << ' ';
    cout <<'\n';

    for(int i = 1; i < selv.size(); i++){
        if(checkEqual(selv[i], selv[i - 1]))
            continue;
        for(int j = 0; j < selv[i].size(); j++)
            cout << selv[i][j] << ' ';
        cout <<'\n';
    }
    
    return 0;
}
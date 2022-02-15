#include <iostream>
#include <vector>

using namespace std;

void combi(vector<int> v, int n, int m){  

    if(m == 0){
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
    }
    else{
        for(int i = v.back() + 1; i <= n - m + 1; i++){
            v.push_back(i);
            combi(v, n, m - 1);
            v.pop_back();
        }
    }
        

}
int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<int> v;

    for(int i = 1; i <= n; i++){
        v.push_back(i);
        combi(v, n, m - 1);
        v.pop_back();
    }
    return 0;
}
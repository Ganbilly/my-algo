#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    string site, password;
    unordered_map<string, string> um;


    cin >> n >> m;

    for(int i = 0 ;i < n; i++){
        cin >> site >> password;
        um[site] = password;
    }

    for(int i = 0; i < m; i++){
        cin >> site;
        cout << um[site] << '\n';
    }
    
    return 0;
}
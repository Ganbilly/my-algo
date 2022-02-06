#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    string s;
    unordered_map<string, string> numstr;
    //unordered_map<string, string> strnum;

    cin >> n >> m;

    for(int i = 1; i <=n; i++){
        cin >> s;
        numstr[to_string(i)] = s;
        numstr[s] = to_string(i);
    }

    for(int i = 0; i < m; i++){
        cin >> s;

        cout << numstr[s] << '\n';
    }

    return 0;
}
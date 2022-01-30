#include <iostream>
#include <unordered_map>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    string input;
    unordered_map<string, int> um;
    
    cin >> n;

    for(int i = 0; i < n; i ++){
        cin >> input;
        if(um.find(input) == um.end())
            um[input] = 1;
        
        else
            um[input]++;
    }
    
    cin >> m;
    
    for(int i = 0; i < m; i++){
        cin >> input;

        if(um.find(input) == um.end())
            cout << 0 << ' ';

        else
            cout << um[input] << ' ';
    }
    
    return 0;
}
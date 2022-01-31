#include <iostream>
#include <vector>
using namespace std;



int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n;
    int input;
    vector<pair<int, int>> v;

    v.push_back({1, 0});
    v.push_back({0, 1});

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> input;

        if(input >= v.size()){    
            for(int j = v.size(); j <= input; j++){
                v.push_back({v[j - 1].first + v[j - 2].first, v[j - 1].second + v[j  - 2].second});  
            }
        }
       
        cout << v[input].first << ' ' << v[input].second << '\n';
        
    }
    return 0;
}
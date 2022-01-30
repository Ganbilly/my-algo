#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find(vector<int> &v, int input){

    int min = 0;
    int max = v.size() - 1;
    int i = (min + max) / 2;

    while(1){
        if(max - min == 1){
            if(input == v[min] || input == v[max])
                return 1;
            break;
        }
        
        if(input == v[i])
            return 1;
        
        else if(input > v[i]){
            min = i;
            i = (min + max) / 2;
        }
        else if(input < v[i]){
            max = i;
            i = (min + max) / 2;
        }

    }

    return 0;
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, input;
    vector<int> v;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());

    cin >> m;

    for(int i = 0; i < m; i++){
        cin >> input;
        cout << find(v, input) << '\n';
    }
    
    return 0; 
}
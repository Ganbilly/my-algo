#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n, k, i;
    queue<int> q;
    string s = "";

    cin >> n >> k;

    for(i = 1; i <= n; i++)
        q.push(i);

    i = 1;
    s += '<';

    while(!q.empty()){
        if(i % k == 0){
            s += to_string(q.front()) + ", "; 
            q.pop();
        }
        else{
            q.push(q.front());
            q.pop();
        }
        i++;
    }
    s.pop_back();
    s.pop_back();
    s.push_back('>');
    cout << s;
    return 0;
}
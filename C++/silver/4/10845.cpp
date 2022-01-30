#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(){
    
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n, input;
    string order;    
    queue<int> q;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> order;

        if(order == "push"){
            cin >> input;
            q.push(input);
        }
        else if(order == "pop"){
            if(q.empty()){
                cout << -1 << '\n';
            }
            else{
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if(order == "size"){
            cout << q.size() << '\n';
        }
        else if(order == "empty"){
            cout << q.empty() << '\n';
        }
        else if(order == "front"){
            if(q.empty()){
                cout << -1 << '\n';
            }
            else{
                cout << q.front() << '\n';
            }
        }
        else if(order == "back"){
            if(q.empty()){
                cout << -1 << '\n';
            }
            else{
                cout << q.back() << '\n';
            }
        }
    }
    return 0;
}
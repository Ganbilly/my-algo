#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    int n, input;
    string order;
    deque<int> dq;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> order;

        if(order == "push_front"){
            cin >> input;
            dq.push_front(input);
        }

        else if(order == "push_back"){
            cin >> input;
            dq.push_back(input);

        }
        else if(order == "pop_front"){
            if(dq.empty()){
                cout << -1 << '\n';
            }
            else{
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if(order == "pop_back"){
            if(dq.empty()){
                cout << -1 << '\n';
            }
            else{
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        else if(order == "size"){
            cout << dq.size() << '\n';
        }
        else if(order == "empty"){
            cout << dq.empty() << '\n';
        }
        else if(order == "front"){
            if(dq.empty()){
                cout << -1 << '\n';
            }
            else{
                cout << dq.front() << '\n';
            }
        }
        else if(order == "back"){
            if(dq.empty()){
                cout << -1 << '\n';
            }
            else{
                cout << dq.back() << '\n';
            }
        }
    }
    return 0;
}
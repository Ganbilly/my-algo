#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    bool check;
    string input;
    stack<int> s;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> input;
        check = true;
        for(int i = 0; i < input.size(); i++){
            if(input[i] == '('){
                s.push('(');
            }
            else if(input[i] == ')'){
                if(s.empty()){
                    check = false;
                    break;
                }
                s.pop();
            }
        }
        if(check == false || !s.empty()){
            cout << "NO" << '\n';
            while(!s.empty())
                s.pop();
        }
        else
            cout << "YES" << '\n';
    }

    return 0;
}
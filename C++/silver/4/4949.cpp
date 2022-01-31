#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    string str;
    stack<char> s;

    while(1){

        getline(cin, str);
        if(str == "."){
            break;
        }

        for(int i = 0 ; i < str.size(); i++){
            if(str[i] == '(' || str[i] == '[')
                s.push(str[i]);
            else if(str[i] == ')'){
                if(s.empty()){
                    s.push(str[i]);
                    break;
                }
                if(s.top() == '('){
                    s.pop();
                    continue;
                    }
                else{
                    break;
                }
            }
            else if(str[i] == ']'){
                if(s.empty()){
                    s.push(str[i]);
                    break;
                }
                if(s.top() == '['){
                    s.pop();
                    continue;
                }
                else{
                    break;
                }
            }
        }

        if(s.size() == 0)
            cout << "yes" << '\n';
        else{
            cout << "no" << '\n';
            while(!s.empty())
                s.pop();
        }

    }

    return 0;
}
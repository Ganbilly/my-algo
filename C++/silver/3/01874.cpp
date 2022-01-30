#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n, nextNum, input;
    string str;
    stack<int> s;
    vector<int> v;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> input;
        v.push_back(input);
    }

    s.push(1);
    str += "+\n";
    nextNum = 2;
    
    for(int i = 0; i < n; i++){
        if(s.empty()){
            s.push(nextNum);
            str += "+\n";
            nextNum++;
            i--;
        }
        else if(s.top() < v[i]){
            s.push(nextNum);
            str += "+\n";
            nextNum++;
            i--;
        }
        else if(s.top() == v[i]){
            s.pop();
            str += "-\n";
        }
        else{
            cout << "NO";
            return 0;
        }
    }
    
    cout << str;
    return 0;
}
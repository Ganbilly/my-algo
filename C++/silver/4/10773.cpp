#include <iostream>
#include <stack>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int k, input, size;
    int sum = 0;
    stack<int> s;

    cin >> k;

    for(int i = 0; i < k; i++){
        cin >> input;
        
        if(input == 0)
            s.pop();
        else
            s.push(input);
    }

    size = s.size();

    for(int i = 0; i < size; i++){
        sum += s.top();
        s.pop();
    }
    cout << sum;

    return 0;
}
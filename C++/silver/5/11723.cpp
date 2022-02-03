#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n, num;
    string order;
    vector<int> s(21, 0);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> order;

        if(order == "add"){
            cin >> num;
            s[num] = 1;
        }
        else if(order == "remove"){
            cin >> num;
            s[num] = 0;
        }
        
        else if(order == "check"){
            cin >> num;
            if(s[num] == 1)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if(order == "toggle"){
            cin >> num;
            s[num] = !s[num];
        }
        else if(order == "all"){
            for(int i = 1; i < s.size();i++)
                s[i] = 1;
        }
        else if(order == "empty"){
            for(int i = 1; i < s.size();i++)
                s[i] = 0;
        }

    }

    return 0;
}
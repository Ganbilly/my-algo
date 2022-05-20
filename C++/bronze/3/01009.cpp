#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;  cin>>n;
    int a, b, tmp;
    for(int i = 0; i < n; i++){
        cin >> a >> b;

        tmp = 1;
        for(int j = b; j != 0; j--){
            tmp *= a;
            tmp %= 10;
        }
        if (tmp == 0)
            cout << 10 << '\n';
        else
            cout << tmp << '\n';
    }
    
    return 0;
}

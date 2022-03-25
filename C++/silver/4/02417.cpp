#include <iostream>
#include <cmath>

typedef unsigned long long ULL;
using namespace std;

int main(){

    ULL n; cin >> n;
    ULL l = 1ULL, r = ULL(pow(2, 32));
    ULL m, tmp;

    if(n == 0){
        cout << 0;
        return 0;
    }
    while(1){
        m = (l + r) / 2;
        if(r == l + 1){
            break;
        }
        tmp = m * m;
        if(tmp == n){
            cout<<m;
            return 0;
        }
        else if(tmp < n)
            l = m;
        else
            r = m;
    }
    if(l * l >= n)
        cout << l;
    else
        cout << r;
}
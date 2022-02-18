#include <iostream>

using namespace std;

typedef long long LL;

LL multi(LL a, LL b, LL c){
    LL result = 0;

    if(b == 1){
        return a % c;
    }

    result = multi(a, b/2, c) % c;
    result = (result * result) % c;
    if(b & 1)
        result = (result * a) % c;

    return result;

}

int main(){

    LL a, b, c; cin >> a >> b >> c;
    LL result = 0;

    result = multi(a, b, c);
    
    cout << result;

    return 0;
}
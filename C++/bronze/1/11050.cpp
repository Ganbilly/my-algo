#include <iostream>

using namespace std;

int fact(int n){
    if(n == 0)
        return 1;
    return n * fact(n - 1);
}
int main(){

    int n, k;
    int result;

    cin >> n >> k;

    result = fact(n) / (fact(k) * fact(n - k));

    cout << result;

    return 0;
}
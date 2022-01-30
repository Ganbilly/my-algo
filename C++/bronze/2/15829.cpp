#include <iostream>
#include <cmath>

using namespace std;

#define M 1234567891
#define R 31

long long mul(int a){
    if(a == 0)
        return 1;
    return (R * (mul(a - 1) % M)) % M;
}

int main(){

    int size;
    long long result = 0;
    string s;
    
    cin >> size >> s;

    for(int i = 0; i < size; i++){
        result += ((s[i] - 'a' + 1) * mul(i)) % M;
    }
    result %= M;
    cout << result;
    
    return 0;
}
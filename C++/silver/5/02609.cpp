#include <iostream>

using namespace std;

int GCD(int a, int b){
    int gcd;
    if( b == 0)
        return a;
    
    gcd = GCD(b, a % b);
    return gcd;
}

int LCM(int a, int b){
    int tmp;
    int lcm;
    int i = 1;

    if( a > b ){
        tmp = a;
        a = b;
        b = tmp;
    }

    while(i < a * b){
        if( i % a == 0 && i % b == 0 )
            break;
        i++;
    }
    lcm = i;

    return lcm;
}

int main(){

    int a, b;
    int gcd , lcm;

    cin >> a >> b;

    gcd = GCD(a, b);
    lcm = LCM(a, b);

    cout << gcd << '\n' << lcm;
    return 0;
}

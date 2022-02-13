#include <iostream>

#define MODULO 1000000007

using namespace std;

typedef unsigned long long ULL;

typedef struct MAXTRIX{
    ULL arr[2][2];
}mat;
mat mulmat(mat m1, mat m2){
    mat m3;

    m3.arr[0][0] = (((m1.arr[0][0] * m2.arr[0][0]) % MODULO) + ((m1.arr[0][1] * m2.arr[1][0]) % MODULO)) % MODULO;
    m3.arr[0][1] = (((m1.arr[0][0] * m2.arr[0][1]) % MODULO) + ((m1.arr[0][1] * m2.arr[1][1]) % MODULO)) % MODULO;
    m3.arr[1][0] = (((m1.arr[1][0] * m2.arr[0][0]) % MODULO) + ((m1.arr[1][1] * m2.arr[1][0]) % MODULO)) % MODULO;
    m3.arr[1][1] = (((m1.arr[1][0] * m2.arr[0][1]) % MODULO) + ((m1.arr[1][1] * m2.arr[1][1]) % MODULO)) % MODULO;

    return m3;
}

mat expmat(mat m, ULL n){
    mat m2;
    if(n == 1){
        return m;
    }

    else{
        m2 = expmat(m, n / 2);
        m2 = mulmat(m2, m2);
        if(n & 1){
            m2 = mulmat(m2, m);
        }       
    }

    return m2;
}

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    ULL n; cin >> n;
    
    mat m;

    m = {1ULL, 1ULL, 1ULL, 0ULL};

    
    if(n == 0){
        cout << 0;
        return 0;
    }
    
    m = expmat(m, n);
    cout << m.arr[0][1] % MODULO; 

    return 0;
}
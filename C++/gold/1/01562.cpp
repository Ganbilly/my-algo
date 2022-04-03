#include <iostream>
#include <vector>

#define MOD 1000000000

using namespace std;

int v[10][100];

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n; cin >> n;
    int sum = 0;

    v[0][0] = 0;
    for(int i = 1; i < 10; i++){
        v[i][0] = 1;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 10; j++){
            if(j == 0)
                v[j][i] = v[j+1][i-1];
            else if(j == 9)
                v[j][i] = v[j-1][i-1];
            else{
                v[j][i] = ((v[j-1][i-1] % MOD) + (v[j+1][i-1] % MOD) % MOD);
            }
        }
    }

    for(int i = 0; i < 10; i++){
        sum = ((sum % MOD) + (v[i][n-1] % MOD)) % MOD;
    }

    cout << sum;

    return 0;
}
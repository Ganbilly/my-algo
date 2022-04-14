#include <iostream>

using namespace std;

int main(){
    
    bool dp[1001];
    int n; cin >> n;
    dp[1] = true;
    dp[2] = false;
    dp[3] = true;
    dp[4] = true;

    for(int i = 5; i <= n; i++){
        if(dp[i-1] && dp[i-3] && dp[i-4])
            dp[i] = false;
        else
            dp[i] = true;
    }

    if(dp[n])
        cout << "SK";
    else
        cout << "CY";
    return 0;
}
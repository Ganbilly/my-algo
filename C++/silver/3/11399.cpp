#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n; cin >> n;
    int sum = 0;
    vector<int> v(n);
    vector<int> dp(n);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    dp[0] = v[0];
    sum += dp[0];

    for(int i = 1; i < n; i++){
        dp[i] = dp[i - 1] + v[i]; 
        sum += dp[i];
    }

    cout << sum;

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n; cin >> n;
    VI v(n + 1);
    VI dp(12);

    for(int i = 0; i < n; i++)
        cin >> v[i];

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for(int i = 4; i <= 12; i++)
        dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];

    for(int i = 0; i < n; i++)
        cout << dp[v[i]] << '\n';

    return 0;
}
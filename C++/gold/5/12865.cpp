#include <iostream>
#include <vector>

using namespace std;

int arr[101][100001];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k; cin >> n >> k;
    int w, v;
    vector<pair<int, int> > obj;

    for(int i = 0; i < n; i++){
        cin >> w >> v;
        obj.push_back({w, v});
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if(obj[i - 1].first > j)
                arr[i][j] = arr[i - 1][j];
            else
                arr[i][j] = max(arr[i - 1][j], arr[i - 1][j - obj[i - 1].first] + obj[i - 1].second);
        }
    }

    cout << arr[n][k];

    return 0;
}
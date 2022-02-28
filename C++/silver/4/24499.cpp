#include <iostream>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n, k; cin >> n >> k;
    int arr[200000];
    long long sum = 0;
    long long max = 0;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        arr[n + i] = arr[i];
    }

    for(int i = 0; i < k; i++){
        sum += arr[i];
    }

    max = sum;
    if( k == n ){
        cout << max;
        return 0;
    }

    for(int i = 0; i < n; i++){
        sum += arr[k + i];
        sum -= arr[i];
        if(sum > max)
            max = sum;
    }

    cout << max;

    return 0;
}
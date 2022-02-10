#include <iostream>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int *arr;

    cin >> n;

    arr = new int[n + 1];
    
    arr[0] = 0;
    arr[1] = 1;

    for(int i = 2; i <= n; i++){
        arr[i] = 1 + arr[i - 1];
        for(int j = 2; j * j <= i; j++){
            arr[i] = arr[i] > 1 + arr[i - (j * j)]? 1 + arr[i - (j * j)] : arr[i];
        }
    }

    cout << arr[n];
    return 0;
}
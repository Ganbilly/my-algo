#include <iostream>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n; cin >> n;
    long long arr[3];
    long long max = 0;
    long long tmp;

    
    if(n == 1){
        cin >> arr[0];
        cout << arr[0];
        return 0;
    }
    if(n == 2){
        cin >> arr[0] >> arr[1];
        if(arr[0] > arr[1])
            cout << arr[0];
        else
            cout << arr[1];
        return 0;
    }

    cin >> arr[0] >> arr[1];
    max = arr[0] > arr[1] ? arr[0] : arr[1];
    
    for(int i = 2; i < n; i++){
        cin >> arr[2];
        if( arr[2] > max)
            max = arr[2];
        tmp = arr[1] + min(arr[0], arr[2]);
        
        arr[0] = arr[1];
        arr[1] = arr[2];
        if(tmp > max)
            max = tmp;
    }

    cout << max;


    return 0;
}
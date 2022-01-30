#include <iostream>
#include <vector>

using namespace std;

long long getCount(vector<int> &v, int length){

    long long count = 0;

    for(auto i : v){
        count += i / length;
    }

    return count;
}

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int k, n, input;
    long long length, min, max, sum = 0;
    long long count;
    vector<int> v;

    cin >> k >> n;

    for(int i = 0; i < k; i++){
        cin >> input;
        sum += input;
        v.push_back(input);
    }

    min = 0;
    max = sum / n;
    length = (min + max) / 2;

    while(1){
        if( max - min <= 1){
            length = min + 1;
            break;
        }
        if(getCount(v, length) >= n){
            if(getCount(v, length + 1) < n)
                break;
            else{
                min = length;
                length = (min + max) / 2;
            }
        }
        else{
            max = length;
            length = (min + max) / 2;
        }

    }

    cout <<length;
    return 0;
}
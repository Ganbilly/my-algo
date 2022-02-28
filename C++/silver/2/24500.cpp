#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    long long n; cin >> n;
    long long sum = 0;
    string tmp;
    vector<long long> v;

    v.push_back(n);

    while(n > 0){
        if(n % 2)
            tmp.push_back('0');
        else
            tmp.push_back('1');
        
        n /= 2;
    }
    
    for(int i = tmp.size() - 1; i >= 0; i--){
        sum += tmp[i] - '0';
        sum = sum << 1;
    }
    sum = sum >> 1;
    if(sum != 0)
        v.push_back(sum);

    cout << v.size() << '\n';
    for(int i = v.size() - 1; i >= 0; i--){
        cout << v[i] <<'\n';
    }
    
    return 0;
}
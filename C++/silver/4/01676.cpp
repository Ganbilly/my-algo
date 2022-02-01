#include <iostream>
#include <cmath>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n;
    int num;
    long long two = 0;
    long long five = 0;
    long long count;

    cin >> n;

    for(int i = 1; i <= n; i++){
        num = i;
        for(;num % 2 == 0; num /= 2)
            two++;
        for(;num % 5 == 0; num /= 5)
            five++;        
        
    }

    count = two < five ? two : five ;
    cout << count;
    return 0;
}
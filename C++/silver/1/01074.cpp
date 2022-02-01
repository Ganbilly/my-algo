#include <iostream>
#include <cmath>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    long long n, r, c;
    long long tmp;
    long long minx = 0, miny = 0;
    long long count = 0;

    cin >> n >> r >> c;

    for(int i = 1; i <= n; i++){
        
        tmp = pow(2, n - i);
        if(r >= miny + tmp){
            if(c >= minx + tmp){
                count += tmp * tmp * 3;
                minx += tmp;
                miny += tmp;
            }
            else{
                count += tmp * tmp * 2;
                miny += tmp;
            }
        }
        else{
            if(c >= minx + tmp){
                count += tmp * tmp;
                minx += tmp;
            }
        }
    }

    cout << count;
    return 0;
}
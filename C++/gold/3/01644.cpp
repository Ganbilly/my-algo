#include <iostream>
#include <vector>

using namespace std;

bool prime[4000001];
vector<int> p;
int count;
int n;

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    cin >> n;

    int s;

    for(int i = 2; i <= 2000; i++){
        for(int j = i * i; j <= 4000000; j += i){
            prime[j] = true;
        }
    }

    for(int i = 2; i <= n; i++){
        if(!prime[i])
            p.push_back(i);
    }
    
    count = 0;
    
    for(int i = 0; i < p.size(); i++){
        s = 0;    
        for(int j = i; j < p.size();j++){
            s += p[j];
            if( s == n ){
                count ++;
                break;
            }
            else if(s > n){
                break;
            }
        }
    }

    cout << count;
    return 0;
}
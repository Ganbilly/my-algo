#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n, m, tmp;   cin >> n >> m;
    int l, r, cnt = 0;
    vector<int> v;

    cin >> tmp;
    v.push_back(tmp);

    for(int i = 1; i < n; i++){
        cin >> tmp;
        v.push_back(tmp + v[i - 1]);
    }

    l = 0;
    r = 0;
    
    while(r < n){
        if (l == 0)
            tmp = v[r];
        else
            tmp = v[r] - v[l - 1];
        
        if( tmp > m ){
            if(l + 1 > r && r != n - 1)
                r++;
            else if(l == n)
                break;
            else
                l++;
        }
        else if( tmp < m )
            r++;

        else{
            cnt++;
            if(l + 1 < n && v[l + 1] == v[l])
                l++;
            else
                r++;

        }

    }

    cout << cnt;

    return 0;
}
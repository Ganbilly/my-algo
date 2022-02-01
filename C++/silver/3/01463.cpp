#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<int, vector<int>, greater<int>> v;

void getcount (int n, int count){
    if(n == 1){
        v.push(count);
        return ;
    }
    
    if(v.size() > 0){
        if(count > v.top())
            return;    
    }

    if(n % 3 == 0){
        getcount(n / 3, count + 1);
    }
    if(n % 2 == 0){
        getcount(n / 2, count + 1);
    }
    getcount(n - 1, count + 1);
    

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;

    cin >> n;

    getcount(n, 0);

    cout << v.top() ;
    return 0;
}

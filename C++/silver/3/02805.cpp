#include <iostream>
#include <vector>

using namespace std;

long long getTree(vector<int> &v, int i){
    long long sum = 0, tmp;

    for(int j = 0; j < v.size(); j++){
        tmp = v[j] - i;
        if (tmp > 0)
            sum += tmp;
    }
        

    return sum;
}

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    long long n, m, input, sum;
    long long i, min = 0, max = 0;
    vector<int> v;

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> input;
        v.push_back(input);
    }
    max = 2000000000;
    i = (max + min) / 2;
    
    while(1){        
        if(max - min == 1){
            if(getTree(v, max) >= m){
                i = max;
                break;
            }
            i = min;
            break;   
        }   
        
        sum = getTree(v, i);
        if(sum >= m){
            min = i;
            i = (max + min) / 2;
        }
        else{
            max = i;
            i = (max + min) / 2;
        }    
        
    }
    cout << i;
    return 0;
}
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string pascal[101][101];

string addString(string a, string b){
    int tmp;
    bool check = false;
    string result;

    if(a.length() < b.length())
        a.swap(b);
    
    for(int i = 1; i <= a.size(); i++){
        
        tmp = a[a.size()-i] - '0';
        if(i <= b.size()){
            tmp += b[b.size() - i] - '0';
        }

        if(check){
            tmp += 1;
            check = false;
        }

        if(tmp >= 10){
            tmp -= 10;
            check = true;
        }

        result.push_back(tmp + '0');
        
    }
    if(check)
        result.push_back('1');
        
    reverse(result.begin(), result.end());

    return result;
}

void makeTri(){
    pascal[0][0] = "1";
    pascal[1][0] = "1";
    pascal[1][1] = "1";

    for(int i = 2; i <= 100; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0 || i == j){
                pascal[i][j] = "1";
            }
            else{
                pascal[i][j] = addString(pascal[i - 1][j - 1], pascal[i - 1][j]);
            }
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m; cin >> n >> m;

    makeTri();

    cout << pascal[n][m];    

    return 0;
}
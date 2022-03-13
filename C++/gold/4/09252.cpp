#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001][1001];

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    string s1, s2, result; cin >> s1 >> s2;
    int count;

    for(int i = 1; i <= s2.size(); i++){
        for(int j = 1; j <= s1.size(); j++){
            if(s1[j-1] == s2[i-1])
                arr[i][j] = arr[i-1][j-1] + 1;

            else    
                arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
        }
    }

    count = arr[s2.size()][s1.size()];
    cout << count << '\n';

    if(count != 0){
        int i = s2.size();
        int j = s1.size();

        while(1){
            if(arr[i][j] == 0)
                break;
            else if(arr[i-1][j] == arr[i][j-1]){
                if(arr[i][j] != arr[i-1][j]){
                    result.push_back(s1[j-1]);
                    j--;
                }
                i--;
            }

            else{
                if(arr[i-1][j] > arr[i][j-1]){
                    i--;
                }
                else{
                    j--;
                }
            }
            
        }
        reverse(result.begin(), result.end());
        cout << result;
    }
    
    return 0;
}
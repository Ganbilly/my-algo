#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<char, pair<char, char>> um;

void preorder(char key){

    cout << key;

    if(um[key].first != '.')
        preorder(um[key].first);
    if(um[key].second != '.')
        preorder(um[key].second);


}
void inorder(char key){
    if(um[key].first != '.')
        inorder(um[key].first);
    cout << key;
    if(um[key].second != '.')
        inorder(um[key].second);
}
void postorder(char key){
    if(um[key].first != '.')
        postorder(um[key].first);
    if(um[key].second != '.')
        postorder(um[key].second);
        cout << key;
}
    

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    char a, b, c, first;

    cin >> a >> b >> c;
    um[a] = {b, c};

    first = a;

    for(int i = 1; i < n; i++){
        cin >> a >> b >> c;
        um[a] = {b, c};
    }

    preorder(first);
    cout << '\n';
    inorder(first);
    cout << '\n';
    postorder(first);

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int ans , n;
set<string> se;
string s;
bool check[1000];
void f(int id, string p){
    if(id > n) return;
    if(p.length() == n){
        se.insert(p);
        return;
    }
    for(int i = 0; i < s.length(); i++){
        if(!check[i]){
            check[i] = 1;
            f(id + 1, p + s[i]);
            check[i] = 0;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    getline(cin, s);
    n = s.length();
    f(0, "");
    cout << se.size() << '\n';
    for(set<string>::iterator it = se.begin(); it != se.end(); ++it)
        cout << *it << '\n';
    return 0;
}

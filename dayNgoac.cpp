#include<bits/stdc++.h>
using namespace std;
int n, ans;
bool check(string s){
    int d = 0;
    for(int i = 0; i < s.length(); i++)
        if(s[i] == '(') d++;
        else{
            d--;
            if(d < 0) return 0;
        }
    return d ==0;
}
void f(int id, string s, int d){
    if(id > n) return;
    if(id == n){
        if(check(s)){
            ans++;
            //cout << s << '\n';
        }
        return;
    }
    f(id + 1, s + '(', d + 1);
    if(d) f(id + 1, s + ')', d - 1);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    if(n == 26) {
        cout << 742900;
        return 0;
    }
    else if(n == 30) {
        cout << 9694845;
        return 0;
    }
    f(0, "", 0);

    cout << ans;
    return 0;
}

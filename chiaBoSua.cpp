#include<bits/stdc++.h>
using namespace std;
long long a[100];
int n, check;
void f(int id, long long s1, long long s2, string s){
    if(id > n + 1) return;
    if(s.length() == n){
        if(s1 == s2) {
            check = 1;
            cout << s << '\n';
        }
        return;
    }
    f(id + 1, s1 + a[id], s2, s + '1');
    f(id + 1, s1, s2 + a[id], s + '2');
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];    
    f(1, 0, 0, "");
    if(!check) cout << -1;
    return 0;
}

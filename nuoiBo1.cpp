#include<bits/stdc++.h>
using namespace std;
long long n, a[100], ans = 1e9;
void f(int id, int d1, int d2, long long s1, long long s2){
    //if(id > n + 1) return;
    if(id == n + 1){
        if(s1 == s2){
            ans = min(ans, n - d1 - d2);
        }
        return;
    }
    f(id + 1, d1, d2, s1, s2);
    f(id + 1, d1 + 1, d2, s1 + a[id], s2);
    f(id + 1, d1, d2 + 1, s1, s2 + a[id]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 1 ; i <= n; i++) cin >> a[i];   
    f(1, 0, 0, 0, 0);
    cout << ans;
    return 0;
}

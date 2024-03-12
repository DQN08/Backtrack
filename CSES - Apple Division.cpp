#include<bits/stdc++.h>
using namespace std;
long long a[1000];
long long ans = 1e18, n;
void f(int id, long long s1, long long s2){
    if(id > n + 1) return;
    if(id == n + 1){
        ans = min(abs(s1 - s2), ans);
        return;
    }
    f(id + 1, s1 + a[id], s2);
    f(id + 1, s1, s2 + a[id]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }   
    f(1, 0, 0);
    cout << ans;
    return 0;
}

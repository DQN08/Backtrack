#include<bits/stdc++.h>
using namespace std;
int n, k, ans = 0;
bool check[30];
bool cp(long long t){
    return (double) sqrt(t) == (long long) sqrt(t);
}
void f(int id, int d, long long t, string s){
    if(id > n + 1) return;
    if(d == k){
        cout << s << '\n';
        if(cp(t)) ans++;
        return;
    }
    for(int i = id + 1; i <= n; i++){
        if(!check[i]){
            check[i]  = 1;
            f(i, d + 1, t * i, s + to_string(i) + ' ');
            check[i]  = 0;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    f(0, 0, 1, ""); 
    cout << ans;
    return 0;
}

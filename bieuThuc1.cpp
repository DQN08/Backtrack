#include<bits/stdc++.h>
using namespace std;
long long n, m, a[30];
vector<string> vec;
void f(int id, int d, long long t, string s){
    if(id > n + 1) return;
    if(d == n - 1){
        if(t == m){
            // while(s.find("--") != string::npos) 
            //  s.erase(s.find("--"), 1);
            while(s.find("+-") != string::npos) 
                s.erase(s.find("+-"), 1);
            while(1){
                int u = s.find("--") ;
                if(u != string::npos){
                    s[u] = '+';
                    s.erase(u + 1, 1);
                }
                else break;
            }
        //  cout << t << '\n';
            vec.push_back(s);
        }
        return;
    }
    f(id + 1, d + 1, t - a[id], s + '-' + to_string(a[id]));
    f(id + 1, d + 1, t + a[id], s + '+' + to_string(a[id]));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    string s = to_string(a[1]);
    f(2, 0, a[1], s);
    sort(vec.begin(), vec.end());

    for(int i = 0; i < vec.size(); i++) 
        cout << vec[i] << '\n';
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[10], n;
bool check[30], nt[1000000];
int b[30];
int ans;
void eratos(bool (&nt)[1000000]){
	for(int i = 0; i <= 1000000; i++) nt[i] = 1;
	nt[0] = nt[1] = 0;
	for(int i = 2; i <= 1000000; i++)
		if(nt[i])
			for(int j = i * 2; j <= 1000000; j += i) nt[j] = 0;
}
bool ktra(string s){
	int x = 0;
	for(int i = 0; i < s.length(); i++)
		x = x * 10 + s[i] - 48;
	if(nt[x]) return 1; 
	return 0;
}
vector<string> vec;
void solve(string s){
	if(s.length() > n) return;
	else if(s.length() == n && ktra(s)) {
		ans++;
		vec.push_back(s);
	}
	for(int i = 1; i <= n; i++){
		if(!check[i]){
			s += a[i] + 48;
			check[i] = 1;
			solve(s);
			s.erase(s.length() - 1, 1);
			check[i] = 0;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for(int i =1 ; i <= n; i++) cin >> a[i];
	eratos(nt);
	solve("");
	if(ans){
		sort(vec.begin(), vec.end());
		for(auto s : vec) cout << s << '\n';
	}
	if(ans == 0) cout << -1;
	return 0;
}
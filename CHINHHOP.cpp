#includebitsstdc++.h
using namespace std;
int n, k;
bool check[1000];
void solve(int id, string s, int d){
	if(id  n + 1) return;
	if(d == k){
		for(int i = 0; i  s.length(); i++) cout  s[i]  ' ';
		cout  'n';
	}
	for(int  i = 1; i = n; i++){
		if(!check[i]){
			check[i] = 1;
			solve(id + 1, s + char(i + 48), d + 1);
			check[i] = 0;
		}
	}
}
int main(){
	ios_basesync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin  k  n;
	solve(1, , 0);	
	return 0;
}
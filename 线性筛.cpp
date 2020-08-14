#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int vis[N],prime[N];
int cnt;
void get_p(int n) {
	for(int i = 2 ; i < n ; i ++) {
		if(!vis[i]) {
			prime[++cnt] = i;
		}
		for(int j = 1 ; j <= cnt && i * prime[j] < n ; j ++) {
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
	}
} 
int main() {
	get_p(100);
	for(int i = 1 ; i <= cnt ; i ++) {
		cout << prime[i] << endl;
	}
}

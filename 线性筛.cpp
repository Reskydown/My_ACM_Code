#include<bits/stdc++.h>
using namespace std;
/*
标准的欧拉线性筛法，用于求1~n的所有素数
cnt为素数个数
prime[1] ~ prime[cnt]储存了这些素数
调用get_p(x) 即可将1~x的所有素数求出
Author:Reskyllr 
*/
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
	get_p(100);//传入n即可 
	for(int i = 1 ; i <= cnt ; i ++) {
		printf("%d\n",prime[i]); 
	}
}

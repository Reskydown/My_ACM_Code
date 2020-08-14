#include<bits/stdc++.h>
using namespace std;
/*
题目链接:https://www.luogu.com.cn/problem/P3371
SPFA求图最短路(适用于带负权边的图)
SPFA也可以用来判负环 
使用std::vector邻接表存图 
时间复杂度O(VE)
空间复杂度O(E) 
*/ 
const int N = 1e5 + 10;
int dis[N],vis[N];
struct edge {
	int to,w;
	edge(int a,int b):to(a),w(b){}
};
const int inf = 1 << 30;
vector<edge>v[N];
inline int read(){
	char ch;
	int f=1,res=0;
	while((ch=getchar())<'0'||ch>'9')
		if(ch=='-') f=-1;
	while(ch>='0'&&ch<='9')
	{
		res=(res<<1)+(res<<3)+(ch^48);
		ch=getchar();
	}
	return f*res;
}
void spfa(int x) {
	dis[x] = 0;
	queue<int>q;
	q.push(x);
	vis[x] = 1;
	while(!q.empty()) {
		int t = q.front();q.pop();
		vis[t] = 0;
		int lt = v[t].size();
		for(int i = 0 ; i < lt ; i ++) {//松弛 
			int g = v[t][i].w;
			int s = v[t][i].to;
			if(dis[t] + g < dis[s]) {
				dis[s] = dis[t] + g;
				if(!vis[s]) vis[s] = 1,q.push(s);//已松弛且不在队列中的入队 
			}
		}
	}
}
int main() {
	int n,m,s,x,y,z;
	cin >> n >> m >> s;
	for(int i = 1 ; i <= n ; i ++) dis[i] = inf;
	for(int i = 1 ; i <= m ; i ++) {
		x = read();y = read();z = read();
		v[x].push_back(edge(y,z));
	}
	spfa(s);
	for(int i = 1 ; i <= n ; i ++) printf("%d ",dis[i]);
}

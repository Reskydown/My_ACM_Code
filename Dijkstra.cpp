#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10,inf = 1 << 30;
inline int read() {
	char ch;
	int f=1,res=0;
	while((ch=getchar())<'0'||ch>'9')
		if(ch=='-') f=-1;
	while(ch>='0'&&ch<='9') {
		res=(res<<1)+(res<<3)+(ch^48);
		ch=getchar();
	}
	return f*res;
}
struct edge {
	int to,w,next;
}e[N];
int head[N],dis[N],vis[N];
int cnt;
inline void add(int x,int y,int z) {
	e[++cnt].to = y;
	e[cnt].w = z;
	e[cnt].next = head[x];
	head[x] = cnt;
}

struct node {
	int w,pos;
	bool operator<(const node &a) const {
		return w > a.w;
	} 
	node(int a,int b):w(a),pos(b){}
};
void Dijkstra(int x) {
	priority_queue<node>q;
	dis[x] = 0;
	q.push(node(0,x));
	while(!q.empty()) {
		node t = q.top();q.pop();
		int x = t.pos,d = t.w;
		if(vis[x]) continue;
		vis[x] = 1;
		for(int i = head[x] ; i ; i = e[i].next) {
			int y = e[i].w;
			if(dis[x] + y < dis[e[i].to]) {
				dis[e[i].to] = dis[x] + y;
				q.push(node(dis[e[i].to],e[i].to));
			}
		}
	}
}
int main() {
	int n,m,s,x,y,z;
	scanf("%d %d %d",&n,&m,&s);
	for(int i = 1 ; i <= m ; i ++) {
		x = read();y = read(); z = read();
		add(x,y,z);
	}
	for(int i = 1 ; i <= n ; i ++) dis[i] = inf;
	Dijkstra(s);
	for(int i = 1 ; i <= n ; i ++) printf("%d ",dis[i]);
}

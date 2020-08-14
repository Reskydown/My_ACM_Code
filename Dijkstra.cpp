#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10,inf = 1 << 30;
/*
题目链接:https://www.luogu.com.cn/problem/P4779
Dijkstra堆优化求图最短路(适用于无负权边)
使用链式前向星存图 
时间复杂度O(ElogV)
空间复杂度O(E) 
*/
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
//链式前向星 
struct edge {
	int to,w,next;
}e[N];
int head[N],dis[N],vis[N];
int cnt;
inline void add(int x,int y,int z) {//加边 
	e[++cnt].to = y;
	e[cnt].w = z;
	e[cnt].next = head[x];
	head[x] = cnt;
}

struct node {//优先队列结构体 
	int w,pos;//w表示路径权值，pos表示当前位置 
	bool operator<(const node &a) const {
		return w > a.w;
	} 
	node(int a,int b):w(a),pos(b){}
};
void Dijkstra(int x) {
	priority_queue<node>q;//最小堆 
	dis[x] = 0;
	q.push(node(0,x));//起点入堆 
	while(!q.empty()) {
		node t = q.top();q.pop();
		int x = t.pos,d = t.w;
		if(vis[x]) continue;
		vis[x] = 1; 
		for(int i = head[x] ; i ; i = e[i].next) {//边松弛 
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

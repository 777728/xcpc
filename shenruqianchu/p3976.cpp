#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
const int N=50010;
const int INF=1000000099;
int t[N],a[N];//初始点权和建立在时间戳上的点权
int head[N],to[N*2],nex[N*2],cnt;
void add(int x,int y){
	cnt++;
	to[cnt]=y;
	nex[cnt]=head[x];
	head[x]=cnt;
}
int tot,dfn[N],tp[N],fa[N],sz[N],son[N],dep[N];
void dfs1(int x,int f){
	fa[x]=f;
	dep[x]=dep[f]+1;
	sz[x]=1;
	int maxn=-1;
	for(int i=head[x];i;i=nex[i]){
		int y=to[i];
		if(y==f)
			continue;
		dfs1(y,x);
		sz[x]+=sz[y];
		if(sz[y]>maxn){
			maxn=sz[y];
			son[x]=y;
		}
	}
}
void dfs2(int x,int top){
	tp[x]=top;
	tot++;
	dfn[x]=tot;
	a[tot]=t[x];
	if(son[x])
		dfs2(son[x],top);
	for(int i=head[x];i;i=nex[i]){
		int y=to[i];
		if(y==fa[x]||y==son[x])
			continue;
		dfs2(y,y);
	}
}
struct ST{
	int maxx;
	int minn;
	int lmax;
	int rmax;
	int tag;
}st[N*4];
void build(int root,int l,int r){
	if(l==r){
		st[root].maxx=a[l];
		st[root].minn=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(root*2,l,mid);
	build(root*2+1,mid+1,r);
	st[root].maxx=max(st[root*2].maxx,st[root*2+1].maxx);
	st[root].minn=min(st[root*2].minn,st[root*2+1].minn);
	st[root].lmax=max(max(st[root*2].lmax,st[root*2+1].lmax),st[root*2+1].maxx-st[root*2].minn);
	st[root].rmax=max(max(st[root*2].rmax,st[root*2+1].rmax),st[root*2].maxx-st[root*2+1].minn);
}
void push_down(int root){
	int k=st[root].tag;
	st[root].tag=0;
	st[root*2].maxx+=k;
	st[root*2].minn+=k;
	st[root*2+1].maxx+=k;
	st[root*2+1].minn+=k;
	st[root*2].tag+=k;
	st[root*2+1].tag+=k;
}
void change(int root,int l,int r,int x,int y,int k){
	if(l>=x&&r<=y){
		st[root].maxx+=k;
		st[root].minn+=k;
		st[root].tag+=k;
		return;
	}
	if(st[root].tag!=0&&l!=r)
		push_down(root);
	int mid=(l+r)/2;
	if(mid>=x)
		change(root*2,l,mid,x,y,k);
	if(mid+1<=y)
		change(root*2+1,mid+1,r,x,y,k);
	st[root].maxx=max(st[root*2].maxx,st[root*2+1].maxx);
	st[root].minn=min(st[root*2].minn,st[root*2+1].minn);
	st[root].lmax=max(max(st[root*2].lmax,st[root*2+1].lmax),st[root*2+1].maxx-st[root*2].minn);
	st[root].rmax=max(max(st[root*2].rmax,st[root*2+1].rmax),st[root*2].maxx-st[root*2+1].minn);
}
ST ask(int root,int l,int r,int x,int y){
	if(l>=x&&r<=y)
		return st[root];
	if(st[root].tag!=0&&l!=r)
		push_down(root);
	int mid=(l+r)/2;
	if(mid>=y)
		return ask(root*2,l,mid,x,y);
	else{
		if(mid+1<=x)
			return ask(root*2+1,mid+1,r,x,y);
		else{
			ST L=ask(root*2,l,mid,x,y);
			ST R=ask(root*2+1,mid+1,r,x,y);
			ST res;
			res.maxx=max(L.maxx,R.maxx);
			res.minn=min(L.minn,R.minn);
			res.lmax=max(max(L.lmax,R.lmax),R.maxx-L.minn);
			res.rmax=max(max(L.rmax,R.rmax),L.maxx-R.minn);
			return res;
		}
	}
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>t[i];
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	dfs1(1,1);
	dfs2(1,1);
	build(1,1,n);
	int m;
	cin>>m;
	for(int i=1;i<=m;i++){
		int x,y,k;
		ST L,R;
		L.lmax=L.rmax=0;
		L.maxx=-INF;
		L.minn=INF;
		R=L;
		cin>>x>>y>>k;
		int xx=x;
		int yy=y;
		while(tp[x]!=tp[y]){
			if(dep[tp[x]]<dep[tp[y]]){//跳终点一端的链 
				ST res=ask(1,1,n,dfn[tp[y]],dfn[y]);
				R.lmax=max(max(res.lmax,R.lmax),R.maxx-res.minn);
				R.rmax=max(max(res.rmax,R.rmax),res.maxx-R.minn);
				R.maxx=max(R.maxx,res.maxx);
				R.minn=min(R.minn,res.minn);
				y=fa[tp[y]];
			}
			else{//跳起点一端的链 	
				ST res=ask(1,1,n,dfn[tp[x]],dfn[x]);
				L.lmax=max(max(res.lmax,L.lmax),L.maxx-res.minn);
				L.rmax=max(max(res.rmax,L.rmax),res.maxx-L.minn);
				L.maxx=max(L.maxx,res.maxx);
				L.minn=min(L.minn,res.minn);
				x=fa[tp[x]];
			}
		}
		if(dep[x]<dep[y]){//跳终点一段的链 
			ST res=ask(1,1,n,dfn[x],dfn[y]);
			R.lmax=max(max(res.lmax,R.lmax),R.maxx-res.minn);
			R.rmax=max(max(res.rmax,R.rmax),res.maxx-R.minn);
			R.maxx=max(R.maxx,res.maxx);
			R.minn=min(R.minn,res.minn);
		}
		else{//跳起点一端的链 
			ST res=ask(1,1,n,dfn[y],dfn[x]);
			L.lmax=max(max(res.lmax,L.lmax),L.maxx-res.minn);
			L.rmax=max(max(res.rmax,L.rmax),res.maxx-L.minn);
			L.maxx=max(L.maxx,res.maxx);
			L.minn=min(L.minn,res.minn);
		}
		int ans=max(max(L.rmax,R.lmax),R.maxx-L.minn);
		cout<<ans<<'\n';
		x=xx;//修改之前恢复成原来的 x、y 值 
		y=yy;
		while(tp[x]!=tp[y]){
			if(dep[tp[x]]<dep[tp[y]])
				swap(x,y);
			change(1,1,n,dfn[tp[x]],dfn[x],k);
			x=fa[tp[x]];
		}
		if(dep[x]>dep[y])
			swap(x,y);
		change(1,1,n,dfn[x],dfn[y],k);
	}
	return 0;
}


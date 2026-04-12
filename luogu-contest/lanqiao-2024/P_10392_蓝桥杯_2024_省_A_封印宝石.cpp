    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <string>
    #include <map>
    #include <set>
    #include <queue>
    #include <stack>
    #include <cmath>
#include <cstring>
using namespace std;
int n,m;
int a[1000005],ans[1000005];
bool f[1000005];
struct node
{
	int id,val;
	node(){val=id=0;}
}Zero;
bool operator<(node x,node y)
{
	if(x.val==y.val)
		return x.id>y.id;
	return x.val<y.val;
}
bool operator==(node x,node y)
{
	return x.val==y.val;
}
struct Tree
{
	int l,r;
	node mx1,mx2;
	Tree(){mx1.val=mx1.id=0,mx2.val=mx2.id=0;}
}t[1000005];
node a1[4];
inline void Pushup(int i)
{
	a1[0]=t[i*2].mx1;
    a1[1]=t[i*2].mx2;
    a1[2]=t[i*2+1].mx1;
    a1[3]=t[i*2+1].mx2;
	sort(a1,a1+4);
	t[i].mx1=a1[3];
	for(int j=2;j>=0;j--)
		if(a1[j].val!=a1[j+1].val)
		{
			t[i].mx2=a1[j];
			break;
		}
}
inline void Build(int i,int l,int r)
{
	if(l==r)
	{
		t[i].mx1.val=a[l];
        t[i].mx1.id=l;
        t[i].l=l;
        t[i].r=r;
		return;
	}
	int mid=(l+r)/2;
	Build(i*2,l,mid);
	Build(i*2+1,mid+1,r);
	Pushup(i);
}
node m1,m2;
inline node Max1(int i,int l,int r,int l1,int r1)
{
	if(l1<=l&&r1>=r)
	{
		a1[0]=t[i].mx1,a1[1]=t[i].mx2,a1[2]=m1,a1[3]=m2;
		sort(a1,a1+4);
		m1=a1[3];
		for(int j=2;j>=0;j--)
			if(a1[j].val!=a1[j+1].val)
			{
				m2=a1[j];
				break;
			}
		return t[i].mx1;
	}
	if(l1>r||r1<l)
		return Zero;
	int mid=(l+r)/2;
	return max(Max1(i*2,l,mid,l1,r1),Max1(i*2+1,mid+1,r,l1,r1));
}
inline void Modify(int i,int l,int r,int x1)
{
	if(l>x1||r<x1)
		return;
	if(l==x1&&r==x1)
	{
		t[i].mx1=t[i].mx2=Zero;
		return;
	}
	int mid=(l+r)/2;
	Modify(i*2,l,mid,x1);
	Modify(i*2+1,mid+1,r,x1);
	Pushup(i);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	Build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		m1=m2=Zero;
		Max1(1,1,n,i,min(i+m,n));
		if(m1.val==ans[i-1])
		{
			if(m2.val)
			{
				ans[i]=m2.val;
				Modify(1,1,n,m2.id);
				m-=m2.id-i;
			}
		}
		if(m1.val!=ans[i-1]&&m1.val)
		{
			ans[i]=m1.val;
			Modify(1,1,n,m1.id);
			m-=m1.id-i;
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]?ans[i]:-1);
	return 0;
}

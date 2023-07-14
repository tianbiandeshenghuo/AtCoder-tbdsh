#include<bits/stdc++.h>
using namespace std;
int tree[800001],cnt=0;
int pos[200001],ans[200001]; 
void build(int l,int r,int id){
	if(l==r){
		tree[id]=1;
		return;
	}
	else{
		int mid=(l+r)/2; 
		build(l,mid,id*2);
		build(mid+1,r,id*2+1);
		tree[id]=tree[id*2]+tree[id*2+1];
	}
}
void change(int l,int r,int id,int d,int x){
	if(l==r){
		tree[id]=0;
		ans[x]=l;
		return;
	}
	int mid=(l+r)/2;
	if(d<=tree[id*2]) change(l,mid,id*2,d,x);
	else change(mid+1,r,id*2+1,d-tree[id*2],x);
	tree[id]=tree[id*2]+tree[id*2+1];
}
int main(){
  freopen("t.in", "r", stdin);
    freopen("t.ans", "w", stdout);
	int n,x,y,t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		scanf("%d",&n);
		build(1,n,1);
		for(int i=1;i<=n;i++)
		scanf("%d",&pos[i]);
		for(int i=n;i>0;i--)
		change(1,n,1,i-pos[i],i);
		for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
		printf("\n");
		memset(tree,0,sizeof(tree));
	}
}

#include <iostream>
#define MAXN 100010
using namespace std;
int tree[2000005],a[100005];
void build(int node,int start,int end){
	if(start==end)
		tree[node]=a[start];
	else{

		int mid=(start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		if(tree[2*node]<tree[2*node+1])
			tree[node]=tree[2*node];
		else
			tree[node]=tree[2*node+1];
	}
}
void update(int node,int start,int end,int idx,int val){
	if(start==end){
		a[idx]=val;
		tree[node]=val;
	}
	else{

		int mid=(start+end)/2;
		if(idx>=start&&idx<=mid)
			update(2*node,start,mid,idx,val);
		else
			update(2*node+1,mid+1,end,idx,val);
		if(tree[2*node]<tree[2*node+1])
			tree[node]=tree[2*node];
		else
			tree[node]=tree[2*node+1];
	}
}
int query(int node,int start,int end,int l,int r){

	if(l>end||start>r)
		return 100005;
	if(l<=start&&r>=end)
		return tree[node];
	int p1,p2;
	int mid=(start+end)/2;
	p1=query(2*node,start,mid,l,r);
	p2=query(2*node+1,mid+1,end,l,r);
	if(p1<p2)
		return p1;
	else
		return p2;
}
int main(){
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	build(1,1,n);
	while(q--){
		char b;
		int x,y;
		cin>>b>>x>>y;
		if(b=='q'){
			
			int c=query(1,1,n,x,y);
			cout<<c<<endl;
		}
		else
			update(1,1,n,x,y);
	}
	return 0;
}
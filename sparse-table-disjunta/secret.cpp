#include "secret.h"
#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;


const int N = 1010;
int ans[N][11];
int ar[N];
void build(int l,int r,int level){
	if(l == r){
		ans[l][level] = ar[l];
		return;
	}
	int mid = (l+r)/2;
	ans[mid][level] = ar[mid];
	ans[mid+1][level] = ar[mid+1];
	int last = ar[mid];
	for(int i=mid-1;i>=l;i--){
		ans[i][level] = Secret(ar[i],last);
		last = ans[i][level];
	}
	last = ar[mid+1];
	for(int i=mid+2;i<=r;i++){
		ans[i][level] = Secret(last,ar[i]);
		
		last = ans[i][level];
	}
	build(l,mid,level+1);
	build(mid+1,r,level+1);
}
int n;
void Init(int N, int A[]) {
  n = N;
  for(int i=1;i<=N;i++)ar[i] = A[i-1];
  build(1,N,0);
}

int go(int l,int r,int level,int a,int b){
	if(l == r){
		return ans[l][level];
	}

	int mid = (l + r)/2;
	if(a<=mid and b>mid){
	return Secret(ans[a][level],ans[b][level]);
	}
	if(a<=mid)return go(l,mid,level + 1,a,b);
	return go(mid+1,r,level + 1,a,b);
}

int Query(int L, int R) {
	assert(L>=0 and R<n);
//	cout <<"lets go "<<" "<<L<<" "<<R<<endl;
	return go(1,n,0,L+1,R+1);
}

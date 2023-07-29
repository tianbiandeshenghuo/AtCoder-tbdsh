#include<bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2)
#pragma GCC optimize(1)

using namespace std;
const int MAXN = 1e6 + 5;
int n, m;
struct Node{
  int x, id;
} a[MAXN];
vector<int> b[25];
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  freopen("contest.in", "r", stdin);
  freopen("contest.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= n; i++){
    cin >> a[i].x;
    a[i].id = i;
  }
  int q = log2(n);
  q--;
  for (int i = 1; i < n; i += 2){
    if (a[i + 1].x > a[i].x){
      b[q].push_back(a[i + 1].id);
    }else {
      b[q].push_back(a[i].id);
    }
  }
  n /= 2;
  for (int i = q - 1; n; i--, n /= 2){
    for (int j = 0; j < n - 1; j += 2){
      if (a[b[i + 1][j + 1]].x > a[b[i + 1][j]].x){
        b[i].push_back(a[b[i + 1][j + 1]].id);
      }else {
        b[i].push_back(a[b[i + 1][j]].id);
      }
    }
  }
  while (m--){
    int x;
    cin >> x;
    x = log2(x);
    //cerr << x << '\n';
    for (auto v : b[x]){
      cout << v << ' ';
    }
    cout << '\n';
  }
  return 0;
}
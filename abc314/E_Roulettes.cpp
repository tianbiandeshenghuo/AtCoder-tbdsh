#include<bits/stdc++.h>

using namespace std;
const int MAXN = 2e5 + 5;
int n, m;
struct Node{
  int c, p, a[105];
} a[105];
double dp[105][105];
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++){
    cin >> a[i].c >> a[i].p;
    for (int j = 1; j <= a[i].p; j++){
      cin >> a[i].a[j];
    }
  }
  
  return 0;
}
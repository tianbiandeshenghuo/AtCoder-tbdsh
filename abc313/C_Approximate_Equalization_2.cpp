#include<bits/stdc++.h>

using namespace std;
const int MAXN = 2e5 + 5;
long long n, a[MAXN];
long long ans;
long long x;
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++){
    cin >> a[i];
    x += a[i];
  }
  x = 1.0 * x / n + 0.49;
  for (int i = 1; i <= n; i++){
    if (abs(a[i] - x) >= 1){
      ans += abs(a[i] - x);
    }
  }
  //cerr << x << ' ' << ans << ' ' << ans % n << '\n';
  long long op = 0.49 + ans / 2;
  cout << op;
  return 0;
}
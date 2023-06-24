#include <algorithm>
#include<bits/stdc++.h>

using namespace std;
const int Mod = 998244353, MAXV = 1e6 + 5;
long long l, r, ans = 1;
int qwq;
bool v[MAXV] = {1, 1};
vector<long long> a;
bool check(long long x){
  if (x <= 1e6 && find(a.begin(), a.end(), x) != a.end()){
    return 1;
  }
  for (auto v : a){
    if (!(x % v)){
      return 0;
    }
  }
  return 1;
}
long long qcheck(long long x){
  long long cnt = 0;
  while (x){
    cnt += x % 10;
    x /= 10;
  }
  return cnt;
}
int main(){
  long long q = clock();
  //freopen("test.txt", "w", stdout);
  //ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> l >> r;
  
  for (long long i = 2; i * i <= r; i++){
    if (!v[i]){
      a.push_back(i);
      for (long long j = 2; i * j * i * j <= r; j++){
        v[i * j] = 1;
      }
    }
  }
  qwq = a.size();
  for (long long i = 1; i * i <= r; i++){
    if (i * i >= l && check(qcheck(i * i))){
      ans = ans * i % Mod * i % Mod;
    }
  }
  cout << (ans == 1 ? 0 : ans);
  long long qq = clock();
  cout << "\ntime:" << 1.0 * (qq - q) / 1000 << "s."; 
  return 0;
}
#include<bits/stdc++.h>

using namespace std;
const int MAXN = 3e5 + 5;
int n, k;
long long cnt, sum;
struct Node{
  int a, b, id;
  bool operator<(const Node &i)const{
    return a < i.a;
  }
} a[MAXN];
queue<int> b;
int main(){
  cin >> n >> k;
  for (int i = 1; i <= n; i++){
    cin >> a[i].a >> a[i].b;
    a[i].id = i;
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++){
    cout << a[i].a << ' ' << a[i].b << ' ' << a[i].id << '\n';
  }
  for (int i = 1, j = 1; ; i++){
    cout << i << ' ' << cnt << ' ' << a[b.front()].b << ' ' << a[b.front()].id << '\n';
    if (a[j].a >= i){
      b.push(a[j].id);
      cnt += a[j].b;
      j++;
    }
    cout << i << ' ' << cnt << ' ' << a[b.front()].b << ' ' << a[b.front()].id << '\n';
    while (b.size() && a[b.front()].a < i){
      cnt -= a[b.front()].b;
      b.pop();
    }
    if (cnt <= k){
      cout << i;
      return 0;
    }
  }
  return 0;
}
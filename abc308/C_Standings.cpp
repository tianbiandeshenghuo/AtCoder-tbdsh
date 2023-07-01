#include<bits/stdc++.h>

using namespace std;
const int MAXN = 2e5 + 5;
int n;
struct Node{
  long long v;
  int id;
  bool operator<(const Node &i)const{
    return v == i.v ? id < i.id : v > i.v;
  }
} a[MAXN];
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++){
    double x, y;
    cin >> x >> y;
    a[i] = {(x + y) * x * (x + y), i};
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++){
    cout << a[i].id << ' ';
  }
  return 0;
}
# 题意简述
[更好的阅读体验](https://www.luogu.com.cn/blog/tianbiandeshenghuo11/solution-at-abc314-e)

[AtCoder 原题面](https://atcoder.jp/contests/314/tasks/abc314_e)

[洛谷原题面](https://www.luogu.com.cn/problem/at_abc314_e)

有 $N$ 个转盘。第 $i$ 个转盘上有 $P_i$ 个整数 $S_{i,1} \sim S_{i,P_i}$，每次转一次转盘支付 $C_i$ 元。

当你转第 $i$ 个转盘一次，转盘会等概率的出现 $1 \sim P_i$ 中的一个整数 $j$，然后你获得 $S_{i,j}$ 分。每次转转盘的得分是相互独立的。

Takahashi 想要至少获得 $M$ 分。在获得至少 $M$ 分之前，Takahashi 的策略是最小化他支付的总钱数。在每次转转盘过后，taken已根据已有的得分结果选择转哪个转盘。

请求出 Takahashi 至少获得 $M$ 分所需支付的钱数的期望。

# 分析

记 $dp_i$ 为当前得分为 $i$，最优策略下达到 $M$ 分的期望花费。

初始：$dp_x=0(x \ge M)$

对于样例一来说，如果选择第一个转盘，那么有 $dp_i=100+(dp_{i+2}+dp_{i+5}+dp_{i+9})\times \dfrac{1}{3}$

如果选择第二个转盘，那么有 $dp_i=50+(dp_{i+4}+dp_{i+2}+dp_{i+1}+dp_{i+4}+do_{i+8})\times \dfrac{1}{5}$。

那么，我们就有 $M$ 个状态数。由于要求期望最小值，所以对每个转盘都要做一次。最后取 $min$。

那么总时间复杂度为：$O(M\times N\times P)$。

但是，有可能会出现样例二第三个转盘时的情况：此时转移为：$dp_i=10+(dp_{i+0}+dp_{i+0}+dp_{i+0}+dp_{i+0}+dp_{i+0}+dp_{i+100})\times \dfrac{1}{6}$

所以我们要转换一下。

下令 $x=\sum dp_{i+S_{i,j}},S_{i,j}$ 里有 $k$ 个数字为 $0$。

那么有 
$$
dp_i=x+\dfrac{k}{P_i}\times dp{qwq}{qwq}
\\
\dfrac{qwq}{qwq}dp_i=x
$$

# Code
```cpp
#include<bits/stdc++.h>

using namespace std;
const int MAXN = 2e5 + 5;
int n, m;
struct Node{
  int c, p, a[105], zero;
} a[105];
double dp[305];
double Solve(int x, int i){
  double ans = 0;
  for (int j = 1; j <= a[i].p; j++){
    if (a[i].a[j]){
      ans += dp[x + a[i].a[j]];
    }
  }
  return (ans + a[i].p * a[i].c) / (a[i].p - a[i].zero);
}
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++){
    cin >> a[i].c >> a[i].p;
    for (int j = 1; j <= a[i].p; j++){
      cin >> a[i].a[j];
      a[i].zero += !a[i].a[j];
    }
  }
  dp[m] = 0;
  for (int i = m - 1; i >= 0; i--){
    double ans = 1e18;
    for (int j = 1; j <= n; j++){
      ans = min(ans, Solve(i, j));
    }
    dp[i] = ans;
  }
  cout << fixed << setprecision(114514) << dp[0];
  return 0;
}
```
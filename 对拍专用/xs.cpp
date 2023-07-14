#include <vector>
#include <iostream>
#include <algorithm>

int T;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  freopen("t.in", "r", stdin);
  freopen("t.out", "w", stdout);
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), pre(n + 2), post(n + 2);
  for (int i = 1; i <= n; ++i) std::cin >> a[i];
  pre[1] = a[1];
  for (int i = 2; i <= n; ++i) pre[i] = pre[i - 1] & a[i];
  post[n] = a[n];
  for (int i = n - 1; i; --i) post[i] = post[i + 1] & a[i];
  int ans = 1;
  for (int i = 1; i < n; ++i) if (pre[i] + post[i + 1] == pre[n]) {
    ++ans;
  }
  std::cout << ans << '\n';
}
/*
# std::string

## 题目背景

这是一道 **hack 题**。在本题目中，你将得到两个问题和两个解决对应问题的代码，但是给出的代码不能对于某些输入给出正确的输出。不能给出正确的输出的情况包括：

1. 输出错误的结果。
2. 运行超时。
3. 产生一些运行时未定义行为。目前技术可检测的未定义行为仅包括数组越界。

对于这一问题，你需要提交一份符合要求的输入数据，使得给定的代码不能给出正确的输出。你可以直接使用『提交答案』功能，也可以提交一份以任何语言写成的数据生成器。

---
**提示：如果你使用提交答案功能，请在提交其他题目时记得将语言改回你所使用的语言。**

## 题目描述

以下给出两个问题的题目描述：

#### 问题 1

输入 $n$，输出连续 $n$ 个 $\texttt{HelloLuogu}$ 组成的字符串。

#### 问题 2

给定一个数列 $a$，请你将这个数列划分成**尽可能多**的段，使得每段的按位与之和最小。

请你输出最多划分段的数量。

## 输入格式

#### 问题 1

输入只有一行一个整数 $n$。

#### 问题 2

第一行是一个整数 $n$。  
第二行有 $n$ 个整数，第 $i$ 个整数表示 $a_i$。

## 输出格式

#### 问题 1

输出一行一个字符串表示答案。

#### 问题 2

输出一行一个整数表示答案。

## 样例 #1

### 样例输入 #1

```
2
```

### 样例输出 #1

```
HelloLuoguHelloLuogu
```

## 样例 #2

### 样例输入 #2

```
5
2 3 1 5 2
```

### 样例输出 #2

```
2
```

## 提示

### 样例组与实际输入的说明

两个样例分别对应两个问题的样例输入输出。

如果你直接采用『提交答案』的方式，请分别将两个输入数据命名为 `1.in`、`2.in`，并打成 zip 压缩包进行提交；

如果你采用提交数据生成器的方式，你的生成器可以从标准输入读入一个整数 $x$，满足 $1 \leq x \leq 2$，表示该测试点对应的问题编号，然后**输出对应的输入数据**。

显然，你的程序不应该读入『输入格式』里提到的任何内容（而应该构造它们），也不应该输出『样例输出』里提到的任何内容（而是只输出你构造的输入数据）。你不应该使用样例测试你的程序，这只是对两个问题的样例说明。

### 样例 2 解释

划分成 $[2,3,1]$ 和 $[5,2]$ 两个段。两段的按位与都是 $0$，其和也是 $0$，可以证明这是和的最小值。

### 数据规模要求

你给出的数据必须满足如下要求：

1. 完全符合『输入格式』的规定，不能有多余的输入，但是可以有文末回车，问题 $1$ 可以有行末空格。
2. 对于问题 $1$，$1 \leq n \leq 10^5$。
3. 对于问题 $2$，$1 \leq n \leq 2 \times 10^5$，$0 \leq a_i \leq 10^9$。

### 目标代码

你需要 hack 如下的代码：

#### 问题 1

```cpp
#include <iostream>
using namespace std;

int main() {
  int n;
  string ans, base = "HelloLuogu";
  cin >> n;
  while (n--) ans = ans + base;
  cout << ans << endl;
}
```

#### 问题 2

```cpp
#include <vector>
#include <iostream>
#include <algorithm>

int T;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), pre(n + 2), post(n + 2);
  for (int i = 1; i <= n; ++i) std::cin >> a[i];
  pre[1] = a[1];
  for (int i = 2; i <= n; ++i) pre[i] = pre[i - 1] & a[i];
  post[n] = a[n];
  for (int i = n - 1; i; --i) post[i] = post[i + 1] & a[i];
  int ans = 1;
  for (int i = 1; i < n; ++i) if (pre[i] + post[i + 1] == pre[n]) {
    ++ans;
  }
  std::cout << ans << '\n';
}
```

目标代码的编译选项为 `-std=c++14 -fno-asm -O2`。编译器为洛谷提供的 g++。你可以在『在线 IDE』中选择 C++14 语言来获得完全相同的编译环境。

#### 数据判定

你给出的数据必须完全符合『数据规模要求』，否则将得到 Unaccepted 的结果。

#### 超时判定

程序每执行若干条指令，我们会检测一遍程序的运行时间。我们保证两次检测之间的指令条数是一个输入规模无关的量，也即每执行 $O(1)$ 条指令会进行一次检测。且两次检测之间的指令条数不会太多，一般不超过 $100$ 条 C++ 语句。

如果程序的运行时间超过 $500 \text{ms}$，则判定为程序运行超时，返回 accepted 结果。

#### 结果错误判定

如果程序在规定的时间内结束且给出了一个输出，我们会比较这个输出和**完全正确的输出**，如果二者不同，则判定为 hack 成功，返回 accepted 结果。

#### 未定义行为判定

我们会在每次**显式**的调用数组元素前判断数组下标是否超过数组范围，如果超过，则判定为 hack 成功，返回 accepted 结果。

这就是说，如果你希望通过未定义行为进行 hack，只能对显式的调用数组元素的行为进行 hack。

### 样例程序

这是一份可以帮你理解你需要输出的内容的样例程序，**但它不能给出正确的 hack 数据**。直接提交此程序不会得分。

```cpp
#include <iostream>

using namespace std;

int main() {
  int taskId;
  cin >> taskId;
  if (taskId == 1) {
    cout << "" <<endl;
  } else if (taskId == 2) {
    cout << "" << endl;
  } else { // 这个 else 不会被执行
    cout << "Stupid Fusu!" << endl;
  }
}
```

如果你使用『提交答案』功能，请务必保证打开压缩包后能且仅能**直接**看到两个 `.in` 文件。这就是说，文件结构必须是：

```plain
ans.zip
 |---1.in
 |---2.in
```

两个文件不应该被额外的文件夹包含，即文件结构不能是：

```plain
ans.zip
 |---ans(folder)
      |---1.in
      |---2.in
```

### 关于评测信息的说明

如果 hack 成功，对应测试点的信息为 accepted。如果返回其他信息，说明程序本身有误。

例如，如果返回 TLE，不代表成功的将对应程序 hack 至超时，而是表示数据生成器本身运行超时，测试点不得分。

特别的，返回 UKE 结果可能是数据不合法（有多余内容、缺少内容或数据范围不符合要求）。
*/
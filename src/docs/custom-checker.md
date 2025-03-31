# Custom Checker

Custom checker รับ argument 3 ตัวตามลำดับนี้

1. `argv[1]`: ชื่อไฟล์ input
2. `argv[2]`: ชื่อไฟล์ answer
3. `argv[3]`: ชื่อไฟล์ output ของคนแข่ง

ตัวอย่าง Checker (จากข้อ `antenna`)

```cpp
// Author: Borworntat

#include <bits/stdc++.h>

using namespace std;

signed main(int argc, char *argv[]) {
  ifstream inf(argv[1]);
  ifstream ans(argv[2]);
  ifstream ouf(argv[3]);

  string ignored_ans, ignored_ouf; // key line :clown:
  getline(ans, ignored_ans);
  getline(ouf, ignored_ouf);

  if(ignored_ans != ignored_ouf) {
    cout << "0.0\n";
    cerr << "translate:wrong\n";
    exit(0);
  }


  int n, q;
  inf >> n;
  vector<int> a(n);
  for(int i=0; i<n; ++i) {
    inf >> a[i];
  }
  inf >> q;

  long long x;
  vector<long long> real, user;
  while(ans >> x) {
    real.emplace_back(x);
  }
  while(ouf >> x) {
    user.emplace_back(x);
  }

  if(user.size() != real.size()) {
    cout << "0.0\n";
    cerr << "translate:wrong\n";
    exit(0);
  }

  if((int) user.size() != q || (int) real.size() != q) {
    cout << "0.0\n";
    cerr << "translate:wrong\n";
    exit(0);
  }

  bool all_invalid_ok = true;
  bool cor = true;
  for(int i=0; i<q; ++i) {
    long long r = real[i], u = user[i];

    if(r == -1ll && u != -1ll) {
      all_invalid_ok = false;
    }
    if(u == -1ll && r != -1ll) {
      all_invalid_ok = false;
      cor = false;
    }
    if(r != u) {
      cor = false;
    }
  }

  if(cor) {
    cout << "1.0\n";
    cerr << "translate:correct\n";
  }
  else if(all_invalid_ok) {
    cout << "0.25\n";
    cerr << "translate:partial\n";
  }
  else {
    cout << "0.0\n";
    cerr << "translate:wrong\n";
  }

  return 0;
}

```

compile ด้วย linux ที่เป็น environment เดียวกันกับ worker ตอน compile ห้ามลืม `-static` หรือใช้ compile command เดียวกับใน grader เลยก็ได้

example:

```bash
g++ -std=gnu++11 -O2 -pipe -static -s -o checker checker.cpp
```

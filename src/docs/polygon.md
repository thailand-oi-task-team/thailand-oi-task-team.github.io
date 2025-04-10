# Polygon

[Polygon](https://polygon.codeforces.com) เป็นระบบที่ใช้ในการเตรียม Testcase จาก [Codeforces](https://codeforces.com)

## Files

### Resource Files

- Header file ของโจทย์เรา
- Grader file ของโจทย์เรา

สองอันนี้จะต้อง compile ด้วยกัน ให้กด check ข้างหลัง แล้วกด `Advanced`

`Stages`: `Compile time`  
`Assets`: `Solution`

- ถ้าจะใช้ lib นอกเพื่อ generate testcase ให้ใส่ใน `Assets` ด้วย

คำแนะนำ: ถ้าจะ gen graph/tree ใช้ [aquagenlib.h](/aquagenlib.h) หรือ [jngen](https://github.com/ifsmirnov/jngen) จะง่าย (jngen มีหลายอย่างให้ใช้ลองศึกษาดูได้)

### Source Files

- Generator files (ให้ใส่ `bits/stdc++.h` หลัง `testlib.h`)

example จากข้อ antenna:

```cpp
// Borworntat
#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int MAX_A = 1'000'000;

signed main(int argc, char *argv[]) {
	registerGen(argc, argv, 1);
	int N = opt<int> ("N");
	int Q = opt<int> ("Q");
	int MAX_K = opt<int> ("MAX_K");

	vector<int> v;
	for(int i=1; i<=MAX_A; ++i) {
		v.emplace_back(i);
	}
	shuffle(v.begin(), v.end());
	vector<int> a;
	for(int i=1; i<=N; ++i) {
		a.emplace_back(v[i]);
	}

	cout << N << "\n";
	for(int i=0; i<N; ++i) {
		cout << a[i] << " \n"[i == N - 1];
	}
	cout << Q << "\n";
	for(int i=1; i<=Q; ++i) {
		int S = rnd.next(0, N - 1);
		int K = rnd.next(1, MAX_K);
		cout << S << " " << K << "\n";
	}
}
```

- Validator file

example จากข้อ antenna:

```cpp
// Borworntat
#include "testlib.h"

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100'000;
const int MAX_Q = 100'000;
const int MAX_A = 1'000'000;

signed main(int argc, char *argv[]) {
  registerValidation(argc, argv);
  int n = inf.readInt(1, MAX_N, "N");
  inf.readEoln();
  vector<int> a(n);
  for(int i=0; i<n; ++i) {
    a[i] = inf.readInt(1, MAX_A, "a[i]");
    if(i != n-1) {
      inf.readSpace();
    }
    else {
      inf.readEoln();
    }
  }

  int q = inf.readInt(1, MAX_Q, "Q");
  inf.readEoln();

  set<int> uniq(a.begin(), a.end());
  ensuref((int) uniq.size() == n, "A[i] is not unique");

  vector<int> s(q), k(q);
  for(int i=0; i<q; ++i) {
    s[i] = inf.readInt(0, n - 1);
    inf.readSpace();
    k[i] = inf.readInt(1, n - 1);
    inf.readEoln();
  }

  if(validator.group() == "01") {
    ensuref(n <= 5, "N is more than 5");
    ensuref(q <= 1000, "Q is more than 1000");
  }
  else if(validator.group() == "02") {
    ensuref(n <= 500, "N is more than 500");
  }
  else if(validator.group() == "03") {
    for(int i=0; i<q; ++i) {
      ensuref(k[i] <= 100, "K[i] is more than 100");
    }
  }
  else if(validator.group() == "04") {
    int max_idx = max_element(a.begin(), a.end()) - a.begin();
    for(int i=0; i<q; ++i) {
      ensuref(s[i] == max_idx, "S[i] is not argmax(A[i])");
    }
  }
  else if(validator.group() == "05") {
    for(int i=1; i<n; ++i) {
      ensuref(a[i - 1] < a[i], "A[i - 1] >= A[i]");
    }
  }

  inf.readEof();
}
```

## Tests

ใส่ script gen ลงไป

example:

```
gen -N 5 -Q 1000 -MAX_K 4 > $
```

**Note**: ให้ลง file ด้วย โดย pipe ใส่ `$`

## Stresses

ถ้าอยากกันเคสห่วยให้ลองเขียน โค้ดที่อยากจะดักแล้ว upload ไปที่ Solution files จากนั้นให้ลองรัน Stress ดู โดย script จะเขียนเหมือน tests script

## Invocation

ลองรันหลาย ๆ solution พร้อมกัน (คล้าย grader) ให้กดตรงนี้

## Packages

ก่อนสร้าง package ต้อง commit ก่อน

- กด `Create package` (Full) แล้วรอก่อน
- ตอนโหลด package ให้กด `linux`

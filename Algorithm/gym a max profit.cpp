#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#include <memory.h>
#include <algorithm>
#define pb(x)       push_back(x)
#define case        printf("Case %d: ",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)

using namespace std;

const int N = 2010;

int t, n, a[N], last[N], f[N][N];

int main(){
    read;
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    int maxVal = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
      maxVal = max(maxVal, a[i]);
    }
    for (int i = 0; i <= maxVal; ++i) last[i] = 0;
    for (int j = 0; j <= maxVal; ++j) f[n + 1][j] = 0;
    for (int i = 0; i <= n; ++i) f[i][maxVal + 1] = 0;

    for (int i = n; i > 0; --i) {
      for (int j = maxVal; j >= 0; --j) {
        f[i][j] = max(f[i + 1][j], f[i][j + 1]);
        if (j + a[i] <= maxVal and last[j + a[i]]) {
          f[i][j] = max(f[i][j], j + f[last[j + a[i]] + 1][j]);
        }
      }
      last[a[i]] = i;
    }
    printf("%d\n", f[1][0]);
  }
  return 0;
}

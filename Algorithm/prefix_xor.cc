#include <iostream>
#include <vector>

using namespace std;

int xor_out[1000000];

void solve(vector<int> &a, int l, int r, int k) {
    int cnt = 0;
    for (int i = l - 1; i <= r -1; i++) {
        if (k == xor_out[i] ^ a[i]) {
            cnt++;
        }
    }
    cout << cnt << "\n";
}


int main() {
    int n, k, m;
    cin >> n >> m >> k;
    vector<int>  a(n);
    for (int i = 0; i < a.size(); i++) {
        cin >> a[i];
        xor_out[i] = k ^ a[i];
    }


    for (int i = 0; i < m; i++) {
        int l, r;
        cin >>l >> r;
        solve(a, l, r, k);
    }
}

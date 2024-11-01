/**

    https://codeforces.com/contest/1516/problem/D
    sqrt trick

*/
#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;

const int N = 1e5 + 9;
vector<int> pf[N];
vector<int> idxs[N];


int main() {


	for (int i = 2; i < N; i++) {
		if (pf[i].empty())
			for (int j = i; j < N; j += i)
				pf[j].push_back(i);
	}
	int n, q;
	cin >> n >> q;
	int sqrtN = sqrt(n);
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		for (auto &p : pf[v[i]])
			idxs[p].push_back(i);
	}
	vector<int> nxt(n+2,0), cnt(n+5, 1), NXT(n+5,0);
	for (int i = 0; i < n; i++) {
		int j = n;
		for (auto &p : pf[v[i]]) {
			auto it = upper_bound(all(idxs[p]), i);
			if (it != idxs[p].end())
				j = min(j, *it);
		}
		nxt[i] = j;
	}
	for (int i = n - 2; i >= 0; i--)
		nxt[i] = min(nxt[i], nxt[i + 1]);

	for (int i = n - 1; i >= 0; i--) {
		NXT[i] = nxt[i];
		int j = nxt[i];
        if(j==n)    continue;
		if (j / sqrtN == i / sqrtN) {
			NXT[i] = NXT[j];
			cnt[i] += cnt[j];
		}
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		int sum = 0;
		while (l <= r) {
			int idx = l / sqrtN;
			int ed = min(sqrtN * (idx + 1), n) - 1;
			if (ed <= r) {
				sum += cnt[l];
				l = NXT[l];
			} else
				break;
		}
		while (l <= r) {
			sum++;
			l = nxt[l];
		}
		cout << sum << endl;
	}
}

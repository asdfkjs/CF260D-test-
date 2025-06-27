#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define PII std::pair<int,int>

using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
using i128 = __int128;
const int mod = 998244353;
const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<PII> p0, p1;
    for (int i = 1; i <= n; i ++) {
        int c, v;
        cin >> c >> v;
        if (c) p1.emplace_back(v, i);
        else p0.emplace_back(v, i);
    }

    for (int i = 0; i < n - 1; i ++) {
        auto [v0, idx0] = p0.back(); p0.pop_back();
        auto [v1, idx1] = p1.back(); p1.pop_back();
        if (v0 <= v1 && !p0.empty()) {
            cout << idx0 << ' ' << idx1 << ' ' << v0 << endl;
            p1.emplace_back(v1 - v0, idx1);
        }
        else {
            cout << idx0 << ' ' << idx1 << ' ' << v1 << endl;
            p0.emplace_back(v0 - v1, idx0);
        }
    }
}

signed main(){
	IOS;
	int t=1;
	//cin >> t;
	while(t--) {
	    solve();
	}
	return 0;
}

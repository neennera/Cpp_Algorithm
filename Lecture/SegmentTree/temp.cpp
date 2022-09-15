#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define ar array
 
const int INF = 1e17;
const int MOD = 1e9 + 7;

void USACO(string s = "") {
	if (s.size() == 0) return;
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

struct lol { int seg, pref, suf; };
// pref is size of gap from l
// suf is size of gap from r
// seg is most size of gap
//      seg = {a.gap, b.gab, a.suf + b.gap (the middle)} 
struct SegTree {
	int size, n;
	vector<lol> values;
	vector<int> operations;
	const lol NEUTRAL_VALUE = lol{0,0,0};
	const int NO_OPERATION = -1;
	// let empty cells have a value of 1 in them
	// we store seg pref suf

	SegTree(int _n) : n(_n) {
		size = 1; while (size < n) size <<= 1; //bit shift
		values.resize(2*size, lol{0,0,0}); 
		operations.resize(2*size, NO_OPERATION);
	}

	lol calc_op(lol a, lol b, int lx, int rx) {
		int m = (lx + rx) >> 1;
		lol x;

		if (a.pref == m - lx) x.pref = a.pref + b.pref;
		else x.pref = a.pref;
        // x.pref = a or a+b.pref if a is empty

		if (b.suf == rx - m) x.suf = b.suf + a.suf;
		else x.suf = b.suf;
        // x.suf= b or b + a.suf if b is empty
        // we don't use seg since seg can be other middle or back

		x.seg = max({a.seg, b.seg, a.suf + b.pref});
		return x;
	}

	void modify_op(int x, int v, int lx, int rx) {
		values[x] = lol{v*(rx - lx), v*(rx - lx), v*(rx - lx)};
        // reset value by *v all
		operations[x] = v; // get the oparation
	}

	void build(int x, int lx, int rx) {
		if (rx - lx == 1) return void(values[x] = (lx < n) ? lol{1,1,1} : lol{0,0,0});
		// if got the left node
            // in n : get 1,1,1
            // out of n : get 0,0,0 due it out of range(BUT SEG TREE NEED 2**X SIZE)
        int m = (lx + rx) >> 1;
		build(2*x+1, lx, m); build(2*x+2, m, rx);
		values[x] = calc_op(values[2*x+1], values[2*x+2], lx, rx);
        // why it use 2x + 1 / 2x + 2 ??
	} 
	void build() { build(0,0,size);} 
    //it start with index 0

	void propagate(int x, int lx, int rx){
		if (rx - lx == 1) return;
        // not need to propagate since it get leaf
		if (operations[x] != NO_OPERATION) {
            //pass to child by op of x
			int m = (lx + rx) >> 1;
			modify_op(2*x+1, operations[x], lx, m);
			modify_op(2*x+2, operations[x], m, rx);
		}
		operations[x] = NO_OPERATION;
        // set 0
	}

	void modify(int l, int r, int v, int x, int lx, int rx) {
		if (r <= lx || rx <= l) return;
		if (l <= lx && rx <= r) return modify_op(x, v, lx, rx);
		propagate(x, lx, rx);
		int m = (lx + rx) >> 1;
		modify(l, r, v, 2*x+1, lx, m);
		modify(l, r, v, 2*x+2, m, rx);
		values[x] = calc_op(values[2*x+1], values[2*x+2], lx, rx);
	}
	void modify(int l, int r, int v) { modify(l, r, v, 0, 0, size); }

	void emplace(int v, int x, int lx, int rx) {
		if (rx - lx <= v) return modify_op(x, 0, lx, rx);
		propagate(x, lx, rx);
		int m = (lx + rx) >> 1;
		if (values[2*x+1].seg >= v) emplace(v, 2*x+1, lx, m);
		else if (values[2*x+1].suf + values[2*x+2].pref >= v)
			modify(m - values[2*x+1].suf, m - values[2*x+1].suf + v, 0);
		else if (values[2*x+2].seg >= v) emplace(v, 2*x+2, m, rx);
		values[x] = calc_op(values[2*x+1], values[2*x+2], lx, rx);
	}
	void emplace(int v) { emplace(v, 0, 0, size); }
};

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	USACO("seating");
	int n, q; cin>>n>>q;  
	SegTree st(n); st.build();
	int ans = 0;
	while (q--) {
		char t; cin>>t;
		if (t == 'A') {
			int v; cin>>v;
			if (st.values[0].seg >= v) {
				st.emplace(v);
			} else ans++;
		} else {
			int l, r; cin>>l>>r;
			st.modify(l-1, r, 1);
		}
	}
	cout<<ans<<"\n";
} 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define all(x) (x).begin(), (x).end()
class Solution {
public:
    struct MergeTree {
        int N;
        bool U = false;
        vector<pll> &A;
        vector<vector<pll>> T;
        void build(int v, int tl, int tr) {
            if (tl == tr) {
                if (U) T[v] = { {A[tl].second, 0} };
                else T[v] = {A[tl]};
            }
            else {
                int mid = (tl + tr) / 2;
                build(v*2, tl, mid);
                build(v*2+1, mid+1, tr);
                T[v].resize(tr-tl+1);
                auto &L = T[v*2], &R = T[v*2+1];
                merge(all(L), all(R), begin(T[v]));
            }
        }
        ll query(ll x, int L, int R) { return query(x, L, R, 1, 0, N-1); }
        ll query(ll x, int al, int ar, int v, int tl, int tr) {
            if (tr < al || ar < tl) return 0;
            if (al <= tl && tr <= ar) {
                pll tmp = {x, -1};
                auto it = lower_bound(all(T[v]), tmp);
                if (U) return it - begin(T[v]);
                if (it == begin(T[v])) return 0;
                return prev(it)->second;
            }
            int mid = (tl + tr) / 2;
            ll ql = query(x, al, ar, v*2, tl, mid);
            ll qr = query(x, al, ar, v*2+1, mid+1, tr);
            return ql + qr;
        }
        MergeTree(int n, vector<pll> &v, bool u) : N(n), A(v), T(4ul*n), U(u) {
            build(1, 0, N-1);
            for (auto &v : T) {
                int sz = v.size();
                for (int i = 1; i < sz; ++i)
                    v[i].second += v[i-1].second;
            }
        }
    };

    ll goodTriplets(vector<int>& A, vector<int>& B) {
        int N = A.size();
        vector<int> pa(N), pb(N);
        for (int i = 0; i < N; ++i)
            pa[A[i]] = pb[B[i]] = i;

        vector<pll> P;
        for (int x = 0; x < N; ++x)
            P.push_back( {pa[x], pb[x]} );
        sort(begin(P), end(P));
        vector<pll> dp1(N);
        MergeTree seg1(N, P, true);
        for (int i = 1; i < N; ++i) {
            int y = P[i].second;
            ll q = seg1.query(y, 0, i-1);
            dp1[i] = {y, q};
        }
        ll ans = 0;
        MergeTree seg2(N, dp1, false);
        for (int i = 2; i < N; ++i) {
            int y = P[i].second;
            ll q = seg2.query(y, 0, i-1);
            ans += q;
        }
        return ans;
    }
};
static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
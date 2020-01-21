#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define REP(i, n) for (ll i = 0; i < (n); ++i)
#define OUT(x) cout << (x) << endl;
#define OUTA(a, n) \
    REP(i, n) { cout << (a[i]) << (i == n - 1 ? "\n" : " "); }
#define ALL(a) (a).begin(), (a).end()
#define SORT(a) sort(ALL(a))
#define RSORT(a) \
    SORT(a);     \
    reverse(ALL(a))

const ll INF = 1e18;
const ll MOD = 1e9 + 7;

ll A, B, Q;
vi s;
vi t;
vi x;

int main()
{
    cin >> A >> B >> Q;
    s = vi(A + 2);
    t = vi(B + 2);
    x = vi(Q);
    s[0] = -INF;
    REP(i, A)
    {
        cin >> s[i + 1];
    }
    s[A + 1] = INF;
    t[0] = -INF;
    REP(i, B)
    {
        cin >> t[i + 1];
    }
    t[B + 1] = INF;
    REP(i, Q)
    {
        cin >> x[i];
    }

    REP(k, Q)
    {
        ll i = lower_bound(ALL(s), x[k]) - s.begin();
        ll j = lower_bound(ALL(t), x[k]) - t.begin();
        ll sl = x[k] - s[i - 1];
        ll sr = s[i] - x[k];
        ll tl = x[k] - t[j - 1];
        ll tr = t[j] - x[k];
        ll ans = min({max(sl, tl), max(sr, tr), 2 * min(sl, tr) + max(sl, tr), 2 * min(sr, tl) + max(sr, tl)});
        OUT(ans);
    }
}
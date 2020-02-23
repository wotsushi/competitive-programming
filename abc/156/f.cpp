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

ll k, q;
vi d;
vi n, x, m;

int main()
{
    cin >> k >> q;
    d = vi(k);
    REP(i, k)
    {
        cin >> d[i];
    }
    n = x = m = vi(q);
    REP(i, q)
    {
        cin >> n[i] >> x[i] >> m[i];
    }
    REP(i, q)
    {
        ll s = 0;
        ll a = 0;
        ll z = 0;
        REP(j, k)
        {
            s += d[j] % m[i];
            if (s >= m[i])
            {
                ++a;
                s -= m[i];
            }
            if (d[j] % m[i] == 0)
            {
                ++a;
            }
        }
        ll p = ((n[i] - 1) / k);
        s = x[i] % m[i] + s * p;
        a = (a * p) + s / m[i];
        s %= m[i];
        REP(j, (n[i] - 1) % k)
        {
            s += d[j] % m[i];
            if (s >= m[i])
            {
                ++a;
                s -= m[i];
            }
            if (d[j] % m[i] == 0)
            {
                ++a;
            }
        }
        ll ans = (n[i] - 1) - a;
        OUT(ans);
    }
}
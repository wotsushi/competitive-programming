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

ll N, M, P, Q, R;
vi x, y, z;

int main()
{
    cin >> N >> M >> P >> Q >> R;
    x = vi(R);
    y = vi(R);
    z = vi(R);
    REP(i, R)
    {
        cin >> x[i] >> y[i] >> z[i];
    }

    ll ans = 0;
    REP(s, 1 << N)
    {
        ll n = 0;
        REP(i, N)
        {
            n += (s >> i) & 1;
        }
        if (n != P)
        {
            continue;
        }
        vi a = vi(M + 1);
        REP(i, R)
        {
            if (s >> (x[i] - 1) & 1)
            {
                a[y[i]] += z[i];
            }
        }
        RSORT(a);
        ll opt = 0;
        REP(i, Q)
        {
            opt += a[i];
        }
        ans = max(ans, opt);
    }

    OUT(ans);
}
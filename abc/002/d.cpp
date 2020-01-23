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

ll N, M;
vi x, y;

int main()
{
    cin >> N >> M;
    x = vi(M);
    y = vi(M);
    REP(i, M)
    {
        cin >> x[i] >> y[i];
    }

    vector<vector<bool>> G(N, vector<bool>(N, false));
    REP(i, M)
    {
        G[x[i] - 1][y[i] - 1] = true;
        G[y[i] - 1][x[i] - 1] = true;
    }
    ll ans = 0;
    REP(p, 1 << N)
    {
        bool ok = true;
        REP(i, N)
        {
            REP(j, N)
            {
                if (((p >> i) & 1) and ((p >> j) & 1) and i != j)
                {
                    ok &= G[i][j];
                }
            }
        }
        if (ok)
        {
            ll k = 0;
            REP(i, N)
            {
                k += (p >> i) & 1;
            }
            ans = max(ans, k);
        }
    }

    OUT(ans);
}
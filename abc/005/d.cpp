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

ll N;
vector<vi> D;
ll Q;
vi P;

int main()
{
    cin >> N;
    D = vector<vi>(N, vi(N));
    REP(i, N)
    {
        REP(j, N)
        {
            cin >> D[i][j];
        }
    }
    cin >> Q;
    P = vi(Q);
    REP(i, Q)
    {
        cin >> P[i];
    }

    vector<vi> dp = vector<vi>(N, vi(N));
    REP(i, N)
    {
        REP(j, N)
        {
            dp[i][j] = D[i][j];
            if (i > 0)
            {
                dp[i][j] += dp[i - 1][j];
            }
            if (j > 0)
            {
                dp[i][j] += dp[i][j - 1];
            }
            if (i > 0 and j > 0)
            {
                dp[i][j] -= dp[i - 1][j - 1];
            }
        }
    }

    vi opt = vi(N * N + 1);
    REP(i, N)
    {
        REP(j, N)
        {
            for (ll k = i; k < N; ++k)
            {
                for (ll l = j; l < N; ++l)
                {
                    ll s = dp[k][l];
                    if (i > 0)
                    {
                        s -= dp[i - 1][l];
                    }
                    if (j > 0)
                    {
                        s -= dp[k][j - 1];
                    }
                    if (i > 0 and j > 0)
                    {
                        s += dp[i - 1][j - 1];
                    }
                    ll c = (k - i + 1) * (l - j + 1);
                    opt[c] = max(opt[c], s);
                }
            }
        }
    }

    REP(q, Q)
    {
        ll ans = 0;
        REP(i, P[q] + 1)
        {
            ans = max(ans, opt[i]);
        }
        OUT(ans);
    }
}
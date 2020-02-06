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
vi a, b, t;

int main()
{
    cin >> N >> M;
    a = vi(M);
    b = vi(M);
    t = vi(M);
    REP(i, M)
    {
        cin >> a[i] >> b[i] >> t[i];
    }

    vector<vi> dp = vector<vi>(N, vi(N, INF));
    REP(i, N)
    {
        dp[i][i] = 0;
    }
    REP(i, M)
    {
        dp[a[i] - 1][b[i] - 1] = t[i];
        dp[b[i] - 1][a[i] - 1] = t[i];
    }
    REP(k, N)
    {
        REP(i, N)
        {
            REP(j, N)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    ll ans = INF;
    REP(i, N)
    {
        ans = min(ans, *max_element(ALL(dp[i])));
    }

    OUT(ans);
}
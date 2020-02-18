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
vi A, B;

int main()
{
    cin >> N >> M;
    A = vi(M);
    B = vi(M);
    REP(i, M)
    {
        cin >> A[i] >> B[i];
    }

    vector<vi> dp = vector<vi>(N + 1, vi(N + 1, INF));
    REP(i, N + 1)
    {
        dp[i][i] = 0;
    }
    REP(i, M)
    {
        dp[A[i]][B[i]] = 1;
        dp[B[i]][A[i]] = 1;
    }
    REP(k, N + 1)
    {
        REP(i, N + 1)
        {
            REP(j, N + 1)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    for (ll i = 1; i <= N; ++i)
    {
        ll ans = 0;
        REP(j, N + 1)
        {
            if (dp[i][j] == 2)
            {
                ++ans;
            }
        }
        OUT(ans);
    }
}
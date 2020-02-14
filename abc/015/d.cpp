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

ll W;
ll N, K;
vi A, B;

int main()
{
    cin >> W;
    cin >> N >> K;
    A = vi(N);
    B = vi(N);
    REP(i, N)
    {
        cin >> A[i] >> B[i];
    }

    vector<vi> dp = vector<vi>(K + 1, vi(W + 1));
    REP(i, N)
    {
        for (ll j = K; j >= 1; --j)
        {
            for (ll k = W; k >= A[i]; --k)
            {
                dp[j][k] = max(dp[j][k], dp[j - 1][k - A[i]] + B[i]);
            }
        }
    }
    ll ans = 0;
    REP(i, K + 1)
    {
        ans = max(ans, dp[i][W]);
    }

    OUT(ans);
}
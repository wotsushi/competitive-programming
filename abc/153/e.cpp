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

ll H, N;
vi A, B;

int main()
{
    cin >> H >> N;
    A = vi(N);
    B = vi(N);
    REP(i, N)
    {
        cin >> A[i] >> B[i];
    }

    vi dp = vi(H + 1, INF);
    dp[0] = 0;
    REP(i, N)
    {
        for (ll j = A[i]; j <= H; ++j)
        {
            dp[j] = min(dp[j], dp[j - A[i]] + B[i]);
        }
        for (ll j = max(0LL, H - A[i]); j < H; ++j)
        {
            dp[H] = min(dp[H], dp[j] + B[i]);
        }
    }
    ll ans = dp[H];

    OUT(ans);
}
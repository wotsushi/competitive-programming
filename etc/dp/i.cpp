#pragma region template 1.0
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
#define REP(i, n) for (ll i = 0; i < (n); ++i)
#define REP1(i, n) for (ll i = 1; i <= (n); ++i)
#define OUT(x) cout << (x) << endl;
#define OUTA(a) \
    REP(i, (a).size()) { cout << (a[i]) << (i == (a).size() - 1 ? "\n" : " "); }
#define ALL(a) (a).begin(), (a).end()
#define SORT(a) sort(ALL(a))
#define RSORT(a) \
    SORT(a);     \
    reverse(ALL(a))

const ll INF = 1e18;
const ll MOD = 1e9 + 7;

int main()
{
    ll N;
    cin >> N;
    vector<double> p(N);
    REP(i, N)
    {
        cin >> p[i];
    }

    vector<double> dp(N + 1);
    dp[0] = 1;
    REP(i, N)
    {
        dp[i + 1] = dp[i] * p[i];
        for (ll j = i; j > 0; --j)
        {
            dp[j] = dp[j] * (1 - p[i]) + dp[j - 1] * p[i];
        }
        dp[0] = dp[0] * (1 - p[i]);
    }
    double ans = 0;
    for (ll i = (N / 2 + 1); i <= N; ++i)
    {
        ans += dp[i];
    }

    cout << fixed << setprecision(15) << ans << endl;
}
#pragma endregion template
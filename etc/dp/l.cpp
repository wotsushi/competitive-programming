#pragma region template 1.0
#pragma region def
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
#pragma endregion enddef

int main()
{
    ll N;
    cin >> N;
    vi a(N);
    REP(i, N)
    {
        cin >> a[i];
    }

    vector<vi> dp(N + 1, vi(N + 1));
    REP1(i, N)
    {
        REP1(j, i)
        {
            if ((N - j) & 1)
            {
                dp[i][j] = min(dp[i - 1][j - 1] - a[i - 1], dp[i][j - 1] - a[i - j]);
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j - 1] + a[i - 1], dp[i][j - 1] + a[i - j]);
            }
        }
    }
    ll ans = dp[N][N];
    OUT(ans);
}
#pragma endregion template
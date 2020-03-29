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

vector<vi> G;
vi dp;

ll f(ll i)
{
    if (dp[i] != -INF)
    {
        return dp[i];
    }
    dp[i] = 0;
    REP(k, G[i].size())
    {
        ll j = G[i][k];
        dp[i] = max(dp[i], 1 + f(j));
    }
    return dp[i];
}

int main()
{
    ll N, M;
    cin >> N >> M;
    vi x(M), y(M);
    REP(i, M) { cin >> x[i] >> y[i]; }

    G = vector<vi>(N + 1);
    REP(i, M)
    {
        G[x[i]].push_back(y[i]);
    }
    dp = vi(N + 1, -INF);
    ll ans = 0;
    REP1(i, N)
    {
        ans = max(ans, f(i));
    }
    OUT(ans);
}
#pragma endregion template
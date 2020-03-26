#pragma region template
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
    ll N, X;
    cin >> N >> X;
    vi w(N);
    REP(i, N)
    {
        cin >> w[i];
    }
    map<ll, ll> dp;
    ll m = N / 2;
    REP(p, 1 << m)
    {
        ll s = 0;
        REP(i, m)
        {
            if (p >> i & 1)
            {
                s += w[i];
            }
        }
        ++dp[s];
    }
    ll ans = 0;
    REP(p, 1 << (N - m))
    {
        ll s = 0;
        REP(i, (N - m))
        {
            if (p >> i & 1)
            {
                s += w[m + i];
            }
        }
        ans += dp[X - s];
    }
    OUT(ans);
}
#pragma endregion template
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
vi c;

int main()
{
    cin >> N;
    c = vi(N);
    REP(i, N)
    {
        cin >> c[i];
    }

    vi dp = vi(N + 1, INF);
    dp[0] = 0;
    REP(i, N)
    {
        ll j = lower_bound(ALL(dp), c[i]) - dp.begin();
        dp[j] = c[i];
    }
    ll k = 0;
    REP(i, N + 1)
    {
        if (dp[i] < INF)
        {
            k = i;
        }
    }
    ll ans = N - k;

    OUT(ans);
}
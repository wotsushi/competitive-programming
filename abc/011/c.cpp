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
ll NG1;
ll NG2;
ll NG3;

int main()
{
    cin >> N;
    cin >> NG1;
    cin >> NG2;
    cin >> NG3;

    vi dp = vi(N + 3, INF);
    auto f = [&](ll k) { return k != NG1 and k != NG2 and k != NG3; };
    dp[N] = f(N) ? 0 : INF;
    for (ll i = N - 1; i >= 0; --i)
    {
        dp[i] = f(i) ? min({dp[i + 1], dp[i + 2], dp[i + 3]}) + 1 : INF;
    }
    string ans = dp[0] <= 100 ? "YES" : "NO";

    OUT(ans);
}
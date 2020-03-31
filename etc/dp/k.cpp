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
    ll N, K;
    cin >> N >> K;
    vi a(N);
    REP(i, N)
    {
        cin >> a[i];
    }

    vector<bool> dp(K + 1);
    REP(i, K + 1)
    {
        REP(j, N)
        {
            dp[i] = dp[i] or a[j] <= i and not dp[i - a[j]];
        }
    }
    if (dp[K])
    {
        OUT("First");
    }
    else
    {
        OUT("Second");
    }
}
#pragma endregion template
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

ll N, H;
ll A, B, C, D, E;

#define CEIL(a, b) ((a) + (b)-1) / (b)

int main()
{
    cin >> N >> H;
    cin >> A >> B >> C >> D >> E;

    ll ans = INF;
    REP(i, N + 1)
    {
        ll j = CEIL(max(0LL, (N - i) * E - (H - 1 + i * B)), D + E);
        if (i + j <= N)
        {
            ans = min(ans, (i * A + j * C));
        }
    }
    OUT(ans);
}

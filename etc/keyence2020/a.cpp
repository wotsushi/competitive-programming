#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define REP(i, n) for (ll i = 0; i < (n); ++i)
#define OUT(x) cout << (x) << endl;
#define OUTA(a, n) \
    REP(i, n) { cout << (a[i]) << (i == n - 1 ? "\n" : " "); }
#define SORT(a) sort(a.begin(), a.end())
#define RSORT(a) \
    SORT(a);     \
    reverse(a.begin(), a.end())
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

#define CEIL(a, b) ((a) + (b)-1) / (b)

ll H, W, N;

int main()
{
    cin >> H;
    cin >> W;
    cin >> N;

    ll ans = CEIL(N, max(H, W));

    OUT(ans);
}
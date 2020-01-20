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

ll N, M;
vi X;

int main()
{
    cin >> N >> M;
    X = vi(M);
    REP(i, M)
    {
        cin >> X[i];
    }
    SORT(X);

    vi D = vi(M - 1);
    REP(i, M - 1)
    {
        D[i] = X[i + 1] - X[i];
    }
    SORT(D);
    ll ans = 0;
    REP(i, M - N)
    {
        ans += D[i];
    }

    OUT(ans);
}
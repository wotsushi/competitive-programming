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

ll N, K;
vector<vi> T;

bool f(ll i, ll s)
{
    if (i == N)
    {
        return s == 0;
    }
    REP(j, K)
    {
        if (f(i + 1, s ^ T[i][j]))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    cin >> N >> K;
    T = vector<vi>(N, vi(K));
    REP(i, N)
    {
        REP(j, K)
        {
            cin >> T[i][j];
        }
    }

    string ans = f(0, 0) ? "Found" : "Nothing";

    OUT(ans);
}

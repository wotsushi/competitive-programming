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

ll N, K, S;

int main()
{
    cin >> N >> K >> S;

    vi ans = vi(N);
    REP(i, N)
    {
        if (i < K)
        {
            ans[i] = S;
        }
        else if (S < 1e9)
        {
            ans[i] = 1e9;
        }
        else
        {
            ans[i] = 1;
        }
    }

    OUTA(ans, N);
}
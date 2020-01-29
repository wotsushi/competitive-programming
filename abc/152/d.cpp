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

ll N;

int main()
{
    cin >> N;

    vector<vi> c = vector<vi>(10, vi(10));
    for (ll i = 1; i <= N; ++i)
    {
        string s = to_string(i);
        ++c[s[0] - '0'][s[s.size() - 1] - '0'];
    }
    ll ans = 0;
    for (ll i = 1; i <= 9; ++i)
    {
        for (ll j = 1; j <= 9; ++j)
        {
            ans += c[i][j] * c[j][i];
        }
    }

    OUT(ans);
}
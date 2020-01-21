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

ll N, A, B;

int main()
{
    cin >> N >> A >> B;

    ll ans;
    if ((B - A) % 2 == 0)
    {
        ans = (B - A) / 2;
    }
    else
    {
        ans = min(A + (B - A - 1) / 2, (N - B) + 1 + (B - A - 1) / 2);
    }

    OUT(ans);
}
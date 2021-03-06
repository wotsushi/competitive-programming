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
vi L;

int main()
{
    cin >> N;
    L = vi(N);
    REP(i, N)
    {
        cin >> L[i];
    }
    SORT(L);

    ll s = 0;
    REP(i, N - 1)
    {
        s += L[i];
    }
    string ans = L[N - 1] < s ? "Yes" : "No";

    OUT(ans);
}
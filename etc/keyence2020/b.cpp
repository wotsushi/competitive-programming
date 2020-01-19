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

typedef pair<ll, ll> ii;
typedef vector<ii> vp;
#define OUTA2(a, n) \
    REP(i, n) { cout << (a[i]).first << " " << (a[i]).second << endl; }

ll N;
vi X, L;

int main()
{
    cin >> N;
    X = vi(N);
    L = vi(N);
    REP(i, N)
    {
        cin >> X[i] >> L[i];
    }

    vp A = vp(N);
    REP(i, N)
    {
        A[i] = ii(X[i] + L[i], X[i] - L[i]);
    }
    SORT(A);
    ll prev = -INF;
    ll ans = 0;
    REP(i, N)
    {
        if (prev <= A[i].second)
        {
            ++ans;
            prev = A[i].first;
        }
    }

    cout << ans << endl;
    return 0;
}
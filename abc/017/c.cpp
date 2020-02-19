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

typedef pair<ll, ll> ii;

ll N, M;
vi l, r, s;

int main()
{
    cin >> N >> M;
    l = vi(N);
    r = vi(N);
    s = vi(N);
    REP(i, N)
    {
        cin >> l[i] >> r[i] >> s[i];
    }

    priority_queue<ii, vector<ii>, greater<ii>> A, B;
    ll t = 0;
    REP(i, N)
    {
        A.push(ii(l[i], i));
        t += s[i];
    }
    ll ans = 0;
    for (ll i = 1; i <= M; i++)
    {
        while (!B.empty() and B.top().first < i)
        {
            t += s[B.top().second];
            B.pop();
        }
        while (!A.empty() and A.top().first == i)
        {
            ll j = A.top().second;
            t -= s[j];
            A.pop();
            B.push(ii(r[j], j));
        }
        ans = max(ans, t);
    }
    OUT(ans);
}
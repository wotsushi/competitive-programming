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
vi A, B;

int main()
{
    cin >> N;
    A = vi(N);
    B = vi(N);
    REP(i, N)
    {
        cin >> A[i];
    }
    REP(i, N)
    {
        cin >> B[i];
    }

    ll ans = INF;
    REP(p, 1 << N)
    {
        vp X = vp(N);
        REP(i, N)
        {
            X[i] = ii(i, 0);
        }
        vi Y = vi(N);
        REP(i, N)
        {
            Y[i] = ((p >> i) & 1) ? B[i] : A[i];
        }
        ll cnt = 0;
        REP(i, N)
        {
            ll k = INF;
            for (ll j = i; j < N; ++j)
            {
                if ((j - i + X[j].second) % 2 == ((p >> X[j].first) & 1) and (k == INF or Y[X[j].first] < Y[X[k].first]))
                {
                    k = j;
                }
            }
            if (k == INF)
            {
                cnt = INF;
                break;
            }
            for (ll j = k; j > i; --j)
            {
                swap(X[j - 1], X[j]);
                X[j - 1].second = 1 - X[j - 1].second;
                X[j].second = 1 - X[j].second;
                ++cnt;
            }
        }
        REP(i, N - 1)
        {
            if (Y[X[i].first] > Y[X[i + 1].first])
            {
                cnt = INF;
            }
        }
        ans = min(ans, cnt);
    }
    if (ans == INF)
    {
        ans = -1;
    }

    OUT(ans)
}
#pragma region template 1.2
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
#define REP(i, n) for (ll i = 0; i < (n); ++i)
#define REP1(i, n) for (ll i = 1; i <= (n); ++i)
#define OUT(x) cout << (x) << endl;
#define OUTA(a) \
    REP(i, (a).size()) { cout << (a[i]) << (i == (a).size() - 1 ? "\n" : " "); }
#define FOUT(x) cout << fixed << setprecision(15) << (x) << endl;
#define ALL(a) (a).begin(), (a).end()
#define SORT(a) sort(ALL(a))
#define RSORT(a) \
    SORT(a);     \
    reverse(ALL(a))

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
#pragma endregion template
#pragma region segt 1.0
template <typename T>
struct segt
{
    using F = function<T(T, T)>;
    ll m;
    vector<T> a;
    T e;
    F f;

    segt(ll n, T e, F f) : e(e), f(f)
    {
        m = 1;
        while (m < n)
        {
            m <<= 1;
        }
        a.assign(2 * m, e);
    }

    void update(ll i, T x)
    {
        i += m;
        a[i] = x;
        while (i >>= 1)
        {
            a[i] = f(a[2 * i], a[2 * i + 1]);
        }
    }

    T query(ll i, ll j)
    {
        T l = e;
        T r = e;
        for (i += m, j += m; i < j; i >>= 1, j >>= 1)
        {
            if (i & 1)
            {
                l = f(l, a[i]);
                ++i;
            }
            if (j & 1)
            {
                --j;
                r = f(r, a[j]);
            }
        }
        return f(l, r);
    }
};
#pragma endregion segt

int main()
{
    ll N;
    cin >> N;
    vi h(N), a(N);
    REP(i, N)
    {
        cin >> h[i];
    }
    REP(i, N)
    {
        cin >> a[i];
    }

    segt<ll> dp(N + 1, 0, [](ll x, ll y) { return max(x, y); });
    REP(i, N)
    {
        dp.update(h[i], dp.query(0, h[i]) + a[i]);
    }
    ll ans = dp.query(0, N + 1);

    OUT(ans);
}
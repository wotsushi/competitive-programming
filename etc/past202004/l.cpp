#pragma region template 2.4
#include <bits/stdc++.h>
using namespace std;
template <typename T>
using pq_asc = priority_queue<T, vector<T>, greater<T>>;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
#define REP(i, n) for (ll i = 0; i < (n); ++i)
#define REP1(i, n) for (ll i = 1; i <= (n); ++i)
#define FOR(i, a) for (auto &i : a)
#define CH(f, x, y) x = f(x, y)
#define IN(T, x) \
    T x;         \
    cin >> x;
#define AIN(T, a, n) \
    vector<T> a(n);  \
    FOR(i, a)        \
    cin >> i;
#define A2IN(T1, a, T2, b, n) \
    vector<T1> a(n);          \
    vector<T2> b(n);          \
    REP(i, n)                 \
    cin >> a[i] >> b[i];
#define OUT(x) cout << (x) << endl;
#define FOUT(x) cout << fixed << setprecision(15) << (x) << endl;
#define ALL(a) (a).begin(), (a).end()
#define SORT(a) sort(ALL(a))
#define RSORT(a) \
    SORT(a);     \
    reverse(ALL(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define DUMPA(a)          \
    cout << #a << " = {"; \
    JOUT(ALL(a), ", ", cout) << "}" << endl;

template <typename T>
ostream &JOUT(T s, T e, string sep = " ", ostream &os = cout)
{
    if (s != e)
    {
        os << *s;
        ++s;
    }
    while (s != e)
    {
        os << sep << *s;
        ++s;
    }
    return os;
}

ostream &YES(bool cond, string yes = "Yes", string no = "No", ostream &os = cout)
{
    if (cond)
    {
        os << yes << endl;
    }
    else
    {
        os << no << endl;
    }
    return os;
}

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << '(' << p.first << ", " << p.second << ')';
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << '[';
    JOUT(ALL(v), ", ", os) << ']';
    return os;
}

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

    segt() {}

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
    IN(ll, N);
    IN(ll, K);
    IN(ll, D);
    AIN(ll, A, N);
    if (K + (K - 1) * (D - 1) > N)
    {
        OUT(-1);
        return 0;
    }
    segt<ii> seg(N, {INF, 0}, [](ii x, ii y) { return min(x, y); });
    REP(i, N)
    {
        seg.update(i, {A[i], i});
    }
    vi ans;
    ll l = 0;
    for (; K > 0; --K)
    {
        auto [a, j] = seg.query(l, N - (K + (K - 1) * (D - 1)) + 1);
        ans.push_back(a);
        l = j + D;
    }
    JOUT(ALL(ans)) << endl;
}
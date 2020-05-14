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

int main()
{
    IN(string, a);
    IN(string, b);
    IN(string, c);
    ll na = a.size();
    ll nb = b.size();
    ll nc = c.size();
    ll offset = nb + nc;
    ll r = na + max(nb, nc);
    auto f = [&](string &x, string &y) {
        ll n = x.size();
        ll m = y.size();
        vector<bool> res(offset + r + 1);
        for (ll i = -offset; i <= r; ++i)
        {
            res[i + offset] = true;
            REP(j, m)
            {
                if (not(i + j < 0 or i + j >= n or y[j] == x[i + j] or y[j] == '?' or x[i + j] == '?'))
                {
                    res[i + offset] = false;
                }
            }
        }
        return res;
    };
    auto ab = f(a, b);
    auto ac = f(a, c);
    auto bc = f(b, c);
    ll ans = INF;
    for (ll i = -offset; i <= r; ++i)
    {
        for (ll j = -offset; j <= r; ++j)
        {
            ll d = j - i;
            if (ab[i + offset] and ac[j + offset] and (d < -offset or d > r or bc[d + offset]))
            {
                CH(min, ans, max({na, i + nb, j + nc}) - min({0LL, i, j}));
            }
        }
    }
    OUT(ans);
}
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

void solve()
{
    IN(ll, a);
    IN(ll, b);
    IN(ll, c);
    ll ans = INF;
    ll A, B, C;
    REP1(j, 2 * c)
    {
        ll i = 1;
        for (ll x = 1; x * x <= j; ++x)
        {
            if (j % x == 0 and abs(x - a) < abs(i - a))
            {
                i = x;
            }
            if (j % x == 0 and abs(j / x - a) < abs(i - a))
            {
                i = j / x;
            }
        }
        ll k;
        if (c % j == 0)
        {
            k = c;
        }
        else if (j < c)
        {
            if (c % j < j - c % j)
            {
                k = c - c % j;
            }
            else
            {
                k = c + j - c % j;
            }
        }
        else
        {
            k = j;
        }
        ll cost = abs(a - i) + abs(b - j) + abs(c - k);
        if (cost < ans)
        {
            ans = cost;
            A = i;
            B = j;
            C = k;
        }
    }
    OUT(ans);
    cout << A << ' ' << B << ' ' << C << endl;
}

int main()
{
    IN(ll, t);
    REP(i, t)
    {
        solve();
    }
}
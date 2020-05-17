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
#pragma region mint 1.1
struct mint
{
    ll a;

    mint(ll a = 0) : a((a % MOD + MOD) % MOD) {}
    mint pow(ll y)
    {
        ll exp = y;
        mint res = 1;
        mint p = a;
        while (exp)
        {
            if (exp & 1)
            {
                res *= p;
            }
            exp >>= 1;
            p *= p;
        }
        return res;
    }
    mint pow(mint y)
    {
        return pow(y.a);
    }
    mint &operator+=(ll y)
    {
        *this = a + y;
        return *this;
    }
    mint &operator+=(mint y)
    {
        *this += y.a;
        return *this;
    }
    mint &operator-=(ll y)
    {
        *this = a - y;
        return *this;
    }
    mint &operator-=(mint y)
    {
        *this -= y.a;
        return *this;
    }
    mint &operator*=(ll y)
    {
        *this = a * y;
        return *this;
    }
    mint &operator*=(mint y)
    {
        *this *= y.a;
        return *this;
    }
    mint &operator/=(ll y)
    {
        *this *= mint(y).pow(MOD - 2);
        return *this;
    }
    mint &operator/=(const mint y)
    {
        *this /= y.a;
        return *this;
    }
    mint &operator++()
    {
        *this += 1;
        return *this;
    }
    mint &operator++(int)
    {
        *this += 1;
        return *this;
    }
    mint &operator--()
    {
        *this -= 1;
        return *this;
    }
    mint &operator--(int)
    {
        *this -= 1;
        return *this;
    }
};

mint operator+(const mint &x, const mint &y)
{
    return mint(x.a) += y;
}
mint operator+(const mint &x, const ll &y)
{
    return mint(x.a) += y;
}
mint operator+(const ll &x, mint &y)
{
    return mint(x) += y;
}
mint operator-(const mint &x, const mint &y)
{
    return mint(x.a) -= y;
}
mint operator-(const mint &x, const ll &y)
{
    return mint(x.a) -= y;
}
mint operator-(const ll &x, const mint &y)
{
    return mint(x) -= y;
}
mint operator*(const mint &x, const mint &y)
{
    return mint(x.a) *= y;
}
mint operator*(const mint &x, const ll &y)
{
    return mint(x.a) *= y;
}
mint operator*(const ll &x, const mint &y)
{
    return mint(x) *= y;
}
mint operator/(const mint &x, const mint &y)
{
    return mint(x.a) /= y;
}
mint operator/(const mint &x, const ll &y)
{
    return mint(x.a) /= y;
}
mint operator/(const ll &x, const mint &y)
{
    return mint(x) /= y;
}
bool operator==(const mint &x, const mint &y)
{
    return x.a == y.a;
}
bool operator==(const mint &x, const ll &y)
{
    return x.a == y;
}
bool operator==(const ll &x, mint &y)
{
    return x == y.a;
}
bool operator!=(const mint &x, const mint &y)
{
    return !(x == y);
}
bool operator!=(const mint &x, const ll &y)
{
    return !(x == y);
}
bool operator!=(const ll &x, mint &y)
{
    return !(x == y);
}
istream &operator>>(istream &is, mint &i)
{
    is >> i.a;
    return is;
}
ostream &operator<<(ostream &os, const mint &i)
{
    os << i.a;
    return os;
}

typedef vector<mint> vm;
#pragma endregion mint

int main()
{
    IN(ll, N);
    A2IN(ll, A, ll, B, N);
    map<ii, ll> c;
    ll z = 0;
    REP(i, N)
    {
        ll a = A[i];
        ll b = B[i];
        if (a == 0 and b == 0)
        {
            ++z;
        }
        else
        {

            if (a < 0)
            {
                a *= -1;
                b *= -1;
            }
            if (a == 0 and b < 0)
            {
                b *= -1;
            }
            ll g = gcd(a, b);
            a /= g;
            b /= g;
            ++c[{a, b}];
        }
    }
    mint ans = 1;
    for (auto [k, v] : c)
    {
        if (v == 0)
        {
            continue;
        }
        auto [x, y] = k;
        ii opp;
        if (y > 0)
        {
            opp = {y, -x};
        }
        else if (y == 0)
        {
            opp = {0, 1};
        }
        else
        {
            opp = {-y, x};
        }
        if (c.find(opp) == c.end())
        {
            ans *= mint(2).pow(v);
        }
        else
        {
            ans *= mint(2).pow(v) + mint(2).pow(c[opp]) - 1;
            c[opp] = 0;
        }
    }
    ans += z - 1;
    OUT(ans);
}
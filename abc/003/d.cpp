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

class mint
{
public:
    ll a;

    mint(const ll x = 0) : a(x % MOD) {}
    ll &value() { return a; }
    mint pow(ll rhs)
    {
        ll exp = rhs;
        mint res = mint(1);
        mint p = mint(a);
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
    mint pow(mint rhs)
    {
        return pow(rhs.a);
    }
    mint &operator+=(ll rhs)
    {
        a += rhs;
        if (a >= MOD)
        {
            a -= MOD;
        }
        return *this;
    }
    mint &operator+=(mint rhs)
    {
        *this += rhs.a;
        return *this;
    }
    mint &operator-=(ll rhs)
    {
        if (a < rhs)
        {
            a += MOD;
        }
        a -= rhs;
        return *this;
    }
    mint &operator-=(mint rhs)
    {
        *this -= rhs.a;
        return *this;
    }
    mint &operator*=(ll rhs)
    {
        a = a * rhs % MOD;
        return *this;
    }
    mint &operator*=(mint rhs)
    {
        *this *= rhs.a;
        return *this;
    }
    mint &operator/=(ll rhs)
    {
        *this *= mint(rhs).pow(MOD - 2);
        return *this;
    }
    mint &operator/=(mint rhs)
    {
        *this /= rhs.a;
        return *this;
    }
};

mint operator+(const mint &lhs, const mint &rhs)
{
    return mint(lhs.a) += rhs;
}
mint operator+(const mint &lhs, const ll &rhs)
{
    return mint(lhs.a) += rhs;
}
mint operator+(const ll &lhs, const mint &rhs)
{
    return mint(lhs) += rhs;
}
mint operator-(const mint &lhs, const mint &rhs)
{
    return mint(lhs.a) -= rhs;
}
mint operator-(const mint &lhs, const ll &rhs)
{
    return mint(lhs.a) -= rhs;
}
mint operator-(const ll &lhs, const mint &rhs)
{
    return mint(lhs) -= rhs;
}
mint operator*(const mint &lhs, const mint &rhs)
{
    return mint(lhs.a) *= rhs;
}
mint operator*(const mint &lhs, const ll &rhs)
{
    return mint(lhs.a) *= rhs;
}
mint operator*(const ll &lhs, const mint &rhs)
{
    return mint(lhs) *= rhs;
}
mint operator/(const mint &lhs, const mint &rhs)
{
    return mint(lhs.a) /= rhs;
}
mint operator/(const mint &lhs, const ll &rhs)
{
    return mint(lhs.a) /= rhs;
}
mint operator/(const ll &lhs, const mint &rhs)
{
    return mint(lhs) /= rhs;
}

ll R, C;
ll X, Y;
ll D, L;

int main()
{
    cin >> R >> C;
    cin >> X >> Y;
    cin >> D >> L;

    vector<mint> fact = vector<mint>(R * C + 1);
    fact[0] = mint(1);
    REP(i, R * C)
    {
        fact[i + 1] = (i + 1) * fact[i];
    }
    auto comb = [&](ll n, ll r) { return fact[n] / (fact[r] * fact[n - r]); };
    auto f = [&](ll x, ll y) { return x < 0 or x * y < D + L ? mint(0) : comb(x * y, D) * comb(x * y - D, L); };
    ll P = (R - X + 1) * (C - Y + 1);
    mint A = f(X, Y);
    mint A1 = 2 * (f(X - 1, Y) + f(X, Y - 1));
    mint A2 = (f(X - 2, Y) + f(X, Y - 2) + 4 * f(X - 1, Y - 1));
    mint A3 = 2 * (f(X - 1, Y - 2) + f(X - 2, Y - 1));
    mint A4 = f(X - 2, Y - 2);
    mint ans = P * (A - (A1 - A2 + A3 - A4));

    OUT(ans.a);
}
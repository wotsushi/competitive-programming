#pragma region template
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
#define ALL(a) (a).begin(), (a).end()
#define SORT(a) sort(ALL(a))
#define RSORT(a) \
    SORT(a);     \
    reverse(ALL(a))

const ll INF = 1e18;
const ll MOD = 1e9 + 7;

#pragma region mint
struct mint
{
    ll a;

    mint(ll x = 0) : a((x % MOD + MOD) % MOD) {}
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
        if (rhs < 0)
        {
            rhs += MOD;
        }
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
    mint &operator/=(const mint rhs)
    {
        *this /= rhs.a;
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

mint operator+(const mint &lhs, const mint &rhs)
{
    return mint(lhs.a) += rhs;
}
mint operator+(const mint &lhs, const ll &rhs)
{
    return mint(lhs.a) += rhs;
}
mint operator+(const ll &lhs, mint &rhs)
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
#pragma endregion mint

int main()
{
    ll N;
    cin >> N;
    vi x(N);
    REP(i, N) { cin >> x[i]; }

    mint ans(0), acc(0);
    REP1(i, N - 1)
    {
        acc += mint(1) / i;
        ans += (x[i] - x[i - 1]) * acc;
    }
    REP1(i, N - 1)
    {
        ans *= i;
    }

    OUT(ans);
}
#pragma endregion template
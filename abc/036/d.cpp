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

vector<vi> G;
vector<mint> dp;
vector<bool> used;

mint dfs(ll i, ll p)
{
    if (used[i])
    {
        return dp[i];
    }
    mint w = mint(1);
    mint b = mint(1);
    REP(j, G[i].size())
    {
        ll c = G[i][j];
        if (c != p)
        {
            w *= dfs(c, i);
            REP(k, G[c].size())
            {
                if (G[c][k] != i)
                {
                    b *= dfs(G[c][k], c);
                }
            }
        }
    }
    dp[i] = (w + b);
    used[i] = true;
    return dp[i];
}

int main()
{
    ll N;
    cin >> N;
    vi a(N - 1), b(N - 1);
    REP(i, N - 1)
    {
        cin >> a[i] >> b[i];
    }

    G = vector<vi>(N + 1);
    REP(i, N - 1)
    {
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
    dp = vector<mint>(N + 1);
    used = vector<bool>(N + 1);
    mint ans = dfs(1, 0);

    OUT(ans.a);
}
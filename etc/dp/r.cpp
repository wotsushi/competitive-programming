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
#pragma region matrix 1.0
template <typename T>
struct matrix
{
    ll n, m;
    vector<vector<T>> A;

    matrix() {}
    matrix(ll n) : n(n), m(n)
    {
        A.assign(n, vector<T>(n));
    }
    matrix(ll n, ll m) : n(n), m(m)
    {
        A.assign(n, vector<T>(m));
    }
    matrix(vector<vector<T>> X) : A(X)
    {
        n = X.size();
        m = X[0].size();
    }
    matrix pow(ll k)
    {
        matrix<T> res = matrix(n, n);
        REP(i, n)
        {
            res[i][i] = 1;
        }
        matrix P = A;
        while (k)
        {
            if (k & 1)
            {
                res *= P;
            }
            k >>= 1;
            P *= P;
        }
        return res;
    }
    matrix &operator+=(matrix<T> B)
    {
        REP(i, n)
        {
            REP(j, m)
            {
                A[i][j] += B[i][j];
            }
        }
        return *this;
    }
    matrix &operator-=(matrix<T> B)
    {
        REP(i, n)
        {
            REP(j, m)
            {
                A[i][j] -= B[i][j];
            }
        }
        return *this;
    }
    matrix &operator*=(T x)
    {
        REP(i, n)
        {
            REP(j, m)
            {
                A[i][j] *= x;
            }
        }
        return *this;
    }
    matrix &operator*=(matrix<T> B)
    {
        vector<vector<T>> X(n, vector<T>(m));
        REP(i, n)
        {
            REP(j, B.m)
            {
                REP(k, m)
                {
                    X[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        A = X;
        return *this;
    }
    matrix &operator/=(T x)
    {
        REP(i, n)
        {
            REP(j, m)
            {
                A[i][j] /= x;
            }
        }
        return *this;
    }

    vector<T> &operator[](int i)
    {
        return A[i];
    }
};

template <typename T>
matrix<T> operator+(const matrix<T> &A, const matrix<T> &B)
{
    return matrix<T>(A.A) += B;
}
template <typename T>
matrix<T> operator-(const matrix<T> &A, const matrix<T> &B)
{
    return matrix<T>(A.A) -= B;
}
template <typename T>
matrix<T> operator*(const matrix<T> &A, const T &x)
{
    return matrix<T>(A.A) *= x;
}
template <typename T>
matrix<T> operator*(const T &x, const matrix<T> &A)
{
    return matrix<T>(A.A) *= x;
}
template <typename T>
matrix<T> operator*(const matrix<T> &A, const matrix<T> &B)
{
    return matrix<T>(A.A) *= B;
}
template <typename T>
matrix<T> operator/(const matrix<T> &A, const T &x)
{
    return matrix<T>(A.A) /= x;
}
template <typename T>
bool operator==(const matrix<T> &x, const matrix<T> &y)
{
    return x.A == y.A;
}
template <typename T>
bool operator!=(const matrix<T> &x, const matrix<T> &y)
{
    return x.A != y.A;
}

#pragma endregion matrix

int main()
{
    IN(ll, N);
    IN(ll, K);
    vector<vm> a(N, vm(N));
    REP(i, N)
    {
        REP(j, N)
        {
            cin >> a[i][j];
        }
    }
    auto C = matrix<mint>(a).pow(K);
    mint ans;
    REP(i, N)
    {
        REP(j, N)
        {
            ans += C[i][j];
        }
    }
    OUT(ans);
}
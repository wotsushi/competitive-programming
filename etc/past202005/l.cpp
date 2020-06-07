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
    IN(ll, N);
    vi K(N);
    vvi T(N);
    REP(i, N)
    {
        cin >> K[i];
        T[i].assign(K[i], 0);
        REP(j, K[i])
        {
            cin >> T[i][j];
        }
    }
    IN(ll, M);
    AIN(ll, a, M);
    vector<set<ii>> S(2);
    vi I(N, 1);
    REP(i, N)
    {
        S[0].insert({T[i][0], i});
        if (K[i] >= 2)
        {
            S[1].insert({T[i][1], i});
        }
    }
    FOR(x, a)
    {
        auto [u, i] = *S[0].rbegin();
        ll v, j;
        if (x == 2 and not S[1].empty())
        {
            v = (*S[1].rbegin()).first;
            j = (*S[1].rbegin()).second;
        }
        else
        {
            v = 0;
            j = 0;
        }
        if (u > v)
        {
            OUT(u);
            S[0].erase({u, i});
            if (I[i] < K[i])
            {
                S[1].erase({T[i][I[i]], i});
                S[0].insert({T[i][I[i]], i});
                ++I[i];
                if (I[i] < K[i])
                {
                    S[1].insert({T[i][I[i]], i});
                }
            }
        }
        else
        {
            OUT(v);
            S[1].erase({v, j});
            ++I[j];
            if (I[j] < K[j])
            {
                S[1].insert({T[j][I[j]], j});
            }
        }
    }
}

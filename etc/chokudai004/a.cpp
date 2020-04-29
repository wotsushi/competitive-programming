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

ll N, B1, B2, B3;
ll calc_score(vvi &A)
{
    ll score = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int now = 0;
            for (int k = i; k < N; k++)
            {
                now += A[k][j];
                if (now == B1)
                    score += B1;
                if (now == B2)
                    score += B2;
                if (now == B3)
                    score += B3;
                if (now > B3)
                    break;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int now = 0;
            for (int k = j; k < N; k++)
            {
                now += A[i][k];
                if (now == B1)
                    score += B1;
                if (now == B2)
                    score += B2;
                if (now == B3)
                    score += B3;
                if (now > B3)
                    break;
            }
        }
    }
    return score;
}

int main()
{
    cin >> N;
    cin >> B1;
    cin >> B2;
    cin >> B3;
    vvi l(N, vi(N));
    REP(i, N)
    {
        REP(j, N)
        {
            cin >> l[i][j];
        }
    }
    vvi r(N, vi(N));
    REP(i, N)
    {
        REP(j, N)
        {
            cin >> r[i][j];
        }
    }

    vvi A(N, vi(N));
    REP(i, N)
    {
        REP(j, N)
        {
            ll s = 0;
            ll p = 0;
            REP(k, i - 1)
            {
                s += A[i - 1 - k][j];
                if (p < 3 and l[i][j] <= B3 - s and B3 - s <= r[i][j])
                {
                    A[i][j] = B3 - s;
                    p = 3;
                }
                if (p < 2 and l[i][j] <= B2 - s and B2 - s <= r[i][j])
                {
                    A[i][j] = B2 - s;
                    p = 2;
                }
                if (p < 1 and l[i][j] <= B1 - s and B1 - s <= r[i][j])
                {
                    A[i][j] = B1 - s;
                    p = 1;
                }
            }
            s = 0;
            REP(k, j - 1)
            {
                s += A[i][j - 1 - k];
                if (p < 3 and l[i][j] <= B3 - s and B3 - s <= r[i][j])
                {
                    A[i][j] = B3 - s;
                    p = 3;
                }
                if (p < 2 and l[i][j] <= B2 - s and B2 - s <= r[i][j])
                {
                    A[i][j] = B2 - s;
                    p = 2;
                }
                if (p < 1 and l[i][j] <= B1 - s and B1 - s <= r[i][j])
                {
                    A[i][j] = B1 - s;
                    p = 1;
                }
            }
            if (A[i][j] == 0)
            {
                A[i][j] = r[i][j];
            }
        }
    }
    ll score_opt = calc_score(A);
    REP(i, N)
    {
        REP(j, N)
        {
            ll tmp = A[i][j];
            for (ll a = l[i][j]; a <= r[i][j]; ++a)
            {
                A[i][j] = a;
                ll score = calc_score(A);
                if (score <= score_opt)
                {
                    A[i][j] = tmp;
                }
                else
                {
                    score_opt = score;
                }
            }
        }
    }

    REP(i, N)
    {
        JOUT(ALL(A[i])) << endl;
    }
}
//Link: https://oj.vnoi.info/problem/bedao_r20_a

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const long long INF = 1e15;
const ll MOD = 1e9+7;
const double eps = 1e-12;
#define forn(i,e) for(ll i = 1; i <= e; i++)
#define forsn(i,s,e) for(ll i = s; i <= e; i++)
#define rforn(i,s) for(ll i = s; i >= 1; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define DEBUG(x) cout<<#x<<" = "<<x<<ln
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((ll)(x).size())

//Modulo Calculation
ll add(ll x, ll y)
{
    return (x + y) % MOD;
}

ll sub(ll x, ll y)
{
    return ((x - y) % MOD + MOD) % MOD;
}

ll mul(ll x, ll y)
{
    return (long long)x * y % MOD;
}

void solve()
{
    ll n, t;
    cin >> t;
    while (t--)
    {
        cin>>n;
        ll tmp1 = sqrt(n);
        if (tmp1*tmp1 != n)
        {
            cout << 0 << ln;
            continue;
        }
        ll res = 0;
        for (ll i=2; i*i<=tmp1; i++)
        {
            if (tmp1 % i == 0)
            {
                if (i%2==0 && (tmp1/i)%2==0)
                {
                    if (i == tmp1/i) res++;
                    else res+=2;

                }
            }
        }
        cout << res << ln;
    }
}


int main()
{
    fast_cin();
    solve();
    return 0;
}

/*
Link: https://lqdoj.edu.vn/problem/2023thtc2b3
*/

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
ll add(ll x, ll y){
    return (x + y) % MOD;
}

ll sub(ll x, ll y){
    return ((x - y) % MOD + MOD) % MOD;
}

ll mul(ll x, ll y){
    return (long long)x * y % MOD;
}

void sub1(ll n, ll k, vector<ll> &v){
    double res = (double)(-INF);
    double cnt = 0;
    double curr_sum = 0;
    for (ll i=1;i<=n;i++){
        cnt = 0;
        curr_sum = 0;
        for (ll j=i;j<=n;j++){
            cnt++;
            curr_sum+=v[i];
            double tbc = curr_sum / cnt;
            res = max(tbc,res);
        }
    }
    cout << fixed << setprecision(3) << res;
}

void sub2(ll n, ll k, vector<ll> &v){
    double res = (double)(-INF);
    double cnt = 0;
    double curr_sum = 0;

    for (double k1 = k; k1<=n;k1++){
        for (ll i=1;i<=n;i++){
            curr_sum = 0;
            bool flag = true;
            for (ll j = i;j<=i+k1-1;j++){
                if (j > n){
                  flag = false; break;
                }
                curr_sum+=v[j];
            }
            if (flag == true){
                double tbc = curr_sum / k1;
                res = max(tbc,res);
            }
        }
    }

    cout << fixed << setprecision(3) << res;
}

void sub3(ll n, ll k, vector<ll> &v){
    vector<ll> prefix(n+1,0);
    for (ll i=1;i<=n;i++){
        prefix[i] = prefix[i-1] + v[i];
    }
    double res = (double)(-INF);
    double cnt = 0;
    double curr_sum = 0;
    for (double k1 = k; k1<=n;k1++){
        for (ll i=1;i<=n;i++){
            if (i + k1 - 1 <=n){
                curr_sum = prefix[i+k1-1] - prefix[i-1];
                double tbc = curr_sum / k1;
                res = max(res, tbc);
            }
        }
    }
    cout << fixed << setprecision(3) << res;
}

void sub4(ll n, ll k, vector<ll> &v){
    double res = (double)(-INF);
    vector<ll> max_sum_of(k+1,0);


}

void solve(){
    ll n,k; cin >> n >> k;
    vector<ll> v(n+1);
    for(ll i=1;i<=n;i++) cin >> v[i];
    if (n<=400 && k==1){
        sub1(n,k,v);
    }
    else if (k > 1 && n>=k && n<=400){
        sub2(n,k,v);
    }
    else if (k>1 && n>=k && n<=5e3){
        sub3(n,k,v);
    }
    else {
        sub4(n,k,v);
    }
}


int main()
{
//    freopen("BOCBONG.INP","r",stdin);
//    freopen("BOCBONG.OUT","w",stdout);
    fast_cin();
    solve();
    return 0;
}


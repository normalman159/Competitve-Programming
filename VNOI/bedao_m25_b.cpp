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
ll n,a,b,c;
void sub12(){
    vector<ll> uoc;
    for (ll i=1;i*i<=n;i++){
        if (n % i ==0 ){
            if (i * i != n){
                uoc.pb(i); uoc.pb(n/i);
            }
            else uoc.pb(i);
        }
    }
    ll ans = 0;
    auto ktra = [](ll x){
        vector<ll> z = {a,b,c};
        if (x % z[0] == 0 && x % z[1]== 0) return true;
        if (x % z[1] == 0 && x % z[2]== 0) return true;
        if (x % z[0] == 0 && x % z[2]== 0) return true;
        return false;
    };
    for (auto x : uoc){
        if (ktra(x)) ans++;
    }
    cout << ans;
}

ll LCM(ll a, ll b){
    if (a == -1 || b == -1) return -1;
    ll ans =  (a*b)/__gcd(a,b);
    if (ans > n) return -1;
    return ans;
}

ll Solve_sub3(ll a, ll b){
    if (b == -1) return 0;
    if (a%b !=0 ) return 0;
    ll z = a/b;
    ll cnt = 0;
    for (ll i=1; i*i<=z;i++){
        if (z % i == 0){
            cnt+=2;
            if (i*i == z) cnt--;
        }
    }
    return cnt;
}

void sub3(){
    cout << Solve_sub3(n, LCM(a,b)) + Solve_sub3(n, LCM(b,c)) + Solve_sub3(n, LCM(c,a)) - 2*Solve_sub3(n,LCM(LCM(a,b),c));
}

void solve(){

    cin >> n >> a >> b >> c;
    sub3();
}


int main()
{
    freopen("bedao_m25_b.inp", "r", stdin);
    freopen("bedao_m25_b.out", "w", stdout);
    fast_cin();
    solve();
    return 0;
}

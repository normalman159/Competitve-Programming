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
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((ll)(x).size())
 
ll powMod(ll a, ll b, ll m){
    ll res = 1;
    while (b){
        if (b%2) res = (res*a)%m;
        a= (a*a)%m;
        b/=2;
    }
    return res;
}

ll modulo_inverse(int a, int M)
{
      return powMod(a, M - 2, M);
}

//Modulo Calculation
ll add(ll x, ll y){
    return (x + y) % MOD;
}

ll sub(ll x, ll y){
    return ((x - y) % MOD + MOD) % MOD;
}

ll mul(ll x, ll y){
    return (ll)x * y % MOD;
}
 
ll div(ll a, ll b, ll c)
{
      ll inverse = modulo_inverse(b, c);
      return (a % c * inverse) % c;
}

void sub1(ll n){
    auto check = [&](ll x){
        string s = to_string(x);
        set<char> st;
        for (ll i=0; i<s.size();i++){
            if (st.find(s[i]) != st.end()) return false;
            st.insert(s[i]);
        }
        return true;
    };
    ll res =0;
    for (ll i=1;i<=n;i++){
        if (i%5==0 && check(i)==true) res++;
    }
    cout << res;
}

void sub2(ll n){
    ll c[100];
    auto check = [&](ll x){
        fill(c,c+90,0);
        string s = to_string(x);
        for(ll i=0;i<s.size();i++){
            c[s[i]]++;
            if (c[s[i]]>1) return false;
        }
        return true;
    };
    ll res =0;
    for (ll i=5 ; i<=n; i+=5){
        if (check(i) == true){
            res++;
        }  
    }
    cout << res;
}



void solve(){
    ll n; cin >> n;
    if (n < 1e2){
        sub1(n);
    }
    else if (n < 1e8){
        sub2(n);
    }
    else{

    }

}
 
 
int main()
{
    fast_cin();
    solve();
    return 0;
}
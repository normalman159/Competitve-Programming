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



void solve(){
    ll k; cin >> k;
    string s; cin >> s;
    ll n =s.size();
    s= ' ' + s;
    ll k1= k;
    string SMIN, SMAX, origi;
    vector<char> v;
    for (ll i=1;i<=n;i++){
        if (s[i]>='a' && s[i]<='z'){
            ll j =i+1;
            string pos;
            while (s[j]>='0' && s[j]<='9') pos+=s[j], j++;
            for (ll z =1;z<=stoll(pos); z++){
                origi+=s[i];
            }
        }
    }
    ll i =0;
    while (i<origi.size()){
            if (origi[i] < origi[i+1]){
                while (origi[i] < origi[i+1] && k >=1){
                    k--;
                    i++;
                }
            }
            else{
                SMAX+=origi[i];
                i++;
            }
    }
    i =0;
    origi.pb('|');
    while (i < origi.size()-1){
        if (origi[i] > origi[i+1]){
            while (origi[i] > origi[i+1] && k1>=1){
                k1--;
                i++;
            }
        }
        else{
            SMIN+=origi[i];
            i++;
        }
    }
    string SMIN1, SMAX1;
    i=0;
    while (i<SMAX.size()){
        ll cnt = 1;
        SMAX1 += SMAX[i];
        while (SMAX[i] == SMAX[i+1]){
            cnt++;
            i++;
        }
        SMAX1 += to_string(cnt);
        i++;
    }
    i=0;
    while (i<SMIN.size()){
        ll cnt=1;
        SMIN1 += SMIN[i];
        while (SMIN[i]== SMIN[i+1]){
            cnt++;
            i++;
        }
        SMIN1 += to_string(cnt);
        i++;
    }
    cout << SMAX1 << ln << SMIN1;
}
 
 
int main()
{
    fast_cin();
    solve();
    return 0;
}
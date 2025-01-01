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
ll t, n,k;

void trau(){
    bool ktra = true;
    ll count_leaf = 0;
    for (ll i=1;i<=n;i++){
        count_leaf+= i*i;
        if (!((i-k)>=1)) continue;
        count_leaf-= (i-k)*(i-k);
    }
    if (count_leaf & 1){cout << "NO";}
    else cout << "YES";
    cout << ln;
}



void solve_sub(){
    ll end_point = n - k;
    if (end_point < 1){
        if (n % 2==0){
            if (n/2% 2 == 1) cout << "NO" << ln;
            else cout << "YES" << ln;
        }
        if (n % 2 == 1){
            if ((n-1)/2 % 2==1) cout << "YES" << ln;
            else cout << "NO" << ln;
        }
    }

    else{
        end_point++;
        if (end_point % 2 == 0){
            if (n % 2 ==0){ //even even
                if (((n  - 2 - end_point)/2  + 1 )% 2 == 1) cout << "NO" << ln;
                else cout << "YES" << ln;
            }
            else{ //even odd
//                DEBUG((n - 1 - end_point)/2 + 1);
                if (((n - 1 - end_point)/2 + 1) % 2 == 1) cout << "NO" << ln;
                else cout << "YES" << ln;
            }
        }
        else{
            if (n % 2 ==0){ //odd even
                if (((n-1 -end_point)/2 + 1)  % 2 == 1) cout << "NO" << ln;
                else cout << "YES" << ln;
            }
            else{ //odd odd
                if (((n - 2 - end_point)/2  + 1)% 2==1) cout << "YES" << ln;
                else cout << "NO" << ln;
            }
        }
    }
}

void solve(){
    cin >> t;
//    t=1;
    while (t--){
        cin >> n >> k;
//        trau();
        solve_sub();
    }
}


int main()
{
    fast_cin();
    solve();
    return 0;
}



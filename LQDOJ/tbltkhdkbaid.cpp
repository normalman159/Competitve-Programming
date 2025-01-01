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

//Tìm số lẻ và có tổng các chữ số là lẻ thứ n

void solve_trau(ll x){
    ll cnt = 1, tmp = 1;
    auto tong = [](ll z){
        ll ans = 0;
        while (z){
            ans+=z%10;
            z/=10;
        } return ans;
    };
    while (true){
        if (cnt == x) break;
        tmp+=2;
        if (tmp & 1 && tong(tmp) & 1){
            cnt++;
            cout << cnt << " " << tmp << ln;
        }
    }
//    cout << tmp << ln;
}


void solve(ll x){

}


int main()
{
    ll x; cin >> x;
    fast_cin();
    if (x <=1e7){
        solve_trau(x);
    }
    else{
        solve(x);
    }
    return 0;
}


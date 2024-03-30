#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define ln " \n"
const ll INF = 1e18;

int main(){
    ll n;cin >> n;
    ll res  =0;
    for (ll i=1;i*i<=n;i++){
        if (n%i==0){
            res++;
            if (i!= n/i) res++;
        }
    }
    cout << res;
    return 0;
}

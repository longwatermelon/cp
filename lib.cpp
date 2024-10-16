#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define sig(x) (x<0?-1:1)
#define sz(x) ((int)size(x))
#define all(x) begin(x),end(x)
#define all1(x) begin(x)+1,end(x)
const int MD=1e9+7;
template <typename T> using vec=vector<T>;

// sieve of eratosthenes, O(mx log(log mx))
// determine if all numbers <=mx are prime
void sieveofe(int mx, bool *prime) {
    prime[1]=false;
    fill(prime+2,prime+1+mx,true);
    for (int i=2; i*i<=mx; ++i) {
        int j=i;
        while(i*j<mx) {
            prime[i*j]=false;
            ++j;
        }
    }
}

// unordered factors of x, O(sqrt(x))
template <typename T> vector<T> factor(T x) {
    vector<T> f;
    for (T i=1; i*i<=x; ++i) {
        if (x%i==0) {
            f.push_back(i);
            if (x/i!=i)
                f.push_back(x/i);
        }
    }
    return f;
}

// prime factors of x, O(sqrt(x))
template <typename T> map<T,int> primefac(T x) {
    map<T,int> mp;
    for (T i=2; i*i<=x; ++i) {
        while (x%i==0) {
            mp[i]++;
            x/=i;
        }
    }

    if (x>1) mp[x]++;
    return mp;
}

// log_{base}(x) floored
ll logfl(ll base, ll x) {
    assert(base>1);
    ll res=0, val=1;
    while (val*base<=x) {
        val*=base;
        res++;
    }
    return res;
}

// log_{base}(x) ceiling
ll logcl(ll base, ll x) {
    assert(base>1);
    ll res=0, val=1;
    while (val<x) {
        val*=base;
        res++;
    }
    return res;
}

// floor sqrt of x
ll sqrtfl(ll x) {
    ll rt=sqrtl(x);
    if (rt*rt>x) rt--;
    if ((rt+1)*(rt+1)<=x) rt++;
    return rt;
}

// ceil sqrt of x
ll sqrtcl(ll x) {
    ll rt=sqrtl(x);
    if (rt*rt<x) rt++;
    if ((rt-1)*(rt-1)>=x) rt--;
    return rt;
}

// recursive n choose r
ll rencr(int n, int r) {
    if (n<r) return 0;
    else if (r==0||r==n) return 1;
    else return (rencr(n-1,r-1)+rencr(n-1,r))%MD;
}

// closed form n choose r
vec<int> F,IF; // fac, inv fac
ll clncr(int n, int r) {
    if (n<r) return 0;
    return (((ll)F[n]*IF[r])%MD*IF[n-r])%MD;
}

// x^p in mod MD
ll modpow(ll x, ll p) {
    assert(p>=0);
    return p==0 ? 1 : ((ll)modpow(((ll)x*x)%MD,p/2)*(p&1?x:1))%MD;
}

// modular inverse of x in mod MD
ll modinv(ll x) {
    return modpow(x,MD-2);
}

#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define sig(x) (x<0?-1:1)
#define sz(x) ((int)size(x))
#define all(x) begin(x),end(x)
#define all1(x) begin(x)+1,end(x)
#define cmax(x,y) x=max(x,y)
#define cmin(x,y) x=min(x,y)
template <typename T> using vec=vector<T>;
template <typename T> struct vec2:vector<vector<T>> {vec2()=default;vec2(int n, int m, T val=T()):vector<vector<T>>(n,vector<T>(m,val)){}};
template <typename T> struct vec3:vector<vector<vector<T>>> {vec3()=default;vec3(int n, int m, int k, T val=T()):vector<vector<vector<T>>>(n,vector<vector<T>>(m,vector<T>(k,val))){}};
template <typename T> void vprint(T st, T nd) {auto it=st;while (next(it)!=nd){cout<<*it<<' ';it=next(it);}cout<<*it<<'\n';}

//////////////////////////////////////////////////////////////////////
///////////////////////////// BASIC MATH /////////////////////////////
//////////////////////////////////////////////////////////////////////

template <typename T> T cdiv(T a, T b) {return a/b+(sig(a)/sig(b)==1 && a%b);}
template <typename T> T fdiv(T a, T b) {return a/b-(sig(a)/sig(b)==-1 && a%b);}
template <typename T> T mod(T a, T b) {return ((a%b)+b)%b;}
template <typename T> T rmod(T a, T mn, T mx) {return mod((a-mn),(mx-mn+1))+mn;}

/////////////////////////////////////////////////////////////////////////
///////////////////////////// LARGE NUMBERS /////////////////////////////
/////////////////////////////////////////////////////////////////////////

const int MD=1e9+7;
ll modpow(ll x, ll p) {assert(p>=0);return p==0?1:((ll)modpow(((ll)x*x)%MD,p/2)*(p&1?x:1))%MD;}
ll modinv(ll x) {return modpow(x,MD-2);}

/////////////////////////////////////////////////////////////////////////
///////////////////////////// NUMBER THEORY /////////////////////////////
/////////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////////////////
///////////////////////////// FL/CL INTEGER VARIANTS /////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////////////////
///////////////////////////// COMBINATORICS /////////////////////////////
/////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////
///////////////////////////// SPARSE TABLE /////////////////////////////
////////////////////////////////////////////////////////////////////////

// arr 1-indexed
// build sparse table (range queries for idempotent fn f)
vec2<int> buildrqi(int *a, int n, const function<int(int,int)> &f) {
    int mxh=logfl(2,n);
    vec2<int> v(mxh+1,n+1);
    for (int i=1; i<=n; ++i) {
        v[0][i]=a[i];
    }

    for (int h=1; h<=mxh; ++h) {
        for (int i=1; i+(1<<(h-1))<=n; ++i) {
            v[h][i]=f(v[h-1][i], v[h-1][i+(1<<(h-1))]);
        }
    }

    return v;
}

// query [l,r] with idempotent function f
int rqu(const vec2<int> &v, int l, int r, const function<int(int,int)> &f) {
    assert(l<=r);
    int p=logfl(2,r-l+1);
    return f(v[p][l],v[p][r-(1<<p)+1]);
}

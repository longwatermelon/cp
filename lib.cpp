#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define sign(x) (x<0?-1:1)
#define sz(x) ((int)size(x))
#define all(x) begin(x),end(x)
#define all1(x) begin(x)+1,end(x)
template <typename T> using vec=vector<T>;
template <typename T> struct vec2:vector<vector<T>> {vec2()=default;vec2(int n, int m, T val=T()):vector<vector<T>>(n,vector<T>(m,val)){}void assign(int n, int m, T val = T()) {this->vector<vector<T>>::assign(n, vector<T>(m, val));}};
template <typename T> struct vec3:vector<vector<vector<T>>> {vec3()=default;vec3(int n, int m, int k, T val=T()):vector<vector<vector<T>>>(n,vector<vector<T>>(m,vector<T>(k,val))){}void assign(int n, int m, int k, T val = T()) {this->vector<vector<vector<T>>>::assign(n, vector<vector<T>>(m, vector<T>(k, val)));}};
template <typename T> void vprint(T st, T nd) {auto it=st;while (next(it)!=nd){cout<<*it<<' ';it=next(it);}cout<<*it<<'\n';}
template <typename T> bool ckmin(T &a, T b) {return b<a ? a=b, true : false;}
template <typename T> bool ckmax(T &a, T b) {return b>a ? a=b, true : false;}
const int d4i[]={-1,0,1,0}, d4j[]={0,1,0,-1}, d8i[]={-1,-1,0,1,1,1,0,-1}, d8j[]={0,1,1,1,0,-1,-1,-1};

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using ordset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

//////////////////////////////////////////////////////////////////////
///////////////////////////// BASIC MATH /////////////////////////////
//////////////////////////////////////////////////////////////////////

ll cdiv(ll a, ll b) {return a/b+(sign(a)/sign(b)==1 && a%b);}
ll fdiv(ll a, ll b) {return a/b-(sign(a)/sign(b)==-1 && a%b);}
ll mod(ll a, ll b) {return ((a%b)+b)%b;}
ll rmod(ll a, ll mn, ll mx) {return mod((a-mn),(mx-mn+1))+mn;}

/////////////////////////////////////////////////////////////////////////
///////////////////////////// COMBINATORICS /////////////////////////////
/////////////////////////////////////////////////////////////////////////

const ll MD=1e9+7;
ll modpow(ll x, ll p) {assert(p>=0);return p==0?1:((ll)modpow(((ll)x*x)%MD,p/2)*(p&1?x:1))%MD;}
ll modinv(ll x) {return modpow(x,MD-2);}

// recursive n choose r
ll recomb(ll n, ll r) {
    if (n<r) return 0;
    else if (r==0||r==n) return 1;
    else return (recomb(n-1,r-1)+recomb(n-1,r))%MD;
}

// closed form n choose r
vec<ll> F,IF; // fac, inv fac
ll comb(ll n, ll r) {
    if (n<r) return 0;
    return ((F[n]*IF[r])%MD*IF[n-r])%MD;
}

// gen F, IF for clncr function
void genfac(int mx) {
    F.resize(mx+1);
    IF.resize(mx+1);
    F[0]=1;
    IF[0]=modinv(1);
    for (int x=1; x<=mx; ++x) {
        F[x]=((ll)F[x-1]*x)%MD;
        IF[x]=modinv(F[x]);
    }
}

//////////////////////////////////////////////////////////////////
///////////////////////////// BINARY /////////////////////////////
//////////////////////////////////////////////////////////////////

int popcount(ll x) {
    int cnt=0;
    while (x) {
        cnt+=x&1;
        x/=2;
    }

    return cnt;
}

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
vector<ll> factor(ll x) {
    vector<ll> f;
    for (ll i=1; i*i<=x; ++i) {
        if (x%i==0) {
            f.push_back(i);
            if (x/i!=i)
                f.push_back(x/i);
        }
    }
    return f;
}

// prime factors of x, O(sqrt(x))
map<ll,int> primefac(ll x) {
    map<ll,int> mp;
    for (ll i=2; i*i<=x; ++i) {
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

////////////////////////////////////////////////////////////////////////
///////////////////////////// SPARSE TABLE /////////////////////////////
////////////////////////////////////////////////////////////////////////

// arr 1-indexed
// build sparse table (range queries for idempotent fn f)
vec2<ll> sparse_table_build(ll *a, int n, const function<ll(ll,ll)> &f) {
    int mxh=logfl(2,n);
    vec2<ll> v(mxh+1,n+1);
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
ll sparse_table_query(const vec2<ll> &v, int l, int r, const function<ll(ll,ll)> &f) {
    assert(l<=r);
    int p=logfl(2,r-l+1);
    return f(v[p][l],v[p][r-(1<<p)+1]);
}

///////////////////////////////////////////////////////////////
///////////////////////////// DSU /////////////////////////////
///////////////////////////////////////////////////////////////

// graph vertices 1..n
// v[i]=component i's vertices
// g[u]=ind of graph that vert u is in
void dsu_init(int n, vec<vec<int>> &vt, vec<int> &id) {
    vt=vec<vec<int>>(n+1);
    id=vec<int>(n+1);

    for (int u=1; u<=n; ++u) {
        vt[u]={u};
        id[u]=u;
    }
}

// update dsu w/ edge u<->v
void dsu_add_edge(int u, int v, vec<vec<int>> &vt, vec<int> &id) {
    if (id[u]!=id[v]) {
        if (sz(vt[id[u]])>sz(vt[id[v]])) {
            swap(u,v);
        }

        // merge u to v
        int src=id[u];
        for (int x:vt[src]) {
            id[x]=id[v];
            vt[id[v]].push_back(x);
        }
        vt[src].clear();
    }
}

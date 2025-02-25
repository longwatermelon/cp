#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define sig(x) (x<0?-1:1)
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

// gen F, IF for clncr function
void genfac(int mx) {
    F=vec<int>(mx+1);
    IF=vec<int>(mx+1);
    F[0]=1;
    IF[0]=modinv(1);
    for (int x=1; x<=mx; ++x) {
        F[x]=((ll)F[x-1]*x)%MD;
        IF[x]=modinv(F[x]);
    }
}

//////////////////////////////////////////////////////////////////////////
///////////////////////////// IMPLEMENTATION /////////////////////////////
//////////////////////////////////////////////////////////////////////////

// cyclic right shift on [st, nd]
template <typename T> void cyclic_rshift(T st, T nd) {
    auto last=*nd;
    auto it=nd;
    while (it!=st) {
        *it=*(it-1);
        it--;
    }
    *st=last;
}

// cyclic left shift on [st, nd]
template <typename T> void cyclic_lshift(T st, T nd) {
    auto first=*st;
    auto it=st;
    while (it!=nd) {
        *it=*(it+1);
        it++;
    }
    *nd=first;
}

////////////////////////////////////////////////////////////////////////
///////////////////////////// SPARSE TABLE /////////////////////////////
////////////////////////////////////////////////////////////////////////

// arr 1-indexed
// build sparse table (range queries for idempotent fn f)
vec2<int> sparse_table_build(int *a, int n, const function<int(int,int)> &f) {
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
int sparse_table_query(const vec2<int> &v, int l, int r, const function<int(int,int)> &f) {
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

////////////////////////////////////////////////////////////////////////////////
///////////////////////////// SQRT DECOMP GENERAL //////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// construct sqrt decomp array, O(n)
vec<ll> sqrtd_init(ll *a, int n, const function<ll(ll,ll)> &f) {
    vec<ll> s;
    int rt=sqrtfl(n);
    for (int i=1; i<=n; i+=rt) {
        s.push_back(a[i]);
        for (int j=1; j<rt && i+j<=n; ++j) {
            s.back()=f(s.back(),a[i+j]);
        }
    }

    return s;
}

// return j for a[i] in s[j]
int sqrtd_seg(int i, int n) {
    int rt=sqrtfl(n);
    return (i-1)/rt;
}

// return i for leftmost a[i] in s[j]
int sqrtd_st(int j, int n) {
    int rt=sqrtfl(n);
    return j*rt+1;
}

////////////////////////////////////////////////////////////////////////////////
///////////////////////////// SQRT DECOMP NO LAZY //////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// update segment j according to a, O(sqrt(n))
void sqrtd_upd_seg(ll *a, int n, int j, vec<ll> &s, const function<ll(ll,ll)> &f) {
    int rt=sqrtfl(n);
    int st=sqrtd_st(j,n);
    s[j]=a[st];
    for (int k=st+1; k<st+rt; ++k) {
        s[j]=f(s[j],a[k]);
    }
}

// sqrt decomp range query f(a[l,r]), O(sqrt(n))
ll sqrtd_query(ll *a, int n, int l, int r, const vec<ll> &s, const function<ll(ll,ll)> &f) {
    int il=sqrtd_seg(l,n), ir=sqrtd_seg(r,n);

    ll ans=a[l];
    if (il==ir) {
        for (int i=l+1; i<=r; ++i) {
            ans=f(ans,a[i]);
        }

        return ans;
    }

    for (int i=l+1; i<=sqrtd_st(il+1,n)-1; ++i) {
        ans=f(ans,a[i]);
    }
    for (int i=sqrtd_st(ir,n); i<=r; ++i) {
        ans=f(ans,a[i]);
    }

    for (int i=il+1; i<=ir-1; ++i) {
        ans=f(ans,s[i]);
    }

    return ans;
}

// sqrt decomp point update a[i]=x, O(sqrt(n))
void sqrtd_up(ll *a, int n, int i, ll x, vec<ll> &s, const function<ll(ll,ll)> &f) {
    a[i]=x;
    sqrtd_upd_seg(a,n,sqrtd_seg(i,n),s,f);
}

/////////////////////////////////////////////////////////////////////////////
///////////////////////////// SQRT DECOMP LAZY //////////////////////////////
/////////////////////////////////////////////////////////////////////////////

// update segment j according to a w/ lazy prop, O(sqrt(n))
void sqrtd_upd_seg(ll *a, int n, int j, vec<ll> &s, vec<ll> &lazy, const function<ll(ll,ll)> &f) {
    int rt=sqrtfl(n);
    int st=sqrtd_st(j,n);
    s[j]=a[st];
    for (int k=st+1; k<st+rt; ++k) {
        s[j]=f(s[j],f(a[k],lazy[j]));
    }
}

// sqrt decomp range query f(a[l,r]) w/ lazy prop, O(sqrt(n))
ll sqrtd_query(ll *a, int n, int l, int r, const vec<ll> &s, const vec<ll> &lazy, const function<ll(ll,ll)> &f) {
    int il=sqrtd_seg(l,n), ir=sqrtd_seg(r,n);

    ll ans=a[l];
    if (il==ir) {
        for (int i=l+1; i<=r; ++i) {
            ans=f(ans,f(a[i],lazy[il]));
        }

        return ans;
    }

    for (int i=l+1; i<=sqrtd_st(il+1,n)-1; ++i) {
        ans=f(ans,f(a[i],lazy[il]));
    }
    for (int i=sqrtd_st(ir,n); i<=r; ++i) {
        ans=f(ans,f(a[i],lazy[ir]));
    }

    for (int i=il+1; i<=ir-1; ++i) {
        ans=f(ans,s[i]);
    }

    return ans;
}

// sqrt decomp point query w/ lazy prop, O(1)
ll sqrtd_query(ll *a, int n, int i, const vec<ll> &lazy, const function<ll(ll,ll)> &f) {
    return f(a[i],lazy[sqrtd_seg(i,n)]);
}

// sqrt decomp point update a[i]=x w/ lazy prop, O(sqrt(n))
void sqrtd_up(ll *a, int n, int i, ll x, vec<ll> &s, vec<ll> &lazy, const function<ll(ll,ll)> &f, const function<ll(ll,ll)> &invf) {
    a[i]=invf(x,lazy[sqrtd_seg(i,n)]);
    sqrtd_upd_seg(a,n,sqrtd_seg(i,n),s,lazy,f);
}

// sqrt decomp range update a[l..r]=f(a[l..r],x) w/ lazy prop, O(sqrt(n))
void sqrtd_up(ll *a, int n, int l, int r, ll x, vec<ll> &s, vec<ll> &lazy, const function<ll(ll,ll)> &f, const function<ll(ll,ll,int)> &repf) {
    int il=sqrtd_seg(l,n), ir=sqrtd_seg(r,n);

    if (il==ir) {
        for (int i=l; i<=r; ++i) {
            a[i]=f(a[i],x);
        }
        sqrtd_upd_seg(a,n,il,s,lazy,f);
        return;
    }

    for (int i=l; i<=sqrtd_st(il+1,n)-1; ++i) {
        a[i]=f(a[i],x);
    }
    s[il]=repf(s[il],x,sqrtd_st(il+1,n)-1-l+1);
    for (int i=sqrtd_st(ir,n); i<=r; ++i) {
        a[i]=f(a[i],x);
    }
    s[ir]=repf(s[ir],x,r-sqrtd_st(ir,n)+1);

    int rt=sqrtfl(n);
    for (int i=il+1; i<=ir-1; ++i) {
        lazy[i]=f(lazy[i],x);
        s[i]=repf(s[i],x,rt);
    }
}

/* 
 Codechef problem
 
 c++ implementation
 Question - https://www.codechef.com/COOK76/problems/SETELE
 Solution - using Kruskal's + DSU concept
 
 Date- 26/11/16
 
 */

#include<bits/stdc++.h>
using namespace std;
#define fastScan ios_base::sync_with_stdio(0); cin.tie(NULL);
#define fill(a,x) memset(a,x,sizeof(a))
#define ll long long int
#define MAX 211
#define M 1000000007
#define all(c) (c).begin(), (c).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define mb make_pair
#define pb push_back
#define sc(x) scanf("%d",&x)
#define scc(x1,x2) scanf("%d%d",&x1,&x2)
#define sccc(x1,x2,x3) scanf("%d%d%d",&x1,&x2,&x3)
#define pr(x) printf("%d ",x)
#define rep(i,n) for(ll i=0;i<n;i++)
#define repp(i,a,b) for(ll i=a;i<=b;i++)
#define reff(i,a,b) for(ll i=a;i>=b;i--)
#define IT(x) for(__typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define F first
#define S second
#define co cout<<"vai"<<endl;
#define coo cout<<"yt"<<endl;
#define dbg(a)         std::cerr<<#a<<"="<<(a)<<"\n"
#define dbg1(a,b)       std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"
#define dbg2(a,b,c)     std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
#define dbg3(a,b,c,d)   std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"
#define dbg4(a,b,c,d,e) std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<"\n"
const int INF = 2034567891;
const ll INF64 = 1234567890123456789ll;
int dx[] = { 1,-1,0,0,1,-1,-1,1 };
int dy[] = { 0,0,1,-1,-1,-1,1,1 };
ll power(ll x,ll y)
{
    ll ans=1;
    while(y>0){
        if(y&1)
            ans=(ans*x)%M;
        x=(x*x)%M;
        y/=2;
    }
    return ans;
}

ll par[100010],sz[100010];
ll n;
char C1,C2;
ll find_par(ll x)
{
    if(x!=par[x])
	par[x]=find_par(par[x]);
    return par[x];
}

void merge(ll u,ll v)
{
    ll pu=find_par(u);
    ll pv=find_par(v);
    if(pu==pv)return;
    par[pu]=pv;
    sz[pv]+=sz[pu];
}
void init()
{
	repp(i,1,100005)
	{
	  par[i]=i;
	  sz[i]=1;
    }
}
pair<ll,pll> edges[100005];
int main()
{
	ll a,b,c;
   cin>>n;
   init();
   ll sum=0;
   rep(i,n-1)
   {
   	  cin>>a>>b>>c;
   	  edges[i]=mb(c,mb(a,b));
   	  sum+=c;
   }
   sort(edges,edges+n-1);
   ll num=0, deno=0;
   rep(i,n-1)
   {
      num+=sz[find_par(edges[i].S.F)]*sz[find_par(edges[i].S.S)]*edges[i].F;
   	  deno+=sz[find_par(edges[i].S.F)]*sz[find_par(edges[i].S.S)];
   	  merge(edges[i].S.F, edges[i].S.S);
   }
   double ans=double(sum-(double)num/deno);
   printf("%0.3lf\n",ans);
}

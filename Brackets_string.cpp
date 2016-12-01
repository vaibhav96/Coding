/* 
 c++ implementation
 Question - http://codeforces.com/contest/629/problem/C
 Solution - dp , string
 
 Date - 12/1/16
 
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
ll dp[2005][2005];
int main()
{
	ll n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	dp[0][0]=1;
	repp(i,1,n-m)
	{
		dp[i][0]=dp[i-1][1];
		repp(j,1,i)
		{
			dp[i][j]=dp[i-1][j+1]+dp[i-1][j-1];
			dp[i][j]%=M;
		}
	}
	ll minS=INF,cnt=0;
	rep(i,m)
	{
		if(s[i]=='(') cnt++;
		else cnt--;
		minS=min(cnt,minS);
	}
	ll ans=0;
	repp(i,0,n-m)
	{
		repp(j,0,i)
		{
			if(j>=-minS)
			{
				if(j+cnt<=n-m)
				{
					ans+=dp[i][j]*dp[n-m-i][j+cnt];
					ans%=M;
				}
			}
		}
	}
	cout<<ans;
}

//https://repl.it/@2019csb1084/SteelblueMiniatureTransfer#main.cpp
#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
#define het ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define lld long long int
#define ll long double
#define fl float
#define f first
#define s second
#define p(x) cout<<x<<endl;
#define all(x) x.begin(),x.end()
#define dll(x) x.begin(),x.end(),greater<lld>()
#define vect(x,n) vector<lld>x(n,0);
#define vector(x) vector<lld>x;
#define matrix(x,n,m) vector<vector<lld>>x(n,vector<lld>(m,0));
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define lb lower_bound
#define ub upper_bound
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define ppb(x) pop_back(x)
#define ppf(x) pop_front(x)
#define mkp(x,y) make_pair(x,y)
#define rep(i,a,b) for(i=a;i<b;i++) 
void print(vector<lld>&v);
lld pow(lld x, lld y);
lld pow(lld x, lld y, lld p);
lld sumofdigits(lld n);
void swap(lld &x, lld &y);
void swap(lld &x, lld&y, lld&z);
void leftswap(lld &x,lld &y,lld&z);
void swap(vector<lld>&v);
void leftswap(vector<lld>&v);
const lld mod=1e9+7;
unordered_set<lld>st,ts;
multimap<lld,lld>mm;
map<lld,bool>visited;
class Graph{
    lld vertices;
    list<lld>*adj;
    public:
    
    Graph(lld vertices){
        this->vertices=vertices;
        adj= new list<lld>[vertices];
    }
    void addedge(lld v,lld w){
        adj[v].push_back(w);
        visited[v]=false;
        visited[w]=false;

    }
    void dfs(lld v){
        visited[v]=true;
        p(v);
        for(auto it=adj[v].begin();it!=adj[v].end();it++){
            if(visited[*it]==false){
                dfs(*it);
            }
        }
    }
    
    void bfs(lld v){
        list<lld>queue;
        queue.push_back(v);
        visited[v]=true;
        while(queue.size()!=0){
            v=queue.front();
            p(v);
            queue.pop_front();
            for(auto it=adj[v].begin();it!=adj[v].end();it++){
                if(visited[*it]==false){
                    visited[*it]=true;
                    queue.push_back(*it);
                }
            }
        }
    }
};
// lld *visited = new lld[5];
// for(lld i=0;i<5;i++){
//     visited[i]=0;
//     ps(visited[i]);
// }
int main(){
    het;
    Graph g(60);
    g.addedge(4,55);
    g.addedge(55,13);
    g.addedge(4,28);
    g.addedge(4,13);
    g.addedge(13,50);

    g.dfs(4);

    p("Now the bfs:");
    
    g.addedge(4,55);
    g.addedge(55,13);
    g.addedge(4,28);
    g.addedge(4,13);
    g.addedge(13,50);
    g.bfs(4);

    
}
void print(vector<lld>&v){
    for(lld i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    p("");
}
lld pow(lld x, lld y) { 
    lld res = 1; 
    while (y > 0) { 
        if (y & 1) 
        res = ((res) * (x)); 
        y = y >> 1; 
        x = ((x) * (x)); 
    }
    return res; 
}
lld pow(lld x, lld y, lld p) 
{ 
    lld res = 1; // Initialize result 
  
    // Update x if it is more than or 
    // equal to p 
    x = x % p;  
  
    while (y > 0) { 
        // If y is odd, multiply x with the result 
        if (y & 1) 
            res = (res * x) % p; 
  
        // y must be even now 
        y = y >> 1; // y = y/2 
        x = (x * x) % p; 
    } 
    return res; 
} 
void swap(lld &x, lld &y){
    lld temp = x; 
    x = y; 
    y = temp;
}
void swap(lld &x, lld&y, lld&z){
    lld temp=z;
    z=y;
    y=x;
    x=temp;
}
void leftswap(lld &x,lld &y,lld&z){
    lld temp=x;
    x=y;
    y=z;
    z=temp;
}
void swap(vector<lld>&v){
    // the vector was passed by reference and hence this is fast
    // this will right swap the vector
    lld n=v.size();
    lld temp=v[n-1];
    for(lld i=n-1;i>0;i--){
        v[i]=v[i-1];
    }
    v[0]=temp;
}
void leftswap(vector<lld>&v){
    lld temp=v[0];
    lld i;
    for(i=0;i<v.size()-1;i++){
        v[i]=v[i+1];
    }
    v[i]=temp;
}
lld sumofdigits(lld n){
    lld sum=0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}

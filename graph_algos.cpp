void dft(int x,vector<bool> rec){           // to find a cycle

    if(!rec[x]){
        rec[x]=1;
        if(!visited[x])
            for(auto i:adj[x])
                dft(i,rec);
    }
    else
        cycle=true;

    rec[x]=false;
    visited[x]=true;
}

//simple dft
void dft(int v,int p){
    if(!visited[v]){
        visited[v]=1;
        for(auto i:graph[v])
            if(i != p)
                dft(i,v);
    }
}


int dijsktra(int a,int b){
    if(a==b)
        return 0;
    PQ<node> pq;
    pq.push((node){a,0});
    int n,at;
    while(!pq.empty()){
        n=pq.top().n,at=pq.top().at;
        //cerr<<n<<"\n";
        pq.pop();
        if(visited[n])
            continue;
        visited[n]=1;
        if(n==b)
            break;
        else
            for(auto i:graph[n])
                if(!visited[i.first])
                    pq.push((node){i.first,at+i.second});
    }
    if(n==b)
        return at;
    else
        return -1;
}


void prims(){
    PQ<node> pq;
    pq.push({1,0});
    while(!pq.empty()){
        int n=pq.top().n,at=pq.top().at;
        pq.pop();
        if(visited[n])
            continue;
        //cerr<<"n="<<n<<" at="<<at<<"\n";
        visited[n]=1;
        cost+=p*at;
        for(auto i:graph[n])
            pq.push({i.fi,i.se});

    }
}

// Trie
int t[MAX][26];
void add(const string &s){
    ll id=0;
    for(auto i:s){
        if(t[id][i-'a']==-1)
            t[id][i-'a']=nxt++;
        id=t[id][i-'a'];
    }
}


// full code for tarjan's algorithm for finding SCC
// foundat: analogous to time at which the vertex was discovered
// disc: will contain the foundat value of ith vertex(as in input graph)
// low: will contain the lowest vertex(foundat value) reachable from ith vertex(as in input graph)
// onstack: whether the vertex is on the stack st or not
int n,m,foundat=1;
vvi graph,scc;
vi disc,low; // init disc to -1
bool onstack[MAX]; //init to 0

void tarjan(int u){
    static stack<int> st;

    disc[u]=low[u]=foundat++;
    st.push(u);
    onstack[u]=true;
    for(auto i:graph[u]){
        if(disc[i]==-1){
            tarjan(i);
            low[u]=min(low[u],low[i]);
        }
        else if(onstack[i])
            low[u]=min(low[u],disc[i]);
    }
    if(disc[u]==low[u]){
        vi scctem;
        while(1){
            int v=st.top();
            st.pop();onstack[v]=false;
            scctem.pb(v);
            if(u==v)
                break;
        }
        scc.pb(scctem);
    }
}
int main()
{
    // n= vertices of graph
    // init
    set0(onstack);
    graph.clear();graph.resize(n+1);
    disc.clear();disc.resize(n+1,-1);
    low.clear();low.resize(n+1);
    //
    // input graph here
    FOR(i,n)
        if(disc[i+1]==-1)
            tarjan(i+1);

}
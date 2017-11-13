#include <vector>

vector<int> g[N];
int r[N], l[N], n, m, e, a, b;

// generate g;

bool dfs(int v)
{
	if(vis[v]) return false;
	vis[v] = true;
	for(int u=0; u<g[v].size(); ++u)
	{
		if(!r[g[v][u]])
		{
			l[v]=g[v][u];
			r[g[v][u]]=v;
			return true;
		}
	}
	for(int u=0; u<g[v].size(); ++u)
	{
		if(dfs(r[g[v][u]]))
		{
			l[v]=g[v][u];
			r[g[v][u]]=v;
			return true;
		}
	}
	return false;
}

void hopcroft_karp()
{
	bool change = true;
	while(change)
	{
		change = false;
		fill(vis, vis+n+1, false);
		for(int i=1; i<=n; ++i)
			if(!l[i])
				change|= dfs(i);
	}
}
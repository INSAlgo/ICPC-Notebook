//Dijkstra Algorithm
int t,n,m,s,e;
vector<ii> edges[N];//pair<NodeEnd,dist>
int distances[N]; // =INF=0x3f3f3f3f 
int parent[N]; // =-1 

int Dijkstra() 
{        
	vector<ii> :: iterator it;        
	priority_queue< ii, vector<ii>, greater<ii> > pq;        
	distances[s]=0;        
	pq.push(ii(distances[s],s));        
	while(!pq.empty())        
	{                
		ii p = pq.top();                
		pq.pop();                
		int d=p.first;                
		int a=p.second;                
		for(it=edges[a].begin();it!=edges[a].end();++it) 
		{                        
			if(distances[it->first]>distances[a]+it->second) 
			{
			    distances[it->first]=distances[a]+it->second; 
			    parent[it->first]=a;
			    pq.push(ii(distances[it->first],it->first));                        
			}                
		}        
	}        
	return distances[e]; 
}
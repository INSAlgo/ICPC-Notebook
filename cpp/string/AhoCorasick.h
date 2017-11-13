
/*
Implementation - Benoit Chabod
------------------------------
Aho Corasick algorithm 
------------------------------
*/

struct node 
{    
	int f;    
	map<char, int> g;    
	vector<short> out;    
	node(int fail = -1): f(fail) {} 
}; 

vector<node> nodes;

void add_str(const string & s, int num) 
{    
	int cur = 0;    
	int n = s.size();    
	for(int i = 0; i < n; i++) 
	{        
		auto it = nodes[cur].g.find(s[i]);        
		if(it == nodes[cur].g.end()) 
		{            
			nodes[cur].g[s[i]] = nodes.size();            
			cur = nodes.size();            
			nodes.push_back(node());        
		} 
		else 
		{            
			cur = it->second;        
		}    
	}    
	nodes[cur].out.push_back(num); 
}

void init_fail() 
{    
	int cur = 0;    
	queue<int> q;    
	q.push(cur);
    
    while( !q.empty() ) 
    {        
    	cur = q.front();        
    	map<char, int>::iterator it;        
    	for(it = nodes[cur].g.begin(); it != nodes[cur].g.end(); it++) 
    	{            
    		int child = it->second;            
    		int pfail = nodes[cur].f;            
    		char ch = it->first;            
    		map<char, int>::iterator f;            
    		while( pfail != -1 && ((f = nodes[pfail].g.find(ch)) == nodes[pfail].g.end()) ) 
    		{                
    			pfail = nodes[pfail].f;            
    		}            
    		nodes[child].f = (pfail == -1)? 0 : f->second;            
    		pfail = nodes[child].f;            
    		nodes[child].out.insert(nodes[child].out.end(),nodes[pfail].out.begin(),nodes[pfail].out.end());    
    		q.push(child);        
    	}        
    	q.pop();    
    } 
}

// Usage 
void usage()
{
	nodes.push_back(node()); 
	for [each word] add_str(word,i)    
		init_fail(); 
	for [each letter] 
	{    
		map<char, int>::iterator f;    
		while( cur != -1 && ((f = nodes[cur].g.find(letter)) == nodes[cur].g.end()) )        
			cur = nodes[cur].f;    
		if( cur == -1 ) 
		{        
			cur = 0;         
			continue; 
    	}    
    	cur = f->second;    
    	for(auto v : nodes[cur].out) 
    	{ 
    		// Word v was found    
    	} 
    }
}

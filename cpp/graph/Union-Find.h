struct Edge // MST 
{    
	int a,b,d;    
	bool operator < (const Edge &E) const{ 
	return this->d <E.d;    
	} 
};
int ranks[M]; int c[N]; 

int Find(int x)
{    
	int y=x;    
	while(y!=c[y])        
		y=c[y];    
	while(x!=c[x])    
	{        
		int aux=c[x];        
		c[x]=y;        
		x=aux;    
	}    
	return y; 
}

void Union(int x,int y) 
{    
	if(ranks[x]>ranks[y])        
		c[x]=y;    
	else        
		c[y]=x;    
	if(ranks[x]==ranks[y])        
		ranks[y]++; 
}

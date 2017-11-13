bool compare(PT a,PT b){    return a.y<b.y || (a.y==b.y && a.x<b.x); }
double cross(PT o,PT a, PT b)
{
	return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
} 

vector<PT> ConvexHull(vector<PT> p) {    int n=p.size();    int k=0;
    vector<PT> h(2*n);
    sort(p.begin(),p.end(),compare);
	//build lower hull    
	for(int i=0;i<n;++i)    
	{        
		while(k>=2 && cross(h[k-2],h[k-1],p[i])<=0) k--;        
		h[k++]=p[i];    
	}
	//build top hull    
	for(int i=n-2,t=k+1;i>=0;--i)    
	{        
		while(k>=t && cross(h[k-2],h[k-1],p[i])<=0) k--;        
		h[k++]=p[i];    
	}    
	h.resize(k);    
	return h; 
}
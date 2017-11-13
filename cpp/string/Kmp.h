/*
---------------
KMP/Pi function 
Note : cin>>(s+1) (the operations in the pi-function start at 1)
---------------
*/
void preKmp() 
{    
	int k;    
	k=kmpNext[1]=0;    
	for(int i=2;i<=n;++i)    
	{        
		while(k && p[k+1]!=p[i]) k=kmpNext[k];        
		if(p[k+1]==p[i])            
			k++;        
		kmpNext[i]=k;    
	} 
} 

void KMP() 
{    
	preKmp();    
	int k=0;    
    
	for(int i=1;i<=m;++i)    
	{        
		while(k && p[k+1]!=s[i]) 
			k=kmpNext[k];        
		if(p[k+1]==s[i])            
			k++;        
		if(k==n)        
		{            
			// here we have a match         
			k=kmpNext[k];        
		}    
	} 
}
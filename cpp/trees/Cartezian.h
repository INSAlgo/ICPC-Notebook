
struct Tr
{    
	Tr *l,*r;    
	int key,pr,cnt,val,rev;    
	long long sum;    
	Tr(int new_key,int new_pr,int new_val)    
	{        
		rev=0;        
		key=new_key;        
		cnt=1;        
		l=r=NULL;        
		pr=new_pr;        
		val=new_val;        
		sum=new_val;    
	} 
};


#define T Tr*
T R=NULL; 

int cnt(T t) 
{    
	if(!t) return 0;    
	return t->cnt; 
}

void upd_cnt(T &t) 
{    
	if(t) t->cnt=cnt(t->l)+cnt(t->r)+1; 
}
long long sum(T t) 
{    
	if(!t) return 0;    
	return t->sum; 
}
void upd_sum(T &t) 
{ 
    if(t) t->sum=sum(t->l)+sum(t->r)+t->val; 
}
void push(T &t) 
{    
	if(t && t->rev)    
	{        
		t->rev=0;     	
		swap(t->l,t->r); 
		upd_sum(t); 
		if(t->l) t->l->rev^=1; 
		if(t->r) t->r->rev^=1; 
	}
}


void split(T t,T &l,T &r,int key,int add) 
{    
	if(!t)        
		return void(l=r=NULL);    
	push(t);    
	upd_cnt(t);    
	int current_key=add+cnt(t->l)+1;    
	if(key<=current_key)        
		split(t->l,l,t->l,key,add),r=t;
    else        
		split(t->r,t->r,r,key,current_key),l=t;    
	upd_cnt(t);    
	upd_sum(t); 
}


void merge(T &t,T l,T r) 
{    
	push(l);    
	push(r);    
	if(!l || !r)        
		t=l?l:r;    
	else if(l->pr>r->pr)      
		merge(l->r,l->r,r), t=l;  
	else    
		merge(r->l,l,r->l), t=r; 
	upd_cnt(t);  
	upd_sum(t); 
}


void insert(T &t,T it,int add) 
{    
	push(t);    
	if(!t)    
	{        
		t=it;        
		upd_cnt(t);        
		return;    
	}    
	upd_sum(t);    
	if(it->pr > t->pr)   
		split(t,it->l,it->r,it->key,add),t=it; 
	else if(it->key>add+cnt(t->l)+1)   
		insert(t->r,it,add+cnt(t->l)+1);  
	else  
		insert(t->l,it,add); 
	upd_sum(t); 
	upd_cnt(t); 
}

void print(T t) 
{    
	if(!t) return;    
	print(t->l);    
	cout<<t->val<<" ";    
	print(t->r); 
}

void reverse(int left,int right) 
{    
	Tr *t1,*t2,*t3;    
	t1=t2=t3=NULL;    
	split(R,t1,t2,left,0);    
	split(t2,t2,t3,right-left+2,0);    
	t2->rev^=1;    
	merge(R,t1,t2);    
	merge(R,R,t3); 
}

void get_sum(int left,int right) 
{    
	Tr *t1,*t2,*t3;    
	t1=t2=t3=NULL;   
	split(R,t1,t2,left,0);    
	split(t2,t2,t3,right-left+2,0);    
	cout<<t2->sum<<"\n";    
	merge(R,t1,t2);    
	merge(R,R,t3);
}


int n,m, q,a,b; 
void example() 
{    
	ios_base::sync_with_stdio(0);    
	cin.tie(0);    
	freopen("reverse.in","r",stdin);    
	freopen("reverse.out","w",stdout);    
	srand(time(0));    
	cin>>n>>m;    
	for(int i=1;i<=n;++i)    
	{        
		cin>>a;        
		T it=new Tr(i,rand()+1,a);        
		insert(R,it,0);    
	}    
	for(int i=0;i<m;++i)    
	{        
		cin>>q>>a>>b;        
		if(q) reverse(a,b);        
		else  get_sum(a,b);    
	}    
	return 0; 
}




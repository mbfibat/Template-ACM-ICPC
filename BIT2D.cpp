struct Template_BIT2D
{
	int n;
	vector<int> Tree[100011], node[100011];

	void init(int _n)
	{
		n = _n;
		return;
	}

	void update(bool f,int x,int yy,int val)
	{
		if (!f)
			for (;x<=n;x+=x&(-x))
				node[x].push_back(yy);
		else
			for (;x<=n;x+=x&(-x))
				for (int y=lower_bound(node[x].begin(),node[x].end(),yy)-node[x].begin();y<node[x].size();y+=y&(-y))
					Tree[x][y] += val;							
	}

	int query(bool f,int x,int yy)
	{
		int ans = 0;
		if (!f)
			for (;x>0;x-=x&(-x))
				node[x].push_back(yy);
		else
			for(;x>0;x-=x&(-x))
				for (int y=lower_bound(node[x].begin(),node[x].end(),yy)-node[x].begin();y>0;y-=y&(-y))
					ans += Tree[x][y];
		return ans;
	}
	
	void normalize()
	{
		for (int i=1;i<=n;i++)
		{
			node[i].push_back(-1e18);
			sort(node[i].begin(),node[i].end());
			vector<int>::iterator it = unique(node[i].begin(),node[i].end());
			node[i].resize(it - node[i].begin());
			Tree[i].resize(node[i].size() + 5);
		}
	}
}BIT2D;

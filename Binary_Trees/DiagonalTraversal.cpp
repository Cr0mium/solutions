class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    
    
    vector <int> func(Node* root)
    {
    	// Code here
        vector<int> ans;
        if(!root) return ans;
        map<int,vector<int>> m;
        
        queue<tuple<Node*,int,int>> q;
 
        q.push({root,0,0});
        while(q.size())
        {
			auto node=get<0>(q.front());
			int x= get<1>(q.front());
			int y= get<2>(q.front());
			q.pop();
			m[y-x].push_back(node->data);
			if(node->left)
				q.push({node->left,x-1,y+1});
			if(node->right)
				q.push({node->right,x+1,y+1});
		}
        
        for(auto it:m)
		{
			for(auto x:it.second)M
			{
				ans.push_back(x);
			}
		}
        
        return ans;
    }
};

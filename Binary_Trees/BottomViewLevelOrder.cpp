class Solution {
  public:
  
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        if(!root) return ans;
        q.push({root,0});
        while(q.size())
        {
            auto x=q.front();
            m[x.second]=x.first->data;
            
            if(x.first->left)
            q.push({x.first->left,x.second-1}),l=min(l,x.second-1);
            
            if(x.first->right)
            q.push({x.first->right,x.second+1}),r=max(r,x.second+1);
            q.pop();
        }
        
        for(int i=l;i<=r;++i)
            ans.push_back(m[i]);
        return ans;
    }
    private:
    queue<pair<Node*,int>> q;
    unordered_map<int,int> m;
    int l=0,r=0;
};

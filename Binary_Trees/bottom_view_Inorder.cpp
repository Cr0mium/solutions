class Solution {
  public:
  
    void recc(Node *node,int y,int x)
    {
        if(!node) return;
        if(node->left)
            recc(node->left,y+1,x-1);
        
        if(y>=high[x])
        {
            m[x]=node->data;
            high[x]=y;
        }
        
        if(node->right)
            recc(node->right,y+1,x+1);
        
    }
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        if(!root) return ans;
        recc(root,0,0);
        for(auto it:m) 
        ans.push_back(it.second);
        return ans;
    }
    private:
    map<int,int> m,high;
};

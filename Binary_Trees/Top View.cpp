class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        queue<pair<Node*,int>> dq;
        vector<int> ans;
        map<int,int> m;
        if(!root) return ans;
        
        dq.push({root,0});
        while(dq.size())
        {
            Node *cur= dq.front().first;
            int axis= dq.front().second;
            dq.pop();
            
            if(m.find(axis)==m.end())
            {
                m[axis]=cur->data;
            }
            if(cur->left)
                dq.push({cur->left,axis-1});
            if(cur->right)
                dq.push({cur->right,axis+1});
        }
        for(auto it:m)
        {
           ans.push_back(it.second);
        }
        return ans;
    }

};

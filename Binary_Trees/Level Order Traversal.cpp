class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    
    vector<int> levelOrder(Node* node)
    {
      //Your code here
        vector<int> ans;
        queue<Node*> nodes;
        if(node) nodes.push(node);
        while(nodes.size())
        {
            
            ans.push_back(nodes.front()->data);
            
            if(nodes.front()->left)
            nodes.push(nodes.front()->left);
            
            if(nodes.front()->right)
            nodes.push(nodes.front()->right);
            nodes.pop();
        }
        return ans;
    }
    vector<int> reverseLevelOrder(Node *node)
    {
        // code here
        vector<int> ans;
        stack<int> s;
            queue<Node*> nodes;
            if(node) nodes.push(node);
            while(nodes.size())
            {
                
                s.push(nodes.front()->data);
                
                if(nodes.front()->right)
                nodes.push(nodes.front()->right);
                
                if(nodes.front()->left)
                nodes.push(nodes.front()->left);
                
                nodes.pop();
                
            }
            while(s.size())
            {
                ans.push_back(s.top());
                s.pop();
            }
            return ans;
    }
};



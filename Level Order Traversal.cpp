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
};

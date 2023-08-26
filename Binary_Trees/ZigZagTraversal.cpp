class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    
    
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
        vector<int> ans;
        if(!root) return ans;
        stack<Node*> node1,node2;
        node1.push(root);
        while(node1.size() || node2.size())
        {
            while(node1.size())
            {
                Node *x= node1.top();
                node1.pop();
                ans.push_back(x->data);
                if(x->left)
                    node2.push(x->left);
                if(x->right)
                    node2.push(x->right);
            }
            while(node2.size())
            {
                Node *x= node2.top();
                node2.pop();
                ans.push_back(x->data);
                if(x->right)
                    node1.push(x->right);
                if(x->left)
                    node1.push(x->left);
            }
        }
        return ans;
    }
};

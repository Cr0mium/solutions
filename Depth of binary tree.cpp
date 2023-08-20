class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(Node* node)
    {
      //Your code here
        vector<Node*> nodes;
        if(!node) return 0;
        nodes.push_back(node);
        int l=0, r=1;
        int height=0;
        while(l<r)
        {
            for(int i=l;i<r;++i)
            {
                
            if(nodes[i]->left)
                nodes.push_back(nodes[i]->left);
            
            if(nodes[i]->right)
                nodes.push_back(nodes[i]->right);
            }
            l=r;
            r=nodes.size();
            ++height;
            
        }
        return height;
    }
    
};

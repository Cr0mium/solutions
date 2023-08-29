class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int sum(Node *node)
    {
        if(!node) return 0;
        int lsum=0,rsum=0;
        if(node->left)
            lsum=sum(node->left);
        if(node->right)
            rsum=sum(node->right);
        int x= node->data;
        node->data=lsum+rsum;
        return lsum+rsum+x;
    }
    void toSumTree(Node *node)
    {
        if(!node) return;
        sum(node);
    }
};

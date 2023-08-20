class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int ans=0;
int m_height(struct Node* root)
{
    if(!root) return 0;
    int lsum=0,rsum=0;
    lsum= m_height(root->left);
    rsum= m_height(root->right);
    ans=max(ans,lsum+rsum+1);
    
    return max(lsum,rsum)+1;
}

int diameter(struct Node* root) {
    // code here
    ans=0;
    m_height(root);
    return ans;
    
}
};

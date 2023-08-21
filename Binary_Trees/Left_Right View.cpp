class Solution
{
    public:
    void recc(Node *root,vector<int> &ans,int mh)
    {
        if(!root) return;
        if(mh>maxheight) 
        {
            ans.push_back(root->data);
            maxheight=mh;
        }
        
        recc(root->right,ans,mh+1);
        recc(root->left,ans,mh+1);
    }
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int> ans;
       if(!root) return ans;
       maxheight=0;
       recc(root,ans,1);
       return ans;
    }
    private:
    int maxheight=0;

};

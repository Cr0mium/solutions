int maxheight=0;
//perform inorder traversal
void recc(Node *root,vector<int> &ans,int mh)
{
    if(!root) return;
  //anytime new max_height is found, update it and store the value in array
    if(mh>maxheight) 
    {
        ans.push_back(root->data);
        maxheight=mh;
    }
    recc(root->left,ans,mh+1);
    recc(root->right,ans,mh+1);
}

vector<int> leftView(Node *root)
{
   // Your code here
    maxheight=0;
    vector<int> ans;
    if(!root) return ans;
    recc(root,ans,1);
    return ans;
}

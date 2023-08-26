/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        unordered_map<Node*,int> axis;
        queue<Node*> nodes;
        deque<int> dq;
        vector<int> ans;
        int l_max=0;
        int r_max=0;
        
        if(!root) return ans;
        
        nodes.push(root);
        axis[root]=0;
        dq.push_back(root->data);
        while(nodes.size())
        {
            Node *cur=nodes.front();
            nodes.pop();
            
            if(cur->left)
            {
                nodes.push(cur->left);
                axis[cur->left]=axis[cur]-1;
                if(axis[cur->left]<l_max)
                    dq.push_front(cur->left->data), --l_max;
            }
            if(cur->right)
            {
                nodes.push(cur->right);
                axis[cur->right]=axis[cur]+1;
                if(axis[cur->right]>r_max)
                    dq.push_back(cur->right->data), ++r_max;
            }
        }
        while(dq.size())
        {
            ans.push_back(dq.front()),dq.pop_front();
        }
        return ans;
    }

};

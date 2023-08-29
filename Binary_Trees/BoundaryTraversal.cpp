class Solution {
    
private:
    vector<int> ans;
    stack<int> s;
    int mx;
    
public:
    void leftbound(Node* node)
    {
        if(!node) return;
        if(node->left || node->right)
            ans.push_back(node->data);
        if(node->left)
            leftbound(node->left);
        else if(node->right)
            leftbound(node->right);
    }
    void leaf(Node *node)
    {
        if(!node) return;
        if(!node->left && !node->right)
            ans.push_back(node->data);
        if(node->left)
            leaf(node->left);
        if(node->right)
            leaf(node->right);
    }
    void rightbound(Node *node)
    {
        if(!node) return;
        if(node->right)
            rightbound(node->right);
        else if(node->left)
            rightbound(node->left);
        if(node->left || node->right)
            ans.push_back(node->data);
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        ans.clear();
        if(!root) return ans;
        ans.push_back(root->data);
        if(!root->left && !root->right) return ans;
        leftbound(root->left);
        leaf(root);
        rightbound(root->right);
        while(s.size())
        {
            ans.push_back(s.top()),s.pop();
        }
        return ans;
        
    }
};

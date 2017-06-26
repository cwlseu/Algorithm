/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(!pRoot || (pRoot->left == NULL && pRoot->right == NULL)) return;
        else
        {
           TreeNode* tmp = pRoot->right;
            pRoot->right = pRoot->left;
            pRoot->left = tmp;
            Mirror(pRoot->left);
            Mirror(pRoot->right);
        }
    }
};
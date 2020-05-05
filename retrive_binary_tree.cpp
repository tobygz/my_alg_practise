vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int> > ret;
	if(root== NULL){
		return ret;
	}

	queue<TreeNode*> que;
	que.push(root);
	while(!que.empty()){
		vector<int> vec;
		int size = que.size();
		for(int i=0;i<size;i++){
			auto node = que.front();
			que.pop();
			vec.push_back(node->val);
			if(node->left){
				que.push(node->left);
			}
			if(node->right){
				que.push(node->right);
			}
		}
		ret.emplace_back( vec );
	}
	return ret;
}

void preTraverBin(TreeNode* root, vector<int>& ret){
	if(root == NULL) return;
	ret.push_back(root->val);
	preTraverBin(root->left);
	preTraverBin(root->right);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ret;
    stack<TreeNode*> st;
    if(root == NULL){
        return ret;
    }
    auto* p = root;
    while( p || !st.empty()) {
        while(p){
            st.push( p );
            ret.push_back( p->val );
            p = p->left;
        }
        p = st.top();
        st.pop();
        p = p->right;
    }
    return ret;
}

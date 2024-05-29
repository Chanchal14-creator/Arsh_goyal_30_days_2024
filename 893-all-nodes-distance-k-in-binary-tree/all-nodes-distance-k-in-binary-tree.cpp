class Solution {
public:
    int n;
    void convertBinaryTreeToUndirectedGraph(TreeNode* root, TreeNode* parent, unordered_map<TreeNode*, vector<TreeNode*>>& graph) {
        if (root == nullptr) {
            return;
        }

        if (parent) {
            n++;
            graph[root].push_back(parent);
            graph[parent].push_back(root);
        }

        convertBinaryTreeToUndirectedGraph(root->left, root, graph);
        convertBinaryTreeToUndirectedGraph(root->right, root, graph);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        if (root == nullptr || target == nullptr) {
            return result;
        }

        unordered_map<TreeNode*, vector<TreeNode*>> graph;
        convertBinaryTreeToUndirectedGraph(root, nullptr, graph);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        map<TreeNode*,int>distance;
        q.push(target);
        visited.insert(target);
        distance[target] = 0;

        // int distance = 0;

        while (!q.empty()) {
            TreeNode* root = q.front();
            q.pop();
            if(distance[root] == k){
                result.push_back(root->val);
            }
            for(TreeNode * root1 : graph[root]){
                if(visited.find(root1) == visited.end()){
                    visited.insert(root1);
                    distance[root1] = distance[root] + 1;
                    q.push(root1);
                }
            }
        }

        return result;
    }
};
class Solution {
public:
    void traverse_graph(int i, vector<bool>& visited, vector<vector<int>>& graph) {
        visited[i] = true;
        for (int j = 0; j < graph.size(); j++) {
            if (graph[i][j] == 1 && !visited[j]) {
                traverse_graph(j, visited, graph);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int node = isConnected.size();
        vector<bool> visited(node, false);
        int ans = 0;
        for (int i = 0; i < node; i++) {
            if (!visited[i]) {
                traverse_graph(i, visited, isConnected);
                ans++;
            }
        }
        return ans;
    }
};

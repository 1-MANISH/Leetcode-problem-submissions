class Solution {
public:

    int bfs(int node, vector<vector<int>>& adjList) {
        int n = adjList.size();

        vector<bool> visited(n, false);
        queue<int> q;

        q.push(node);
        visited[node] = true;

        int cnt = 1;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int adjNode : adjList[curr]) {
                if (!visited[adjNode]) {
                    visited[adjNode] = true;
                    q.push(adjNode);
                    cnt++;
                }
            }
        }

        return cnt;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();

        vector<vector<int>> adjList(n);

        // Build directed graph
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (i == j) continue;

                long long x1 = bombs[i][0];
                long long y1 = bombs[i][1];
                long long r1 = bombs[i][2];

                long long x2 = bombs[j][0];
                long long y2 = bombs[j][1];

                long long dx = x1 - x2;
                long long dy = y1 - y2;

                // Can bomb i detonate bomb j?
                if (dx * dx + dy * dy <= r1 * r1) {
                    adjList[i].push_back(j);
                }
            }
        }

        int ans = 1;

        // Try detonating each bomb
        for (int i = 0; i < n; i++) {
            ans = max(ans, bfs(i, adjList));
        }

        return ans;
    }
};
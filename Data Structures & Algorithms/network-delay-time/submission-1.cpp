class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // Create adjacency list
        unordered_map<int, vector<pair<int, int>>> adjacencyList;

        for (auto& edge : times) {
            int source = edge[0];
            int destination = edge[1];
            int weight = edge[2];

            adjacencyList[source].push_back({destination, weight});
        }

        // Min heap: {distance, node}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > minHeap;

        // Shortest distance from k to every node
        vector<int> shortestDistance(n + 1, INT_MAX);

        shortestDistance[k] = 0;
        minHeap.push({0, k});

        while (!minHeap.empty()) {

            int currentDistance = minHeap.top().first;
            int currentNode = minHeap.top().second;
            minHeap.pop();

            for (auto& neighbour : adjacencyList[currentNode]) {

                int nextNode = neighbour.first;
                int edgeWeight = neighbour.second;

                int newDistance = currentDistance + edgeWeight;

                if (newDistance < shortestDistance[nextNode]) {
                    shortestDistance[nextNode] = newDistance;
                    minHeap.push({newDistance, nextNode});
                }
            }
        }

        // Find the maximum shortest distance
        int maximumTime = 0;

        for (int node = 1; node <= n; node++) {

            if (shortestDistance[node] == INT_MAX) {
                return -1;
            }

            maximumTime = max(maximumTime, shortestDistance[node]);
        }

        return maximumTime;
    }
};
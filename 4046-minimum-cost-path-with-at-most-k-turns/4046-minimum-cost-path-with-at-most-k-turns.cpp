class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

      
        if (m == 1 && n == 1) {
            return grid[0][0];
        }

   
        vector<int> dr = {1, -1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};

        const long long INF = 1e18;

    
        vector dist(
            m,
            vector(
                n,
                vector(
                    4,
                    vector<long long>(k + 1, INF)
                )
            )
        );

  
        using State = tuple<long long, int, int, int, int>;

        priority_queue<
            State,
            vector<State>,
            greater<State>
        > pq;


        for (int dir = 0; dir < 4; dir++) {

            int nr = dr[dir];
            int nc = dc[dir];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n) {

                long long cost = grid[0][0] + grid[nr][nc];

                dist[nr][nc][dir][0] = cost;

                pq.push({cost, nr, nc, dir, 0});
            }
        }

        while (!pq.empty()) {

            auto [cost, r, c, dir, turns] = pq.top();
            pq.pop();

            if (cost != dist[r][c][dir][turns]) {
                continue;
            }

          
            if (r == m - 1 && c == n - 1) {
                return cost;
            }

            for (int newDir = 0; newDir < 4; newDir++) {

                int nr = r + dr[newDir];
                int nc = c + dc[newDir];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                    continue;
                }

             
                int newTurns = turns;

                if (newDir != dir) {
                    newTurns++;
                }

                if (newTurns > k) {
                    continue;
                }

                long long newCost = cost + grid[nr][nc];

                if (newCost < dist[nr][nc][newDir][newTurns]) {

                    dist[nr][nc][newDir][newTurns] = newCost;

                    pq.push({
                        newCost,
                        nr,
                        nc,
                        newDir,
                        newTurns
                    });
                }
            }
        }

        return -1;
    }
};
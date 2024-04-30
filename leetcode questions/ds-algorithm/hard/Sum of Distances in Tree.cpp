//question      https://leetcode.com/problems/sum-of-distances-in-tree/description/?envType=daily-question&envId=2024-04-28
//my solution:  https://leetcode.com/problems/sum-of-distances-in-tree/solutions/5091065/2-times-dfs-c/?envType=daily-question&envId=2024-04-28


class Solution {
public:
    vector<int> numOfChilds;
    vector<int> vals;
    vector<int> visited;
    unordered_map<int, vector<int>> tree;
    

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        if (!edges.size()) return vector<int>(1, 0);
        
        numOfChilds = vector<int>(n, 0);
        vals = vector<int>(n, 0);
        
        
        //generate tree
        for (vector<int> edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        


        //DFS 1: calculate for parents
        visited = vector<int>(n, 0);
        dfs1(edges[0][0]);
        

        //DFS 2: Feed childs
        visited = vector<int>(n, 0);
        int numEdges = n-1;
        dfs2(edges[0][0], numEdges);
        
        
        return vals;
    }
    void dfs1(int parentVal) {
        visited[parentVal]++;
       
        //traverse through childs
        for (int childVal : tree[parentVal]) {
            if(visited[childVal]) continue;
            dfs1(childVal);
            vals[parentVal] += vals[childVal] + numOfChilds[childVal] + 1;
            numOfChilds[parentVal] += numOfChilds[childVal] + 1;
        }
    }
    void dfs2(int parentVal, int& numEdges) {
        
        visited[parentVal]++;
        
        for (int childVal : tree[parentVal]) {
            if(visited[childVal]) continue;
            //update child
            vals[childVal] += (vals[parentVal] - (vals[childVal] + numOfChilds[childVal] + 1)) + (numEdges - numOfChilds[childVal]);

            dfs2(childVal, numEdges);
        }
    }
};

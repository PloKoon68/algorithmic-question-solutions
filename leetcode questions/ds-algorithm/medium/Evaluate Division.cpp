//https://leetcode.com/problems/evaluate-division/description/


//my solution
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<string>> graph;
        unordered_map<string, double> results;
        vector<double> queryResults;
      
      for(int i = 0; i < equations.size(); i++) {
        string numerator = equations[i][0];
        string denominator = equations[i][1];
        
        graph[numerator].push_back(denominator);
        graph[denominator].push_back(numerator);

        results[numerator + "/" + denominator] = values[i];
        results[denominator + "/" + numerator] = 1 / values[i];
      }

      for(vector<string> query: queries) {
        string numerator = query[0];
        string denominator = query[1];

        if(graph.find(numerator) == graph.end() || graph.find(denominator) == graph.end())
          queryResults.push_back(-1);
        else {
          unordered_map<string, int> visited;
          queryResults.push_back(found(numerator, denominator, 1, visited, graph, results));
        }
      }

      return queryResults;
    }

  double found(string current, string end, double val, unordered_map<string, int> visited, unordered_map<string, vector<string>> graph, unordered_map<string, double> results) {
    visited[current]++;
    if(current == end)
      return val;

    for(string next: graph[current]) {
      if(visited[next])
        continue;

      double result = found(next, end, val * results[current + "/" + next], visited, graph, results);
      if(result != -1)
        return result;
    }

    return -1;
  }
};


//similar solution but 100 in speed why?
/*
class Solution {
public:
void dfs(string start,string end,map<string,double>& mp,map<string,vector<string>>& graph,double& val,map<string,int>& visited,bool& found){
        visited[start]=1;
    
        if(found==true)
            return ;
        for(auto child:graph[start]){
            if(visited[child]!=1){
                // cout<<start<<" "<<child<<"\n";
                val*=mp[start+"->"+child];
                if(end==child){
                    // cout<<end<<" -- "<<child<<"\n";
                    found=true;
                    return ;
                }
                dfs(child,end,mp,graph,val,visited,found);
                if(found==true){
                    return ;
                }
                else{
                    val/=mp[start+"->"+child];
                }
            }
        }
       
        
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        map<string,double> mp;
        map<string,vector<string>> graph;
        for(int i=0;i<equations.size();i++){
            string u=equations[i][0];
            string v=equations[i][1];
            mp[u+"->"+v]=values[i];
            mp[v+"->"+u]=1/values[i];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(int i=0;i<queries.size();i++){
            string start=queries[i][0];
            string end=queries[i][1];
            if(graph.find(start)==graph.end()||graph.find(end)==graph.end()){
                ans.push_back(-1);
            }
            else{
                // ans.push_back(1);
                double val=1;
                map<string,int> visited;
                bool found=false;
                if(start==end){
                    found=true;
                }
                else
                dfs(start,end,mp,graph,val,visited,found);
                if(found==true)
                ans.push_back(val);
                else
                    ans.push_back(-1);
                
            }
        }
        return ans;
    }
};*/

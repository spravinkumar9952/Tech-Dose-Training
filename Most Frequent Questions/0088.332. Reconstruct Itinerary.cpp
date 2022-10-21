class Solution {

    unordered_map<string, vector<string>> graph;
    unordered_map<pair<string, string>, int> counter;
    vector<string> path;
    int totTickets = 0;
    
    bool findPath(string curr){
        
        if(path.size()==totTickets){
            return true;
        }
        
        for(string &i : graph[curr]){
            pair<string, string> edge = {curr, i};
            if(counter[edge]){
                path.push_back(i);
                counter[edge]--;
        
                if(findPath(i)){
                    return true;
                }

                counter[edge]++;
                path.pop_back();
            }
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        totTickets = tickets.size()+1;
        
        for(vector<string> &i : tickets){
            graph[i[0]].push_back(i[1]);
            counter[{i[0], i[1]}]++;
        }    
        
        for(auto &i : graph){
            sort(i.second.begin(), i.second.end());
        }
        
        path.push_back("JFK");
        findPath("JFK");
        
        return path;
    }
};
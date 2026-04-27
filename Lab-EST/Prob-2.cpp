class Solution {
public:
    vector<int> JobScheduling(vector<int>& deadline, vector<int>& profit) {
        
        int n = deadline.size();
        
        struct Job {
            int id, deadline, profit;
        };
        
        vector<Job> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({i, deadline[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end(), [](Job a, Job b) {
            return a.profit > b.profit;
        });
        
        int maxDeadline = 0;
        for (auto job : jobs) {
            maxDeadline = max(maxDeadline, job.deadline);
        }
        
        vector<int> slot(maxDeadline + 1, -1);
        
        int count = 0, totalProfit = 0;
        
        for (auto job : jobs) {
            for (int j = job.deadline; j > 0; j--) {
                if (slot[j] == -1) {
                    slot[j] = job.id;
                    count++;
                    totalProfit += job.profit;
                    break;
                }
            }
        }
        
        return {count, totalProfit};
    }
};

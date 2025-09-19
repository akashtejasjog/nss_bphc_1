class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> out_vector;
        for (auto &interval : intervals)
        {
            if (out_vector.empty())
            {
                out_vector.push_back(interval);
            }
            else if (out_vector.back()[1] < interval[0])
            {
                out_vector.push_back(interval);
            }
            else
            {
                out_vector.back()[1] = max(out_vector.back()[1], interval[1]);
            }
        }
        return out_vector;
    }
};
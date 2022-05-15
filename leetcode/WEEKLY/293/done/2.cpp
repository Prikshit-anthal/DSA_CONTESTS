class Solution
{
public:
    int maxConsecutive(int bottom, int top, vector<int> &special)
    {

        int n = special.size();
        sort(special.begin(), special.end());
        int first = special[0] - bottom;
        int last = top - special[n - 1];

        int max = -1;
        for (int i = 1; i < n; i++)
        {
            int diff = special[i] - special[i - 1] - 1;
            if (diff > max)
                max = diff;
        }

        int g = max;
        if (first > max)
            g = first;

        if (g < last)
            g = last;
        return g;
    }
};
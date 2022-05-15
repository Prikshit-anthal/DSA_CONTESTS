class Solution
{
public:
    int divisorSubstrings(int num, int k)
    {
        string s = to_string(num);
        int count = 0;
        for (int i = 0; i <= s.length() - k; i++)
        {
            int curr = stoi(sub_str(s, i, k));
            if (curr == 0)
                continue;
            if (num % curr == 0)
                count++;
        }
        return count;
    }

    string sub_str(string s, int i, int n)
    {
        string p;
        for (int j = i; j < i + n; j++)
        {
            p.push_back(s[j]);
        }
        return p;
    }
};
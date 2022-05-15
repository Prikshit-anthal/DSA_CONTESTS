class Solution
{
public:
    vector<string> removeAnagrams(vector<string> &words)
    {

        int n = words.size();
        int ana[2][26] = {0};
        int idx = 0;

        for (int i = 0; i < words[0].length(); i++)
        {
            int curr = words[0][i] - 97;
            ana[idx][curr]++;
        }

        vector<string> new_;
        new_.push_back(words[0]);

        for (int i = 1; i < n; i++)
        {
            int p = idx + 1;
            if (p == 2)
                p = 0;
            int extra[26] = {0};

            for (int j = 0; j < words[i].length(); j++)
            {
                int curr = words[i][j] - 97;
                extra[curr]++;
            }

            // check
            bool check = false;
            for (int j = 0; j < 26; j++)
            {
                if (extra[j] != ana[0][j])
                {
                    check = true;
                }
            }
            if (check)
            {
                new_.push_back(words[i]);
                for (int p = 0; p < 26; p++)
                {
                    ana[0][p] = 0;
                }
                for (int jk = 0; jk < words[i].length(); jk++)
                {

                    int curr = words[i][jk] - 97;
                    ana[0][curr]++;
                }
            }
        }
        return new_;
    }
};
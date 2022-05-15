bool comparator(vector<int> a, vector<int> b)
{
    return a[0] < b[0] ? true : false;
}

class Solution
{
public:
    int maximumWhiteTiles(vector<vector<int>> &tiles, int carpetLen)
    {

        int n = tiles.size();
        sort(tiles.begin(), tiles.end(), comparator);

        vector<int> gap;
        for (int i = 1; i < n; i++)
        {
            gap.push_back(tiles[i][0] - tiles[i - 1][1] - 1);
        }

        int max = -1;

        for (int i = 0; i < n; i++)
        {

            int len_left = carpetLen - (tiles[i][1] - tiles[i][0] + 1);
            int nakli = (tiles[i][1] - tiles[i][0] + 1);
            int asli = nakli;
            int j = i;

            if (len_left <= 0)
                return carpetLen;
            while (1 && j < n - 1)
            {
                nakli += gap[j];
                len_left -= gap[j];
                // cout<<" gap "<<j<<" "<<gap[j]<<endl;
                if (nakli >= carpetLen)
                {
                    break;
                }
                j++;
                nakli += (tiles[j][1] - tiles[j][0] + 1);
                asli += min((tiles[j][1] - tiles[j][0] + 1), len_left);
                len_left -= (tiles[j][1] - tiles[j][0] + 1);

                if (nakli >= carpetLen)
                {

                    break;
                }
            }
            // cout<<" asli "<<asli<<" itr "<<i<<endl;
            if (max < asli)
            {
                max = asli;
            }
        }
        return max;
    }
};
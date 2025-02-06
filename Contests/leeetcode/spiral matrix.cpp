class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {

        int rows = matrix.size();
        int cols = matrix[0].size();
        int total = rows * cols;
        int count = 0;

        vector<int> ans;

        int str_row = 0;
        int str_col = 0;
        int end_col = cols;
        int end_row = rows;

        if (total == 0)
            return ans;

        while (count < total)
        {
            for (int j = str_col; j < end_col; j++)
            {
                ans.push_back(matrix[str_row][j]);
                count++;
            }
            str_row++;
            if (count == total)
                break;

            for (int j = str_row; j < end_row; j++)
            {
                ans.push_back(matrix[j][end_col - 1]);
                count++;
            }
            end_col--;

            if (count == total)
                break;

            for (int j = end_col - 1; j >= str_col; j--)
            {
                ans.push_back(matrix[end_row - 1][j]);
                count++;
            }
            end_row--;
            if (count == total)
                break;

            for (int j = end_row - 1; j >= str_row; j--)
            {
                ans.push_back(matrix[j][str_col]);
                count++;
            }
            str_col++;
            if (count == total)
                break;
        }
        return ans;
    }
};
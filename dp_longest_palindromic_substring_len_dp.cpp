#include <iostream>
#include <string>
#include <vector>

using namespace std;

int findLPSLengthRecursive(string str, vector<vector<int>> dp, int left, int right)
{
    if (left > right)
        return 0;

    if (left == right)
        return 1;

    if (dp[left][right] == -1)
    {
        int c1 = 0;
        if (str[left] == str[right])
        {
            int remainLength = right - left - 1;
            if (remainLength == findLPSLengthRecursive(str, dp, left + 1, right - 1))
            {
                c1 = 2 + remainLength;
            }
        }

        int c2 = findLPSLengthRecursive(str, dp, left + 1, right);
        int c3 = findLPSLengthRecursive(str, dp, left, right - 1);

        dp[left][right] = max(c1, max(c2, c3));
    }

    return dp[left][right];
}

int findLPSLength(string str)
{
    vector<vector<int>> dp(str.length(), vector<int>(str.length(), -1));
    return findLPSLengthRecursive(str, dp, 0, str.length() - 1);
}

int main()
{
    cout << findLPSLength("abdbca") << endl;
}
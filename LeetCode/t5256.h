class Solution {
public:
    int N;
    bool dfs(int pos, int upper, int lower, int remain, vector<vector<int>>& arr) {
        if (upper < 0 || lower < 0)
            return false;
        if (pos >= N) {
            return lower == 0 && upper == 0;
        } else if (arr[0][pos] != -1) {
            return dfs(pos + 1, upper, lower, remain, arr);
        } else {
            if (upper > remain || lower > remain)
                return false;
            if (upper == remain || lower == 0) {
                arr[0][pos] = 1;
                arr[1][pos] = 0;
                if (dfs(pos + 1, upper - 1, lower, remain - 1, arr))
                    return true;
            } else if (lower == remain || upper == 0) {
                arr[0][pos] = 0;
                arr[1][pos] = 1;
                if (dfs(pos + 1, upper, lower - 1, remain - 1, arr))
                    return true;
            } else {
                arr[0][pos] = 0;
                arr[1][pos] = 1;
                if (dfs(pos + 1, upper, lower - 1, remain - 1, arr))
                    return true;
                arr[0][pos] = 1;
                arr[1][pos] = 0;
                if (dfs(pos + 1, upper - 1, lower, remain - 1, arr))
                    return true;
            }
            arr[0][pos] = arr[1][pos] = -1;
            return false;
        }
    }

    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        N = colsum.size();
        vector<vector<int>> arr(2, vector<int>(N, -1));
        int remain = N;
        for (int i = 0; i < N; ++i) {
            if (colsum[i] == 0) {
                arr[0][i] = arr[1][i] = 0;
                --remain;
            } else if (colsum[i] == 2) {
                arr[0][i] = arr[1][i] = 1;
                --upper, --lower;
                --remain;
            }
        }
//        bool res = dfs(0, upper, lower, remain, arr);
//        if (res)
//            return arr;
//        else
//            return {};
        for (int i = 0; i < N; ++i) {
            if (arr[0][i] == -1) {
                if (upper > lower) {
                    arr[0][i] = 1;
                    arr[1][i] = 0;
                    --upper;
                } else {
                    arr[0][i] = 0;
                    arr[1][i] = 1;
                    --lower;
                }
                if (upper < 0 || lower < 0)
                    return {};
            }
        }
        if (upper == 0 && lower == 0) {
            return arr;
        } else {
            return {};
        }
    }
};
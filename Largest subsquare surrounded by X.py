class Solution:
    def largestSubsquare(self, n, a):
        by_rows = [[0] * n for _ in range(n)]
        by_cols = [[0] * n for _ in range(n)]
        
        # Calculate the number of 'X' horizontally for each row
        for i in range(n):
            by_rows[i][0] = 1 if a[i][0] == 'X' else 0
            for j in range(1, n):
                if a[i][j] == 'X':
                    by_rows[i][j] = by_rows[i][j - 1] + 1
                else:
                    by_rows[i][j] = 0
        
        # Calculate the number of 'X' vertically for each column
        for j in range(n):
            by_cols[0][j] = 1 if a[0][j] == 'X' else 0
            for i in range(1, n):
                if a[i][j] == 'X':
                    by_cols[i][j] = by_cols[i - 1][j] + 1
                else:
                    by_cols[i][j] = 0
        
        res = 0
        
        # Iterate over each cell from bottom right to top left
        for i in range(n - 1, res - 1, -1):
            for j in range(n - 1, res - 1, -1):
                side = min(by_rows[i][j], by_cols[i][j])
                while side > res:
                    # Check if a subsquare of size 'side' can be formed
                    if by_rows[i - side + 1][j] >= side and by_cols[i][j - side + 1] >= side:
                        res = side
                    else:
                        side -= 1
        return res

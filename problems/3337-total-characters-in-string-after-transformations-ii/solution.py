# Link: https://leetcode.cn/problems/total-characters-in-string-after-transformations-ii/
# Level: Hard
# Date: 2025-05-14

MOD = 10**9 + 7

class Solution:
    def lengthAfterTransformations(self, s: str, t: int, nums: List[int]) -> int:
        count = [0] * 26
        for c in s:
            count[ord(c) - ord('a')] += 1
        
        # 构建转移矩阵
        M = self.build_matrix(nums)
        # 计算矩阵快速幂
        mat = self.matrix_power(M, t)
        # 计算最终向量
        res = [0] * 26
        for i in range(26):
            if count[i] == 0:
                continue
            for j in range(26):
                res[j] = (res[j] + count[i] * mat[i][j]) % MOD
        return sum(res) % MOD

    def build_matrix(self, nums):
        M = [[0] * 26 for _ in range(26)]
        for i in range(26):
            for k in range(nums[i]):
                j = (i + 1 + k) % 26
                M[i][j] += 1
        return M
    
    def matrix_power(self, mat, power):
        result = [[0] * 26 for _ in range(26)]
        for i in range(26):
            result[i][i] = 1  # 单位矩阵
        
        while power > 0:
            if power % 2 == 1:
                result = self.multiply(result, mat)
            mat = self.multiply(mat, mat)
            power //= 2
        return result
    
    def multiply(self, a, b):
        res = [[0] * 26 for _ in range(26)]
        for i in range(26):
            for k in range(26):
                if a[i][k] == 0:
                    continue
                for j in range(26):
                    res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD
        return res

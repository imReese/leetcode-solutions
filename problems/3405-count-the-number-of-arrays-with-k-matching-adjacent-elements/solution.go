// Link: https://leetcode.cn/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/
// Level: Hard
// Date: 2025-04-13

const mod int64 = 1e9 + 7

func countGoodArrays(n int, m int, k int) int {
    n64 := int64(n)
    m64 := int64(m)
    k64 := int64(k)

    quickmul := func(x, y int64) int64 {
        ret := int64(1)
        mul := x
        for y > 0 {
            if y&1 == 1 {
                ret = (ret * mul) % mod
            }
            mul = (mul * mul) % mod
            y >>= 1
        }
        return ret
    }

    comb := func(n, k int64) int64 {
        if k > n {
            return 0
        }
        if k == 0 || k == n {
            return 1
        }
        if k > n - k {
            k = n - k
        }
        ret := int64(1)
        for i := int64(1); i <= k; i++ {
            ret = ret * ((n - i + 1) % mod) % mod
            inv := quickmul(i, mod - 2)
            ret = ret * inv % mod
        }
        return ret
    }
    
    res := comb(n64 - 1, k64)
    res = res * quickmul(m64 - 1, n64 - 1 - k64) % mod
    res = res * m64 % mod
    return int(res)
}

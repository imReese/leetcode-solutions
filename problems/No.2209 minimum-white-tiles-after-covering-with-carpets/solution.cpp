// Link: https://leetcode.cn/problems/minimum-white-tiles-after-covering-with-carpets/
// Level: Hard
// Date: 2025-02-21

class Solution {
    public:
        static constexpr int INF = 0x3f3f3f3f;
        int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
            int n = floor.size();
            vector<vector<int>> d(n + 1, vector<int>(numCarpets + 1, INF));
            for (int j = 0; j <= numCarpets; ++j) {
                d[0][j] = 0;
            }
            for (int i = 1; i <= n; ++i) {
               d[i][0] = d[i - 1][0] + (floor[i - 1] == '1'); 
            }
            for (int i = 1; i <= n; ++i) {
               for (int j = 1; j <= numCarpets; ++j) {
                    d[i][j] = d[i - 1][j] + (floor[i - 1] == '1');
                    d[i][j] = min(d[i][j], d[max(0, i - carpetLen)][j - 1]);
               }
            }
            return d[n][numCarpets];
        }
};

class Solution {
    public:
        int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
            // vector<int> whiteFloor, blackFloor;
            // int whiteFloorLen = 0, blackFloorLen = 0;
            // char curColor = floor[0];
            // int curLen = 0;
            // for (int i = 0; i < floor.size(); ++i) {
            //     if (floor[i] == curColor) {
            //         curLen++;
            //     } else {
            //         if (curColor == '0') {
            //             blackFloor.push_back(curLen);
            //             blackFloorLen += curLen;
            //             curColor = '1';
            //             curLen = 1;
            //         } else if (curColor == '1') {
            //             whiteFloor.push_back(curLen);
            //             whiteFloorLen += curLen;
            //             curColor = '0';
            //             curLen = 1;
            //         }
            //     }
            //     if (i == floor.size() - 1) {
            //         if (curColor == '0') {
            //             blackFloor.push_back(curLen);
            //             blackFloorLen += curLen; 
            //         } else if (curColor == '1') {
            //             whiteFloor.push_back(curLen);
            //             whiteFloorLen += curLen;
            //         }
            //     }
            // }
            
            // int ans = whiteFloorLen;

            // return ans;
        }
};
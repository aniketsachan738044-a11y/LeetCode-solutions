class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        static bool present[1501];
        memset(present, 0, sizeof(present));
        for (int x : nums) present[x] = true;

        int vals[1501], vn = 0;
        for (int v = 1; v <= 1500; v++)
            if (present[v]) vals[vn++] = v;

        static bool pairXor[2048];
        memset(pairXor, 0, sizeof(pairXor));
        for (int i = 0; i < vn; i++)
            for (int j = 0; j < vn; j++)
                pairXor[vals[i] ^ vals[j]] = true;

        static bool tripleXor[2048];
        memset(tripleXor, 0, sizeof(tripleXor));
        for (int v = 0; v < 2048; v++) {
            if (!pairXor[v]) continue;
            for (int i = 0; i < vn; i++)
                tripleXor[v ^ vals[i]] = true;
        }

        int count = 0;
        for (int v = 0; v < 2048; v++) count += tripleXor[v];
        return count;
    }
};
class ProductOfNumbers {
    vector<int> pre;  // pre[i] = product of the first i numbers since the last zero
public:
    ProductOfNumbers() {
        pre = {1};
    }

    void add(int num) {
        if (num == 0) {
            pre = {1};              // a zero wipes out all earlier products
        } else {
            pre.push_back(pre.back() * num);
        }
    }

    int getProduct(int k) {
        int n = pre.size();
        if (k >= n) return 0;       // window includes the last zero
        return pre.back() / pre[n - 1 - k];
    }
};

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) return false;
        int sum = 0;
        get_devisors(num, sum);
        // printf("%d\n", sum);
        return sum - num == num;
    }

private:
    void get_devisors(int num, int& sum) {
        for (int i = sqrt(num); i >= 1; --i) {
            if (num % i != 0) continue;
            sum += i;
            if (i * i != num)
                sum += num / i;
        }
    }
};
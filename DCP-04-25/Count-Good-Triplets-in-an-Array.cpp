class FenwickTree {
private:
    vector<int> tree;
public:
    FenwickTree(int size) : tree(size + 2, 0) {}

    void update(int index, int delta) {
        index++;
        while (index < tree.size()) {
            tree[index] += delta;
            index += index & -index;
        }
    }

    int query(int index) {
        index++;
        int res = 0;
        while (index > 0) {
            res += tree[index];
            index -= index & -index;
        }
        return res;
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos2(n);
        for (int i = 0; i < n; ++i) {
            pos2[nums2[i]] = i;
        }
        vector<int> transformed(n);
        for (int i = 0; i < n; ++i) {
            transformed[i] = pos2[nums1[i]];
        }
        FenwickTree leftTree(n);
        vector<int> leftLess(n);
        for (int i = 0; i < n; ++i) {
            leftLess[i] = leftTree.query(transformed[i] - 1);
            leftTree.update(transformed[i], 1);
        }
        FenwickTree rightTree(n);
        vector<int> rightGreater(n);
        for (int i = n - 1; i >= 0; --i) {
            rightGreater[i] = rightTree.query(n - 1) - rightTree.query(transformed[i]);
            rightTree.update(transformed[i], 1);
        }

        long long result = 0;
        for (int i = 0; i < n; ++i) {
            result += (long long)leftLess[i] * rightGreater[i];
        }

        return result;
    }
};

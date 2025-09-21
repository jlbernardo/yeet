#include <iostream>
#include <vector>

int main() {
    std::vector<int> nums1 = {4, 5, 6, 0, 0, 0};
    std::vector<int> nums2 = {1, 2, 3};
    int m = 3;
    int n = 3;

    for (int i = m; i < m + n; i++)
        nums1[i] = nums2[i - m];

    for (int i = 0; i < m + n; ++i) {
        if (i + 1 < m + n && nums1[i] > nums1[i + 1]) {
            int buf = nums1[i];
            nums1[i] = nums1[i + 1];
            nums1[i + 1] = buf;
            i = -1;
        }
    }
    return 0;
}
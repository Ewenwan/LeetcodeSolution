class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        bool odd = len % 2;
        if (odd) return findKth(nums1, 0, nums2, 0, len/2+1);
        else return (findKth(nums1, 0, nums2, 0, len/2) + findKth(nums1, 0, nums2, 0, len/2+1)) / 2.0;
    }
    
    int findKth(const vector<int> &nums1, int start1, const vector<int> &nums2, int start2, int k) {
        while (start1 < nums1.size() || start2 < nums2.size()) {
            if (start1 >= nums1.size()) return nums2[start2+k-1];
            if (start2 >= nums2.size()) return nums1[start1+k-1];
            if (k == 1) return nums1[start1] < nums2[start2] ? nums1[start1] : nums2[start2];
            int mid = k / 2;
            int key1 = start1 + mid > nums1.size() ? INT_MAX : nums1[start1+mid-1];
            int key2 = start2 + mid > nums2.size() ? INT_MAX : nums2[start2+mid-1];
            if (key1 < key2) start1 += mid;
            else start2 += mid;
            k -= mid;
        }
        return INT_MAX;
    }
};
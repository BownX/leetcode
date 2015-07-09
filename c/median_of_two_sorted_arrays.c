/*
There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

https://leetcode.com/problems/median-of-two-sorted-arrays/

With the help of: http://fisherlei.blogspot.hk/2012/12/leetcode-median-of-two-sorted-arrays.html
*/

#include "stdio.h"
#include "stdlib.h"

int findK(int* a, int m, int* b, int n, int k) {
	if (m <= 0) return b[k-1];
	if (n <= 0) return a[k-1];
	if (k <= 1) return a[0] < b[0] ? a[0] : b[0];
	if (b[n/2] >= a[m/2]) {
		if (m/2 + n/2 + 1 >= k) {
			return findK(a, m, b, n/2, k);
		} else {
			return findK(a + m/2 + 1, m - (m/2 + 1), b, n, k - (m/2 + 1));
		}
	} else {
		if (m/2 + n/2 + 1 >= k) {
			return findK(a, m/2, b, n, k);
		} else {
			return findK(a, m, b + n/2 + 1, n - (n/2 + 1), k - (n/2 + 1));
		}
	}
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	if ((nums1Size + nums2Size) % 2 == 0) {
		return (findK(nums1, nums1Size, nums2, nums2Size, (nums1Size + nums2Size)/2) + findK(nums1, nums1Size, nums2, nums2Size, (nums1Size + nums2Size)/2 + 1))/2.0;
	} else {
		return findK(nums1, nums1Size, nums2, nums2Size, (nums1Size + nums2Size)/2 + 1);
	}
}

int main() {
	int l1[] = {1, 2, 3};
	int l2[] = {4};
	printf("%f\n", findMedianSortedArrays(l1, 3, l2, 1));
	return 0;
}
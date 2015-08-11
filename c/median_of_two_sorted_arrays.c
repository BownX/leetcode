/*
There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

https://leetcode.com/problems/median-of-two-sorted-arrays/

=======
With the help of: http://fisherlei.blogspot.hk/2012/12/leetcode-median-of-two-sorted-arrays.html

常规解法：
两个数组merge为一个排好序的，复杂度为O(m+n)

O(log(m+n))二分搜索解法：
a[1] a[2] a[3] ... a[m/2] ... a[m-2] a[m-1] a[m]
b[1] b[2] b[3] ... b[n/2] ... b[n-2] b[n-1] b[n]
找到其中分别的中位数 a[m/2], b[n/2]
可以分成4个Section：
S1: a[1]~a[m/2]
S2: a[m/2+1]~a[m]
S3: b[1]~b[n/2]
S4: b[n/2+1]~b[n]

目标找到两个list中第k大的数
当a[m/2]<b[n/2]时:
	若 k<(m+n)/2，既目标第k大数不可能在S4中，递归在S1 S2 S3，既a[0]~a[m]和b[0]~b[n/2]中搜索k，即 findK(a, m, b, n/2, k);
	若 k>=(m+n)/2，舍弃S1，递归在 a[m/2]~a[m]和b[0]~b[n] 中搜索 k-m/2-1
当a[m/2]>b[n/2]时:
	若 k<(m+n)/2，舍弃S2，findK(a, m/2, b, n, k);
	若 k>(m+n)/2，舍弃S3，findK(a, m, b + n/2 + 1, n - (n/2 + 1), k - (n/2 + 1));
注意中间点的边界条件，和递归终止条件:
	当m<=0，既a数组空，第k大就是b数组中的第k大，既b[k-1]
	当n<=0，既b数组空，第k大就是a数组中的第k大，既a[k-1]
	k<=1时，就是看a[0]和b[0]中小的
还要注意，不能乱用加减法结合律.. 比如 m-(m/2+1) 和 m/2-1 不一定相等
*/

#include "stdio.h"
#include "stdlib.h"

int findK(int* a, int m, int* b, int n, int k) {
	if (m <= 0) return b[k - 1];
	if (n <= 0) return a[k - 1];
	if (k <= 1) return a[0] < b[0] ? a[0] : b[0];
	if (b[n / 2] >= a[m / 2]) {
		if (m / 2 + n / 2 + 1 >= k) {
			return findK(a, m, b, n / 2, k);
		} else {
			return findK(a + m / 2 + 1, m - (m / 2 + 1), b, n, k - (m / 2 + 1));
		}
	} else {
		if (m / 2 + n / 2 + 1 >= k) {
			return findK(a, m / 2, b, n, k);
		} else {
			return findK(a, m, b + n / 2 + 1, n - (n / 2 + 1), k - (n / 2 + 1));
		}
	}
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	if ((nums1Size + nums2Size) % 2 == 0) {
		return (findK(nums1, nums1Size, nums2, nums2Size, (nums1Size + nums2Size) / 2) + findK(nums1, nums1Size, nums2, nums2Size, (nums1Size + nums2Size) / 2 + 1)) / 2.0;
	} else {
		return findK(nums1, nums1Size, nums2, nums2Size, (nums1Size + nums2Size) / 2 + 1);
	}
}

int main() {
	int l1[] = {1, 2, 3};
	int l2[] = {4};
	printf("%f\n", findMedianSortedArrays(l1, 3, l2, 1));
	return 0;
}
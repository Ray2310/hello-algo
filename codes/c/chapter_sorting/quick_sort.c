/**
 * File: quick_sort.c
 * Created Time: 2023-01-18
 * Author: Reanon (793584285@qq.com)
 */

#include "../include/include.h"

/* 元素交换 */
void swap(int nums[], int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

/* 快速排序类 */
// 快速排序类-哨兵划分
int partition(int nums[], int left, int right) {
    // 以 nums[left] 作为基准数
    int i = left, j = right;
    while (i < j) {
        while (i < j && nums[j] >= nums[left]) {
            // 从右向左找首个小于基准数的元素
            j--;
        }
        while (i < j && nums[i] <= nums[left]) {
            // 从左向右找首个大于基准数的元素
            i++;
        }
        // 交换这两个元素
        swap(nums, i, j);
    }
    // 将基准数交换至两子数组的分界线
    swap(nums, i, left);
    // 返回基准数的索引
    return i;
}

// 快速排序类-快速排序
void quickSort(int nums[], int left, int right) {
    // 子数组长度为 1 时终止递归
    if (left >= right) {
        return;
    }
    // 哨兵划分
    int pivot = partition(nums, left, right);
    // 递归左子数组、右子数组
    quickSort(nums, left, pivot - 1);
    quickSort(nums, pivot + 1, right);
}

/* 快速排序类（中位基准数优化） */
// 选取三个元素的中位数
int medianThree(int nums[], int left, int mid, int right) {
    // 此处使用异或运算来简化代码
    // 异或规则为 0 ^ 0 = 1 ^ 1 = 0, 0 ^ 1 = 1 ^ 0 = 1
    if ((nums[left] < nums[mid]) ^ (nums[left] < nums[right]))
        return left;
    else if ((nums[mid] < nums[left]) ^ (nums[mid] < nums[right]))
        return mid;
    else
        return right;
}

// 哨兵划分（三数取中值）
int partitionMedian(int nums[], int left, int right) {
    // 选取三个候选元素的中位数
    int med = medianThree(nums, left, (left + right) / 2, right);
    // 将中位数交换至数组最左端
    swap(nums, left, med);
    // 以 nums[left] 作为基准数
    int i = left, j = right;
    while (i < j) {
        while (i < j && nums[j] >= nums[left])
            j--; // 从右向左找首个小于基准数的元素
        while (i < j && nums[i] <= nums[left])
            i++;          // 从左向右找首个大于基准数的元素
        swap(nums, i, j); // 交换这两个元素
    }
    swap(nums, i, left); // 将基准数交换至两子数组的分界线
    return i;            // 返回基准数的索引
}

// 中位基准数优化-快速排序
void quickSortMedian(int nums[], int left, int right) {
    // 子数组长度为 1 时终止递归
    if (left >= right)
        return;
    // 哨兵划分
    int pivot = partitionMedian(nums, left, right);
    // 递归左子数组、右子数组
    quickSortMedian(nums, left, pivot - 1);
    quickSortMedian(nums, pivot + 1, right);
}

/* 快速排序类（尾递归优化） */
// 快速排序（尾递归优化）
void quickSortTailCall(int nums[], int left, int right) {
    // 子数组长度为 1 时终止
    while (left < right) {
        // 哨兵划分操作
        int pivot = partition(nums, left, right);
        // 对两个子数组中较短的那个执行快排
        if (pivot - left < right - pivot) {
            quickSortTailCall(nums, left, pivot - 1); // 递归排序左子数组
            left = pivot + 1;                         // 剩余待排序区间为 [pivot + 1, right]
        } else {
            quickSortTailCall(nums, pivot + 1, right); // 递归排序右子数组
            right = pivot - 1;                         // 剩余待排序区间为 [left, pivot - 1]
        }
    }
}

/* Driver Code */
int main() {
    /* 快速排序 */
    int nums[] = {2, 4, 1, 0, 3, 5};
    int size = sizeof(nums) / sizeof(int);
    quickSort(nums, 0, size - 1);
    printf("快速排序完成后 nums = ");
    printArray(nums, size);

    /* 快速排序（中位基准数优化） */
    int nums1[] = {2, 4, 1, 0, 3, 5};
    quickSortMedian(nums1, 0, size - 1);
    printf("快速排序（中位基准数优化）完成后 nums = ");
    printArray(nums1, size);

    /* 快速排序（尾递归优化） */
    int nums2[] = {2, 4, 1, 0, 3, 5};
    quickSortTailCall(nums2, 0, size - 1);
    printf("快速排序（尾递归优化）完成后 nums = ");
    printArray(nums1, size);

    return 0;
}

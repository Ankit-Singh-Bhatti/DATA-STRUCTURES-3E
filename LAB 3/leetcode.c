#include <stdio.h>

void searchRange(int nums[], int numsSize, int target, int result[2]) {
    int left = 0, right = numsSize - 1;
    result[0] = -1;
    result[1] = -1;

    // Binary search for the leftmost occurrence
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            result[0] = mid;
            right = mid - 1;  // Continue searching on the left side
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // Reset the left and right pointers for the rightmost occurrence
    left = 0;
    right = numsSize - 1;

    // Binary search for the rightmost occurrence
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            result[1] = mid;
            left = mid + 1;  // Continue searching on the right side
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
}
int main() {
    int arr[] = {5, 7, 7, 8, 8, 10};
    int target;
    int len = sizeof(arr) / sizeof(arr[0]);
    int result[2];

    printf("Enter the target integer: ");
    scanf("%d", &target);

    searchRange(arr, len, target, result);

    printf("Result: [%d, %d]\n", result[0], result[1]);

    return 0;
}



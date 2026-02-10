/**
 * Strategy: Sliding Window with incremental frequency updates.
 * Instead of re-scanning the entire window (O(N^3)), we update 
 * counters in O(1) as the window slides.
 */
int longestBalanced(int* nums, int numsSize) {
    if (numsSize <= 0) return 0;

    // We use a frequency array to handle numbers up to 10^5
    // Using static to avoid repeated stack allocation
    static int freq[100001];

    for (int size = numsSize; size > 0; size--) {
        // Reset state for the new window size
        memset(freq, 0, sizeof(freq));
        int dEven = 0, dOdd = 0;

        // 1. Initialize the first window of current 'size'
        for (int i = 0; i < size; i++) {
            int val = nums[i];
            if (freq[val] == 0) { // First time seeing this number in the window
                if (val % 2 == 0) dEven++;
                else dOdd++;
            }
            freq[val]++;
        }

        if (dEven == dOdd) return size;

        // 2. Slide the window: O(1) per move
        for (int strt = 1; strt <= numsSize - size; strt++) {
            int outIdx = strt - 1;
            int inIdx = strt + size - 1;

            // Remove the element that is sliding out
            int valOut = nums[outIdx];
            freq[valOut]--;
            if (freq[valOut] == 0) { // No more occurrences of this number
                if (valOut % 2 == 0) dEven--;
                else dOdd--;
            }

            // Add the element that is sliding in
            int valIn = nums[inIdx];
            if (freq[valIn] == 0) { // New distinct number in this window
                if (valIn % 2 == 0) dEven++;
                else dOdd++;
            }
            freq[valIn]++;

            if (dEven == dOdd) return size;
        }
    }
    return 0;
}
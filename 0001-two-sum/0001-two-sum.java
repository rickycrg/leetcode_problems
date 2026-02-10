/**
implementing in O(n) time complexity, avoiding "double loop"
O(n) space complexity because of the creation of the map
*/
class Solution {
    public int[] twoSum(int[] nums, int target) {
        //mapping 2 ints for the final result
        Map<Integer, Integer> map = new HashMap<>();
        //iterating trough all elements in the list
        for (int i=0;i<nums.length;i++){
            //dont need a second loop, because we alredy know what number we want to find, and there is no need to iterate 2 times
            int complemento = target - nums[i];
            if (map.containsKey(complemento)){
                return new int[] {map.get(complemento), i};
            }
            map.put(nums[i], i);
        }
        return new int[] {};
    }
}
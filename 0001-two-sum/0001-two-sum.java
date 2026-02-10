class Solution {
    public int[] twoSum(int[] nums, int target) {
        //get size of the array
        int size = nums.length;
        int[] result = new int[2];//result array
        //"int i" and "int j" to pass through the array and verify each couple of numbers 
        int i = 0;
        while (i<size){
        int j = 0;
            while (j<size){
                if (nums[i]+nums[j]==target && i!=j){
                    result[0]=i;result[1]=j;
                    return result;
                }
                j++;
            }
            i++;
        }
        return result;
    }
}
class Solution {
    public int removeDuplicates(int[] nums) {
        //avoiding errors
        if (nums.length == 0) return 0;
        //'i' to go trough the distinct numbers
        int i=0;
        for (int j=0;j<nums.length;j++){
            if (nums[i]!=nums[j]){
                //incrementing i and assigning to nums, if we find a different number
                i++;
                nums[i]=nums[j];
            }
        }
        //index + 1 to return the size
        return i+1;
    }
}
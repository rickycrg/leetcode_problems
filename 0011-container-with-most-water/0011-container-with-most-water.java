class Solution {
    /**
    O(n) time complexity
    O(1) space complexity
    */
    public int maxArea(int[] height) {
        int maxArea=0;// to put the max area and compare with the current
        int left=0;//index left limit
        int right = height.length-1;//index of right limit
        while (left<right){
            int width = right-left;//distance of the vertical lines
            int currentWidth = Math.min(height[left], height[right]);//calculing the current width 

            int currentArea = width * currentWidth;
            maxArea = Math.max(maxArea, currentArea);//comparing current area with maxarea and replace if the current is bigger
            
            // Strategy: Move the pointer pointing to the shorter line 
            // to potentially find a taller line that compensates for the width loss
            if (height[left]<height[right]){
                left++;
            }else {
                right--;
            }
        }
        return maxArea;
    }
}
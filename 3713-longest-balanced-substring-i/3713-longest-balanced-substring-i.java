class Solution {
    /**
    Principal function : find the size of the longest balanced string possible
    time complexity O(n^2)
    space complexity O(n)
    */
    public int longestBalanced(String s) {
        int max=0;
        int size=s.length();
        for (int i=0;i<size;i++){
            int[] count = new int[26];//"alphabet" array to verify all english letters
            int distinctCount=0;//count how many distinct chars there is in the input

            for (int j=i;j<size;j++){//loop to verify each letter until we find the present letter in the string
                int charIdx = s.charAt(j) - 'a';//transforming the char in int
                if (count[charIdx]==0){
                    distinctCount++;
                }
                count[charIdx]++;
                
                //calling function
                if (isBalanced(count, distinctCount)){
                    max = Math.max(max, j - i + 1);
                }
            }
        }
        return max;
    }

    /** 
    function to verify if an array is balanced
    time complexity : O(n) (one loop)
    */ 
    private boolean isBalanced (int[] count, int distinctCount){

        int targetFreq = 0;
        for (int c:count){
            if (c>0){
                if (targetFreq==0){
                    targetFreq = c;
                }else if(c != targetFreq){
                    return false;
                }
            }
        }
        return true;
    }
}
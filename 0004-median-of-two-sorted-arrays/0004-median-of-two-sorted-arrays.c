//Implementation of median in 2 arrays, without using a sort, avoiding the O(n^2) time complexity.
//Used the merge algorithm to reach the O(n) time complexity and consequently improving the system efficiency.
//Time complexity : O(n)
//Space complexity : O(n)

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    //initializing final array variable
    int mediaDen = nums1Size + nums2Size;
    int *result = malloc(mediaDen*(sizeof(int)));
    if (result == NULL) {
    free (result);
    return 0;
}
    int i=0;//index variable for 1st array
    int j=0;//index variable for 2nd array
    int k=0;//index variable for final array
    //merge system (avoiding sorts), reaching better efficiency
    while (k<mediaDen && i<nums1Size && j<nums2Size){
        if (nums1[i]<nums2[j]){
            *(result+k)=nums1[i];
            k++;i++;
        }else if(nums1[i]>nums2[j]){
            *(result+k)=nums2[j];
            k++;j++;
        }else if(nums1[i]==nums2[j]){
            *(result+k)=nums1[i];
            k++;i++;
            *(result+k)=nums2[j];
            k++;j++;
        }else if (i<nums1Size){
            *(result+k)=nums1[i];
            k++;i++;
        }
    }
    while (nums2Size>j){
        *(result + k)=nums2[j];
        k++;j++;
    }
    while (nums1Size>i){
        *(result + k)=nums1[i];
        k++;i++;
    }
    //finding the middle element/elements (using new index variables)
    int m=0, n=mediaDen-1;
    while (m!=n && m<n){
        m++;
        n--;
    }
    double Resolution = 0;
    //condition for the exception if is a single number
    if (mediaDen==1){
    Resolution = *result;
    }else{
    Resolution = (*(result+m)+*(result+n))/2.0;
    }
    //deallocating memory and finishing
    free(result);
    return Resolution;
}

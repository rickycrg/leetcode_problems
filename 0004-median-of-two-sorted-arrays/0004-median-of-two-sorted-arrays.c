double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int mediaDen = nums1Size + nums2Size;
    int *result = malloc(mediaDen*(sizeof(int)));
    if (result == NULL) {
    free (result);
    return 0;
}
    int i=0;
    int j=0;
    int k=0;
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
    int m=0, n=mediaDen-1;
    while (m!=n && m<n){//find median
        m++;
        n--;
    }
    double Resolution = 0;
    if (mediaDen==1){
    Resolution = *result;
    }else{
    Resolution = (*(result+m)+*(result+n))/2.0;
    }
    free(result);
    return Resolution;
}
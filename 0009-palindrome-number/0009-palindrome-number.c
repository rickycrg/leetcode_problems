bool isPalindrome(int x) {
    if (x<0) return false;//negative numbers are not palindromes
    if (x==0) return true;
    //calculating size of the number utilizing an x copy
    int xSize = 0;
    long xBuffer = x;
    while (xBuffer > 0){
        xBuffer /=10;
        xSize +=1;
    }
    //creating array and putting each number in it
    int *res = malloc(xSize * sizeof(int));
    if (res==NULL) return false;
    for (int i=0;i<xSize;i++){
        *(res + i)= x % 10;
        x /=10;
    }
    //verifing if it's a palindrome number or not using two new "index" variables
        int i = 0;
        int j = xSize-1;
            while (i<j){
            if (*(res+i)!=*(res+j)){
                free(res);
                return false;   
                }
                i++;
                j--;
            }
    //deallocating memory and finishing
    free(res);
    return true;
    }

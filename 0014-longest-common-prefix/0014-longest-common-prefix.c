char* longestCommonPrefix(char** strs, int strsSize) {
    //ending function if input = null
    if (strsSize==0) return "";
    int size = 0;
    //finding 1st string size
    while (strs[0][size]!='\0'){
        size++;
    }
    //creating result array (size + 1 to count the final character '\0')
    char *result = malloc((size+1)*(sizeof(char)));
    //loop that pick 1st string char to compare with the others strings chars in the same positions
    for (int i=0;i<size;i++){
        char c =strs[0][i];
        for (int j=1;j<strsSize;j++){
            //comparing with next string  to see if they dont have more characters in common
            if (strs[j][i]=='\0' || strs[j][i]!=c){
                result[i]='\0';
                return result;//putting '\0' to end string and ending function
            }
        }
        result[i]=c;
    }
    //ending
    result[size]='\0';
    return result;
}
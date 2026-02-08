int romanToInt(char* s) {
    //I V X L C D M
    int output = 0;
    int size = 0;
    while (*(s + size)!= '\0'){
        size++;
    }
    for (int i=0;i<size;i++){
        if (*(s + i)== 'I'){
            if (*(s+i+1)!= 'V' && *(s+i+1)!= 'X'){
                output++;
            }else{
                output--;
            }
        }else if (*(s+i)=='X'){
            if (*(s+i+1)!= 'L' && *(s+i+1)!= 'C'){
                output+=10;
            }else{
                output-=10;
            }
        }else if (*(s+i)=='C'){
            if (*(s+i+1)!= 'D' && *(s+i+1)!= 'M'){
                output+=100;
            }else{
                output-=100;
                }
             }
        else if (*(s+i)=='V') output+=5;
        else if (*(s+i)=='L') output+=50;
        else if (*(s+i)=='D') output+=500;
        else if (*(s+i)=='M') output+=1000;
    }

    return output;
}
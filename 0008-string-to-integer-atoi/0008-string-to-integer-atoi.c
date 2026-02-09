int myAtoi(char* s) {
    int index = 0;
    int sign = 1;
    long result = 0;

    while (s[index] == ' '){
        index++;
    }
    if (s[index]=='-'||s[index]=='+'){
        sign = (s[index]=='-') ? -1 : 1;
        index++;
    }
    while (s[index] >= '0' && s[index] <= '9'){
        int digit = s[index] - '0';
        result = result * 10 + digit;
        if (result * sign >= INT_MAX) return INT_MAX;
        if (result * sign <= INT_MIN) return INT_MIN;
        index++;
    }
    return (int)(result * sign);
    }
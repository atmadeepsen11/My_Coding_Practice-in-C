int myAtoi(const char *str)
{
    const char *p = str;
    int acc = 0;
    int neg = 0, add;
    
    while (*p == ' ')
        ++p;
    
    if (*p == '-') {
        neg = 1;
        ++p;
    } else if (*p == '+') {
        ++p;
    }
    
    while (*p >= '0' && *p <= '9') {
        add = *p - '0';
        if (acc > INT_MAX/10) {
            return neg ? INT_MIN : INT_MAX;
        } else if (acc == INT_MAX/10) {
            if (neg && add > 8)
                return INT_MIN;
            if (!neg && add > 7)
                return INT_MAX;
        }
        acc = 10 * acc + add;
        ++p;
    }
    
    if (neg)
        acc = -acc;
    
    return acc;
}
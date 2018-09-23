bool isNumeric(char* string) {
    if (string == NULL) return false;
    int isNum = 0, isDecimal = 0, isE = 0;
    if (*string == '+' || *string == '-') string++;
    if (*string == '\0') return false;
    while (*string != '\0') {
        if (*string >= '0' && *string <= '9') {
            isNum = 1;
            string++;
        } else if (*string == '.') {
            if (isDecimal || isE) return false;
            isDecimal = 1;
            string++;
        } else if (*string == 'e' || *string == 'E') {
            if (isNum == 0 || isE > 0) return false;
            isE = 1;
            string++;
            if (*string == '+' || *string == '-')
                string++;
            if (*string == '\0')
                return false;
        } else {
            // 其他字符
            return false;
        }
    }
    return true;
}
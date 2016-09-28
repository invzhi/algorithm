char* convert(char* s, int numRows) {
    char* output;
    char map[1000][1000];
    int length = 0, i = 0, j = 0, x = 0, k = 0;
    if (numRows < 2) return s;
    for (i = 0; s[i]; i++) length++;
    output = (char*) malloc(sizeof(char) * (length + 1));
    if (numRows == 2) {
        for (i = 0; i < length; i += 2) output[x++] = s[i];
        for (i = 1; i < length; i += 2) output[x++] = s[i];
        output[x] = 0;
        return output;
    }
    for (i = 0; i < numRows; i++) {
        for (j = 0; j < length; j++) {
            map[i][j] = 0;
        }
    }
    i = j = x = 0;
    while (s[x]) {
        if (j % 2) {
            i = numRows - 2;
            while (s[x] && i > 0) map[i--][j] = s[x++];
        } else {
            i = 0;
            while (s[x] && i < numRows) map[i++][j] = s[x++];
        }
        j++;
    }
    x = 0;
    for (i = 0; i < numRows; i++) {
        for (k = 0; k < j; k++) {
            if (map[i][k]) output[x++] = map[i][k];
        }
    }
    output[x] = 0;
    return output;
}
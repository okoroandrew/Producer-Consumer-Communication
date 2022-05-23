
char *sliceString(char *str, int start, int end){
    /** This is for getting a substring from a string by specifying the parameters - string,
     * where the substring begins (start), and where it should (end)*/
    int i;
    int size = (end - start) + 2;
    char *bitString = (char *)malloc(size * sizeof(char));

    for (i = 0; start <= end; start++, i++){
        bitString[i] = str[start];
    }
    bitString[size] = '\0';
    return bitString;
}

char * parityCheck(char * dataString) {
    /** counts the number of 1 in a string bits and return even or odd based on the count*/
    int count = 0;
    for (char *dataStringP = dataString; *dataStringP != '\0'; ++dataStringP){
        if (*dataStringP == '1') count ++;
    }
    return (count % 2 == 0) ? "even parity" : "odd parity";
}

char * deFraming(char * frameString){
    /** from dropping the syn bits and control bits from a frame and returns only the data bits (with parity)*/
    char * syncBit = "0001011000010110";
    if (strcmp(sliceString(frameString, 0, 15), syncBit) == 0){
        return sliceString(frameString, 24, (int)strlen(frameString));
    }
    else {
        printf("error in deFraming, check frame!!!\n");
    }
    return NULL;
}

char * getDataString(char * deFramedString){
    /** Checks for parity,If the parity is odd, it drops the most significant bit and replaces it with a zero.
     * Otherwise, it would report it as a transmission error. All the data bit is merged
     * and ready for conversion into ASCII.*/
    char * dataBits = (char *)malloc(sizeof(char) * strlen(deFramedString) + 1);
    int start = 0, end = 7;
    char * dataStringWithParity;
    for (int i = 0; i < strlen(deFramedString)/8; i++){
        dataStringWithParity = sliceString(deFramedString, start, end);
        start += 8, end += 8;
        if (strcmp(parityCheck(dataStringWithParity), "odd parity") == 0){
            char * a = sliceString(dataStringWithParity, 1, 7);
            strcat(strcat(dataBits, "0"), a);
        }
        else printf("There's an error in the data bit!!!");
    }
    return dataBits;
}

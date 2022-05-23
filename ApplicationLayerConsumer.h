
void BinaryToText(char * bitsToConvert, char * outputFilePath) {
    /** converts each binary bit into an ASCII char, and writer the char to the screen
     * as well as to an output file*/
    FILE *f = fopen(outputFilePath, "w");
    char * inputBuffer;
    char temp;
    int start = 0, end = 7;
    if (bitsToConvert == NULL) exit(1);
    unsigned long bitsLeft = strlen(bitsToConvert);
    do {
        inputBuffer = sliceString(bitsToConvert, start, end);
        if (bitsLeft < 8)
            break;
        temp = 0;
        for (int i = 0; i < 8; ++i) {
            temp |= (inputBuffer[i] & 1) << (7 - i);
        }
        bitsLeft -= 8; start += 8, end += 8;
        printf("%c", temp);
        fputc(temp, f);
    } while (1);
    fclose(f);
    printf("\n");
}


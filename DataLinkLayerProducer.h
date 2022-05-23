
const int MAX_CHAR = 64, MAX_CHAR_BIT = 512;

char * DecimalToBinary(int num) {
    /** This is for converting a decimal to binary, It helps the producer to convert
     * the control digit its 8 bits binary equivalence*/
    int n = num;
    char *s = malloc(sizeof(int) * 8);
    int i, c = 0;

    for (i = sizeof(int) * 2 - 1; i >= 0; i--) {
        n = num >> i;
        *(s + c) = (n & 1) ? '1' : '0';
        c++;
    }
    *(s + c) = NULL;
    return s;
}

char* framing(char * parityBitString, int BitsLeft){
    /** Generates frames for transmission by concatenating the syn bits, control bits, and data bits*/
    char * synBit = "0001011000010110";
    char * controlChar = (BitsLeft >= MAX_CHAR_BIT) ? DecimalToBinary(MAX_CHAR) : DecimalToBinary(
            MAX_CHAR_BIT % BitsLeft);
    char * frame;
    frame = (char *) malloc(sizeof(char) * (strlen(synBit) + strlen(controlChar) + strlen(parityBitString)) + 1);
    strcat(strcat(strcat(frame, synBit), controlChar), parityBitString);
    return frame;
}


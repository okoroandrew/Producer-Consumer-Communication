#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <time.h>
#include "PhysicalLayerProducer.h"
#include "DataLinkLayerProducer.h"
#include "ApplicationLayerProducer.h"

#define MAX_CHAR_BITS 512
#define CHAR_BITS 8

int main() {
    char inputFilePath[100];
    char outputFilePath[100];
    printf("Please enter input file directory: ");
    scanf("%s", inputFilePath);
    printf("Enter binary output file directory: ");
    scanf("%s", outputFilePath);

    char *text = readFile(inputFilePath);
    char *str = stringToBinary(text);

    unsigned long numOfFrame = (strlen(str) + 1) / (CHAR_BITS - 1);
    printf("%lu", numOfFrame);

    srand((unsigned) time(NULL));

    *//**Slice through the entire string, and add a parity bit to each, and return the sliced array*//*
    char * bitsToFrame = (char *) malloc(sizeof (char) * strlen(str) + 1); //size 65 assuming 8 x 8 bits string plus 1 for null pointer
    int start = 0, end = CHAR_BITS - 2;

    for (int i = 0; i < (strlen(str) + 1) / (CHAR_BITS - 1); i++){                   //looking at 8 characters = 64bits ; int i = 0; i <= 7; i++ for that
        char * slicedBitsWithParity = addParityBit( sliceString(str, start, end));

        *//**flip the last bit in the ith iteration based on a random number between 1 and 10*//*
        if (i == rand() % 10){
            char * errorBit = strcmp(sliceString(slicedBitsWithParity, 7, 7), "1" ) == 0 ? "0" : "1";
            slicedBitsWithParity = sliceString(slicedBitsWithParity, 0, 6);
            strcat(slicedBitsWithParity, errorBit);
            printf("??????Error in frame %d, the last bit is flipped", i);
        }
        
        strcat(bitsToFrame, slicedBitsWithParity);
        start += CHAR_BITS - 1; end += CHAR_BITS - 1;
    }

    *//** iterate through bitsToFrame, after every 512 bits (64 characters), frame, and store in writeThis.
     * transmit writeThis to a binary (.binf) file *//*
    char *toFrame;
    char * writeThis = (char *)malloc(sizeof (char) * 8056);
    int begin = 0, stop = MAX_CHAR_BITS - 1, countBitsLeft = (int)strlen(bitsToFrame);
    for (int i = 0; i <= strlen(bitsToFrame) / MAX_CHAR_BITS; i++){
        if(countBitsLeft >= MAX_CHAR_BITS) {
            toFrame = sliceString(bitsToFrame, begin, stop);
        }
        else {
            toFrame = sliceString(bitsToFrame, begin, (begin + countBitsLeft - 1));
        }
        char * toTransmit = framing(toFrame, countBitsLeft);
        strcat(writeThis, toTransmit);
        begin += MAX_CHAR_BITS; stop += MAX_CHAR_BITS; countBitsLeft -= MAX_CHAR_BITS;
    }
    writeFile(outputFilePath,  writeThis);
}



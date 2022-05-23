#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PhysicalLayerConsumer.h"
#include "DataLinkLayerConsumer.h"
#include "ApplicationLayerConsumer.h"


int main() {
    /** Reads a binary file from the producer and store in string variable binaryData */
    char inputFilePath[100];
    char outputFilePath[100];
    printf("Please enter binary input file directory: ");
    scanf("%s", inputFilePath);
    printf("Enter ASCII output file directory: ");
    scanf("%s", outputFilePath);
    char* binaryData = readFile(inputFilePath);

    /** Iterate through the binary data string, extract each frame using the syn bit, deframe by dropping
     * the syn bits and control bits, break the data bits into 8, check for parity and replace the MSB with
     * '0' after which it would be ready for conversion to text*/
    char* frameString; char * ToTextConvert;
    int start = 0, end = 535, countBitsLeft = (int)strlen(binaryData);
    char *ToTextConverter = (char *) malloc(sizeof(char) * strlen(binaryData)); //This space is much

    for (int i = 0; i <= strlen(binaryData) / 536; i++){
        if (countBitsLeft >= 536) frameString = sliceString(binaryData, start, end);
        else frameString = sliceString(binaryData, start, start + countBitsLeft - 1);
        ToTextConvert = getDataString(deFraming(frameString));
        strcat(ToTextConverter, ToTextConvert);
        start += 536; end += 536; countBitsLeft -= 536;
    }
    BinaryToText(ToTextConverter, outputFilePath);
    free(ToTextConverter);
}



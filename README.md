# Producer-Consumer-Communication
This aim of this project is to review the fundamental concepts and components of data communication using files.
There is a single producer (server) and a single consumer (client).
 
## Procucer and Consumer
The producer takes the input from the user file which are ASCII characters, 
converts each character into binary, encodes each character (8 bits binary) with a parity bit, and writes the output to a binary file in frames. 
Each frame contains 2 syn characters, a control character that contains the length of the data to be transmitted, and the data transmitted.

The consumer on the other end reads the binary file from the producer, gets each
frame transmitted using the syn bits, removes the frame, and obtains the data bits.
The data bits are checked for parity to ensure that there was no error during
transmission, the parity bit is dropped, and the bits are converted back ASCII. The
ASCII is then saved in another file or printed on the screen. In the absence of error,
the original user data would exactly be the same as the data from the consu

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) 
{   
     // Variables
    char* mot;
    int argumentCount = argc;

    printf("%d\n", argc);

    // Print header
    printf("\n======== SHA256 - HASHING ALGORITHM ========\n");

    // Test to make sure the user is inputting a filename
    if(argumentCount <= 1 || argumentCount > 2)
    {
        printf("Merci d'ecrire qu'une chaine de caractere en argument.\n");
        return -1;
    }
    else if(argumentCount == 2)
    {
        printf("Bon nombre d'argument. Decodage de la chaine de caractere.\n");

        mot = argv[1];

        printf("%s\n", mot);

    }
}

int fillMessageBlock(char* mot, union messageBlock *msgBlock, enum status *state, uint64_t *numBits)
{   
    // Variables
    uint64_t numBytes;
    int i;

    // If we've finished padding and processing all the message blocks, exit
    if(*state == FINISH)
    {
        printf("\n State = FINISH.\n");
        return 0;
    }

    // Handle our PAD0 and PAD1 states
    // Check if we need another block full of padding
    if(*state == PAD0 || *state == PAD1)
    {
        printf("\n State = PAD0 or PAD1.\n");

        // Set the first 56 bytes to all zero bits
        for(i=0; i<56; i++)
        {
            msgBlock->e[i] = 0x00;
        }

        // Set the last 64 bits to an integer (should be big endian)
        msgBlock->s[7] = byteSwap64(*numBits);

        // Set the state to finish
        *state = FINISH;

        // If state is PAD1, set the first bit of msgBlock to 1
        if(*state == PAD1)
        {
            // 0x80 = 10000000
            msgBlock->e[0] = 0x80;
        }

        // keep the loop in SHA256 going for one more iteration
        return 1;
    }

    // Read bytes instead of characters
    // Read until the end of the file

    for(int m=0; m<strlen(mot); m++)
    {
        msgBlock->e[m] = int(mot[m]);
    }
    // numBytes = fread(msgBlock->e, 1, 64, file



    // printf("%d\n", msgBlock->e[0]);
    
    // Keep track of the number of bytes we've read
    *numBits = *numBits + (numBytes * 8);
    
    // If theres enough room to finish the padding
    if(numBytes < 56)
    {
        // 0x80 = 10000000
        // Add the one bit, as per the standard before padding with 0s
        msgBlock->e[numBytes] = 0x80;

        // Add 0 bits until the last 64 bits
        while(numBytes < 56)
        {
            // Add the index into our block
            numBytes = numBytes +1;
            
            // Add enough zeroes so that there are 64 bits left at the end
            msgBlock->e[numBytes] = 0x00;
        }

        // Store the length of the file in bits as a (Should be big endian) unsigned 64 bit int
        msgBlock->s[7] = byteSwap64(*numBits);

        // Change the state of our program
        *state = FINISH;
    }
    // Otherwise, check if we can put some padding into this message block
    else if(numBytes < 64)
    {   
        // Set the state to PAD0
        *state = PAD0;
        
        // 0x80 = 10000000
        // Add the one bit into the current message block
        msgBlock->e[numBytes] = 0x80;

        // Pad the rest of the message block with 0 bits
        while(numBytes < 64)
        {
            numBytes = numBytes + 1;
            msgBlock->e[numBytes] = 0x00;
        }
    }
    // Otherwise if we're at the end of the file, need to create a new message block full of padding
    else if(feof(file))
    {
        // Set the state to PAD1
        // We need a message Block full of padding
        *state = PAD1;
    }
    
    // Print padding
    /*
    printf("\n--- PADDING --- \n");
    for (int i=0; i<64; i++)
    {
       printf("%x", msgBlock.e[i]);
    }
    printf("\n");
    */
    return 1;
}
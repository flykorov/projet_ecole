#include <stdio.h>
#include <string.h>
#include <inttypes.h>

#define byteSwap32(x) (((x) >> 24) | (((x)&0x00FF0000) >> 8) | (((x)&0x0000FF00) << 8) | ((x) << 24))
#define byteSwap64(x)                                                      \
	((((x) >> 56) & 0x00000000000000FF) | (((x) >> 40) & 0x000000000000FF00) | \
	 (((x) >> 24) & 0x0000000000FF0000) | (((x) >> 8) & 0x00000000FF000000) |  \
	 (((x) << 8) & 0x000000FF00000000) | (((x) << 24) & 0x0000FF0000000000) |  \
	 (((x) << 40) & 0x00FF000000000000) | (((x) << 56) & 0xFF00000000000000))


union messageBlock
{
    uint8_t e[64];
    uint32_t t[16];
    uint64_t s[8];
};

enum status
{	
	READ, 
    PAD0,
    PAD1,
    FINISH
};

int fillWordBlock();

int main(int argc, char* argv[])
{

	char* mot = argv[1];
	union messageBlock msgBlock; 

	uint64_t numBits = 0;

	enum status state = READ;

	int depart = 0;

	while(fillWordBlock(mot, depart, &msgBlock, &state, &numBits))
	{
		depart += 64;
		for(int i=0; i<64; i++)
		{
			printf("%d ", msgBlock.e[i]);
		}

		printf("\n");
	}

	printf("bou\n");

	return 0;

}



int fillWordBlock(char* mot, int depart, union messageBlock *msgBlock, enum status *state, uint64_t *numBits)
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
    for(int m=depart, j=0; m<depart+64 && m<strlen(mot); m++, j++)
    {
        msgBlock->e[j] = mot[m];
    }

    if(strlen(mot) - depart > 64)
    {
    	numBytes = 64;
    }
    else
    {
    	numBytes = strlen(mot) - depart;
    }

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
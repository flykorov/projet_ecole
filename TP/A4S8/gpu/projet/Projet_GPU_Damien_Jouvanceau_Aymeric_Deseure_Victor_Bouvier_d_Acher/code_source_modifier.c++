/*
    Projet GPU
    
    Membre :
        Damien Jouvanceau
        Aymeric Deseure
        Victor Bouvier d'Acher

    Classe 42 Groupe 10

    Code source CPU modifier

    source : 
    https://github.com/EddieEldridge/SHA256-in-C/blob/master/SHA256.c

    deroulement visuelle de l'algorithme SHA256 :
    https://sha256algorithm.com/

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>
#include <iostream>
#include <chrono>
using namespace std;

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

_Bool endianCheck()
{
    int num = 1 ;
        if(*(char *)&num == 1) {
                return false;
        } else {
                return true;
        }
}

int fillWordBlock(char* mot, int depart, union messageBlock *msgBlock, enum status *state, uint64_t *numBits)
{   

    // Variables
    uint64_t numBytes;
    int i;

    // If we've finished padding and processing all the message blocks, exit
    if(*state == FINISH)
    {
        // printf("\n State = FINISH.\n");
        return 0;
    }


    // Handle our PAD0 and PAD1 states
    // Check if we need another block full of padding
    if(*state == PAD0 || *state == PAD1)
    {
        // printf("\n State = PAD0 or PAD1.\n");

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


uint32_t sig0(uint32_t x);
uint32_t sig1(uint32_t x);

uint32_t rotr(uint32_t n, uint16_t x);
uint32_t shr(uint32_t n, uint16_t x);

uint32_t SIG0(uint32_t x);
uint32_t SIG1(uint32_t x);

uint32_t Ch(uint32_t x,uint32_t y,uint32_t z);
uint32_t Maj(uint32_t x,uint32_t y,uint32_t z);

// Section 4.1.2  
// ROTR = Rotate Right 
// SHR = Shift Right
// ROTR_n(x) = (x >> n) | (x << (32-n))
// SHR_n(x) = (x >> n)
uint32_t sig0(uint32_t x)
{
    // Section 3.2
    return (rotr(x, 7) ^ rotr(x, 18) ^ shr(x, 3));
};

uint32_t sig1(uint32_t x)
{
    return (rotr(x, 17) ^ rotr(x, 19) ^ shr(x, 10));
};

// Rotate bits right
uint32_t rotr(uint32_t x, uint16_t a)
{
    return (x >> a) | (x << (32 - a));
};

// Shift bits right
uint32_t shr(uint32_t x, uint16_t b)
{
    return (x >> b);
};

uint32_t SIG0(uint32_t x)
{
    return (rotr(x, 2) ^ rotr(x, 13) ^ rotr(x, 22));
};

uint32_t SIG1(uint32_t x)
{
    return (rotr(x, 6) ^ rotr(x, 11) ^ rotr(x, 25));
};

// Choose
uint32_t Ch(uint32_t x,uint32_t y,uint32_t z)
{
    return ((x & y) ^ (~(x)&z));
};

// Majority decision
uint32_t Maj(uint32_t x,uint32_t y,uint32_t z)
{
    return ((x & y) ^ (x & z) ^ (y & z));
};


bool verfification(uint32_t* res, uint32_t* mot)
{
    bool verif = true;

    for(int j=0; j<8; j++)
    {
        if(mot[j] != res[j])
        {
            verif = false;
            break;
        }
    }

    return verif;
}


// === Functions ===
bool calculateHash(char* mot, uint32_t* mdp)
{   
    // Variables
    // The current message block
    union messageBlock msgBlock;

    // The number of bits read from the file
    uint64_t numBits = 0;

    // The state of the program
    enum status state = READ;

    // uint32_t mdp[8] = {
    //     0xb9ec475b,
    //     0x167bae9b,
    //     0x39e086de,
    //     0x4f97e01d,
    //     0x3ccdd7ea,
    //     0x5e1aa00d,
    //     0xb8cffc6e,
    //     0x2ce91d31
    // };

    // Declare the K constant
    // Defined in Section 4.2.2
    uint32_t K[] =
    {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 
        0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
        0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
        0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 
        0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967, 
        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
        0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
        0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
        0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3, 
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
        0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
    };

    // Message schedule
    uint32_t W[64];

    // Working variables
    uint32_t a, b, c, d, e, f, g, h;

    // Temp variables
    uint32_t T1;
    uint32_t T2;

    // Hash values
    // Taken from https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.180-4.pdf
    uint32_t H[8] = {
        0x6a09e667,
        0xbb67ae85,
        0x3c6ef372,
        0xa54ff53a,
        0x510e527f,
        0x9b05688c,
        0x1f83d9ab,
        0x5be0cd19
    };

    // The current message block

    // For loop to iterate through the message block 
    int j;
    int o;

    int depart = 0;


    while(fillWordBlock(mot, depart, &msgBlock, &state, &numBits))
    {

        depart += 64;

        for(j=0; j<16; j++)
        {   
            // Fist check for big or little endian
            // If our system is big endian we dont need to do any conversion
            if(endianCheck()==true)
            {
                W[j] = msgBlock.t[j];
            }
            else
            {
                // Add the current message block to our messag schedule
                // Convert to big endian first
                W[j] = byteSwap32(msgBlock.t[j]);
            }
           
        }

        for (j=16; j<64; j++)
        {
            // Step 1
            W[j] = sig1(W[j-2]) + W[j-7] + sig0(W[j-15]) + W[j-16];
        }


        // Initalize a..h
        // Step 2
        a=H[0];
        b=H[1];
        c=H[2];
        d=H[3];
        e=H[4];
        f=H[5];
        g=H[6];
        h=H[7];

        // For loop
        // Step 3
        for(j = 0; j < 64; j++)
        {
            // Creating new variables
            T1 = h + SIG1(e) + Ch(e,f,g) + K[j] + W[j];
            T2 = SIG0(a) + Maj(a,b,c);
            h = g;
            g = f;
            f = e;
            e = d + T1;
            d = c;
            c = b;
            b = a;
            a = T1 + T2;
        }

        // Step 4
        H[0] = a + H[0];
        H[1] = b + H[1];
        H[2] = c + H[2];
        H[3] = d + H[3];
        H[4] = e + H[4];
        H[5] = f + H[5];
        H[6] = g + H[6];
        H[7] = h + H[7];
    
    }// end while
    
    // // Print the results
    // printf("\n=================== HASH OUTPUT ==================================\n\n");
    // printf("%08llx", H[0]);
    // printf("%08llx", H[1]);
    // printf("%08llx", H[2]);
    // printf("%08llx", H[3]);
    // printf("%08llx", H[4]);
    // printf("%08llx", H[5]);
    // printf("%08llx", H[6]);
    // printf("%08llx", H[7]);

    
    // printf("\n\n==================================================================\n\n");


    bool verif = verfification(H, mdp);

    return verif;
}


int is_valid_hash(const char *hash) {
    // Vérifier la longueur du hash
    if (strlen(hash) != 64) // 256 bits = 64 caractères hexadécimaux
        return 0;

    // Vérifier si chaque caractère est un caractère hexadécimal
    for (int i = 0; i < 64; i++) {
        char c = hash[i];
        if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')))
            return 0;
    }

    return 1;
}

// Fonction pour convertir un hash 256 bits en uint32_t
void hash_to_uint32(const char *hash, uint32_t *output) {
    for (int i = 0; i < 8; i++) {
        sscanf(hash + i * 8, "%8x", &output[i]);
    }
}

int main(int argc, char* argv[])
{


    if (argc != 2) {
        printf("Usage: %s <hash256>\n", argv[0]);
        return 1;
    }

    char *hash = argv[1];
    uint32_t mdp[8]; // 256 bits / 32 bits = 8 uint32_t

    if (!is_valid_hash(hash)) {
        printf("Hash invalide.\n");
        return 1;
    }

    hash_to_uint32(hash, mdp);

    printf("Le hash en tant que uint32_t :\n");
    for (int i = 0; i < 8; i++) {
        printf("%08x ", mdp[i]);
    }
    printf("\n");
    char nom[12] = "rockme.txt";

    int nb_iter = 0;

    int nb_case = 8;
    // int nb_mot = 1024;

    char temp[100];
    char mot[100];

    FILE* fic = fopen(nom, "r");

    bool continuer = true; 
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    while(continuer)
    {
        // printf("%d\n", nb_iter);
        // nb_iter += 1;
        if(fgets(temp, sizeof(mot), fic) == NULL)
        {
            continuer = false;
            break;
        }else
        {
            int m=0;
            while(temp[m] != '\n')
            {
                mot[m] = temp[m];
                m++;
            }
            mot[m]='\0';
        }
        
        bool verif = calculateHash(mot, mdp);
        if(verif)
        {
            continuer = false;
            printf("le mdp est : %s\n", mot);
            break;
        }
        
    }

    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    double cpuTime = elapsed_seconds.count();

    cout << cpuTime << endl;

    fclose(fic);
}
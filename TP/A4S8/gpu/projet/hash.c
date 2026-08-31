#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// Fonction pour vérifier si une chaîne est un hash 256 bits valide
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

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <hash256>\n", argv[0]);
        return 1;
    }

    char *hash = argv[1];
    uint32_t output[8]; // 256 bits / 32 bits = 8 uint32_t

    if (!is_valid_hash(hash)) {
        printf("Hash invalide.\n");
        return 1;
    }

    hash_to_uint32(hash, output);

    printf("Le hash en tant que uint32_t :\n");
    for (int i = 0; i < 8; i++) {
        printf("%08x ", output[i]);
    }
    printf("\n");

    return 0;
}
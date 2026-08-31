#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 90

int main() {
    FILE *input_file, *output_file;
    char input_filename[] = "rockyou.txt"; // Nom du fichier d'entrée
    char output_filename[] = "rockme.txt"; // Nom du fichier de sortie
    char line[MAX_LINE_LENGTH + 2]; // +2 pour le caractère de fin de ligne et le caractère nul ('\0')

    // Ouvrir le fichier d'entrée en mode lecture
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        perror("Erreur lors de l'ouverture du fichier d'entrée");
        return 1;
    }

    // Ouvrir le fichier de sortie en mode écriture
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        perror("Erreur lors de l'ouverture du fichier de sortie");
        fclose(input_file);
        return 1;
    }

    // Parcourir le fichier d'entrée ligne par ligne
    while (fgets(line, sizeof(line), input_file)) {
        // Vérifier si la ligne a plus de 100 caractères
        if (strlen(line) < MAX_LINE_LENGTH) {
            // Écrire la ligne dans le fichier de sortie
            fputs(line, output_file);
        }
    }

    // Fermer les fichiers
    fclose(input_file);
    fclose(output_file);

    printf("Opération terminée avec succès.\n");

    return 0;
}
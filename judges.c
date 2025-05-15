#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JUDGES 100
#define MAX_INPUT 512
#define FIELD_COUNT 7

typedef struct {
    char name[50];
    char gender[10];
    char affiliation[50];
    char title[100];
    char specialty[50];
    char email[50];
    char phone[20];
} Judge;

void printJudge(const Judge* judge, int index) {
    printf("[Judge %d]\n", index + 1);
    printf("Name: %s\n", judge->name);
    printf("Gender: %s\n", judge->gender);
    printf("Affiliation: %s\n", judge->affiliation);
    printf("Title: %s\n", judge->title);
    printf("Expertise: %s\n", judge->specialty);
    printf("Email: %s\n", judge->email);
    printf("Phone: %s\n", judge->phone);
    printf("-----------------------------------\n");
}

int splitFields(char* input, char* fields[], int maxFields) {
    int count = 0;
    char* token = strtok(input, ",");

    while (token != NULL && count < maxFields) {
        // Remove leading/trailing spaces
        while (*token == ' ') token++;
        char* end = token + strlen(token) - 1;
        while (end > token && (*end == ' ' || *end == '\n')) *end-- = '\0';
        fields[count++] = token;
        token = strtok(NULL, ",");
    }
    return count;
}

int main() {
    char project[100];
    int totalJudges, selectedMembers;
    Judge judges[MAX_JUDGES];
    char buffer[MAX_INPUT];

    printf("####################################\n");
    printf("#      Judge List Data Entry      #\n");
    printf("####################################\n");

    printf("Participating Project: ");
    fgets(project, sizeof(project), stdin);
    project[strcspn(project, "\n")] = '\0';  // Remove newline

    printf("Total Number of Judges: ");
    scanf("%d", &totalJudges);
    getchar(); // Consume newline

    printf("Number of Selected Members: ");
    scanf("%d", &selectedMembers);
    getchar(); // Consume newline

    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("Starting to input information for %d judges.\n", totalJudges);
    printf("++++++++++++++++++++++++++++++++++++\n");

    for (int i = 0; i < totalJudges; i++) {
        while (1) {
            printf("Judge %d: ", i + 1);
            fgets(buffer, sizeof(buffer), stdin);
            char* fields[FIELD_COUNT];
            int numFields = splitFields(buffer, fields, FIELD_COUNT);

            if (numFields != FIELD_COUNT) {
                printf("The input items are incorrect. Please enter them again.\n");
                continue;
            }

            sscanf(fields[0], "Name: %[^\n]", judges[i].name);
            sscanf(fields[1], "Gender: %[^\n]", judges[i].gender);
            sscanf(fields[2], "Affiliation: %[^\n]", judges[i].affiliation);
            sscanf(fields[3], "Title: %[^\n]", judges[i].title);
            sscanf(fields[4], "Specialty: %[^\n]", judges[i].specialty);
            sscanf(fields[5], "Email: %[^\n]", judges[i].email);
            sscanf(fields[6], "Phone: %[^\n]", judges[i].phone);
            break;
        }
    }

    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("Judge information entry is complete.\n");
    printf("++++++++++++++++++++++++++++++++++++\n");

    printf("\"%s\" Should we check the judge information? ", project);
    char choice;
    scanf(" %c", &choice);

    if (choice == 'Y') {
        printf("####################################\n");
        printf("#        Display Judge Data        #\n");
        printf("####################################\n");

        for (int i = 0; i < totalJudges; i++) {
            printJudge(&judges[i], i);
        }
    } else {
        printf("Program terminated.\n");
    }

    return 0;
}

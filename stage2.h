#define MAX_TRAINEES 100

char traineeList[MAX_TRAINEES][50];      // Trainee names
int traineeValues[MAX_TRAINEES];         // ASCII sum values
int traineeAbilities[MAX_TRAINEES];      // Random abilities
int traineeCount = 0;
typedef struct {
    int id;                  // Unique ID (1–8)
    char name[50];
    int menteeIndex;         // Index of matched trainee
} Mentor;

Mentor mentorList[8];
int mentorCount = 0;
int parseIntMember(const char *name) {
    int sum = 0;
    for (int i = 0; name[i] != '\0'; ++i) {
        sum += (int)name[i];
    }
    return sum;
}
#include <stdlib.h>
#include <time.h>

int getRandomAbility() {
    return (rand() % 901) + 100; // 100–1000
}
void inputMentors() {
    char temp[50];
    printf("Enter mentor names (up to 8):\n");
    for (int i = 0; i < 8; ++i) {
        printf("Mentor %d name: ", i + 1);
        scanf("%s", temp);
        mentorList[i].id = i + 1;
        strcpy(mentorList[i].name, temp);
        mentorList[i].menteeIndex = -1;
        mentorCount++;
    }
}
void matchMentoring() {
    for (int i = 0; i < traineeCount; ++i) {
        int mentorId = i % 8;
        mentorList[mentorId].menteeIndex = i;
    }

    printf("\nMentoring Assignments:\n");
    for (int i = 0; i < 8; ++i) {
        if (mentorList[i].menteeIndex != -1) {
            int mentee = mentorList[i].menteeIndex;
            printf("Trainee #%d (%s) → Mentor ID: %d (%s)\n",
                   mentee + 1,
                   traineeList[mentee],
                   mentorList[i].id,
                   mentorList[i].name);
        }
    }
}

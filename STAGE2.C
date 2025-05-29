#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MEMBERS 100
#define MAX_TRAUMA_DESC 256
#define MAX_RESPONSE_LEN 101
#define NUM_QUESTIONS 5

// Structure to store member trauma information
struct Trauma {
    char nickname[50];
    int age;
    char description[MAX_TRAUMA_DESC];
};

// Structure for counseling questions
struct Question {
    int id;
    char content[256];
};

// Structure to store counseling session responses
struct CounselingResponse {
    char nickname[50];
    struct Question question;
    char response[MAX_RESPONSE_LEN];
};

// Global arrays to store data
struct Trauma memberTrauma[MAX_MEMBERS];
struct CounselingResponse counselingResponses[MAX_MEMBERS];
struct Question counselingQuestions[NUM_QUESTIONS] = {
    {1, "In what situations have you experienced this trauma?"},
    {2, "How has this situation affected your daily life and emotions?"},
    {3, "How have you tried to overcome this trauma?"},
    {4, "What emotions do you associate with this trauma?"},
    {5, "What kind of support do you think is necessary to overcome this trauma?"}
};
int memberCount = 0;
int responseCount = 0;
void overcomeTrauma() {
    char choice;
    do {
        printf("Select an option:\n");
        printf("A. Input trauma data\n");
        printf("B. Start counseling session\n");
        printf("C. Exit\n");
        printf("Your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'A':
            case 'a':
                inputTraumaData();
                break;
            case 'B':
            case 'b':
                startCounselingSession();
                break;
            case 'C':
            case 'c':
                printf("Exiting trauma management.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 'C' && choice != 'c');
}
void inputTraumaData() {
    char nickname[50];
    char description[MAX_TRAUMA_DESC];
    int age;
    int i;

    printf("Enter nickname: ");
    scanf("%s", nickname);

    // Check if nickname exists
    for (i = 0; i < memberCount; i++) {
        if (strcmp(memberTrauma[i].nickname, nickname) == 0) {
            break;
        }
    }

    if (i == memberCount) {
        printf("Error: Nickname not found.\n");
        return;
    }

    printf("Enter trauma description: ");
    getchar(); // Consume newline character left by previous scanf
    fgets(description, MAX_TRAUMA_DESC, stdin);
    description[strcspn(description, "\n")] = '\0'; // Remove newline character

    // Store trauma description
    strncpy(memberTrauma[i].description, description, MAX_TRAUMA_DESC);
    printf("Trauma description updated for %s.\n", nickname);
}
void startCounselingSession() {
    char nickname[50];
    int i, j, k;
    int selectedQuestions[3];
    char response[MAX_RESPONSE_LEN];
    srand(time(NULL));

    // List members with trauma data
    printf("Members with trauma data:\n");
    for (i = 0; i < memberCount; i++) {
        if (strlen(memberTrauma[i].description) > 0) {
            printf("%d. %s\n", i + 1, memberTrauma[i].nickname);
        }
    }

    printf("Select a member by number: ");
    int memberIndex;
    scanf("%d", &memberIndex);
    memberIndex--; // Adjust for 0-based index

    if (memberIndex < 0 || memberIndex >= memberCount || strlen(memberTrauma[memberIndex].description) == 0) {
        printf("Invalid selection or no trauma data available.\n");
        return;
    }

    // Select 3 random questions
    for (i = 0; i < 3; i++) {
        do {
            selectedQuestions[i] = rand() % NUM_QUESTIONS;
            // Check for duplicates
            for (j = 0; j < i; j++) {
                if (selectedQuestions[i] == selectedQuestions[j]) {
                    break;
                }
            }
        } while (j < i);
    }

    // Ask questions and record responses
    for (i = 0; i < 3; i++) {
        printf("Question %d: %s\n", counselingQuestions[selectedQuestions[i]].id,
               counselingQuestions[selectedQuestions[i]].content);
        printf("Your response (max 100 characters): ");
        getchar(); // Consume newline character left by previous scanf
        fgets(response, MAX_RESPONSE_LEN, stdin);
        response[strcspn(response, "\n")] = '\0'; // Remove newline character

        // Validate response length
        if (strlen(response) == 0 || strlen(response) > 100) {
            printf("Invalid response length. Please try again.\n");
            i--; // Retry the same question
            continue;
        }

        // Store response
        strncpy(counselingResponses[responseCount].nickname, memberTrauma[memberIndex].nickname, 50);
        counselingResponses[responseCount].question = counselingQuestions[selectedQuestions[i]];
        strncpy(counselingResponses[responseCount].response, response, MAX_RESPONSE_LEN);
        responseCount++;
    }

    printf("Counseling session completed for %s.\n", memberTrauma[memberIndex].nickname);
}
void pauseCounselingSession() {
    printf("Press Enter to resume...\n");
    getchar(); // Wait for user input to resume
}
void populateMemberData() {
    // Example data
    strcpy(memberTrauma[0].nickname, "JohnDoe");
    memberTrauma[0].age = 30;
    strcpy(memberTrauma[0].description, "");

    strcpy(memberTrauma[1].nickname, "JaneSmith");
    memberTrauma[1].age = 25;
    strcpy(memberTrauma[1].description, "");

    memberCount = 2;
}
int main() {
    populateMemberData();
    overcomeTrauma();
    return 0;
}

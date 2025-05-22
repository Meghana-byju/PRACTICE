#ifndef FITNESS_H
#define FITNESS_H

#define MAX_MEMBERS 100
#define NUM_FITNESS_TESTS 7

// Structure to store member information
typedef struct {
    char name[50];
    char nickname[50];
} Member;

// Structure to store fitness test results
typedef struct {
    char nickname[50];         // Member's nickname
    float fitness_scores[NUM_FITNESS_TESTS]; // Array to store the 7 fitness test results
} HealthData;

// Global array to store members
extern Member milliways_members[MAX_MEMBERS];
extern HealthData health_scores[MAX_MEMBERS];

// Function declarations
void setHealth(int member_index, float *fitness_scores);
void getHealth(int member_index);
void parseFitnessData(const char *input, float *fitness_scores);
int findMemberIndexByNickname(const char *nickname);

#endif

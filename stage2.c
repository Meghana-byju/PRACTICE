#include <stdio.h>
#include <string.h>

#define NUM_MEMBERS 4
#define NUM_DAYS 6

// [Type][Exercise]
const char* exercise_types[5][3] = {
    {"Running", "Cycling", "Fast Walking"},         // Cardio
    {"Push-ups", "Squats", ""},                     // Full-body
    {"Leg Press", "Leg Curl", ""},                  // Lower-body
    {"Pull-ups", "Chin-ups", ""},                   // Upper-body
    {"Plank", "Crunches", ""}                       // Core (limit: once/week)
};

// [Member][Real/Nick][Name]
char milliways_members[NUM_MEMBERS][2][50] = {
    {"Jiyeon Park", "JY"},
    {"Ethan Smith", "ES"},
    {"Helena Silva", "HS"},
    {"Liam Wilson", "LW"}
};

// [Member][Day][Exercise1, Exercise2]
char member_routine[NUM_MEMBERS][NUM_DAYS][2][50];

void displayMemberList() {
    printf("====== Milliways Members ======\n");
    for (int i = 0; i < NUM_MEMBERS; i++) {
        printf("%d. %s (%s)\n", i + 1, milliways_members[i][0], milliways_members[i][1]);
    }
}

void setExerciseRoutine() {
    displayMemberList();
    int choice;
    printf("Select member number to set routine: ");
    scanf("%d", &choice);
    if (choice < 1 || choice > NUM_MEMBERS) {
        printf("Invalid member.\n");
        return;
    }
    choice--;

    int core_used = 0;

    for (int day = 0; day < NUM_DAYS; day++) {
        printf("\nDay %d (Mon=1 ~ Sat=6)\n", day + 1);

        printf("Select a Cardio Exercise (0=Running, 1=Cycling, 2=Fast Walking): ");
        int cardio;
        scanf("%d", &cardio);
        if (cardio < 0 || cardio > 2) cardio = 0;  // default fallback
        strcpy(member_routine[choice][day][0], exercise_types[0][cardio]);

        printf("Select Strength/Core Exercise Type:\n");
        printf("1. Full-body (0=Push-ups, 1=Squats)\n");
        printf("2. Lower-body (0=Leg Press
int main() {
    int option;
    while (1) {
        printf("\n=== Milliways Routine Menu ===\n");
        printf("1. Set Workout Routine\n");
        printf("2. View Workout Routine\n");
        printf("3. Display Member List\n");
        printf("0. Exit\n");
        printf("Select: ");
        scanf("%d", &option);
        switch (option) {
            case 1: setExerciseRoutine(); break;
            case 2: getExerciseRoutine(); break;
            case 3: displayMemberList(); break;
            case 0: return 0;
            default: printf("Invalid option.\n");
        }
    }
}

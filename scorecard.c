#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CANDIDATES 6
#define NUM_CATEGORIES 5
#define MAX_NAME_LEN 50
#define MAX_JUDGES 5

// Candidate data
char candidate_names[NUM_CANDIDATES][MAX_NAME_LEN] = {
    "Jiyeon Park", "Ethan Smith", "Helena Silva",
    "Liam Wilson", "Sora Kim", "Noah Brown"
};

int candidate_ids[NUM_CANDIDATES];

// Scoring data: scoring_sheet[candidate_index][7]
int scoring_sheet[NUM_CANDIDATES][7];

// Generates non-duplicate 6-digit IDs
void generate_unique_ids() {
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        int unique = 0;
        while (!unique) {
            int id = 100000 + rand() % 900000;
            unique = 1;
            for (int j = 0; j < i; j++) {
                if (candidate_ids[j] == id) {
                    unique = 0;
                    break;
                }
            }
            if (unique) {
                candidate_ids[i] = id;
                scoring_sheet[i][0]()_

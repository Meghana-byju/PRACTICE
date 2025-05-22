#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TRAINING 8

char training_stages[MAX_TRAINING][40] = {
    "Physical Strength & Knowledge",
    "Self-Management & Teamwork",
    "Language & Pronunciation",
    "Vocal",
    "Dance",
    "Visual & Image",
    "Acting & Stage Performance",
    "Fan Communication"
};

char training_results[MAX_TRAINING]; // 'P' = passed, 'F' = failed, '\0' = not attempted

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void press_en_

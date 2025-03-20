#include <stdio.h>

// Function to convert years of experience into a 4-byte binary string
void print_binary(int num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 8 == 0) printf(" "); // Add space every 8 bits for readability
    }
}

void print_intro(char* intro) {
    // Print the introduction (automatically wrap lines after a period)
    printf("Introduction | ");
    for (int i = 0; intro[i] != '\0'; i++) {
        printf("%c", intro[i]);
        if (intro[i] == '.' && intro[i + 1] != '\0') {
            printf("\n              "); // Wrap line after a period and indent
        }
    }
    printf("\n=====================================================================\n");
}

int main() {
    // Start output
    printf("[Magrathea] \u2665\u2665 Project Member Introduction ♥♥\n");
    printf("=====================================================================\n");

    // Arthur Dent
    printf("Name  | %-15s Gender | %s\n", "Arthur Dent", "Male");
    printf("Major | %-15s Experience | ", "Mechanical Engineering");
    print_binary(15);
    printf("(15) years\n");
    printf("Role  | %-15s Skills | %s\n", "Architect", "C/C++, Java, Spring, Python, Machine Learning/Deep Learning");
    printf("---------------------------------------------------------------------\n");
    printf("Introduction | Gained experience by participating in various projects in Silicon Valley, including SNS, FinTech, HR, and Media.\n");
    printf("              I want to share the lessons learned through successes and failures with you.\n");
    printf("=====================================================================\n");

    // Kim Young-jin
    printf("Name  | %-15s Gender | %-5s\n", "Kim Young-jin", "Male");
    printf("Major | %-15s Experience | ", "Computer Science");
    print_binary(2);
    printf("(2) years\n");
    printf("Role  | %-15s Skills | %s\n", "Developer", "C#, Python, JavaScript, React, Kotlin");
    printf("---------------------------------------------------------------------\n");
    printf("Introduction | Recently, I developed a passion for software development while working on a personal asset management project using the MAUI framework.\n");
    printf("              Solving real-world problems with my code is exciting! Successfully developing Magrathea is now one of my bucket list goals.\n");
    printf("=====================================================================\n");

    // Lim Won-cheol
    printf("Name  | %-15s Gender | %-5s\n", "Lim Won-cheol", "Male");
    printf("Major | %-15s Experience | ", "Electronics Engineering");
    print_binary(1);
    printf("(1) year\n");
    printf("Role  | %-15s Skills | %s\n", "DBA", "Java, PHP, MongoDB, MS SQL, MySQL");
    printf("---------------------------------------------------------------------\n");
    printf("Introduction | I believe applications are ultimately about handling data.\n");
    printf("              I developed a strong interest in data platforms while studying a Big Data course in university.\n");
    printf("              The success of this project depends on data, and I’m already excited about working with the data in Magrathea.\n");
    printf("=====================================================================\n");

    // Yoo Go-eun
    printf("Name  | %-15s Gender | %s\n", "Yoo Go-eun", "Female");
    printf("Major | %-15s Experience | ", "Management Information Systems");
    print_binary(1);
    printf("(1) year\n");
    printf("Role  | %-15s Skills | %s\n", "Cloud Engineer", "Java, PowerShell, Azure, AWS, GCP");
    printf("---------------------------------------------------------------------\n");
    printf("Introduction | Worked on a project with Kim Young-jin, handling cloud architecture implementation.\n");
    printf("          …

typedef struct {
    char name[50];
    int is_vegan;
    char allergies[5][30]; // Up to 5 allergies
    char allowed_ingredients[10][30]; // Up to 10 allowed items
    int calorie_limit; // daily limit
} MemberDiet;
typedef struct {
    char day[10]; // "Monday", "Tuesday", etc.
    char meals[3][100]; // breakfast, lunch, dinner
    int calories[3]; // corresponding calorie count
} DailyMenu;

typedef struct {
    char member_name[50];
    DailyMenu week[7]; // Monday to Sunday
} WeeklyMenu;
printf("1. Set Diet Preferences\n");
printf("2. View Diet Preferences\n");
printf("3. Set Weekly Menu\n");
printf("4. View Weekly Menu\n");
printf("5. List Vegan Members\n");
printf("0. Exit\n");

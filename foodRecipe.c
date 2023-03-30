#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECIPES 100
#define MAX_NAME_LENGTH 50
#define MAX_INGREDIENTS 20
#define MAX_INGREDIENT_NAME_LENGTH 30
#define MAX_INSTRUCTIONS_LENGTH 500

struct Ingredient {
    char name[MAX_INGREDIENT_NAME_LENGTH];
    float amount;
    char unit[10];
};

struct Recipe {
    char name[MAX_NAME_LENGTH];
    struct Ingredient ingredients[MAX_INGREDIENTS];
    int num_ingredients;
    char instructions[MAX_INSTRUCTIONS_LENGTH];
};

int main() {
    struct Recipe recipes[MAX_RECIPES];
    int num_recipes = 0;
    
    while (1) {
        int choice;
        printf("\n1. Add recipe\n2. View recipes\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (num_recipes >= MAX_RECIPES) {
                    printf("Maximum number of recipes reached\n");
                    break;
                }
                
                printf("Enter recipe name: ");
                scanf("%s", recipes[num_recipes].name);
                
                printf("Enter number of ingredients: ");
                scanf("%d", &recipes[num_recipes].num_ingredients);
                
                printf("Enter ingredients (name, amount, unit):\n");
                for (int i = 0; i < recipes[num_recipes].num_ingredients; i++) {
                    scanf("%s %f %s", recipes[num_recipes].ingredients[i].name,
                          &recipes[num_recipes].ingredients[i].amount,
                          recipes[num_recipes].ingredients[i].unit);
                }
                
                printf("Enter instructions:\n");
                scanf(" %[^\n]s", recipes[num_recipes].instructions);
                
                num_recipes++;
                break;
                
            case 2:
                if (num_recipes == 0) {
                    printf("No recipes added yet\n");
                    break;
                }
                
                printf("\nRecipes:\n");
                for (int i = 0; i < num_recipes; i++) {
                    printf("%d. %s\n", i+1, recipes[i].name);
                }
                
                printf("\nEnter recipe number to view: ");
                int recipe_number;
                scanf("%d", &recipe_number);
                recipe_number--;
                
                printf("\n%s\n\nIngredients:\n", recipes[recipe_number].name);
                for (int i = 0; i < recipes[recipe_number].num_ingredients; i++) {
                    printf("%s %.2f %s\n", recipes[recipe_number].ingredients[i].name,
                           recipes[recipe_number].ingredients[i].amount,
                           recipes[recipe_number].ingredients[i].unit);
                }
                
                printf("\nInstructions:\n%s\n", recipes[recipe_number].instructions);
                break;
                
            case 3:
                exit(0);
                
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    
    return 0;
}

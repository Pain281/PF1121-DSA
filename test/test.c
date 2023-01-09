#include <stdio.h>
#define MAX 100

int menuUI(char **ptr, int count)
{
    int i = 0, choice;
    printf("============================================\n");
    printf("%s\n", ptr[i]);
    printf("============================================\n");
    for (i = 1; i < count; i++)
    {
        printf(" %d. %s\n", i, ptr[i]);
    }
    printf("============================================\n");
    printf(" #YOUR CHOICE: ");
    scanf("%d", &choice);
    return choice;
}

int main()
{
    char *menu[] = {"   --- VTC ACADEMY CONTACT MANAGEMENT ---", "SEARCH YOUR CONTACT", "ADD CONTACT", "DISPLAY FAVOURITES CONTACT", "DISPLAY ALL CONTACT", "EXIT APPLICATION"};
    int itemCount = sizeof(menu) / sizeof(menu[0]);
    menuUI(menu, itemCount);
    return 0;
}
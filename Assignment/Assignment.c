#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ContactInfo
{
    int id;
    char firstName[10];
    char middleName[10];
    char lastName[10];
    char company[30];
    char phone[11];
    char email[30];
    char address[30];
    char birthday[11];
    char website[30];
    char note[50];
    int status;
    struct ContactInfo *next;
} ContactInfo;

int menuUI(char **ptr, int count);
int addContactInfo(ContactInfo **head);
int searchContactInfo();
int red();
int green();
int yellow();
int black();
int resetColor();
int line();
int getAllContact(ContactInfo *head);
void getString(char *str, int length, char field[20]);
void pressEnterToContinue();
ContactInfo *SortedMerge(ContactInfo *a, ContactInfo *b);
void MergeSort(ContactInfo **headRef);
void FrontBackSplit(ContactInfo *source, ContactInfo **frontRef, ContactInfo **backRef);

int main()
{
    int mainChoice, itemCount, allContact;
    ContactInfo *head = NULL;
    ContactInfo *newContact = NULL;
    do
    {
        char *mainMenuItem[] = {"   --- VTC ACADEMY CONTACT MANAGEMENT ---", "SEARCH YOUR CONTACT", "ADD CONTACT", "DISPLAY FAVOURITES CONTACT", "DISPLAY ALL CONTACT", "EXIT APPLICATION"};
        itemCount = sizeof(mainMenuItem) / sizeof(mainMenuItem[0]);
        mainChoice = menuUI(mainMenuItem, itemCount);
        switch (mainChoice)
        {
        case 1:
            searchContactInfo();
            break;
        case 2:
            addContactInfo(&head);
            break;
        case 3:

            break;
        case 4:
            allContact = getAllContact(head);
            // printf("*Input 0 to back main menu*\n\n");
            // printf("INPUT CONTACT NO TO VIEW DETAILS: ");
            // if ()
            // {
            //     printf("true");
            // }
            // else
            // {
            //     red();
            //     printf("Please enter no between 1 - %s", allContact);
            //     resetColor();
            // }

            break;
        case 5:
            resetColor();
            break;
        default:
            break;
        }
    } while (mainChoice != 5);
    return 0;
}

int addContactInfo(ContactInfo **head)
{
    ContactInfo *newContact = (ContactInfo *)malloc(sizeof(ContactInfo));
    getString(newContact->firstName, 10, "First Name");
    getString(newContact->middleName, 10, "Middle Name");
    getString(newContact->lastName, 10, "Last Name");
    getString(newContact->company, 30, "Company");
    getString(newContact->phone, 11, "Phone");
    getString(newContact->email, 30, "Email");
    getString(newContact->address, 30, "Address");
    getString(newContact->birthday, 11, "Birthday");
    getString(newContact->website, 30, "Website");
    getString(newContact->note, 50, "Note");
    newContact->status = 0;
    newContact->next = NULL;

    if (*head == NULL)
    {
        *head = newContact;
    }
    else
    {
        newContact->next = *head;
        *head = newContact;
    }

    MergeSort(&*head);

    green();
    printf("\n Saving.. Success!\n\n");
    pressEnterToContinue();

    return 0;
}

int getAllContact(ContactInfo *head)
{
    int count = 0;
    line();
    printf("  %s  | %s\n", "ID", "NAME");
    line();
    if (head == NULL)
        return count;
    while (head != NULL)
    {
        count++;
        printf(" %3d  |", count);
        printf(" %s %s\n", head->firstName, head->lastName);
        head = head->next;
    }
    pressEnterToContinue();

    return count;
}

int searchContactInfo()
{
    return 0;
}

void MergeSort(ContactInfo **headRef)
{
    ContactInfo *head = *headRef;
    ContactInfo *a;
    ContactInfo *b;

    if ((head == NULL) || (head->next == NULL))
    {
        return;
    }

    FrontBackSplit(head, &a, &b);

    MergeSort(&a);
    MergeSort(&b);

    *headRef = SortedMerge(a, b);
}

ContactInfo *SortedMerge(ContactInfo *a, ContactInfo *b)
{
    ContactInfo *result = NULL;

    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    if (a->lastName <= b->lastName)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}

void FrontBackSplit(ContactInfo *source, ContactInfo **frontRef, ContactInfo **backRef)
{
    ContactInfo *fast;
    ContactInfo *slow;
    slow = source;
    fast = source->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

int menuUI(char **ptr, int count)
{
    int i = 0, choice;
    line();
    printf("%s\n", ptr[i]);
    line();
    for (i = 1; i < count; i++)
    {
        printf(" %d. %s\n", i, ptr[i]);
    }
    line();
    printf(" #YOUR CHOICE: ");
    scanf("%d", &choice);
    return choice;
}

int red()
{
    printf("\033[1;31m");
    return 0;
}

int green()
{
    printf("\033[0;32m");
    return 0;
}

int yellow()
{
    printf("\033[0;33m");
    return 0;
}

int black()
{
    printf("\033[0;30m");
    return 0;
}

int line()
{
    black();
    printf("============================================\n");
    resetColor();
    return 0;
}

int resetColor()
{
    printf("\033[0m");
    return 0;
}

void getString(char *str, int length, char field[20])
{
    printf(" %s: ", field);
    fflush(stdin);
    fgets(str, length, stdin);
    str[strlen(str) - 1] = '\0';
    fflush(stdin);
}

void pressEnterToContinue()
{
    yellow();
    printf(" Press Enter To Continue..");
    fflush(stdin);
    getchar();
    system("cls");
}
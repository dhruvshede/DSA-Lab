#include <stdio.h>

/* Structure declaration */
struct student
{
    char name[10];
    int roll_num;
} s[100];

/* Function to create student records */
void create(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter name: ");
        scanf("%9s", s[i].name);

        printf("Enter roll no.: ");
        scanf("%d", &s[i].roll_num);
    }
}

/* Function to display student records */
void display(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nName: %s", s[i].name);
        printf("\nRoll No.: %d\n", s[i].roll_num);
    }
}

/* Function to search student by roll number */
struct student search(int key, int n)
{
    struct student not_found = {"NotFound", -1};

    for (int i = 0; i < n; i++)
    {
        if (key == s[i].roll_num)
        {
            printf("\nYes, the selected element is present.\n");
            return s[i];
        }
    }

    printf("\nRoll number not found.\n");
    return not_found;
}

/* Main function */
int main()
{
    struct student result;

    create(3);
    display(3);

    result = search(2, 3);

    if (result.roll_num != -1)
    {
        printf("Name: %s\n", result.name);
        printf("Roll No.: %d\n", result.roll_num);
    }

    return 0;
}
```

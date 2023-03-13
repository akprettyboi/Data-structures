/******************************************************************************

                         student database using a circular single linked list
( little problems in delete function)
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_ID_LEN 15
#define MAX_STUDENTS 100

struct student {
    char name[MAX_NAME_LEN];
    char id[MAX_ID_LEN];
    struct student *next;
};

// Prototypes for functions
void display_students(struct student *head);
void display_students_reverse(struct student *head);
void insert_student(struct student **head, struct student *new_student, int position);
void delete_student(struct student **head, char *id);
struct student *create_student(char *name, char *id);

int main(void) {
    // Initialize the student database
    struct student *database = NULL;

    // Loop until the user chooses to exit
    int choice = 0;
    while (choice != 5) {
        printf("\nMenu:\n");
        printf("1. Display all students\n");
        printf("2. Display students in reverse order\n");
        printf("3. Insert new student\n");
        printf("4. Delete student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Display all students
                display_students(database);
                break;
            case 2:
                // Display students in reverse order
                display_students_reverse(database);
                break;
            case 3:
                // Insert new student
                printf("Enter student name: ");
                char name[MAX_NAME_LEN];
                scanf("%s", name);

                printf("Enter student ID: ");
                char id[MAX_ID_LEN];
                scanf("%s", id);

                printf("Enter position to insert (1 for first, 2 for second, etc.): ");
                int position;
                scanf("%d", &position);

                struct student *new_student = create_student(name, id);
                insert_student(&database, new_student, position);

                // If the list was previously empty, set the first student's next pointer to point back to itself
                if (database->next == NULL) {
                    database->next = database;
                }
                break;
            case 4:
                // Delete student
                printf("Enter student ID to delete: ");
                char delete_id[MAX_ID_LEN];
                scanf("%s", delete_id);
                delete_student(&database, delete_id);
                break;
            case 5:
                // Exit
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}

// Display all students
void display_students(struct student *head) {
    if (head == NULL) {
        printf("No students in database\n");
        return;
    }

    struct student *current = head;
    do {        printf("Name: %s\n", current->name);
        printf("ID: %s\n", current->id);
        current = current->next;
    } while (current != head);
}

// Display students in reverse order using a single linked list
void display_students_reverse(struct student *head) {
    if (head == NULL) {
        printf("No students in database\n");
        return;
    }

    // Create a temporary array to store the students
    struct student *temp[MAX_STUDENTS];
    int i = 0;

    // Iterate through the list and store the students in the array
    struct student *current = head;
    do {
        temp[i++] = current;
        current = current->next;
    } while (current != head);

    // Print the students in reverse order
    for (int j = i-1; j >= 0; j--) {
        printf("Name: %s\n", temp[j]->name);
        printf("ID: %s\n", temp[j]->id);
    }
}

// Insert a new student into the list
void insert_student(struct student **head, struct student *new_student, int position) {
    // If the list is empty, insert the new student as the head
    if (*head == NULL) {
        *head = new_student;
        new_student->next = new_student;
        return;
    }

    // If the position is 1, insert the new student as the head
    if (position == 1) {
        new_student->next = *head;
        *head = new_student;
        return;
    }

    // Find the student at the specified position
    struct student *current = *head;
    int i = 2;
    while (i < position && current->next != *head) {
        current = current->next;
        i++;
    }

    // Insert the new student after the current student
    new_student->next = current->next;
    current->next = new_student;
}


void delete_student(struct student **head, char *id) {
    // If the list is empty, do nothing
    if (*head == NULL) {
        return;
    }

    // Find the student to be deleted
    struct student *current = *head;
    while (current->next != *head && strcmp(current->next->id, id) != 0) {
        current = current->next;
    }

    // If the student was not found, do nothing
    if (current->next == *head) {
        return;
    }

    // If the student to be deleted is the head, update the head
    if (strcmp((*head)->id, id) == 0) {
        *head = (*head)->next;
    }

    // Delete the student
    struct student *temp = current->next;
    current->next = temp->next;
    free(temp);

    // If the list is now empty, set the head to NULL
    if (*head == current) {
        *head = NULL;
    }
}




// Create a new student
// Create a new student
struct student *create_student(char *name, char *id) {
    struct student *new_student = (struct student *)malloc(sizeof(struct student));
    strcpy(new_student->name, name);
    strcpy(new_student->id, id);
    new_student->next = NULL;
    return new_student;
}


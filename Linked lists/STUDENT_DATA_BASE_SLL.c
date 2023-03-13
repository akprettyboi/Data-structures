/******************************************************************************

                         student database using single linked list

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
    while (current != NULL) {
        printf("Name: %s\n", current->name);
        printf("ID: %s\n", current->id);
        current = current->next;
    }
}

/* Display students in reverse order using DLL
void display_students_reverse(struct student *head) {
if (head == NULL) {
printf("No students in database\n");
return;
}
// First, get a pointer to the last student in the list
struct student *current = head;
while (current->next != NULL) {
    current = current->next;
}

// Then, iterate through the list backwards and print the students
while (current != NULL) {
    printf("Name: %s\n", current->name);
    printf("ID: %s\n", current->id);
    current = current->prev;
}
}
*/


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
    while (current != NULL) {
        temp[i++] = current;
        current = current->next;
    }

    // Print the students in reverse order
    for (int j = i-1; j >= 0; j--) {
        printf("Name: %s\n", temp[j]->name);
        printf("ID: %s\n", temp[j]->id);
    }
}


// Insert a new student at the specified position
void insert_student(struct student **head, struct student *new_student, int position) {
if (*head == NULL) {
// If the list is empty, the new student becomes the head
*head = new_student;
return;
}
int i = 1;
struct student *current = *head;
while (i < position-1 && current->next != NULL) {
    current = current->next;
    i++;
}

// Insert the new student
new_student->next = current->next;
current->next = new_student;
}

// Delete a student with the specified ID
void delete_student(struct student **head, char *id) {
if (*head == NULL) {
printf("No students in database\n");
return;
}
struct student *current = *head;
if (strcmp(current->id, id) == 0) {
    // If the student to delete is the first in the list, update the head
    *head = current->next;
    free(current);
    return;
}

while (current->next != NULL && strcmp(current->next->id, id) != 0) {
    current = current->next;
}

if (current->next == NULL) {
    printf("Student with ID %s not found\n", id);
    return;
}

// Delete the student
struct student *temp = current->next;
current->next = temp->next;
free(temp);
}

// Create a new student with the specified name and ID
struct student *create_student(char *name, char *id) {
struct student *new_student = malloc(sizeof(struct student));
strcpy(new_student->name, name);
strcpy(new_student->id, id);
new_student->next = NULL;
return new_student;
}

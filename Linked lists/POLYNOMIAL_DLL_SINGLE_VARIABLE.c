/******************************************************************************
single variable polynomials using Double linked list ( BETTER CODE THAN ASSINGMENT)

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// Define a node for the double linked list
struct Node {
  int coefficient;
  int exponent;
  struct Node *prev;
  struct Node *next;
};

// Function prototypes
void AcceptPolynomial(struct Node **);
void DisplayPolynomial(struct Node *);
void AddPolynomials(struct Node *, struct Node *, struct Node **);
void MultiplyPolynomials(struct Node *, struct Node *, struct Node **);

int main() {
  int choice, choice1;
  struct Node *poly1 = NULL, *poly2 = NULL, *result = NULL;

  while (1) {
    printf("\nMenu:\n");
    printf("1. Accept  polynomials\n");
    printf("2. Display a polynomial\n");
    printf("3. Add two polynomials\n");
    printf("4. Multiply two polynomials\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter first polynomial:\n");
        AcceptPolynomial(&poly1);
        printf("Enter Second polynomial:\n");
        AcceptPolynomial(&poly2);
        break;
      case 2:
        do {
          printf("Enter the polynomial to display:\n");
          printf("1. First polynomial\n");
          printf("2. Second polynomial\n");
          printf("3. Back to main menu\n");
          scanf("%d", &choice1);
          switch (choice1) {
            case 1:
              DisplayPolynomial(poly1);
              break;
            case 2:
              DisplayPolynomial(poly2);
              break;
            case 3:
              break;
            default:
              printf("Invalid choice\n");
              break;
          }
        } while (choice1 != 3);
        break;
      case 3:
        printf("Adding the polynomials...\n");
        AddPolynomials(poly1, poly2, &result);
        printf("Result:\n");
        DisplayPolynomial(result);
        break;
      case 4:
        printf("Multiplying the polynomials...\n");
        MultiplyPolynomials(poly1, poly2, &result);
        printf("Result:\n");
        DisplayPolynomial(result);
        break;
      case 5:
        printf("Exiting...\n");
        exit(0);
      default:
        printf("Invalid choice\n");
        break;
    }
  }
}

//Here is the modified version of the AcceptPolynomial function that uses a double linked list:

void AcceptPolynomial(struct Node **poly) {
  int coefficient, exponent;
  struct Node *temp, *last = *poly;

  printf("Enter coefficient and exponent (enter 0 0 to end): ");
  scanf("%d%d", &coefficient, &exponent);

  while (coefficient != 0 || exponent != 0) {
    temp = (struct Node *) malloc(sizeof(struct Node));
    temp->coefficient = coefficient;
    temp->exponent = exponent;
    temp->prev = NULL;
    temp->next = NULL;
    if (*poly == NULL) {
      *poly = temp;
    } else {
      last->next = temp;
      temp->prev = last;
    }
    last = temp;

    printf("Enter coefficient and exponent (enter 0 0 to end): ");
    scanf("%d%d", &coefficient, &exponent);
  }
}

//Here is the modified version of the DisplayPolynomial function that uses a double linked list:

void DisplayPolynomial(struct Node *poly) {
  while (poly != NULL) {
    printf("%dx^%d ", poly->coefficient, poly->exponent);
    poly = poly->next;
    if (poly != NULL) {
      printf("+ ");
    }
  }
  printf("\n");
}

//Here is the modified version of the AddPolynomials function that uses a double linked list:

void AddPolynomials(struct Node *poly1, struct Node *poly2, struct Node **result) {
  struct Node *temp, *last = *result;

  while (poly1 != NULL && poly2 != NULL) {
    if (poly1->exponent > poly2->exponent) {
      temp = (struct Node *) malloc(sizeof(struct Node));
      temp->coefficient = poly1->coefficient;
      temp->exponent = poly1->exponent;
      temp->prev = NULL;
      temp->next = NULL;
      if (*result == NULL) {
        *result = temp;
      } else {
        last->next = temp;
        temp->prev = last;
      }
      last = temp;
      poly1 = poly1->next;
    } else if (poly1->exponent < poly2->exponent) {
      temp = (struct Node *) malloc(sizeof(struct Node));
      temp->coefficient = poly2->coefficient;
      temp->exponent = poly2->exponent;
      temp->prev = NULL;
      temp->next = NULL;
      if (*result == NULL) {
        *result = temp;
      } else {
        last->next = temp;
        temp->prev = last;
      }
      last = temp;
      poly2 = poly2->next;
    } else {
      temp = (struct Node *) malloc(sizeof(struct Node));
      temp->coefficient = poly1->coefficient + poly2->coefficient;
      temp->exponent = poly1->exponent;
      temp->prev = NULL;
      temp->next = NULL;
      if (*result == NULL) {
        *result = temp;
      } else {
        last->next = temp;
        temp->prev = last;
      }
      last = temp;
      poly1 = poly1->next;
      poly2 = poly2->next;
    }
  }

  while (poly1 != NULL) {
    temp = (struct Node *) malloc(sizeof(struct Node));
    temp->coefficient = poly1->coefficient;
    temp->exponent = poly1->exponent;
    temp->prev = NULL;
    temp->next = NULL;
    if (*result == NULL) {
      *result = temp;
    } else {
      last->next = temp;
      temp->prev = last;
    }
    last = temp;
    poly1 = poly1->next;
  }

  while (poly2 != NULL) {
    temp = (struct Node *) malloc(sizeof(struct Node));
    temp->coefficient = poly2->coefficient;
    temp->exponent = poly2->exponent;
    temp->prev = NULL;
    temp->next = NULL;
    if (*result == NULL) {
      *result = temp;
    } else {
      last->next = temp;
      temp->prev = last;
    }
    last = temp;
    poly2 = poly2->next;
  }
}

//here is the modified version of the MultiplyPolynomials function that uses a double linked list:

void MultiplyPolynomials(struct Node *poly1, struct Node *poly2, struct Node **result) {
  *result = NULL;  // Initialize result to an empty list
  struct Node *temp, *last = *result;

  while (poly1 != NULL) {
    poly2 = *result;
    while (poly2 != NULL) {
      temp = (struct Node *) malloc(sizeof(struct Node));
      temp->coefficient = poly1->coefficient * poly2->coefficient;
      temp->exponent = poly1->exponent + poly2->exponent;
      temp->prev = NULL;
      temp->next = NULL;
      if (*result == NULL) {
        *result = temp;
      } else {
        last->next = temp;
        temp->prev = last;
      }
      last = temp;
      poly2 = poly2->next;
    }
    poly1 = poly1->next;
  }
}






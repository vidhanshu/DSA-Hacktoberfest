#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int power; // power of polynomial
    int cf;    // coeffecient
    struct Node* next;
};

void display(struct Node* ptr)
{
    printf("%dx^%d", ptr->cf, ptr->power);
    ptr = ptr->next;
    while (ptr != NULL)
    {
        printf(" + %dx^%d", ptr->cf, ptr->power);
        ptr = ptr->next;
    }
    printf("\n");
}

struct Node* init(int power, int cf)
{
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));

    p->power = power;
    p->cf = cf;
    p->next = NULL;

    return p;
}

struct Node* insertEnd(struct Node* head, int power, int cf)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = ptr;

    ptr->power = power;
    ptr->cf = cf;
    ptr->next = NULL;

    return head;
}

struct Node* deleteFirst(struct Node* head)
{
    struct Node* p;
    p = head->next;
    free(head);
    return p;
}

struct Node* get_poly(struct Node* p, int a, int deg)
{

    for (int i = 0; i < deg + 1; i++)
    {
        int cf;

        if (i > a)
        {
            p = insertEnd(p, i, 0);
        }
        else
        {

            printf("Enter coefficient of %d\n", i);
            scanf("%d", &cf);

            if (i == 0)
            {
                p = init(i, cf);
            }

            else
            {
                p = insertEnd(p, i, cf);
            }
        }
    }
    return p;
}

struct Node* add(struct Node* p1, struct Node* p2)
{
    struct Node* sum;

    int cf = p1->cf + p2->cf;

    sum = init(p1->power, cf);

    p1 = p1->next;
    p2 = p2->next;

    while (p1 != NULL)
    {
        // sum->cf = p1->cf + p2->cf;
        // sum->power = p1->power;

        cf = p1->cf + p2->cf;
        sum = insertEnd(sum, p1->power, cf);

        p1 = p1->next;
        p2 = p2->next;
    }

    return sum;
}

struct Node* sort(struct Node* p, int deg)
{
    struct Node* res;

    res = (struct Node*)malloc(sizeof(struct Node));
    res = init(0, 0);

    for (int i = 0; i < deg + 1; i++)
    {

        struct Node* temp = p;
        int cf = 0;
        while (temp != NULL)
        {

            if (temp->power == i)
            {
                cf += temp->cf;
            }

            temp = temp->next;
        }
        res = insertEnd(res, i, cf);
    }
    res = deleteFirst(res);
    return res;
}

struct Node* multiply(struct Node* p1, struct Node* p2, int deg)
{
    struct Node* product = (struct Node*)malloc(sizeof(struct Node));
    struct Node* result = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = p2;

    int cf;
    int power;

    while (p1 != NULL)
    {
        temp = p2;
        while (temp != NULL)
        {
            cf = p1->cf * temp->cf;          // product of two coeffecients
            power = p1->power + temp->power; // product of powers
            // printf("Power%d :%d x %d = %d\n",power,p1->cf,temp->cf,cf);
            product = insertEnd(product, power, cf);

            temp = temp->next;
        }
        p1 = p1->next;
    }

    deleteFirst(product); // Delete the first empty node

    result = sort(product, deg);

    return result;
}

int max(int a, int b)
{
    return (a >= b) ? a : b;
}

int main()
{
    struct Node* p1;
    struct Node* p2;
    struct Node* sum;
    struct Node* result;

    int a, b, deg;

    // Enter degree of polynomial p1
    printf("Enter degree of polynomial p1\n");
    scanf("%d", &a);

    // Enter degree of polynomial p2
    printf("Enter degree of polynomial p2\n");
    scanf("%d", &b);

    deg = max(a, b);

    // Enter coefficients of p1
    printf("Enter coefficients of p1\n");

    p1 = get_poly(p1, a, deg);
    display(p1);

    // Enter coefficients of p2
    printf("Enter coefficients of p2\n");

    p2 = get_poly(p2, b, deg);
    display(p2);

    int choice;

    printf("\nPress:\n1 for Addition\n2 for Multiplication\n");
    scanf("%d", &choice);

    if (choice == 1)
    {
        // add two polynomials
        printf("Sum of p1 and p2\n");

        sum = add(p1, p2);
        display(sum);
    }
    else if (choice == 2)
    {
        // multiply two polynomials
        printf("Product of p1 and p2\n");

        result = multiply(p1, p2, a + b);
        display(result);
    }

    return 0;
}
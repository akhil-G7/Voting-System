#include <stdio.h>
#include <stdlib.h>

// Define a structure for a linked list node
struct Node {
    int data;
    struct Node *next;
}; 

// Global variable to represent the vote count
int vote = 0;

// Function to calculate the length of a linked list
int length(struct Node *head) {
    if (head == NULL) {
        return 0;
    } else {
        int count = 0;
        while (head != NULL) {
            count += 1;
            head = head->next;
        }
        return count;
    }
}

// Function to delete the first node of a linked list
struct Node *del(struct Node *head) {
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// Function to add a new node at the beginning of a linked list
struct Node *add(struct Node *head) {
    if (head == NULL) {
        // If the list is empty, create a new head node
        struct Node *head = (struct Node *)malloc(sizeof(struct Node));
        head->data = vote;
        head->next = NULL;
        return head;
    } else {
        // If the list is not empty, add a new node at the beginning
        struct Node *ptr = head;
        struct Node *p = (struct Node *)malloc(sizeof(struct Node));
        p->data = vote;
        p->next = head;
        return p;
    }
}

// Function to determine the winner of the elections
void won(struct Node *trs, struct Node *bjp, struct Node *congress, struct Node *aimim, struct Node *nota) {
    int a, b, c, d, e;
    a = length(trs);
    b = length(bjp);
    c = length(congress);
    d = length(aimim);
    e = length(nota);

    if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0) {
        printf("NOTA won the elections\n");
    } else {
        if (a > b && a > c && a > d && a > e) {
            printf("TRS won the elections\n");
        } else if (b > a && b > c && b > d && b > e) {
            printf("BJP won the elections\n");
        } else if (c > a && c > b && c > d && c > e) {
            printf("CONGRESS won the elections\n");
        } else if (d > a && d > b && d > c && d > e) {
            printf("AIMIM won the elections\n");
        } else if (e > a && e > b && e > c && e > d) {
            printf("NOTA won the elections\n");
        } else {
            printf("tie voting\n");
        }

        printf("number of votes for TRS is %d\n", a);
        printf("number of votes for BJP is %d\n", b);
        printf("number of votes for CONGRESS is %d\n", c);
        printf("number of votes for AIMIM is %d\n", d);
        printf("number of votes for NOTA is %d\n", e);
    }
} 

// Function to display the current leader
void result(struct Node *trs, struct Node *bjp, struct Node *congress, struct Node *aimim, struct Node *nota) {
    int a, b, c, d, e;
    a = length(trs);
    b = length(bjp);
    c = length(congress);
    d = length(aimim);
    e = length(nota);

    if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0) {
        printf("no vote is casted yet\n");
    } else {
        if (a >= b && a >= c && a >= d && a >= e) {
            printf("TRS is leading\n");
        } else if (b >= a && b >= c && b >= d && b >= e) {
            printf("BJP is leading\n");
        } else if (c >= a && c >= b && c >= d && c >= e) {
            printf("CONGRESS is leading\n");
        } else if (d >= a && d >= b && d >= c && d >= e) {
            printf("AIMIM is leading\n");
        } else if (e >= a && e >= b && e >= c && e >= d) {
            printf("NOTA is leading\n");
        }
    }
}

int main() {
    // Declare linked lists for each party
    struct Node *trs = NULL;
    struct Node *bjp = NULL;
    struct Node *congress = NULL;
    struct Node *aimim = NULL;
    struct Node *nota = NULL;

    int ch, num;

    // Menu-driven voting machine
    while (1) {
        printf("**** Voting Machine ****\n");
        printf("1.TRS\n");
        printf("2.BJP\n");
        printf("3.CONGRESS\n");
        printf("4.AIMIM\n");
        printf("5.NOTA\n");
        printf("6.RESULT\n");
        printf("7.EXIT\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                trs = add(trs);
                // To clear the screen
                system("cls");
                break;
            case 2:
                bjp = add(bjp);
                system("cls");
                break;
            case 3:
                congress = add(congress);
                system("cls");
                break;
            case 4:
                aimim = add(aimim);
                system("cls");
                break;
            case 5:
                nota = add(nota);
                system("cls");
                break;
            case 6:
                result(trs, bjp, congress, aimim, nota);
                break;
            case 7:
                won(trs, bjp, congress, aimim, nota);
                exit(0);
                break;
            default:
                printf("invalid input\n");
        }
    }
}
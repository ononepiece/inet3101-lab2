#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int part_number;
    char part_name[50];
    float part_size;
    char part_size_metric[5];
    float part_cost;
} Part;

// Function to add a new record
void add_record(Part **database, int *num_records) {
    Part *new_database = malloc((*num_records + 1) * sizeof(Part));  // Allocate memory for one more record

    if (new_database == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Copy old records to the new database
    for (int i = 0; i < *num_records; i++) {
        *(new_database + i) = *(*database + i);  // Pointer arithmetic
    }

    // Add new record
    printf("Enter part number: ");
    scanf("%d", &new_database[*num_records].part_number);
    printf("Enter part name: ");
    scanf("%s", new_database[*num_records].part_name);
    printf("Enter part size: ");
    scanf("%f", &new_database[*num_records].part_size);
    printf("Enter part size metric: ");
    scanf("%s", new_database[*num_records].part_size_metric);
    printf("Enter part cost: ");
    scanf("%f", &new_database[*num_records].part_cost);

    // Free the old database and set the new one
    free(*database);
    *database = new_database;
    (*num_records)++;
}

// Func that delete the last record
void delete_record(Part **database, int *num_records) {
    if (*num_records == 0) {
        printf("No records to delete.\n");
        return;
    }

    Part *new_database = malloc((*num_records - 1) * sizeof(Part));  // Allocate memory for one less record

    if (new_database == NULL && *num_records > 1) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Copy old records except the last one
    for (int i = 0; i < *num_records - 1; i++) {  // Stop before last element
        *(new_database + i) = *(*database + i);
    }

    // Free the old database and set the new one
    free(*database);
    *database = new_database;
    (*num_records)--;
}




// Func that print all records
void print_records(Part *database, int num_records) {
    if (num_records == 0) {
        printf("No records to print.\n");
        return;
    }

    for (int i = 0; i < num_records; i++) {
        printf("Part %d: %s, %.2f %s, Cost: %.2f\n", 
               database[i].part_number, 
               database[i].part_name, 
               database[i].part_size, 
               database[i].part_size_metric, 
               database[i].part_cost);
    }
}

// Func that print the number of records
void print_number_of_records(int num_records) {
    printf("Number of records: %d\n", num_records);
}

// Func that print the size of the database
void print_size_of_database(int num_records) {
    printf("Size of database: %lu bytes\n", num_records * sizeof(Part));
}

// Func that print the number of accesses to the database
void print_access_count(int access_count) {
    printf("Database accessed %d times\n", access_count);
}






// Main menu and program logic
int main() {
    Part *database = NULL;
    int num_records = 0;
    int access_count = 0;
    int choice;

    while (1) {
        printf("\nMENU\n");
        printf("1. Print all records\n");
        printf("2. Print number of records\n");
        printf("3. Print size of database\n");
        printf("4. Add record\n");
        printf("5. Delete record\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                print_records(database, num_records);
                access_count++;
                break;
            case 2:
                print_number_of_records(num_records);
                access_count++;
                break;
            case 3:
                print_size_of_database(num_records);
                access_count++;
                break;
            case 4:
                add_record(&database, &num_records);
                access_count++;
                break;
            case 5:
                delete_record(&database, &num_records);
                access_count++;
                break;
            case 6:
                free(database);  // Free allocated memory
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
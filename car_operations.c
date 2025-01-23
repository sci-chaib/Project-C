#include <stdio.h>
#include <string.h>
#include "car_operations.h"

// Utility function to remove newline from string
void trimNewline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

void addCar(Car *cars, int *carCount) {
    printf("\nAdding a new car:\n");

    Car *newCar = &cars[*carCount];

    printf("Enter Car ID: ");
    scanf("%d", &newCar->ID);

    printf("Enter Car Marque: ");
    getchar(); // Consume newline
    fgets(newCar->Marque, sizeof(newCar->Marque), stdin);
    trimNewline(newCar->Marque);

    printf("Enter Car Model: ");
    fgets(newCar->Model, sizeof(newCar->Model), stdin);
    trimNewline(newCar->Model);

    printf("Enter Carburetor Type: ");
    fgets(newCar->CarburetorType, sizeof(newCar->CarburetorType), stdin);
    trimNewline(newCar->CarburetorType);

    printf("Enter Number of Places: ");
    scanf("%d", &newCar->NumberOfPlaces);

    printf("Enter Transmission (A for Automatic, M for Manual): ");
    getchar();
    scanf("%c", &newCar->Transmission);

    printf("Enter Price Per Day: ");
    scanf("%f", &newCar->PricePerDay);

    newCar->Availability = 1;
    newCar->RentedDays = 0;

    (*carCount)++;
    saveAllCarsToFile(cars, *carCount);
    printf("Car added successfully!\n\n");
}

void displayCars(const Car *cars, int carCount) {
    if (carCount == 0) {
        printf("No cars available to display.\n\n");
        return;
    }

    printf("\nDisplaying all cars:\n");
    for (int i = 0; i < carCount; i++) {
        printf("Car ID: %d\n", cars[i].ID);
        printf("Marque: %s\n", cars[i].Marque);
        printf("Model: %s\n", cars[i].Model);
        printf("Carburetor Type: %s\n", cars[i].CarburetorType);
        printf("Number of Places: %d\n", cars[i].NumberOfPlaces);
        printf("Transmission: %c\n", cars[i].Transmission);
        printf("Price Per Day: %.2f\n", cars[i].PricePerDay);
        printf("Availability: %s\n", cars[i].Availability ? "Available" : "Not Available");
        printf("Rented Days: %d\n", cars[i].RentedDays);
        printf("Total Income: %.2f\n\n", cars[i].RentedDays * cars[i].PricePerDay);
    }
}

void loadCars(Car *cars, int *carCount) {
    FILE *file = fopen("car_data.csv", "r");
    if (!file) {
        printf("No existing car data found.\n\n");
        return;
    }

    while (fscanf(file, "%d,%[^,],%[^,],%[^,],%d,%c,%f,%d,%d\n",
                  &cars[*carCount].ID, cars[*carCount].Marque, cars[*carCount].Model,
                  cars[*carCount].CarburetorType, &cars[*carCount].NumberOfPlaces,
                  &cars[*carCount].Transmission, &cars[*carCount].PricePerDay,
                  &cars[*carCount].Availability, &cars[*carCount].RentedDays) == 9) {
        (*carCount)++;
    }
    fclose(file);
    printf("Loaded %d cars from file.\n\n", *carCount);
}

void saveAllCarsToFile(const Car *cars, int carCount) {
    FILE *file = fopen("car_data.csv", "w");
    if (!file) {
        printf("Error saving data to file.\n");
        return;
    }

    for (int i = 0; i < carCount; i++) {
        fprintf(file, "%d,%s,%s,%s,%d,%c,%.2f,%d,%d\n",
                cars[i].ID, cars[i].Marque, cars[i].Model, cars[i].CarburetorType,
                cars[i].NumberOfPlaces, cars[i].Transmission, cars[i].PricePerDay,
                cars[i].Availability, cars[i].RentedDays);
    }

    fclose(file);
    printf("Data saved successfully.\n");
}


void rentCar(Car *cars, int carCount) {
    int carID, days;
    printf("Enter the ID of the car to rent: ");
    scanf("%d", &carID);

    Car *car = NULL;
    for (int i = 0; i < carCount; i++) {
        if (cars[i].ID == carID) {
            car = &cars[i];
            break;
        }
    }

    if (!car) {
        printf("Car with ID %d not found.\n", carID);
        return;
    }

    if (!car->Availability) {
        printf("Car with ID %d is not available for rent.\n", carID);
        return;
    }

    printf("Enter the number of days to rent the car: ");
    scanf("%d", &days);

    car->RentedDays += days;
    car->Availability = 0; // Mark as not available
    saveAllCarsToFile(cars, carCount);

    printf("Car rented successfully for %d days. Total income generated: %.2f\n", days, days * car->PricePerDay);
}


void editCar(Car *cars, int carCount) {
    int carID;
    printf("Enter the ID of the car to edit: ");
    scanf("%d", &carID);

    Car *car = NULL;
    for (int i = 0; i < carCount; i++) {
        if (cars[i].ID == carID) {
            car = &cars[i];
            break;
        }
    }

    if (!car) {
        printf("Car with ID %d not found.\n", carID);
        return;
    }

    printf("Editing car ID %d:\n", carID);
    printf("Enter new Marque: ");
    getchar();
    fgets(car->Marque, sizeof(car->Marque), stdin);
    trimNewline(car->Marque);

    printf("Enter new Model: ");
    fgets(car->Model, sizeof(car->Model), stdin);
    trimNewline(car->Model);

    printf("Enter new Carburetor Type: ");
    fgets(car->CarburetorType, sizeof(car->CarburetorType), stdin);
    trimNewline(car->CarburetorType);

    printf("Enter new Number of Places: ");
    scanf("%d", &car->NumberOfPlaces);

    printf("Enter new Transmission (A for Automatic, M for Manual): ");
    getchar();
    scanf("%c", &car->Transmission);

    printf("Enter new Price Per Day: ");
    scanf("%f", &car->PricePerDay);

    saveAllCarsToFile(cars, carCount);
    printf("Car updated successfully!\n");
}

void deleteCar(Car *cars, int *carCount) {
    int carID;
    printf("Enter the ID of the car to delete: ");
    scanf("%d", &carID);

    int index = -1;
    for (int i = 0; i < *carCount; i++) {
        if (cars[i].ID == carID) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Car with ID %d not found.\n", carID);
        return;
    }

    for (int i = index; i < *carCount - 1; i++) {
        cars[i] = cars[i + 1];
    }
    (*carCount)--;
    saveAllCarsToFile(cars, *carCount);
    printf("Car deleted successfully!\n");
}

void sortCars(Car *cars, int *carCount) {
    int choice;
    printf("\nSort by:\n");
    printf("1. Marque\n");
    printf("2. Availability (1 for Available, 0 for Not Available)\n");
    printf("3. Income (Descending)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    for (int i = 0; i < *carCount - 1; i++) {
        for (int j = i + 1; j < *carCount; j++) {
            int swap = 0;
            if (choice == 1 && strcmp(cars[i].Marque, cars[j].Marque) > 0) {
                swap = 1; // Sort by Marque (alphabetically)
            } else if (choice == 2 && cars[i].Availability < cars[j].Availability) {
                swap = 1; // Sort by Availability
            } else if (choice == 3 && 
                       (cars[i].RentedDays * cars[i].PricePerDay) < (cars[j].RentedDays * cars[j].PricePerDay)) {
                swap = 1; // Sort by Income (Descending)
            }

            if (swap) {
                Car temp = cars[i];
                cars[i] = cars[j];
                cars[j] = temp;
            }
        }
    }

    if (choice == 1) {
        printf("Cars sorted by Marque.\n");
    } else if (choice == 2) {
        printf("Cars sorted by Availability.\n");
    } else if (choice == 3) {
        printf("Cars sorted by Income (Descending).\n");
    } else {
        printf("Invalid choice. Exiting sort.\n");
    }
}


void searchCars(Car *cars, int *carCount) {
    int choice;
    printf("\nSearch by:\n");
    printf("1. Marque\n");
    printf("2. Availability (1 for Available, 0 for Not Available)\n");
    printf("3. Income Threshold\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        char searchMarque[50];
        printf("Enter Marque to search: ");
        getchar(); // Consume the newline character
        fgets(searchMarque, sizeof(searchMarque), stdin);
        searchMarque[strcspn(searchMarque, "\n")] = '\0';

        printf("\nCars with Marque '%s':\n", searchMarque);
        int found = 0;
        for (int i = 0; i < *carCount; i++) {
            if (strcmp(cars[i].Marque, searchMarque) == 0) {
                found = 1;
                printf("Car ID: %d, Model: %s, Availability: %s, Income: %.2f\n", 
                    cars[i].ID, cars[i].Model, 
                    cars[i].Availability ? "Available" : "Not Available", 
                    cars[i].RentedDays * cars[i].PricePerDay);
            }
        }
        if (!found) {
            printf("No cars found with the given Marque.\n");
        }
    } else if (choice == 2) {
        int searchAvailability;
        printf("Enter Availability to search (1 for Available, 0 for Not Available): ");
        scanf("%d", &searchAvailability);

        printf("\nCars with Availability %d:\n", searchAvailability);
        int found = 0;
        for (int i = 0; i < *carCount; i++) {
            if (cars[i].Availability == searchAvailability) {
                found = 1;
                printf("Car ID: %d, Marque: %s, Model: %s, Income: %.2f\n", 
                    cars[i].ID, cars[i].Marque, cars[i].Model, 
                    cars[i].RentedDays * cars[i].PricePerDay);
            }
        }
        if (!found) {
            printf("No cars found with the given Availability.\n");
        }
    } else if (choice == 3) {
        float threshold;
        printf("Enter Income Threshold: ");
        scanf("%f", &threshold);

        printf("\nCars with Income >= %.2f:\n", threshold);
        int found = 0;
        for (int i = 0; i < *carCount; i++) {
            float income = cars[i].RentedDays * cars[i].PricePerDay;
            if (income >= threshold) {
                found = 1;
                printf("Car ID: %d, Marque: %s, Model: %s, Income: %.2f\n", 
                    cars[i].ID, cars[i].Marque, cars[i].Model, income);
            }
        }
        if (!found) {
            printf("No cars found meeting the income threshold.\n");
        }
    } else {
        printf("Invalid choice. Exiting search.\n");
    }
}

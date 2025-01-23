#include <stdio.h>
#include "car_operations.h"

int main() {
    Car cars[100];
    int carCount = 0;

    loadCars(cars, &carCount);

    int choice;
    do {
        printf("\nCar Rental System Menu:\n");
        printf("1. Add Car\n");
        printf("2. Display Cars\n");
        printf("3. Rent a Car\n");
        printf("4. Edit Car\n");
        printf("5. Delete Car\n");
        printf("6. Search cars\n");
        printf("7. Sort cars\n");
        printf("8. Save and Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addCar(cars, &carCount); break;
            case 2: displayCars(cars, carCount); break;
            case 3: rentCar(cars, carCount); break;
            case 4: editCar(cars, carCount); break;
            case 5: deleteCar(cars, &carCount); break;
            case 6: searchCars(cars, &carCount); break;
            case 7: sortCars(cars, &carCount); break;
            case 8: saveAllCarsToFile(cars, carCount); printf("Exiting...\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}


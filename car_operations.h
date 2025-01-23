#ifndef CAR_OPERATIONS_H
#define CAR_OPERATIONS_H

#include "car.h"

// Function prototypes
void addCar(Car *cars, int *carCount);
void displayCars(const Car *cars, int carCount);
void loadCars(Car *cars, int *carCount);
void rentCar(Car *cars, int carCount);
void editCar(Car *cars, int carCount);
void deleteCar(Car *cars, int *carCount);
void saveAllCarsToFile(const Car *cars, int carCount);
void searchCars(Car *cars, int *carCount);
void sortCars(Car *cars, int *carCount);
void trimNewline(char *str);

#endif


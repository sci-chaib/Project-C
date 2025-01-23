#ifndef CAR_H
#define CAR_H

// Define the structure for a car
typedef struct {
    int ID;
    char Marque[50];
    char Model[50];
    char CarburetorType[20];
    int NumberOfPlaces;
    char Transmission; // 'A' for Automatic, 'M' for Manual
    float PricePerDay;
    int Availability; // 1 for available, 0 for not available
    int RentedDays; // Number of days the car is rented
} Car;

#endif


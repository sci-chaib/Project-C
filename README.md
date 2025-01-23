# 🚗 Car Rental System

A simple command-line **Car Rental System** written in C. This system allows users to manage rental cars, including adding, displaying, renting, editing, deleting, searching, sorting, and saving car details.

---

## 📋 Features

- **Add a Car** – Input car details such as ID, marque, model, seats, transmission type, and rental price.
- **Display Cars** – View a list of available cars with their details and rental income.
- **Rent a Car** – Rent a car by specifying the number of days.
- **Edit Car Information** – Modify existing car details.
- **Delete a Car** – Remove a car from the inventory.
- **Search Cars** – Find cars based on marque, availability, or income.
- **Sort Cars** – Sort cars by marque, availability, or income.
- **Save and Load Data** – Persist car information in a CSV file.

---

## 📂 Project Structure

```
car_rental_system/
│-- car.h               # Structure definition for Car
│-- car_operations.h    # Function prototypes for car operations
│-- car_operations.c    # Implementation of car functions
│-- main.c              # Main program logic and menu
│-- car_data.csv        # Data file for storing car info
│-- README.md           # Project documentation
```

### 🗂️ File Descriptions

- **`car.h`** → Defines the `Car` structure used in the program.  
- **`car_operations.h`** → Function prototypes for car operations.  
- **`car_operations.c`** → Implements core features such as adding, searching, and sorting cars.  
- **`main.c`** → Handles the menu system and overall program control.  
- **`car_data.csv`** → Stores car data persistently.  

---

## ⚙️ Installation and Usage

### Prerequisites

Ensure you have the following installed:

- **GCC compiler** (for compiling the C code)
- **Command-line terminal** (to run the program)

### 🔧 Compilation Instructions

To compile the project, use:

```bash
gcc -o car_rental main.c car_operations.c -Wall
```

### ▶️ Running the Program

After compilation, run the executable:

```bash
./car_rental    # For Linux/Mac users
car_rental.exe  # For Windows users
```

---

## 📖 How to Use

Once the program starts, you will see the following menu:

```
Car Rental System Menu:
1. Add Car
2. Display Cars
3. Rent a Car
4. Edit Car
5. Delete Car
6. Search Cars
7. Sort Cars
8. Save and Exit
Enter your choice:
```

Simply enter a number to perform the desired operation.

---

## 💾 Data Persistence

Car details are saved in **`car_data.csv`**, ensuring that data is available even after the program is closed. If no data file exists, the program starts with an empty inventory.

---

## 🚀 Future Improvements

Potential enhancements include:

- Adding a graphical user interface (GUI).  
- Implementing customer management features.  
- Enhancing search with more filters.  
- Tracking car maintenance.  

---


## 👤 Authors
- **Chaib Mohamed** 
- **Elmamsaoui Mohammed** 
- **Ellatifi Malak**
- **Elaziz Amira**

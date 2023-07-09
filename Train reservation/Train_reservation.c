#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

struct details{
    char name[30];
    int trainNum, seats;
};
void reservation(void);
void view(void);
void cancel(void);
void printTicket(char[], int, int, float);
void bookedTrain(void);
float calculateCharge(int, int);

int main(){

    int menuChoice;
    while(1){
        system("cls");
        printf("=================================\n");
        printf("    TRAIN RESERVATION SYSTEM\n");
        printf("=================================\n");
        printf("1>> Reserve A Ticket\n");
        printf("------------------------\n");
        printf("2>> View All Available Trains\n");
        printf("------------------------\n");
        printf("3>> Cancel Reservation\n");
        printf("------------------------\n");
        printf("4>> Exit\n");
        printf("------------------------\n");
        printf("\n-->");
        scanf("%d", &menuChoice);

        switch(menuChoice){
            case 1:
                reservation();
                getch();
                break;
            case 2:
                view();
                printf("\n\nPress any key to go to Main Menu..");
                getch();
                break;
            case 3:
                cancel();
                printf("\n\nPress any key to go to Main Menu..");
                getch();
                break;
            case 4:
                return 0;
            default:
                printf("\nInvalid choice.");
                getch();
                break;
        }
   }
    return 0;
}

void view()
{
    system("cls");
    printf("-----------------------------------------------------------------------------\n");
    printf("Tr.No\tName\t\t\tDestinations\t\tCharges\t\tTime\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("1001\tChennai Express\t\tChennai to mumbai\tRs.5000\t\t9am\n");
    printf("1002\tChennai Express\t\tMumbai to chennai\tRs.5000\t\t12pm\n");
    printf("1003\tCoimbatore Express\tCoimbatore to madurai\tRs.4500\t\t8am\n");
    printf("1004\tCoimbatore Express\tMadurai to coimbatore\tRs.4500\t\t11am\n");
    printf("1005\tBanglore Express\tBanglore to trichy\tRs.4000\t\t7am\n");
    printf("1006\tBanglore Express\tTrichy to Banglore\tRs.4000\t\t9.30am\n");
    printf("1007\tSengottai Express\tSengottai to madurai\tRs.3500\t\t1pm\n");
    printf("1008\tSengottai Express\tMadurai to sengottai\tRs.3500\t\t4pm\n");
    printf("1009\tPalani Express\t\tPalani to mysore\tRs.6000\t\t3.35pm\n");
    printf("1010\tPalani Express\t\tMysore to palani\tRs.6000\t\t4.15pm\n");
}

float calculateCharge(int trainNum, int seats){
    float charge = 0.0;

    switch (trainNum) {
        case 1001:
        case 1002:
            charge = 5000.0 * seats;
            break;
        case 1003:
        case 1004:
            charge = 4500.0 * seats;
            break;
        case 1005:
        case 1006:
            charge = 4000.0 * seats;
            break;
        case 1007:
        case 1008:
            charge = 3500.0 * seats;
            break;
        case 1009:
        case 1010:
            charge = 6000.0 * seats;
            break;
        default:
            break;
    }

    return charge;   
}

void specificTrain(int train_num)
{
    switch (train_num) {
        case 1001:
            printf("Train:\t\t\tChennai Express\n");
            printf("Destination:\t\tChennai to mumbai\n");
            printf("Departure:\t\t9am\n");
            break;
        case 1002:
            printf("Train:\t\t\tChennai Express\n");
            printf("Destination:\t\tMumbai to chennai\n");
            printf("Departure:\t\t12pm\n");
            break;
        case 1003:
            printf("Train:\t\t\tCoimbatore Express\n");
            printf("Destination:\t\tCoimbatore to madurai\n");
            printf("Departure:\t\t8am\n");
            break;
        case 1004:
            printf("Train:\t\t\tCoimbatore Express\n");
            printf("Destination:\t\tMadurai to coimbatore\n");
            printf("Departure:\t\t11am\n");
            break;
        case 1005:
            printf("Train:\t\t\tBanglore Express\n");
            printf("Destination:\tBanglore to trichy\n");
            printf("Departure:\t\t7am\n");
            break;
        case 1006:
            printf("Train:\t\t\tBanglore Express\n");
            printf("Destination:\t\tTrichy to Banglore\n");
            printf("Departure:\t\t9.30am\n");
            break;
        case 1007:
            printf("Train:\t\t\tSengottai Express\n");
            printf("Destination:\t\tSengottai to madurai\n");
            printf("Departure:\t\t1pm\n");
            break;
        case 1008:
            printf("Train:\t\t\tSengottai Express\n");
            printf("Destination:\t\tMadurai to sengottai\n");
            printf("Departure:\t\t4pm\n");
            break;
        case 1009:
            printf("Train:\t\t\tPalani Express\n");
            printf("Destination:\t\tPalani to mysore\n");
            printf("Departure:\t\t3.35pm\n");
            break;
        case 1010:
            printf("Train:\t\t\tPalani Express\n");
            printf("Destination:\t\tMysore to palani\n");
            printf("Departure:\t\t4.15pm\n");
            break;
        default:
            break;
    }
}

void printTicket(char name[], int trainNum, int seats, float charge){
    system("cls");
    printf("---------------------------------------\n");
    printf("\t\tTICKET\n");
    printf("---------------------------------------\n\n");
    printf("Name: \t\t\t%s\n", name);
    printf("No. of seats:\t\t%d\n", seats);
    printf("Train number:\t\t%d\n", trainNum);
    specificTrain(trainNum);
    printf("Charge:\t\t\t%.2f\n", charge);
}

void reservation(){

    char choice;
    system("cls");
    struct details passenger;
    printf("\nEnter your name: ");
    scanf("%s", passenger.name);
    printf("Enter number of seats: ");
    scanf("%d", &passenger.seats);

    printf("\n\n>>Press Enter To View Available Trains<< ");
    system("cls");
    view();

    printf("\n\nEnter train number: ");
    scanf("%d", &passenger.trainNum);
    if(!(passenger.trainNum >= 1001 && passenger.trainNum <= 1010)){
        printf("No train found.");
        return;
    }
    float charge = calculateCharge(passenger.trainNum, passenger.seats);
    printTicket(passenger.name, passenger.trainNum, passenger.seats, charge);

    printf("\nCONFIRM your ticket(y/n): ");
    while(1){
        scanf("%s", &choice);
        if (choice == 'y'){
            FILE *file = fopen("seats_reserved.csv", "a");
            if(file == NULL){
                printf("\nError opening file!");
                return;
            }
            fprintf(file, "%s,%d,%d,%.2f\n", passenger.name, passenger.seats, passenger.trainNum, charge);
            fclose(file);
            printf("==================");
            printf("\n Reservation Done\n");
            printf("==================");
            printf("\nPress any key to go back to Main menu");
            break;
        }
        else if(choice == 'n'){
            printf("\nReservation Not Done!\nPress any key to go back to Main menu!");
            break;
        }
        else{
            printf("Invalid entry... Enter again >> ");
        }
    }
    getch();
}

void cancel(){
    char nameToDelete[30];
    char confirm;
    char filename[] = "seats_reserved.csv";
    FILE* orgfile = fopen(filename,"r");
    FILE* tempFile = fopen("temp.csv", "w");
    printf("Enter name: ");
    scanf("%s", nameToDelete);
    if(orgfile == NULL){
        printf("Error opening file...");
        return;
    }
    char line[100];
    int recordDeleted = 0;

    while(fgets(line, sizeof(line), orgfile)){
        char name[30];
        int seats, trainNum;
        float charge;
        
        sscanf(line, "%[^,],%d,%d,%.2f", name, &seats, &trainNum, &charge);

        if(strcmp(name, nameToDelete) == 0){
            recordDeleted = 1;
            printf("Are you sure you want to cancel the booking for %s? (y/n): ", name);
            scanf(" %c", &confirm);

            if (confirm == 'n') {
                fprintf(tempFile, "%s,%d,%d,%.2f\n", name, seats, trainNum, charge);
                recordDeleted = 0;
            }
            continue;
        }

        fprintf(tempFile, "%s,%d,%d,%.2f\n", name, seats, trainNum, charge);
    }

    fclose(orgfile);
    fclose(tempFile);

    if(recordDeleted){
        remove("seats_reserved.csv");
        rename("temp.csv", "seats_reserved.csv");
        printf("Booking cancelled successfully...\n");
    }
    else{
        remove("temp.csv");
        if (confirm == 'n'){
            printf("Cancellation stopped.");
        }else{
            printf("Booking not found!\n");
        }
    }
}

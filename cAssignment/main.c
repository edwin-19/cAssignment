//
//  main.c
//  cAssignment
//
//  Created by Edwin Cheong on 30/03/2019.
//  Copyright © 2019 Point2Points. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom function
#include "menu.h"
#include "utils.h"

int main(int argc, const char * argv[]) {
    char choice;
    int destinationChoice, ticket, selectedTimeSlot;
    int i = 0, k = 0;
    int row, column, selectedDeck;
    
    if (intializeVars() == SUCCESS) {
        // Proceed with main program
        showMainMenu();
        do {
            //showMainMenu();
            
            //Allow users to key in their menu choice
            scanf("%c", &choice);
            
            if (choice == 'T') {
                showTicketPrice();
            } else if(choice == 'B') {
                printf("\nEnter how many tickets you intend to buy: ");
                scanf("%d", &ticket);
                
                for (i = 0; i < ticket; i++) {
                    destinationMenu();
                    scanf("%d", &destinationChoice);
                    
                    if (destinationChoice == 1) {
                        showLangkawiSchedule(timeSlots, ferryID, langkawiSeats);
                    } else {
                        showPenangSchedule(timeSlots, ferryID, penangSeats);
                    }
                    
                    printf("\nPlease select prefered timeslot:\n");
                    for (k = 0; k < NUM_TIME_SLOTS; k++) {
                        printf("%d. %s\n", k, timeSlots[k].time);
                    }
                    printf("Timeslot select: ");
                    scanf("%d", &selectedTimeSlot);
                    printf("\n");
                    
                    if (destinationChoice == 1) {
                        showSeatings(langkawiSeats[selectedTimeSlot]);
                    } else {
                        showSeatings(penangSeats[selectedTimeSlot]);
                    }
                    
                    printf("Select Deck:\n");
                    scanf("%d", &selectedDeck);
                    
                    printf("\nPlease select seating with an 'x':\n");
                    printf("Enter row:\n");
                    scanf("%d", &row);
                    
                    printf("\nEnter column:\n");
                    scanf("%d", &column);
                    
                    if (destinationChoice == 1) {
                        if (selectedDeck == 1) {
                            langkawiSeats[selectedTimeSlot].upper_deck[row][column] = 'o';
                        } else {
                            langkawiSeats[selectedTimeSlot].lower_deck[row][column] = 'o';
                        }
                    } else {
                        if (selectedDeck == 1) {
                            penangSeats[selectedTimeSlot].upper_deck[row][column] = 'o';
                        } else {
                            penangSeats[selectedTimeSlot].lower_deck[row][column] = 'o';
                        }
                    }
                    
                }
            } else if (choice == 'V') {
                destinationMenu();
                scanf("%d", &destinationChoice);
                
                printf("\nPlease select prefered timeslot:\n");
                for (k = 0; k < NUM_TIME_SLOTS; k++) {
                    printf("%d. %s\n", k, timeSlots[k].time);
                }
                printf("Timeslot select: ");
                scanf("%d", &selectedTimeSlot);
                printf("\n");
                
                if (destinationChoice == 1) {
                    showSeatings(langkawiSeats[selectedTimeSlot]);
                } else {
                    showSeatings(penangSeats[selectedTimeSlot]);
                }
            } else if(choice == 'U') {
                int oldRow, oldColumn;
                
                destinationMenu();
                scanf("%d", &destinationChoice);
                
                if (destinationChoice == 1) {
                    showLangkawiSchedule(timeSlots, ferryID, langkawiSeats);
                } else {
                    showPenangSchedule(timeSlots, ferryID, penangSeats);
                }
                
                printf("\nPlease select prefered timeslot:\n");
                for (k = 0; k < NUM_TIME_SLOTS; k++) {
                    printf("%d. %s\n", k, timeSlots[k].time);
                }
                printf("Timeslot select: ");
                scanf("%d", &selectedTimeSlot);
                printf("\n");
                
                if (destinationChoice == 1) {
                    showSeatings(langkawiSeats[selectedTimeSlot]);
                } else {
                    showSeatings(penangSeats[selectedTimeSlot]);
                }
                
                printf("Select Deck:\n");
                scanf("%d", &selectedDeck);
                
                printf("\nPlease select old seating':\n");
                printf("Enter old row:\n");
                scanf("%d", &oldRow);
                
                printf("\nEnter old column:\n");
                scanf("%d", &oldColumn);
                
                printf("\nPlease select seating with an 'x':\n");
                printf("Enter row:\n");
                scanf("%d", &row);
                
                printf("\nEnter column:\n");
                scanf("%d", &column);
                
                if (destinationChoice == 1) {
                    if (selectedDeck == 1) {
                        langkawiSeats[selectedTimeSlot].upper_deck[oldRow][oldColumn] = 'x';
                        langkawiSeats[selectedTimeSlot].upper_deck[row][column] = 'o';
                    } else {
                        langkawiSeats[selectedTimeSlot].lower_deck[oldRow][oldColumn] = 'x';
                        langkawiSeats[selectedTimeSlot].lower_deck[row][column] = 'o';
                    }
                } else {
                    if (selectedDeck == 1) {
                        penangSeats[selectedTimeSlot].upper_deck[oldRow][oldColumn] = 'x';
                        penangSeats[selectedTimeSlot].upper_deck[row][column] = 'o';
                    } else {
                        penangSeats[selectedTimeSlot].lower_deck[oldRow][oldColumn] = 'x';
                        penangSeats[selectedTimeSlot].lower_deck[row][column] = 'o';
                    }
                }
            }
            
            //printf("\n");
        } while (choice != 'E');

    }
    
    return 0;
}

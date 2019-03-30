//
//  menu.c
//  cAssignment
//
//  Created by Edwin Cheong on 30/03/2019.
//  Copyright © 2019 Point2Points. All rights reserved.
//

#include "menu.h"
#include "utils.h"

void showMainMenu(void) {
    printf("Main Menu: \n");
    printf("Press B to Buy Ticket! \n");
    printf("Press D to Choose Destination \n");
    printf("Press T to View Ticket Price List! \n");
    printf("Press V to View Seating Arrangement! \n");
    printf("Press E to Exit System! \n");
    printf("\nEnter your menu choice: ");
}

void showPenangSchedule(string timeSlots[NUM_TIME_SLOTS], string ferryID[NUM_TIME_SLOTS], deck penangSeats[NUM_TIME_SLOTS]) {
    int i = 0;
    
    printf("\n Penang to Langkawi: ");
    printf("\n ********************");
    printf("\n \t Ferry ID \t Ferry Depart Time \t Ferry Seats \t");
    for (i = 0; i < NUM_TIME_SLOTS; i++) {
        printf("\n \t     %s   \t      %s          \t     %d \t", timeSlots[i].time, ferryID[i].time, countSeatings(penangSeats[i]));
    }
}

void showLangkawiSchedule(string timeSlots[NUM_TIME_SLOTS], string ferryID[NUM_TIME_SLOTS], deck langkawiSlots[NUM_TIME_SLOTS]){
    int i = 0;
    
    printf("\n Langkawi to Penang: ");
    printf("\n ********************");
    printf("\n \t Ferry ID \t Ferry Depart Time \t Ferry Seats \t");
    for (i = 0; i < NUM_TIME_SLOTS; i++) {
        printf("\n \t     %s   \t      %s          \t     %d \t", timeSlots[i].time, ferryID[i].time, countSeatings(langkawiSlots[i]));
    }
}

void destinationMenu(void) {
    printf("\n Press 1 for Penang to Langkawi schedule: ");
    printf("\n Press 2 for Langkawi to Penang schedule:  ");
}

void showTicketPrice(void) {
    printf("The price for upper deck seatings are RM15 per seat\n");
    printf("The price for lower deck seatings are RM10 per seat\n");
}

void showDeckMenu(void) {
    printf("Press 1 for Upper Deck\n");
    printf("Press 2 for Lower Deck\n");
}

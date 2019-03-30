//
//  utils.c
//  cAssignment
//
//  Created by Edwin Cheong on 30/03/2019.
//  Copyright © 2019 Point2Points. All rights reserved.
//

#include <string.h>
#include "utils.h"

string timeSlots[NUM_TIME_SLOTS];
string ferryID[NUM_TIME_SLOTS];
deck penangSeats[NUM_TIME_SLOTS];
deck langkawiSeats[NUM_TIME_SLOTS];

deck bulkInsert(deck selected, char inserted){
    int i = 0;
    int k = 0;
    
    //Count num of seats for upper deck
    for (i = 0; i < UPPER_ROW; i++) {
        for (k = 0; k < UPPER_COLUMN; k++) {
            selected.upper_deck[i][k] = inserted;
        }
    }
    
    for (i = 0; i < LOWER_ROW; i++) {
        for (k = 0; k < LOWER_COLUMN; k++) {
            selected.lower_deck[i][k] = inserted;
        }
    }
    
    return selected;
}

int intializeVars(void) {
    strcpy(timeSlots[0].time, "7am");
    strcpy(timeSlots[1].time, "9am");
    strcpy(timeSlots[2].time, "11am");
    strcpy(timeSlots[3].time, "1pm");
    strcpy(timeSlots[4].time, "3pm");
    strcpy(timeSlots[5].time, "5pm");
    strcpy(timeSlots[6].time, "7pm");
    strcpy(timeSlots[7].time, "9pm");
    
    strcpy(ferryID[0].time, "A1");
    strcpy(ferryID[1].time, "A2");
    strcpy(ferryID[2].time, "A3");
    strcpy(ferryID[3].time, "A4");
    strcpy(ferryID[4].time, "A5");
    strcpy(ferryID[5].time, "A6");
    strcpy(ferryID[6].time, "A7");
    strcpy(ferryID[7].time, "A8");
    
    int i = 0;
    
    for (i = 0; i < NUM_TIME_SLOTS; i++) {
        penangSeats[i] = bulkInsert(penangSeats[i], 'x');
        langkawiSeats[i] = bulkInsert(langkawiSeats[i], 'x');
    }
    
    return SUCCESS;
}

int countSeatings(deck selected) {
    int numSeats = 0;
    int i = 0;
    int k = 0;
    
    //Count num of seats for upper deck
    for (i = 0; i < UPPER_ROW; i++) {
        for (k = 0; k < UPPER_COLUMN; k++) {
            if (selected.upper_deck[i][k] == 'x') {
                numSeats++;
            }
        }
    }
    
    // Count Lower Deck
    for (i = 0; i < LOWER_ROW; i++) {
        for (k = 0; k < LOWER_COLUMN; k++) {
            if (selected.lower_deck[i][k] == 'x') {
                numSeats++;
            }
        }
    }
    
    return numSeats;
}

void showSeatings(deck selected) {
    int i = 0;
    int k = 0;
    
    //Count num of seats for upper deck
    printf("Upper Deck:\n");
    for (i = 0; i < UPPER_ROW; i++) {
        for (k = 0; k < UPPER_COLUMN; k++) {
            printf("%c\t", selected.upper_deck[i][k]);
        }
        printf("\n");
    }
    
    printf("\nLower Deck:\n");
    for (i = 0; i < LOWER_ROW; i++) {
        for (k = 0; k < LOWER_COLUMN; k++) {
            printf("%c\t", selected.lower_deck[i][k]);
        }
        printf("\n");
    }
    
}

//
//  utils.h
//  cAssignment
//
//  Created by Edwin Cheong on 30/03/2019.
//  Copyright © 2019 Point2Points. All rights reserved.
//

#ifndef utils_h
#define utils_h

#define UPPER_ROW 2
#define UPPER_COLUMN 5
#define LOWER_ROW 6
#define LOWER_COLUMN 5

#define NUM_TIME_SLOTS 8
#define NUM_OF_SEATS 40

#define SUCCESS 1
#define FAILURE 0

typedef struct string{
    char time[100];
}string;

typedef struct deck{
    char upper_deck[UPPER_ROW][UPPER_COLUMN];
    char lower_deck[LOWER_ROW][UPPER_COLUMN];
}deck;

#include <stdio.h>

extern string timeSlots[NUM_TIME_SLOTS];
extern string ferryID[NUM_TIME_SLOTS];
extern deck penangSeats[NUM_TIME_SLOTS];
extern deck langkawiSeats[NUM_TIME_SLOTS];

int intializeVars(void);
int countSeatings(deck selected);
void showSeatings(deck selected);

#endif /* utils_h */

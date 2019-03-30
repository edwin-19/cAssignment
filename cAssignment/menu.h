//
//  menu.h
//  cAssignment
//
//  Created by Edwin Cheong on 30/03/2019.
//  Copyright © 2019 Point2Points. All rights reserved.
//

#ifndef menu_h
#define menu_h

#include <stdio.h>
#include "utils.h"

void showMainMenu(void);
void destinationMenu(void);
void showPenangSchedule(string[NUM_TIME_SLOTS], string[NUM_TIME_SLOTS], deck[NUM_TIME_SLOTS]);
void showLangkawiSchedule(string[NUM_TIME_SLOTS], string[NUM_TIME_SLOTS], deck[NUM_TIME_SLOTS]);
void showDeckMenu(void);
void showTicketPrice(void);

#endif /* menu_h */

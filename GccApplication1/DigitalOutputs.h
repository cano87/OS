/*
 * DigitalOutputs.h
 *
 * Created: 12/20/2021 6:34:43 PM
 *  Author: Ricardo
 */ 


#ifndef DIGITALOUTPUTS_H_
#define DIGITALOUTPUTS_H_

//
//
#define GREEN_LED   5
#define YELLOW_LED  6
#define BLUE_LED    7


#define DEFUALT_LED BLUE_LED


void initDigitalOutputs();
void blinkBlueled(void);
void blinkGreenled(void);
void blinkYellowled(void);



#endif /* DIGITALOUTPUTS_H_ */
/**********************************************************************************************
 * Arduino FILX Library - Version 1.0
 * by Alessandro Vinicius <alessandro.vncs@gmail.com>
 *
 **********************************************************************************************/

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include <FILX.h>

FILX::FILX(int sizeArray){
	processAvailable = true;
	firstTime = true;
	lastCompute = 0;
	timeCompute = 80;
	//valueFinal = 0;
	valueAd = 0;
	tempSize = sizeArray;
	tempArray = (double *) calloc(sizeArray, sizeof(double));
}

double FILX::Process(int value){	
	double valueFinal;	
	if(lastCompute <= millis() && processAvailable){
		processAvailable = false;
		lastCompute += timeCompute;
		
		for(int i = tempSize - 1; i > 0; i--){
			tempArray[i] = tempArray[i-1];
		}
		tempArray[0] = value;
		long arrayAll = 0;
		
		for(int i = 0; i < tempSize; i++){
			arrayAll = arrayAll + tempArray[i];
		}
		processAvailable = true;
		double valueFinal = arrayAll/tempSize;
	}
	return valueFinal;
}
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

FILX::FILX(){
	processAvailable = true;
	firstTime = true;
	lastCompute = 0;
	timeCompute = 80;
	valueFinal = 0;
	valueAd = 0;
}

double FILX::Process(double value, int sizeArray){		
	if(lastCompute <= millis()){
		lastCompute += timeCompute;
		
		if(firstTime){
			for(int i = 0; i < sizeArray; i++){
				tempArray[i] = 0.0;
			}
			firstTime = false;
		}
		
		for(int i = 0; i < sizeArray; i++){
			tempArray[i] = tempArray[i+1];
		}
		tempArray[sizeArray-1] = value;
		arrayAll = 0.0;
		
		for(int i = 0; i < sizeArray; i++){
			arrayAll = arrayAll + tempArray[i];
		}
		
		valueFinal = arrayAll/sizeArray;
	}
	return valueFinal;
}

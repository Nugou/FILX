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
}

double FILX::Process(double value, int sizeArray){
	if(processAvailable){
		processAvailable = false;
		int i;
		double tempArray[sizeArray];
		double arrayAll;
		
		for(i = 0; i < sizeArray; i++){
			tempArray[i] = tempArray[i+1];
		}
		tempArray[sizeArray-1] = value;
		
		for(i = 0; i < sizeArray; i++){
			arrayAll += tempArray[i];
		}
		processAvailable = true;
	}
	return arrayAll/sizeArray;
}
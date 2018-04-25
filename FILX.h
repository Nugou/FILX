#ifndef FILX_h
#define FILX_h

class FILX {
	private:
		bool processAvailable;
		bool firstTime;
		
		unsigned long timeCompute;
		unsigned long lastCompute;
		
		double *tempArray;
		double valueAd;
		double valueFinal;
		double tempValue;
		double tempSize;

		int tempSizeArray;
	
	public:
		FILX(int);
		double Process(int);
		
};
#endif



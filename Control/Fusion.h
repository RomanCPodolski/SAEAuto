
#ifndef _Fusion_H
#define	_Fusion_H

#define STEERING_CONSTANT 0.157

#include <string>
#include <iostream>
#include <fstream>

#include "Control.h"

class KalmanPVA;

class Logger;

class Fusion {
public:

	Fusion(Control* CarController, Logger* CarLogger);
    	Fusion(const Fusion& orig);
    	virtual ~Fusion();

	VECTOR_2D CurrentVelocity;
	VECTOR_2D CurrentPosition;
	double CurrentHeading;
	double CurrentSpeed;

	void GPSUpdate(VECTOR_2D GPSPosition, double GPSSpeed, int GPSNumSat);
	void GPSTrackAngleUpdate(double GPSTrackAngle, int GPSNumSat);

private:

	void TrackAngleActions();
	void InterpolateTrackAngle(double IMUHeading);
	void PVActions();
	void InterpolatePV();

	Control* CarControl;

	Logger* Log;

	KalmanPVA *VAKlmX;
	KalmanPVA *VAKlmY;
	KalmanPVA *PVKlmX;
	KalmanPVA *PVKlmY;

	Logger* FusionLog;


};

#endif	/* _Fusion_H */


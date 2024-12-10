#include "foc_math.h"


extern float GetAngle_Ele();
extern float GetSpeed_Ele();
extern float GetIdIq_ref();
extern float GetIdIq();


void CurrentCtrl() {

    float MotorSpeed_Ele, MotorAngle_Ele, ;

    MotorAngle_Ele = GetAngle_Ele();
    MotorSpeed_Ele = GetSpeed_Ele();
    GetIdIq_ref();
    GetIdIq();

    PID_Controller();

    InvPark();
    Svpwm();
}
/*
 * @file   foc.c
 * @author CatLHY
 * @date   2024-12-25
 *
 * @brief
 */

#include <stdint.h>
#include <math.h>

extern float GetAngle_Ele();
extern float GetSpeed_Ele();
extern float GetIdIq_ref();
extern float GetIdIq();


/*================================================================================*/
typedef struct {
    float Id_Ref, Iq_Ref;
    float Ud_Ref, Uq_Ref;
    float Ud0, Uq0;
    float Ud_compensation,Uq_compensation;
} CurrentLoopRefValue_t;

typedef struct {
    float Iu, Iv, Iw;
    float Ialpha,Ibeta;
    float Id,Iq;
} CurrentLoopRealValue_t;

typedef struct {
    float Kp;
    float Ki;
    float Kd;

    float Sigma_SingalIn;
    float Last_SignalIn;
} PID_Cofes_t;

typedef struct {
    uint16_t U_phaseChangeMoment;
    uint16_t V_phaseChangeMoment;
    uint16_t W_phaseChangeMoment;
} ThreePhaseChangeMoment_t;
/*================================================================================*/

static CurrentLoopRefValue_t CurrentLoopRefValue;
static CurrentLoopRealValue_t CurrentLoopRealValue;

/*================================================================================*/



static void Park(float Ialpha, float Ibeta, float angle_ele, float* Id, float* Iq);
static void InvPark(float Ud, float Uq, float angle_ele, float* Ualpha, float* Ubeta);
static void Clarke(float Iu, float Iv, float Iw, float* Ialpha, float* Ibeta);
static void PID_Controller(float SingalIn, float* SignalOut, PID_Cofes_t* PID_Cofes);
static void Svpwm(float Ualpha, float Ubeta, uint32_t SvpwmPeriod);
/*================================================================================*/

void CurrentLoop() {

}
void SpeedLoop() {}




static void PID_Controller(float SingalIn, float* SignalOut, PID_Cofes_t* PID_Cofes) {
    PID_Cofes->Sigma_SingalIn += SingalIn;
    *SignalOut = PID_Cofes->Kp * SingalIn + PID_Cofes->Ki * PID_Cofes->Sigma_SingalIn + PID_Cofes->Kd *(SingalIn - PID_Cofes->Last_SignalIn);
    PID_Cofes->Last_SignalIn = SingalIn;
}

static void Clarke(float Iu, float Iv, float Iw, float* Ialpha, float* Ibeta) {
    *Ialpha = Iu;
    *Ibeta = sqrtf(3) / 3 * (Iv - Iw);
}

static void Park(float Ialpha, float Ibeta, float angle_ele, float* Id, float* Iq) {
    *Id = Ialpha * cosf(angle_ele) + Ibeta * sinf(angle_ele);
    *Iq = -Ialpha * sinf(angle_ele) + Ibeta * cosf(angle_ele);
}

static void InvPark(float Ud, float Uq, float angle_ele, float* Ualpha, float* Ubeta) {
    *Ualpha = Ud * cosf(angle_ele) - Uq * sinf(angle_ele);
    *Ubeta = Ud * cosf(angle_ele) + Uq * cosf(angle_ele);
}

static void Svpwm(float Ualpha, float Ubeta, uint32_t SvpwmPeriod) {

}


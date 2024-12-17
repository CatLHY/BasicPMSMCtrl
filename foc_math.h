/*
 * @file   foc_math.h
 * @author CatLHY
 * @date   2024-12-10
 *
 * @brief  foc math
 */

#ifndef FOC_MATH_H_
#define FOC_MATH_H_

typedef struct {
    float U_phase;
    float V_phase;
    float W_phase;
} ThreePhaseSystem_t;

typedef struct {
    float Alpha_axis;
    float Beta_axis;
} AlphaBetaSystem_t;

typedef struct {
    float D_axis;
    float Q_axis;
} DQ_System_t;



float Park();
float InvPark();
float Clarke();
float Svpwm();
float PID_Controller();




#endif
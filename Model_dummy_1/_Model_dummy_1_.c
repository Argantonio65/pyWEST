#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <float.h>

#include "Tornado/Common/Util/DLL.h"
#include "Tornado/Common/MSLE/MSLE.h"

#include "Tornado/ME/MSLU/MSLU.h"

#include "..\WESTforIUWS_modelLibrary_little\External\External.h"



#define SOD pModel->Params[0]
#define River_2_parameters_T_conv pModel->Params[1]
#define River_2_parameters_slp pModel->Params[2]
#define River_2_parameters_n pModel->Params[3]
#define River_2_parameters_W_b pModel->Params[4]
#define River_2_parameters_L pModel->Params[5]
#define River_2_parameters_z pModel->Params[6]
#define River_2_parameters_d_min pModel->Params[7]
#define River_2_parameters_Vol_min pModel->Params[8]
#define River_2_parameters_Vol_init pModel->Params[9]
#define River_2_parameters_Q_initial pModel->Params[10]
#define River_2_parameters_alpha pModel->Params[11]
#define River_2_parameters_pH pModel->Params[12]
#define River_2_parameters_KLmin pModel->Params[13]
#define River_2_parameters_TKL pModel->Params[14]
#define River_2_parameters_Kd1 pModel->Params[15]
#define River_2_parameters_Kd2 pModel->Params[16]
#define River_2_parameters_KBODs pModel->Params[17]
#define River_2_parameters_Vs1 pModel->Params[18]
#define River_2_parameters_Vs2 pModel->Params[19]
#define River_2_parameters_KO2 pModel->Params[20]
#define River_2_parameters_TKd pModel->Params[21]
#define River_2_parameters_TKp pModel->Params[22]
#define River_2_parameters_Knit pModel->Params[23]
#define River_2_parameters_TKnit pModel->Params[24]
#define River_2_parameters_KNO2 pModel->Params[25]
#define River_2_parameters_KSO2 pModel->Params[26]
#define River_2_parameters_ProdM pModel->Params[27]
#define River_2_parameters_ResM pModel->Params[28]
#define River_2_parameters_TSOD pModel->Params[29]
#define River_2_parameters_SBOD1 pModel->Params[30]
#define River_2_parameters_SBOD2 pModel->Params[31]
#define River_2_parameters_SNH4 pModel->Params[32]
#define River_2_parameters_SOD pModel->Params[33]
#define River_2_parameters_VKL pModel->Params[34]
#define River_2_parameters_MB pModel->Params[35]
#define River_2_parameters_T_ref pModel->Params[36]
#define River_2_parameters_T_par pModel->Params[37]
#define River_3_parameters_T_conv pModel->Params[38]
#define River_3_parameters_slp pModel->Params[39]
#define River_3_parameters_n pModel->Params[40]
#define River_3_parameters_W_b pModel->Params[41]
#define River_3_parameters_L pModel->Params[42]
#define River_3_parameters_z pModel->Params[43]
#define River_3_parameters_d_min pModel->Params[44]
#define River_3_parameters_Vol_min pModel->Params[45]
#define River_3_parameters_Vol_init pModel->Params[46]
#define River_3_parameters_Q_initial pModel->Params[47]
#define River_3_parameters_alpha pModel->Params[48]
#define River_3_parameters_pH pModel->Params[49]
#define River_3_parameters_KLmin pModel->Params[50]
#define River_3_parameters_TKL pModel->Params[51]
#define River_3_parameters_Kd1 pModel->Params[52]
#define River_3_parameters_Kd2 pModel->Params[53]
#define River_3_parameters_KBODs pModel->Params[54]
#define River_3_parameters_Vs1 pModel->Params[55]
#define River_3_parameters_Vs2 pModel->Params[56]
#define River_3_parameters_KO2 pModel->Params[57]
#define River_3_parameters_TKd pModel->Params[58]
#define River_3_parameters_TKp pModel->Params[59]
#define River_3_parameters_Knit pModel->Params[60]
#define River_3_parameters_TKnit pModel->Params[61]
#define River_3_parameters_KNO2 pModel->Params[62]
#define River_3_parameters_KSO2 pModel->Params[63]
#define River_3_parameters_ProdM pModel->Params[64]
#define River_3_parameters_ResM pModel->Params[65]
#define River_3_parameters_TSOD pModel->Params[66]
#define River_3_parameters_SBOD1 pModel->Params[67]
#define River_3_parameters_SBOD2 pModel->Params[68]
#define River_3_parameters_SNH4 pModel->Params[69]
#define River_3_parameters_SOD pModel->Params[70]
#define River_3_parameters_VKL pModel->Params[71]
#define River_3_parameters_MB pModel->Params[72]
#define River_3_parameters_T_ref pModel->Params[73]
#define River_3_parameters_T_par pModel->Params[74]
#define River_4_parameters_T_conv pModel->Params[75]
#define River_4_parameters_slp pModel->Params[76]
#define River_4_parameters_n pModel->Params[77]
#define River_4_parameters_W_b pModel->Params[78]
#define River_4_parameters_L pModel->Params[79]
#define River_4_parameters_z pModel->Params[80]
#define River_4_parameters_d_min pModel->Params[81]
#define River_4_parameters_Vol_min pModel->Params[82]
#define River_4_parameters_Vol_init pModel->Params[83]
#define River_4_parameters_Q_initial pModel->Params[84]
#define River_4_parameters_alpha pModel->Params[85]
#define River_4_parameters_pH pModel->Params[86]
#define River_4_parameters_KLmin pModel->Params[87]
#define River_4_parameters_TKL pModel->Params[88]
#define River_4_parameters_Kd1 pModel->Params[89]
#define River_4_parameters_Kd2 pModel->Params[90]
#define River_4_parameters_KBODs pModel->Params[91]
#define River_4_parameters_Vs1 pModel->Params[92]
#define River_4_parameters_Vs2 pModel->Params[93]
#define River_4_parameters_KO2 pModel->Params[94]
#define River_4_parameters_TKd pModel->Params[95]
#define River_4_parameters_TKp pModel->Params[96]
#define River_4_parameters_Knit pModel->Params[97]
#define River_4_parameters_TKnit pModel->Params[98]
#define River_4_parameters_KNO2 pModel->Params[99]
#define River_4_parameters_KSO2 pModel->Params[100]
#define River_4_parameters_ProdM pModel->Params[101]
#define River_4_parameters_ResM pModel->Params[102]
#define River_4_parameters_TSOD pModel->Params[103]
#define River_4_parameters_SBOD1 pModel->Params[104]
#define River_4_parameters_SBOD2 pModel->Params[105]
#define River_4_parameters_SNH4 pModel->Params[106]
#define River_4_parameters_SOD pModel->Params[107]
#define River_4_parameters_VKL pModel->Params[108]
#define River_4_parameters_MB pModel->Params[109]
#define River_4_parameters_T_ref pModel->Params[110]
#define River_4_parameters_T_par pModel->Params[111]
#define River_5_parameters_T_conv pModel->Params[112]
#define River_5_parameters_slp pModel->Params[113]
#define River_5_parameters_n pModel->Params[114]
#define River_5_parameters_W_b pModel->Params[115]
#define River_5_parameters_L pModel->Params[116]
#define River_5_parameters_z pModel->Params[117]
#define River_5_parameters_d_min pModel->Params[118]
#define River_5_parameters_Vol_min pModel->Params[119]
#define River_5_parameters_Vol_init pModel->Params[120]
#define River_5_parameters_Q_initial pModel->Params[121]
#define River_5_parameters_alpha pModel->Params[122]
#define River_5_parameters_pH pModel->Params[123]
#define River_5_parameters_KLmin pModel->Params[124]
#define River_5_parameters_TKL pModel->Params[125]
#define River_5_parameters_Kd1 pModel->Params[126]
#define River_5_parameters_Kd2 pModel->Params[127]
#define River_5_parameters_KBODs pModel->Params[128]
#define River_5_parameters_Vs1 pModel->Params[129]
#define River_5_parameters_Vs2 pModel->Params[130]
#define River_5_parameters_KO2 pModel->Params[131]
#define River_5_parameters_TKd pModel->Params[132]
#define River_5_parameters_TKp pModel->Params[133]
#define River_5_parameters_Knit pModel->Params[134]
#define River_5_parameters_TKnit pModel->Params[135]
#define River_5_parameters_KNO2 pModel->Params[136]
#define River_5_parameters_KSO2 pModel->Params[137]
#define River_5_parameters_ProdM pModel->Params[138]
#define River_5_parameters_ResM pModel->Params[139]
#define River_5_parameters_TSOD pModel->Params[140]
#define River_5_parameters_SBOD1 pModel->Params[141]
#define River_5_parameters_SBOD2 pModel->Params[142]
#define River_5_parameters_SNH4 pModel->Params[143]
#define River_5_parameters_SOD pModel->Params[144]
#define River_5_parameters_VKL pModel->Params[145]
#define River_5_parameters_MB pModel->Params[146]
#define River_5_parameters_T_ref pModel->Params[147]
#define River_5_parameters_T_par pModel->Params[148]
#define Urban_InputEmulator_parameters_FactorEffluent pModel->Params[149]
#define Urban_InputEmulator_parameters_fBOD1_BOD pModel->Params[150]
#define Urban_InputEmulator_parameters_fBOD2_CODmBOD pModel->Params[151]
#define Urban_InputEmulator_parameters_fBOD1p_BODf pModel->Params[152]
#define Urban_InputEmulator_parameters_fBOD2p_BODs pModel->Params[153]
#define Urban_InputEmulator_parameters_settling pModel->Params[154]
#define Urban_InputEmulator_parameters_yesno pModel->Params[155]
#define Urban_InputEmulator_parameters_Mult_O2 pModel->Params[156]
#define Urban_InputEmulator_parameters_Mult_COD pModel->Params[157]
#define Urban_InputEmulator_parameters_Mult_BOD pModel->Params[158]
#define Urban_InputEmulator_parameters_Mult_NH4 pModel->Params[159]
#define River_1_parameters_T_conv pModel->Params[160]
#define River_1_parameters_slp pModel->Params[161]
#define River_1_parameters_n pModel->Params[162]
#define River_1_parameters_W_b pModel->Params[163]
#define River_1_parameters_L pModel->Params[164]
#define River_1_parameters_z pModel->Params[165]
#define River_1_parameters_d_min pModel->Params[166]
#define River_1_parameters_Vol_min pModel->Params[167]
#define River_1_parameters_Vol_init pModel->Params[168]
#define River_1_parameters_Q_initial pModel->Params[169]
#define River_1_parameters_alpha pModel->Params[170]
#define River_1_parameters_pH pModel->Params[171]
#define River_1_parameters_KLmin pModel->Params[172]
#define River_1_parameters_TKL pModel->Params[173]
#define River_1_parameters_Kd1 pModel->Params[174]
#define River_1_parameters_Kd2 pModel->Params[175]
#define River_1_parameters_KBODs pModel->Params[176]
#define River_1_parameters_Vs1 pModel->Params[177]
#define River_1_parameters_Vs2 pModel->Params[178]
#define River_1_parameters_KO2 pModel->Params[179]
#define River_1_parameters_TKd pModel->Params[180]
#define River_1_parameters_TKp pModel->Params[181]
#define River_1_parameters_Knit pModel->Params[182]
#define River_1_parameters_TKnit pModel->Params[183]
#define River_1_parameters_KNO2 pModel->Params[184]
#define River_1_parameters_KSO2 pModel->Params[185]
#define River_1_parameters_ProdM pModel->Params[186]
#define River_1_parameters_ResM pModel->Params[187]
#define River_1_parameters_TSOD pModel->Params[188]
#define River_1_parameters_SBOD1 pModel->Params[189]
#define River_1_parameters_SBOD2 pModel->Params[190]
#define River_1_parameters_SNH4 pModel->Params[191]
#define River_1_parameters_SOD pModel->Params[192]
#define River_1_parameters_VKL pModel->Params[193]
#define River_1_parameters_MB pModel->Params[194]
#define River_1_parameters_T_ref pModel->Params[195]
#define River_1_parameters_T_par pModel->Params[196]
#define Rural_inflow_parameters_surface pModel->Params[197]
#define Rural_inflow_parameters_BOD1_in pModel->Params[198]
#define Rural_inflow_parameters_BOD2_in pModel->Params[199]
#define Rural_inflow_parameters_O2_in pModel->Params[200]
#define Rural_inflow_parameters_BOD1p_in pModel->Params[201]
#define Rural_inflow_parameters_BOD2p_in pModel->Params[202]
#define Rural_inflow_parameters_BODs_in pModel->Params[203]

#define t pModel->IndepVars[0]

#define Urban_CSO_flow pModel->InputVars[0]
#define Temperature_water pModel->InputVars[1]
#define Solar_Radiation pModel->InputVars[2]
#define Rural_baseflow pModel->InputVars[3]

#define River_1_state_V_help pModel->AlgVars[0]
#define River_1_state_V pModel->AlgVars[1]
#define River_1_state_C_1_1_1_ pModel->AlgVars[2]
#define River_1_state_C_2_1_1_ pModel->AlgVars[3]
#define River_1_state_C_3_1_1_ pModel->AlgVars[4]
#define River_1_state_C_4_1_1_ pModel->AlgVars[5]
#define River_1_state_C_5_1_1_ pModel->AlgVars[6]
#define River_1_state_C_6_1_1_ pModel->AlgVars[7]
#define River_1_state_C_7_1_1_ pModel->AlgVars[8]
#define River_1_state_C_8_1_1_ pModel->AlgVars[9]
#define River_1_state_A_man pModel->AlgVars[10]
#define River_1_state_A pModel->AlgVars[11]
#define River_1_state_d pModel->AlgVars[12]
#define River_1_state_P pModel->AlgVars[13]
#define River_1_state_R pModel->AlgVars[14]
#define River_1_state_Q_Out pModel->AlgVars[15]
#define River_1_interface_Outflow_1_1_1_ pModel->AlgVars[16]
#define River_1_interface_Outflow_2_1_1_ pModel->AlgVars[17]
#define River_1_interface_Outflow_3_1_1_ pModel->AlgVars[18]
#define River_1_interface_Outflow_4_1_1_ pModel->AlgVars[19]
#define River_1_interface_Outflow_5_1_1_ pModel->AlgVars[20]
#define River_1_interface_Outflow_6_1_1_ pModel->AlgVars[21]
#define River_1_interface_Outflow_7_1_1_ pModel->AlgVars[22]
#define River_1_interface_Outflow_8_1_1_ pModel->AlgVars[23]
#define River_2_interface_Inflow1_1_1_1_ pModel->AlgVars[24]
#define River_2_interface_Inflow1_2_1_1_ pModel->AlgVars[25]
#define River_2_interface_Inflow1_3_1_1_ pModel->AlgVars[26]
#define River_2_interface_Inflow1_4_1_1_ pModel->AlgVars[27]
#define River_2_interface_Inflow1_5_1_1_ pModel->AlgVars[28]
#define River_2_interface_Inflow1_6_1_1_ pModel->AlgVars[29]
#define River_2_interface_Inflow1_7_1_1_ pModel->AlgVars[30]
#define River_2_interface_Inflow1_8_1_1_ pModel->AlgVars[31]
#define Urban_InputEmulator_interface_rainfall pModel->AlgVars[32]
#define Urban_InputEmulator_interface_Outflow_1_1_1_ pModel->AlgVars[33]
#define Urban_InputEmulator_interface_Outflow_2_1_1_ pModel->AlgVars[34]
#define Urban_InputEmulator_interface_Outflow_3_1_1_ pModel->AlgVars[35]
#define Urban_InputEmulator_interface_Outflow_4_1_1_ pModel->AlgVars[36]
#define Urban_InputEmulator_interface_Outflow_5_1_1_ pModel->AlgVars[37]
#define Urban_InputEmulator_interface_Outflow_6_1_1_ pModel->AlgVars[38]
#define Urban_InputEmulator_interface_Outflow_7_1_1_ pModel->AlgVars[39]
#define Urban_InputEmulator_interface_Outflow_8_1_1_ pModel->AlgVars[40]
#define River_2_interface_Inflow2_1_1_1_ pModel->AlgVars[41]
#define River_2_interface_Inflow2_2_1_1_ pModel->AlgVars[42]
#define River_2_interface_Inflow2_3_1_1_ pModel->AlgVars[43]
#define River_2_interface_Inflow2_4_1_1_ pModel->AlgVars[44]
#define River_2_interface_Inflow2_5_1_1_ pModel->AlgVars[45]
#define River_2_interface_Inflow2_6_1_1_ pModel->AlgVars[46]
#define River_2_interface_Inflow2_7_1_1_ pModel->AlgVars[47]
#define River_2_interface_Inflow2_8_1_1_ pModel->AlgVars[48]
#define River_2_state_V_help pModel->AlgVars[49]
#define River_2_state_V pModel->AlgVars[50]
#define River_2_state_C_1_1_1_ pModel->AlgVars[51]
#define River_2_state_C_2_1_1_ pModel->AlgVars[52]
#define River_2_state_C_3_1_1_ pModel->AlgVars[53]
#define River_2_state_C_4_1_1_ pModel->AlgVars[54]
#define River_2_state_C_5_1_1_ pModel->AlgVars[55]
#define River_2_state_C_6_1_1_ pModel->AlgVars[56]
#define River_2_state_C_7_1_1_ pModel->AlgVars[57]
#define River_2_state_C_8_1_1_ pModel->AlgVars[58]
#define River_2_state_A_man pModel->AlgVars[59]
#define River_2_state_A pModel->AlgVars[60]
#define River_2_state_d pModel->AlgVars[61]
#define River_2_state_P pModel->AlgVars[62]
#define River_2_state_R pModel->AlgVars[63]
#define River_2_state_Q_Out pModel->AlgVars[64]
#define River_2_interface_Outflow_1_1_1_ pModel->AlgVars[65]
#define River_2_interface_Outflow_2_1_1_ pModel->AlgVars[66]
#define River_2_interface_Outflow_3_1_1_ pModel->AlgVars[67]
#define River_2_interface_Outflow_4_1_1_ pModel->AlgVars[68]
#define River_2_interface_Outflow_5_1_1_ pModel->AlgVars[69]
#define River_2_interface_Outflow_6_1_1_ pModel->AlgVars[70]
#define River_2_interface_Outflow_7_1_1_ pModel->AlgVars[71]
#define River_2_interface_Outflow_8_1_1_ pModel->AlgVars[72]
#define River_2_state_FluxPerComponent_1_1_1_ pModel->AlgVars[73]
#define River_2_state_FluxPerComponent_2_1_1_ pModel->AlgVars[74]
#define River_2_state_FluxPerComponent_3_1_1_ pModel->AlgVars[75]
#define River_2_state_FluxPerComponent_4_1_1_ pModel->AlgVars[76]
#define River_2_state_FluxPerComponent_5_1_1_ pModel->AlgVars[77]
#define River_2_state_FluxPerComponent_6_1_1_ pModel->AlgVars[78]
#define River_2_state_FluxPerComponent_7_1_1_ pModel->AlgVars[79]
#define River_2_state_FluxPerComponent_8_1_1_ pModel->AlgVars[80]
#define Urban_InputEmulator_state_Q pModel->AlgVars[81]
#define Urban_InputEmulator_interface_U_O2_in pModel->AlgVars[82]
#define Urban_InputEmulator_interface_U_BOD_in pModel->AlgVars[83]
#define Urban_InputEmulator_interface_U_COD_in pModel->AlgVars[84]
#define Urban_InputEmulator_interface_U_NH4_in pModel->AlgVars[85]
#define River_2_state_InFluxPerComponent_1_1_1_ pModel->AlgVars[86]
#define River_2_state_InFluxPerComponent_2_1_1_ pModel->AlgVars[87]
#define River_2_state_InFluxPerComponent_3_1_1_ pModel->AlgVars[88]
#define River_2_state_InFluxPerComponent_4_1_1_ pModel->AlgVars[89]
#define River_2_state_InFluxPerComponent_5_1_1_ pModel->AlgVars[90]
#define River_2_state_InFluxPerComponent_6_1_1_ pModel->AlgVars[91]
#define River_2_state_InFluxPerComponent_7_1_1_ pModel->AlgVars[92]
#define River_2_state_InFluxPerComponent_8_1_1_ pModel->AlgVars[93]
#define River_2_state_Q_In pModel->AlgVars[94]
#define River_2_interface_T pModel->AlgVars[95]
#define River_2_state_T_wat_help pModel->AlgVars[96]
#define River_2_state_T_wat pModel->AlgVars[97]
#define River_2_state_CS pModel->AlgVars[98]
#define River_2_state_OTR pModel->AlgVars[99]
#define River_2_interface_kLa pModel->AlgVars[100]
#define River_2_state_SOTR pModel->AlgVars[101]
#define River_2_state_BOD pModel->AlgVars[102]
#define River_2_state_vel_water pModel->AlgVars[103]
#define River_2_state_KL20_help pModel->AlgVars[104]
#define River_2_state_KL20 pModel->AlgVars[105]
#define River_2_state_KLT pModel->AlgVars[106]
#define River_2_state_REAR pModel->AlgVars[107]
#define River_2_interface_I0 pModel->AlgVars[108]
#define River_2_state_PO2M pModel->AlgVars[109]
#define River_2_state_SedO2 pModel->AlgVars[110]
#define River_2_state_BODox pModel->AlgVars[111]
#define River_2_state_Nitrif pModel->AlgVars[112]
#define River_2_state_SODT pModel->AlgVars[113]
#define River_2_state_ConversionTermPerComponent_1_1_1_ pModel->AlgVars[114]
#define River_2_state_ConversionTermPerComponent_2_1_1_ pModel->AlgVars[115]
#define River_2_state_ConversionTermPerComponent_3_1_1_ pModel->AlgVars[116]
#define River_2_state_ConversionTermPerComponent_4_1_1_ pModel->AlgVars[117]
#define River_2_state_ConversionTermPerComponent_5_1_1_ pModel->AlgVars[118]
#define River_2_state_ConversionTermPerComponent_6_1_1_ pModel->AlgVars[119]
#define River_2_state_ConversionTermPerComponent_7_1_1_ pModel->AlgVars[120]
#define River_2_state_ConversionTermPerComponent_8_1_1_ pModel->AlgVars[121]
#define River_2_interface_DO pModel->AlgVars[122]
#define River_2_interface_NH4 pModel->AlgVars[123]
#define River_2_interface_Q pModel->AlgVars[124]
#define River_2_state_DO_sat_perc pModel->AlgVars[125]
#define River_2_state_UIamm pModel->AlgVars[126]
#define River_2_state_UIamm_corr pModel->AlgVars[127]
#define River_2_state_DO_corr pModel->AlgVars[128]
#define River_3_interface_Inflow1_1_1_1_ pModel->AlgVars[129]
#define River_3_interface_Inflow1_2_1_1_ pModel->AlgVars[130]
#define River_3_interface_Inflow1_3_1_1_ pModel->AlgVars[131]
#define River_3_interface_Inflow1_4_1_1_ pModel->AlgVars[132]
#define River_3_interface_Inflow1_5_1_1_ pModel->AlgVars[133]
#define River_3_interface_Inflow1_6_1_1_ pModel->AlgVars[134]
#define River_3_interface_Inflow1_7_1_1_ pModel->AlgVars[135]
#define River_3_interface_Inflow1_8_1_1_ pModel->AlgVars[136]
#define River_3_state_V_help pModel->AlgVars[137]
#define River_3_state_V pModel->AlgVars[138]
#define River_3_state_C_1_1_1_ pModel->AlgVars[139]
#define River_3_state_C_2_1_1_ pModel->AlgVars[140]
#define River_3_state_C_3_1_1_ pModel->AlgVars[141]
#define River_3_state_C_4_1_1_ pModel->AlgVars[142]
#define River_3_state_C_5_1_1_ pModel->AlgVars[143]
#define River_3_state_C_6_1_1_ pModel->AlgVars[144]
#define River_3_state_C_7_1_1_ pModel->AlgVars[145]
#define River_3_state_C_8_1_1_ pModel->AlgVars[146]
#define River_3_state_A_man pModel->AlgVars[147]
#define River_3_state_A pModel->AlgVars[148]
#define River_3_state_d pModel->AlgVars[149]
#define River_3_state_P pModel->AlgVars[150]
#define River_3_state_R pModel->AlgVars[151]
#define River_3_state_Q_Out pModel->AlgVars[152]
#define River_3_interface_Outflow_1_1_1_ pModel->AlgVars[153]
#define River_3_interface_Outflow_2_1_1_ pModel->AlgVars[154]
#define River_3_interface_Outflow_3_1_1_ pModel->AlgVars[155]
#define River_3_interface_Outflow_4_1_1_ pModel->AlgVars[156]
#define River_3_interface_Outflow_5_1_1_ pModel->AlgVars[157]
#define River_3_interface_Outflow_6_1_1_ pModel->AlgVars[158]
#define River_3_interface_Outflow_7_1_1_ pModel->AlgVars[159]
#define River_3_interface_Outflow_8_1_1_ pModel->AlgVars[160]
#define River_3_state_FluxPerComponent_1_1_1_ pModel->AlgVars[161]
#define River_3_state_FluxPerComponent_2_1_1_ pModel->AlgVars[162]
#define River_3_state_FluxPerComponent_3_1_1_ pModel->AlgVars[163]
#define River_3_state_FluxPerComponent_4_1_1_ pModel->AlgVars[164]
#define River_3_state_FluxPerComponent_5_1_1_ pModel->AlgVars[165]
#define River_3_state_FluxPerComponent_6_1_1_ pModel->AlgVars[166]
#define River_3_state_FluxPerComponent_7_1_1_ pModel->AlgVars[167]
#define River_3_state_FluxPerComponent_8_1_1_ pModel->AlgVars[168]
#define River_3_interface_Inflow2_1_1_1_ pModel->AlgVars[169]
#define River_3_interface_Inflow2_2_1_1_ pModel->AlgVars[170]
#define River_3_interface_Inflow2_3_1_1_ pModel->AlgVars[171]
#define River_3_interface_Inflow2_4_1_1_ pModel->AlgVars[172]
#define River_3_interface_Inflow2_5_1_1_ pModel->AlgVars[173]
#define River_3_interface_Inflow2_6_1_1_ pModel->AlgVars[174]
#define River_3_interface_Inflow2_7_1_1_ pModel->AlgVars[175]
#define River_3_interface_Inflow2_8_1_1_ pModel->AlgVars[176]
#define River_3_state_InFluxPerComponent_1_1_1_ pModel->AlgVars[177]
#define River_3_state_InFluxPerComponent_2_1_1_ pModel->AlgVars[178]
#define River_3_state_InFluxPerComponent_3_1_1_ pModel->AlgVars[179]
#define River_3_state_InFluxPerComponent_4_1_1_ pModel->AlgVars[180]
#define River_3_state_InFluxPerComponent_5_1_1_ pModel->AlgVars[181]
#define River_3_state_InFluxPerComponent_6_1_1_ pModel->AlgVars[182]
#define River_3_state_InFluxPerComponent_7_1_1_ pModel->AlgVars[183]
#define River_3_state_InFluxPerComponent_8_1_1_ pModel->AlgVars[184]
#define River_3_state_Q_In pModel->AlgVars[185]
#define River_3_interface_T pModel->AlgVars[186]
#define River_3_state_T_wat_help pModel->AlgVars[187]
#define River_3_state_T_wat pModel->AlgVars[188]
#define River_3_state_CS pModel->AlgVars[189]
#define River_3_state_OTR pModel->AlgVars[190]
#define River_3_interface_kLa pModel->AlgVars[191]
#define River_3_state_SOTR pModel->AlgVars[192]
#define River_3_state_BOD pModel->AlgVars[193]
#define River_3_state_vel_water pModel->AlgVars[194]
#define River_3_state_KL20_help pModel->AlgVars[195]
#define River_3_state_KL20 pModel->AlgVars[196]
#define River_3_state_KLT pModel->AlgVars[197]
#define River_3_state_REAR pModel->AlgVars[198]
#define River_3_interface_I0 pModel->AlgVars[199]
#define River_3_state_PO2M pModel->AlgVars[200]
#define River_3_state_SedO2 pModel->AlgVars[201]
#define River_3_state_BODox pModel->AlgVars[202]
#define River_3_state_Nitrif pModel->AlgVars[203]
#define River_3_state_SODT pModel->AlgVars[204]
#define River_3_state_ConversionTermPerComponent_1_1_1_ pModel->AlgVars[205]
#define River_3_state_ConversionTermPerComponent_2_1_1_ pModel->AlgVars[206]
#define River_3_state_ConversionTermPerComponent_3_1_1_ pModel->AlgVars[207]
#define River_3_state_ConversionTermPerComponent_4_1_1_ pModel->AlgVars[208]
#define River_3_state_ConversionTermPerComponent_5_1_1_ pModel->AlgVars[209]
#define River_3_state_ConversionTermPerComponent_6_1_1_ pModel->AlgVars[210]
#define River_3_state_ConversionTermPerComponent_7_1_1_ pModel->AlgVars[211]
#define River_3_state_ConversionTermPerComponent_8_1_1_ pModel->AlgVars[212]
#define River_3_interface_DO pModel->AlgVars[213]
#define River_3_interface_NH4 pModel->AlgVars[214]
#define River_3_interface_Q pModel->AlgVars[215]
#define River_3_state_DO_sat_perc pModel->AlgVars[216]
#define River_3_state_UIamm pModel->AlgVars[217]
#define River_3_state_UIamm_corr pModel->AlgVars[218]
#define River_3_state_DO_corr pModel->AlgVars[219]
#define River_4_interface_Inflow1_1_1_1_ pModel->AlgVars[220]
#define River_4_interface_Inflow1_2_1_1_ pModel->AlgVars[221]
#define River_4_interface_Inflow1_3_1_1_ pModel->AlgVars[222]
#define River_4_interface_Inflow1_4_1_1_ pModel->AlgVars[223]
#define River_4_interface_Inflow1_5_1_1_ pModel->AlgVars[224]
#define River_4_interface_Inflow1_6_1_1_ pModel->AlgVars[225]
#define River_4_interface_Inflow1_7_1_1_ pModel->AlgVars[226]
#define River_4_interface_Inflow1_8_1_1_ pModel->AlgVars[227]
#define River_4_state_V_help pModel->AlgVars[228]
#define River_4_state_V pModel->AlgVars[229]
#define River_4_state_C_1_1_1_ pModel->AlgVars[230]
#define River_4_state_C_2_1_1_ pModel->AlgVars[231]
#define River_4_state_C_3_1_1_ pModel->AlgVars[232]
#define River_4_state_C_4_1_1_ pModel->AlgVars[233]
#define River_4_state_C_5_1_1_ pModel->AlgVars[234]
#define River_4_state_C_6_1_1_ pModel->AlgVars[235]
#define River_4_state_C_7_1_1_ pModel->AlgVars[236]
#define River_4_state_C_8_1_1_ pModel->AlgVars[237]
#define River_4_state_A_man pModel->AlgVars[238]
#define River_4_state_A pModel->AlgVars[239]
#define River_4_state_d pModel->AlgVars[240]
#define River_4_state_P pModel->AlgVars[241]
#define River_4_state_R pModel->AlgVars[242]
#define River_4_state_Q_Out pModel->AlgVars[243]
#define River_4_interface_Outflow_1_1_1_ pModel->AlgVars[244]
#define River_4_interface_Outflow_2_1_1_ pModel->AlgVars[245]
#define River_4_interface_Outflow_3_1_1_ pModel->AlgVars[246]
#define River_4_interface_Outflow_4_1_1_ pModel->AlgVars[247]
#define River_4_interface_Outflow_5_1_1_ pModel->AlgVars[248]
#define River_4_interface_Outflow_6_1_1_ pModel->AlgVars[249]
#define River_4_interface_Outflow_7_1_1_ pModel->AlgVars[250]
#define River_4_interface_Outflow_8_1_1_ pModel->AlgVars[251]
#define River_4_state_FluxPerComponent_1_1_1_ pModel->AlgVars[252]
#define River_4_state_FluxPerComponent_2_1_1_ pModel->AlgVars[253]
#define River_4_state_FluxPerComponent_3_1_1_ pModel->AlgVars[254]
#define River_4_state_FluxPerComponent_4_1_1_ pModel->AlgVars[255]
#define River_4_state_FluxPerComponent_5_1_1_ pModel->AlgVars[256]
#define River_4_state_FluxPerComponent_6_1_1_ pModel->AlgVars[257]
#define River_4_state_FluxPerComponent_7_1_1_ pModel->AlgVars[258]
#define River_4_state_FluxPerComponent_8_1_1_ pModel->AlgVars[259]
#define River_4_interface_Inflow2_1_1_1_ pModel->AlgVars[260]
#define River_4_interface_Inflow2_2_1_1_ pModel->AlgVars[261]
#define River_4_interface_Inflow2_3_1_1_ pModel->AlgVars[262]
#define River_4_interface_Inflow2_4_1_1_ pModel->AlgVars[263]
#define River_4_interface_Inflow2_5_1_1_ pModel->AlgVars[264]
#define River_4_interface_Inflow2_6_1_1_ pModel->AlgVars[265]
#define River_4_interface_Inflow2_7_1_1_ pModel->AlgVars[266]
#define River_4_interface_Inflow2_8_1_1_ pModel->AlgVars[267]
#define River_4_state_InFluxPerComponent_1_1_1_ pModel->AlgVars[268]
#define River_4_state_InFluxPerComponent_2_1_1_ pModel->AlgVars[269]
#define River_4_state_InFluxPerComponent_3_1_1_ pModel->AlgVars[270]
#define River_4_state_InFluxPerComponent_4_1_1_ pModel->AlgVars[271]
#define River_4_state_InFluxPerComponent_5_1_1_ pModel->AlgVars[272]
#define River_4_state_InFluxPerComponent_6_1_1_ pModel->AlgVars[273]
#define River_4_state_InFluxPerComponent_7_1_1_ pModel->AlgVars[274]
#define River_4_state_InFluxPerComponent_8_1_1_ pModel->AlgVars[275]
#define River_4_state_Q_In pModel->AlgVars[276]
#define River_4_interface_T pModel->AlgVars[277]
#define River_4_state_T_wat_help pModel->AlgVars[278]
#define River_4_state_T_wat pModel->AlgVars[279]
#define River_4_state_CS pModel->AlgVars[280]
#define River_4_state_OTR pModel->AlgVars[281]
#define River_4_interface_kLa pModel->AlgVars[282]
#define River_4_state_SOTR pModel->AlgVars[283]
#define River_4_state_BOD pModel->AlgVars[284]
#define River_4_state_vel_water pModel->AlgVars[285]
#define River_4_state_KL20_help pModel->AlgVars[286]
#define River_4_state_KL20 pModel->AlgVars[287]
#define River_4_state_KLT pModel->AlgVars[288]
#define River_4_state_REAR pModel->AlgVars[289]
#define River_4_interface_I0 pModel->AlgVars[290]
#define River_4_state_PO2M pModel->AlgVars[291]
#define River_4_state_SedO2 pModel->AlgVars[292]
#define River_4_state_BODox pModel->AlgVars[293]
#define River_4_state_Nitrif pModel->AlgVars[294]
#define River_4_state_SODT pModel->AlgVars[295]
#define River_4_state_ConversionTermPerComponent_1_1_1_ pModel->AlgVars[296]
#define River_4_state_ConversionTermPerComponent_2_1_1_ pModel->AlgVars[297]
#define River_4_state_ConversionTermPerComponent_3_1_1_ pModel->AlgVars[298]
#define River_4_state_ConversionTermPerComponent_4_1_1_ pModel->AlgVars[299]
#define River_4_state_ConversionTermPerComponent_5_1_1_ pModel->AlgVars[300]
#define River_4_state_ConversionTermPerComponent_6_1_1_ pModel->AlgVars[301]
#define River_4_state_ConversionTermPerComponent_7_1_1_ pModel->AlgVars[302]
#define River_4_state_ConversionTermPerComponent_8_1_1_ pModel->AlgVars[303]
#define River_4_interface_DO pModel->AlgVars[304]
#define River_4_interface_NH4 pModel->AlgVars[305]
#define River_4_interface_Q pModel->AlgVars[306]
#define River_4_state_DO_sat_perc pModel->AlgVars[307]
#define River_4_state_UIamm pModel->AlgVars[308]
#define River_4_state_UIamm_corr pModel->AlgVars[309]
#define River_4_state_DO_corr pModel->AlgVars[310]
#define River_5_interface_Inflow1_1_1_1_ pModel->AlgVars[311]
#define River_5_interface_Inflow1_2_1_1_ pModel->AlgVars[312]
#define River_5_interface_Inflow1_3_1_1_ pModel->AlgVars[313]
#define River_5_interface_Inflow1_4_1_1_ pModel->AlgVars[314]
#define River_5_interface_Inflow1_5_1_1_ pModel->AlgVars[315]
#define River_5_interface_Inflow1_6_1_1_ pModel->AlgVars[316]
#define River_5_interface_Inflow1_7_1_1_ pModel->AlgVars[317]
#define River_5_interface_Inflow1_8_1_1_ pModel->AlgVars[318]
#define River_5_state_V_help pModel->AlgVars[319]
#define River_5_state_V pModel->AlgVars[320]
#define River_5_state_C_1_1_1_ pModel->AlgVars[321]
#define River_5_state_C_2_1_1_ pModel->AlgVars[322]
#define River_5_state_C_3_1_1_ pModel->AlgVars[323]
#define River_5_state_C_4_1_1_ pModel->AlgVars[324]
#define River_5_state_C_5_1_1_ pModel->AlgVars[325]
#define River_5_state_C_6_1_1_ pModel->AlgVars[326]
#define River_5_state_C_7_1_1_ pModel->AlgVars[327]
#define River_5_state_C_8_1_1_ pModel->AlgVars[328]
#define River_5_state_A_man pModel->AlgVars[329]
#define River_5_state_A pModel->AlgVars[330]
#define River_5_state_d pModel->AlgVars[331]
#define River_5_state_P pModel->AlgVars[332]
#define River_5_state_R pModel->AlgVars[333]
#define River_5_state_Q_Out pModel->AlgVars[334]
#define River_5_interface_Outflow_1_1_1_ pModel->AlgVars[335]
#define River_5_interface_Outflow_2_1_1_ pModel->AlgVars[336]
#define River_5_interface_Outflow_3_1_1_ pModel->AlgVars[337]
#define River_5_interface_Outflow_4_1_1_ pModel->AlgVars[338]
#define River_5_interface_Outflow_5_1_1_ pModel->AlgVars[339]
#define River_5_interface_Outflow_6_1_1_ pModel->AlgVars[340]
#define River_5_interface_Outflow_7_1_1_ pModel->AlgVars[341]
#define River_5_interface_Outflow_8_1_1_ pModel->AlgVars[342]
#define River_5_state_FluxPerComponent_1_1_1_ pModel->AlgVars[343]
#define River_5_state_FluxPerComponent_2_1_1_ pModel->AlgVars[344]
#define River_5_state_FluxPerComponent_3_1_1_ pModel->AlgVars[345]
#define River_5_state_FluxPerComponent_4_1_1_ pModel->AlgVars[346]
#define River_5_state_FluxPerComponent_5_1_1_ pModel->AlgVars[347]
#define River_5_state_FluxPerComponent_6_1_1_ pModel->AlgVars[348]
#define River_5_state_FluxPerComponent_7_1_1_ pModel->AlgVars[349]
#define River_5_state_FluxPerComponent_8_1_1_ pModel->AlgVars[350]
#define River_5_interface_Inflow2_1_1_1_ pModel->AlgVars[351]
#define River_5_interface_Inflow2_2_1_1_ pModel->AlgVars[352]
#define River_5_interface_Inflow2_3_1_1_ pModel->AlgVars[353]
#define River_5_interface_Inflow2_4_1_1_ pModel->AlgVars[354]
#define River_5_interface_Inflow2_5_1_1_ pModel->AlgVars[355]
#define River_5_interface_Inflow2_6_1_1_ pModel->AlgVars[356]
#define River_5_interface_Inflow2_7_1_1_ pModel->AlgVars[357]
#define River_5_interface_Inflow2_8_1_1_ pModel->AlgVars[358]
#define River_5_state_InFluxPerComponent_1_1_1_ pModel->AlgVars[359]
#define River_5_state_InFluxPerComponent_2_1_1_ pModel->AlgVars[360]
#define River_5_state_InFluxPerComponent_3_1_1_ pModel->AlgVars[361]
#define River_5_state_InFluxPerComponent_4_1_1_ pModel->AlgVars[362]
#define River_5_state_InFluxPerComponent_5_1_1_ pModel->AlgVars[363]
#define River_5_state_InFluxPerComponent_6_1_1_ pModel->AlgVars[364]
#define River_5_state_InFluxPerComponent_7_1_1_ pModel->AlgVars[365]
#define River_5_state_InFluxPerComponent_8_1_1_ pModel->AlgVars[366]
#define River_5_state_Q_In pModel->AlgVars[367]
#define River_5_interface_T pModel->AlgVars[368]
#define River_5_state_T_wat_help pModel->AlgVars[369]
#define River_5_state_T_wat pModel->AlgVars[370]
#define River_5_state_CS pModel->AlgVars[371]
#define River_5_state_OTR pModel->AlgVars[372]
#define River_5_interface_kLa pModel->AlgVars[373]
#define River_5_state_SOTR pModel->AlgVars[374]
#define River_5_state_BOD pModel->AlgVars[375]
#define River_5_state_vel_water pModel->AlgVars[376]
#define River_5_state_KL20_help pModel->AlgVars[377]
#define River_5_state_KL20 pModel->AlgVars[378]
#define River_5_state_KLT pModel->AlgVars[379]
#define River_5_state_REAR pModel->AlgVars[380]
#define River_5_interface_I0 pModel->AlgVars[381]
#define River_5_state_PO2M pModel->AlgVars[382]
#define River_5_state_SedO2 pModel->AlgVars[383]
#define River_5_state_BODox pModel->AlgVars[384]
#define River_5_state_Nitrif pModel->AlgVars[385]
#define River_5_state_SODT pModel->AlgVars[386]
#define River_5_state_ConversionTermPerComponent_1_1_1_ pModel->AlgVars[387]
#define River_5_state_ConversionTermPerComponent_2_1_1_ pModel->AlgVars[388]
#define River_5_state_ConversionTermPerComponent_3_1_1_ pModel->AlgVars[389]
#define River_5_state_ConversionTermPerComponent_4_1_1_ pModel->AlgVars[390]
#define River_5_state_ConversionTermPerComponent_5_1_1_ pModel->AlgVars[391]
#define River_5_state_ConversionTermPerComponent_6_1_1_ pModel->AlgVars[392]
#define River_5_state_ConversionTermPerComponent_7_1_1_ pModel->AlgVars[393]
#define River_5_state_ConversionTermPerComponent_8_1_1_ pModel->AlgVars[394]
#define River_5_interface_DO pModel->AlgVars[395]
#define River_5_interface_NH4 pModel->AlgVars[396]
#define River_5_interface_Q pModel->AlgVars[397]
#define River_5_state_DO_sat_perc pModel->AlgVars[398]
#define River_5_state_UIamm pModel->AlgVars[399]
#define River_5_state_UIamm_corr pModel->AlgVars[400]
#define River_5_state_DO_corr pModel->AlgVars[401]
#define Rural_inflow_interface_rainfall pModel->AlgVars[402]
#define Rural_inflow_interface_Outflow_1_1_1_ pModel->AlgVars[403]
#define Rural_inflow_interface_Outflow_2_1_1_ pModel->AlgVars[404]
#define Rural_inflow_interface_Outflow_3_1_1_ pModel->AlgVars[405]
#define Rural_inflow_interface_Outflow_4_1_1_ pModel->AlgVars[406]
#define Rural_inflow_interface_Outflow_5_1_1_ pModel->AlgVars[407]
#define Rural_inflow_interface_Outflow_6_1_1_ pModel->AlgVars[408]
#define Rural_inflow_interface_Outflow_7_1_1_ pModel->AlgVars[409]
#define Rural_inflow_interface_Outflow_8_1_1_ pModel->AlgVars[410]
#define River_1_interface_Inflow1_1_1_1_ pModel->AlgVars[411]
#define River_1_interface_Inflow1_2_1_1_ pModel->AlgVars[412]
#define River_1_interface_Inflow1_3_1_1_ pModel->AlgVars[413]
#define River_1_interface_Inflow1_4_1_1_ pModel->AlgVars[414]
#define River_1_interface_Inflow1_5_1_1_ pModel->AlgVars[415]
#define River_1_interface_Inflow1_6_1_1_ pModel->AlgVars[416]
#define River_1_interface_Inflow1_7_1_1_ pModel->AlgVars[417]
#define River_1_interface_Inflow1_8_1_1_ pModel->AlgVars[418]
#define River_1_state_FluxPerComponent_1_1_1_ pModel->AlgVars[419]
#define River_1_state_FluxPerComponent_2_1_1_ pModel->AlgVars[420]
#define River_1_state_FluxPerComponent_3_1_1_ pModel->AlgVars[421]
#define River_1_state_FluxPerComponent_4_1_1_ pModel->AlgVars[422]
#define River_1_state_FluxPerComponent_5_1_1_ pModel->AlgVars[423]
#define River_1_state_FluxPerComponent_6_1_1_ pModel->AlgVars[424]
#define River_1_state_FluxPerComponent_7_1_1_ pModel->AlgVars[425]
#define River_1_state_FluxPerComponent_8_1_1_ pModel->AlgVars[426]
#define River_1_interface_Inflow2_1_1_1_ pModel->AlgVars[427]
#define River_1_interface_Inflow2_2_1_1_ pModel->AlgVars[428]
#define River_1_interface_Inflow2_3_1_1_ pModel->AlgVars[429]
#define River_1_interface_Inflow2_4_1_1_ pModel->AlgVars[430]
#define River_1_interface_Inflow2_5_1_1_ pModel->AlgVars[431]
#define River_1_interface_Inflow2_6_1_1_ pModel->AlgVars[432]
#define River_1_interface_Inflow2_7_1_1_ pModel->AlgVars[433]
#define River_1_interface_Inflow2_8_1_1_ pModel->AlgVars[434]
#define Rural_inflow_state_Q pModel->AlgVars[435]
#define Rural_inflow_interface_NH4_in pModel->AlgVars[436]
#define River_1_state_InFluxPerComponent_1_1_1_ pModel->AlgVars[437]
#define River_1_state_InFluxPerComponent_2_1_1_ pModel->AlgVars[438]
#define River_1_state_InFluxPerComponent_3_1_1_ pModel->AlgVars[439]
#define River_1_state_InFluxPerComponent_4_1_1_ pModel->AlgVars[440]
#define River_1_state_InFluxPerComponent_5_1_1_ pModel->AlgVars[441]
#define River_1_state_InFluxPerComponent_6_1_1_ pModel->AlgVars[442]
#define River_1_state_InFluxPerComponent_7_1_1_ pModel->AlgVars[443]
#define River_1_state_InFluxPerComponent_8_1_1_ pModel->AlgVars[444]
#define River_1_state_Q_In pModel->AlgVars[445]
#define River_1_interface_T pModel->AlgVars[446]
#define River_1_state_T_wat_help pModel->AlgVars[447]
#define River_1_state_T_wat pModel->AlgVars[448]
#define River_1_state_CS pModel->AlgVars[449]
#define River_1_state_OTR pModel->AlgVars[450]
#define River_1_interface_kLa pModel->AlgVars[451]
#define River_1_state_SOTR pModel->AlgVars[452]
#define River_1_state_BOD pModel->AlgVars[453]
#define River_1_state_vel_water pModel->AlgVars[454]
#define River_1_state_KL20_help pModel->AlgVars[455]
#define River_1_state_KL20 pModel->AlgVars[456]
#define River_1_state_KLT pModel->AlgVars[457]
#define River_1_state_REAR pModel->AlgVars[458]
#define River_1_interface_I0 pModel->AlgVars[459]
#define River_1_state_PO2M pModel->AlgVars[460]
#define River_1_state_SedO2 pModel->AlgVars[461]
#define River_1_state_BODox pModel->AlgVars[462]
#define River_1_state_Nitrif pModel->AlgVars[463]
#define River_1_state_SODT pModel->AlgVars[464]
#define River_1_state_ConversionTermPerComponent_1_1_1_ pModel->AlgVars[465]
#define River_1_state_ConversionTermPerComponent_2_1_1_ pModel->AlgVars[466]
#define River_1_state_ConversionTermPerComponent_3_1_1_ pModel->AlgVars[467]
#define River_1_state_ConversionTermPerComponent_4_1_1_ pModel->AlgVars[468]
#define River_1_state_ConversionTermPerComponent_5_1_1_ pModel->AlgVars[469]
#define River_1_state_ConversionTermPerComponent_6_1_1_ pModel->AlgVars[470]
#define River_1_state_ConversionTermPerComponent_7_1_1_ pModel->AlgVars[471]
#define River_1_state_ConversionTermPerComponent_8_1_1_ pModel->AlgVars[472]
#define River_1_interface_DO pModel->AlgVars[473]
#define River_1_interface_NH4 pModel->AlgVars[474]
#define River_1_interface_Q pModel->AlgVars[475]
#define River_1_state_DO_sat_perc pModel->AlgVars[476]
#define River_1_state_UIamm pModel->AlgVars[477]
#define River_1_state_UIamm_corr pModel->AlgVars[478]
#define River_1_state_DO_corr pModel->AlgVars[479]

#define River_2_state_M_1_1_1_ pModel->DerVars[0]
#define _D_River_2_state_M_1_1_1_ pModel->Derivatives[0]
#define River_2_state_M_2_1_1_ pModel->DerVars[1]
#define _D_River_2_state_M_2_1_1_ pModel->Derivatives[1]
#define River_2_state_M_3_1_1_ pModel->DerVars[2]
#define _D_River_2_state_M_3_1_1_ pModel->Derivatives[2]
#define River_2_state_M_4_1_1_ pModel->DerVars[3]
#define _D_River_2_state_M_4_1_1_ pModel->Derivatives[3]
#define River_2_state_M_5_1_1_ pModel->DerVars[4]
#define _D_River_2_state_M_5_1_1_ pModel->Derivatives[4]
#define River_2_state_M_6_1_1_ pModel->DerVars[5]
#define _D_River_2_state_M_6_1_1_ pModel->Derivatives[5]
#define River_2_state_M_7_1_1_ pModel->DerVars[6]
#define _D_River_2_state_M_7_1_1_ pModel->Derivatives[6]
#define River_2_state_M_8_1_1_ pModel->DerVars[7]
#define _D_River_2_state_M_8_1_1_ pModel->Derivatives[7]
#define River_3_state_M_1_1_1_ pModel->DerVars[8]
#define _D_River_3_state_M_1_1_1_ pModel->Derivatives[8]
#define River_3_state_M_2_1_1_ pModel->DerVars[9]
#define _D_River_3_state_M_2_1_1_ pModel->Derivatives[9]
#define River_3_state_M_3_1_1_ pModel->DerVars[10]
#define _D_River_3_state_M_3_1_1_ pModel->Derivatives[10]
#define River_3_state_M_4_1_1_ pModel->DerVars[11]
#define _D_River_3_state_M_4_1_1_ pModel->Derivatives[11]
#define River_3_state_M_5_1_1_ pModel->DerVars[12]
#define _D_River_3_state_M_5_1_1_ pModel->Derivatives[12]
#define River_3_state_M_6_1_1_ pModel->DerVars[13]
#define _D_River_3_state_M_6_1_1_ pModel->Derivatives[13]
#define River_3_state_M_7_1_1_ pModel->DerVars[14]
#define _D_River_3_state_M_7_1_1_ pModel->Derivatives[14]
#define River_3_state_M_8_1_1_ pModel->DerVars[15]
#define _D_River_3_state_M_8_1_1_ pModel->Derivatives[15]
#define River_4_state_M_1_1_1_ pModel->DerVars[16]
#define _D_River_4_state_M_1_1_1_ pModel->Derivatives[16]
#define River_4_state_M_2_1_1_ pModel->DerVars[17]
#define _D_River_4_state_M_2_1_1_ pModel->Derivatives[17]
#define River_4_state_M_3_1_1_ pModel->DerVars[18]
#define _D_River_4_state_M_3_1_1_ pModel->Derivatives[18]
#define River_4_state_M_4_1_1_ pModel->DerVars[19]
#define _D_River_4_state_M_4_1_1_ pModel->Derivatives[19]
#define River_4_state_M_5_1_1_ pModel->DerVars[20]
#define _D_River_4_state_M_5_1_1_ pModel->Derivatives[20]
#define River_4_state_M_6_1_1_ pModel->DerVars[21]
#define _D_River_4_state_M_6_1_1_ pModel->Derivatives[21]
#define River_4_state_M_7_1_1_ pModel->DerVars[22]
#define _D_River_4_state_M_7_1_1_ pModel->Derivatives[22]
#define River_4_state_M_8_1_1_ pModel->DerVars[23]
#define _D_River_4_state_M_8_1_1_ pModel->Derivatives[23]
#define River_5_state_M_1_1_1_ pModel->DerVars[24]
#define _D_River_5_state_M_1_1_1_ pModel->Derivatives[24]
#define River_5_state_M_2_1_1_ pModel->DerVars[25]
#define _D_River_5_state_M_2_1_1_ pModel->Derivatives[25]
#define River_5_state_M_3_1_1_ pModel->DerVars[26]
#define _D_River_5_state_M_3_1_1_ pModel->Derivatives[26]
#define River_5_state_M_4_1_1_ pModel->DerVars[27]
#define _D_River_5_state_M_4_1_1_ pModel->Derivatives[27]
#define River_5_state_M_5_1_1_ pModel->DerVars[28]
#define _D_River_5_state_M_5_1_1_ pModel->Derivatives[28]
#define River_5_state_M_6_1_1_ pModel->DerVars[29]
#define _D_River_5_state_M_6_1_1_ pModel->Derivatives[29]
#define River_5_state_M_7_1_1_ pModel->DerVars[30]
#define _D_River_5_state_M_7_1_1_ pModel->Derivatives[30]
#define River_5_state_M_8_1_1_ pModel->DerVars[31]
#define _D_River_5_state_M_8_1_1_ pModel->Derivatives[31]
#define River_1_state_M_1_1_1_ pModel->DerVars[32]
#define _D_River_1_state_M_1_1_1_ pModel->Derivatives[32]
#define River_1_state_M_2_1_1_ pModel->DerVars[33]
#define _D_River_1_state_M_2_1_1_ pModel->Derivatives[33]
#define River_1_state_M_3_1_1_ pModel->DerVars[34]
#define _D_River_1_state_M_3_1_1_ pModel->Derivatives[34]
#define River_1_state_M_4_1_1_ pModel->DerVars[35]
#define _D_River_1_state_M_4_1_1_ pModel->Derivatives[35]
#define River_1_state_M_5_1_1_ pModel->DerVars[36]
#define _D_River_1_state_M_5_1_1_ pModel->Derivatives[36]
#define River_1_state_M_6_1_1_ pModel->DerVars[37]
#define _D_River_1_state_M_6_1_1_ pModel->Derivatives[37]
#define River_1_state_M_7_1_1_ pModel->DerVars[38]
#define _D_River_1_state_M_7_1_1_ pModel->Derivatives[38]
#define River_1_state_M_8_1_1_ pModel->DerVars[39]
#define _D_River_1_state_M_8_1_1_ pModel->Derivatives[39]


#ifdef _WIN32
#ifndef _WIN32
#undef _SVID_SOURCE
#define _SVID_SOURCE

extern _LIB_VERSION_TYPE _LIB_VERSION;
#endif

int
#ifdef _WIN32
_matherr(struct _exception* except)
#else
matherr(struct exception* except)
#endif
{
  static char Buffer[1024];

  switch (except->type)
  {
#ifdef _MSC_VER
    case _DOMAIN:
#else
    case DOMAIN:
#endif
      sprintf(Buffer, "Argument domain error: %s(%g, %g)", except->name, except->arg1, except->arg2);
      break;

#ifdef _MSC_VER
    case _SING:
#else
    case SING:
#endif
      sprintf(Buffer, "Argument singularity: %s(%g, %g)", except->name, except->arg1, except->arg2);
      break;

#ifdef _MSC_VER
    case _OVERFLOW:
#else
    case OVERFLOW:
#endif
      sprintf(Buffer, "Overflow range error: %s(%g, %g)", except->name, except->arg1, except->arg2);
      break;

#ifdef _MSC_VER
    case _PLOSS:
#else
    case PLOSS:
#endif
      sprintf(Buffer, "Partial loss of significance: %s(%g, %g)", except->name, except->arg1, except->arg2);
      break;

#ifdef _MSC_VER
    case _TLOSS:
#else
    case TLOSS:
#endif
      sprintf(Buffer, "Total loss of significance: %s(%g, %g)", except->name, except->arg1, except->arg2);
      break;

#ifdef _MSC_VER
    case _UNDERFLOW:
#else
    case UNDERFLOW:
#endif
      sprintf(Buffer, "The result is too small to be represented: %s(%g, %g)", except->name, except->arg1, except->arg2);
      break;

    default:
      sprintf(Buffer, "Unknown error type: %s(%g, %g)", except->name, except->arg1, except->arg2);
  }

  MSLUMessage(MSLU_ERROR, Buffer);

  return 1;
}
#endif


double
MSLUMessage2(struct TModel* pModel,
             size_t Type,
             const char* pMessage)
{
  MSLUMessage(Type, pMessage);
  if (Type == MSLU_ERROR)
    longjmp(pModel->JumpBuffer, 1);

  return 0;
}

#define MSLUMessage(Type, pMessage) MSLUMessage2(pModel, Type, pMessage)


char*
SetPath(const char* pPath)
{
  return MSLUSetPath(pPath);
}





int
ComputeInitial(struct TModel* pModel)
{
  MSLUConfigure(NULL, pModel->pCaller, pModel->pCallbackMessage, pModel->pCallbackTerminate, pModel->pCallbackGetStartTime, pModel->pCallbackGetStopTime, pModel->pCallbackSetGlobalValue, pModel->pCallbackGetGlobalValue, pModel->pCallbackSetGlobalVector, pModel->pCallbackGetGlobalVector);

  River_4_parameters_SOD = SOD;
  River_1_parameters_SOD = SOD;
  River_5_parameters_SOD = SOD;
  River_2_parameters_SOD = SOD;
  River_3_parameters_SOD = SOD;

  return 0;
}


int
ComputeState(struct TModel* pModel)
{
  River_1_state_V_help = ((1e-006 * River_1_state_M_1_1_1_) + (1e-006 * River_1_state_M_2_1_1_) + (1e-006 * River_1_state_M_3_1_1_) + (1e-006 * River_1_state_M_4_1_1_) + (1e-006 * River_1_state_M_5_1_1_) + (1e-006 * River_1_state_M_6_1_1_) + (1e-006 * River_1_state_M_7_1_1_) + (1e-006 * River_1_state_M_8_1_1_));

  River_1_state_V = ( (River_1_state_V_help <= River_1_parameters_Vol_min) ? (River_1_parameters_Vol_min) : (River_1_state_V_help) );

  River_1_state_C_1_1_1_ = ( (River_1_state_V == 0) ? (0) : (River_1_state_M_1_1_1_ / River_1_state_V) );

  River_1_state_A_man = (River_1_state_V - River_1_parameters_Vol_min) / River_1_parameters_L;

  River_1_state_A = River_1_state_V / River_1_parameters_L;

  River_1_state_d = ( (River_1_parameters_z > 0) ? (sqrt(River_1_state_A / River_1_parameters_z + pow((River_1_parameters_W_b / 2 / River_1_parameters_z), 2)) - (River_1_parameters_W_b / 2 / River_1_parameters_z)) : (River_1_state_A / River_1_parameters_W_b) );

  River_1_state_P = River_1_parameters_W_b + 2 * (River_1_state_d - River_1_parameters_d_min) * sqrt(1 + pow(River_1_parameters_z, 2));

  River_1_state_R = River_1_state_A_man / River_1_state_P;

  River_1_state_Q_Out = 60 * 60 * 24 * River_1_state_A_man * pow(River_1_state_R, (2.000000 / 3.000000)) * pow(River_1_parameters_slp, 0.5) / River_1_parameters_n;

  River_1_interface_Outflow_1_1_1_ = - River_1_state_C_1_1_1_ * River_1_state_Q_Out;

  River_2_interface_Inflow1_1_1_1_ = - River_1_interface_Outflow_1_1_1_;

  Urban_InputEmulator_interface_rainfall = Urban_CSO_flow;

  Urban_InputEmulator_interface_Outflow_1_1_1_ = - Urban_InputEmulator_interface_rainfall * Urban_InputEmulator_parameters_FactorEffluent * 1000000;

  River_2_interface_Inflow2_1_1_1_ = - Urban_InputEmulator_interface_Outflow_1_1_1_;

  River_2_state_V_help = ((1e-006 * River_2_state_M_1_1_1_) + (1e-006 * River_2_state_M_2_1_1_) + (1e-006 * River_2_state_M_3_1_1_) + (1e-006 * River_2_state_M_4_1_1_) + (1e-006 * River_2_state_M_5_1_1_) + (1e-006 * River_2_state_M_6_1_1_) + (1e-006 * River_2_state_M_7_1_1_) + (1e-006 * River_2_state_M_8_1_1_));

  River_2_state_V = ( (River_2_state_V_help <= River_2_parameters_Vol_min) ? (River_2_parameters_Vol_min) : (River_2_state_V_help) );

  River_2_state_C_1_1_1_ = ( (River_2_state_V == 0) ? (0) : (River_2_state_M_1_1_1_ / River_2_state_V) );

  River_2_state_A_man = (River_2_state_V - River_2_parameters_Vol_min) / River_2_parameters_L;

  River_2_state_A = River_2_state_V / River_2_parameters_L;

  River_2_state_d = ( (River_2_parameters_z > 0) ? (sqrt(River_2_state_A / River_2_parameters_z + pow((River_2_parameters_W_b / 2 / River_2_parameters_z), 2)) - (River_2_parameters_W_b / 2 / River_2_parameters_z)) : (River_2_state_A / River_2_parameters_W_b) );

  River_2_state_P = River_2_parameters_W_b + 2 * (River_2_state_d - River_2_parameters_d_min) * sqrt(1 + pow(River_2_parameters_z, 2));

  River_2_state_R = River_2_state_A_man / River_2_state_P;

  River_2_state_Q_Out = 60 * 60 * 24 * River_2_state_A_man * pow(River_2_state_R, (2.000000 / 3.000000)) * pow(River_2_parameters_slp, 0.5) / River_2_parameters_n;

  River_2_interface_Outflow_1_1_1_ = - River_2_state_C_1_1_1_ * River_2_state_Q_Out;

  River_2_state_FluxPerComponent_1_1_1_ = (River_2_interface_Inflow1_1_1_1_ + River_2_interface_Inflow2_1_1_1_) + (River_2_interface_Outflow_1_1_1_);

  River_1_state_C_2_1_1_ = ( (River_1_state_V == 0) ? (0) : (River_1_state_M_2_1_1_ / River_1_state_V) );

  River_1_interface_Outflow_2_1_1_ = - River_1_state_C_2_1_1_ * River_1_state_Q_Out;

  River_2_interface_Inflow1_2_1_1_ = - River_1_interface_Outflow_2_1_1_;

  Urban_InputEmulator_state_Q = - Urban_InputEmulator_interface_Outflow_1_1_1_ / 1000000;

  Urban_InputEmulator_interface_Outflow_2_1_1_ = - Urban_InputEmulator_parameters_Mult_O2 * Urban_InputEmulator_parameters_yesno * Urban_InputEmulator_interface_U_O2_in * Urban_InputEmulator_state_Q;

  River_2_interface_Inflow2_2_1_1_ = - Urban_InputEmulator_interface_Outflow_2_1_1_;

  River_2_state_C_2_1_1_ = ( (River_2_state_V == 0) ? (0) : (River_2_state_M_2_1_1_ / River_2_state_V) );

  River_2_interface_Outflow_2_1_1_ = - River_2_state_C_2_1_1_ * River_2_state_Q_Out;

  River_2_state_FluxPerComponent_2_1_1_ = (River_2_interface_Inflow1_2_1_1_ + River_2_interface_Inflow2_2_1_1_) + (River_2_interface_Outflow_2_1_1_);

  River_1_state_C_3_1_1_ = ( (River_1_state_V == 0) ? (0) : (River_1_state_M_3_1_1_ / River_1_state_V) );

  River_1_interface_Outflow_3_1_1_ = - River_1_state_C_3_1_1_ * River_1_state_Q_Out;

  River_2_interface_Inflow1_3_1_1_ = - River_1_interface_Outflow_3_1_1_;

  Urban_InputEmulator_interface_Outflow_3_1_1_ = - Urban_InputEmulator_parameters_yesno * Urban_InputEmulator_parameters_fBOD1_BOD * (1 - Urban_InputEmulator_parameters_fBOD1p_BODf) * Urban_InputEmulator_parameters_Mult_BOD * Urban_InputEmulator_interface_U_BOD_in * Urban_InputEmulator_state_Q;

  River_2_interface_Inflow2_3_1_1_ = - Urban_InputEmulator_interface_Outflow_3_1_1_;

  River_2_state_C_3_1_1_ = ( (River_2_state_V == 0) ? (0) : (River_2_state_M_3_1_1_ / River_2_state_V) );

  River_2_interface_Outflow_3_1_1_ = - River_2_state_C_3_1_1_ * River_2_state_Q_Out;

  River_2_state_FluxPerComponent_3_1_1_ = (River_2_interface_Inflow1_3_1_1_ + River_2_interface_Inflow2_3_1_1_) + (River_2_interface_Outflow_3_1_1_);

  River_1_state_C_4_1_1_ = ( (River_1_state_V == 0) ? (0) : (River_1_state_M_4_1_1_ / River_1_state_V) );

  River_1_interface_Outflow_4_1_1_ = - River_1_state_C_4_1_1_ * River_1_state_Q_Out;

  River_2_interface_Inflow1_4_1_1_ = - River_1_interface_Outflow_4_1_1_;

  Urban_InputEmulator_interface_Outflow_4_1_1_ = - Urban_InputEmulator_parameters_yesno * ((1 - Urban_InputEmulator_parameters_fBOD1_BOD) * (1 - Urban_InputEmulator_parameters_fBOD2p_BODs) * Urban_InputEmulator_parameters_Mult_BOD * Urban_InputEmulator_interface_U_BOD_in + Urban_InputEmulator_parameters_fBOD2_CODmBOD * (Urban_InputEmulator_parameters_Mult_COD * Urban_InputEmulator_interface_U_COD_in - Urban_InputEmulator_parameters_Mult_BOD * Urban_InputEmulator_interface_U_BOD_in)) * Urban_InputEmulator_state_Q;

  River_2_interface_Inflow2_4_1_1_ = - Urban_InputEmulator_interface_Outflow_4_1_1_;

  River_2_state_C_4_1_1_ = ( (River_2_state_V == 0) ? (0) : (River_2_state_M_4_1_1_ / River_2_state_V) );

  River_2_interface_Outflow_4_1_1_ = - River_2_state_C_4_1_1_ * River_2_state_Q_Out;

  River_2_state_FluxPerComponent_4_1_1_ = (River_2_interface_Inflow1_4_1_1_ + River_2_interface_Inflow2_4_1_1_) + (River_2_interface_Outflow_4_1_1_);

  River_1_state_C_5_1_1_ = ( (River_1_state_V == 0) ? (0) : (River_1_state_M_5_1_1_ / River_1_state_V) );

  River_1_interface_Outflow_5_1_1_ = - River_1_state_C_5_1_1_ * River_1_state_Q_Out;

  River_2_interface_Inflow1_5_1_1_ = - River_1_interface_Outflow_5_1_1_;

  Urban_InputEmulator_interface_Outflow_5_1_1_ = - Urban_InputEmulator_parameters_Mult_NH4 * Urban_InputEmulator_parameters_yesno * Urban_InputEmulator_interface_U_NH4_in * Urban_InputEmulator_state_Q;

  River_2_interface_Inflow2_5_1_1_ = - Urban_InputEmulator_interface_Outflow_5_1_1_;

  River_2_state_C_5_1_1_ = ( (River_2_state_V == 0) ? (0) : (River_2_state_M_5_1_1_ / River_2_state_V) );

  River_2_interface_Outflow_5_1_1_ = - River_2_state_C_5_1_1_ * River_2_state_Q_Out;

  River_2_state_FluxPerComponent_5_1_1_ = (River_2_interface_Inflow1_5_1_1_ + River_2_interface_Inflow2_5_1_1_) + (River_2_interface_Outflow_5_1_1_);

  River_1_state_C_6_1_1_ = ( (River_1_state_V == 0) ? (0) : (River_1_state_M_6_1_1_ / River_1_state_V) );

  River_1_interface_Outflow_6_1_1_ = - River_1_state_C_6_1_1_ * River_1_state_Q_Out;

  River_2_interface_Inflow1_6_1_1_ = - River_1_interface_Outflow_6_1_1_;

  Urban_InputEmulator_interface_Outflow_6_1_1_ = - Urban_InputEmulator_parameters_yesno * Urban_InputEmulator_parameters_fBOD1_BOD * Urban_InputEmulator_parameters_fBOD1p_BODf * Urban_InputEmulator_parameters_Mult_BOD * Urban_InputEmulator_interface_U_BOD_in * Urban_InputEmulator_state_Q * (1 - Urban_InputEmulator_parameters_settling);

  River_2_interface_Inflow2_6_1_1_ = - Urban_InputEmulator_interface_Outflow_6_1_1_;

  River_2_state_C_6_1_1_ = ( (River_2_state_V == 0) ? (0) : (River_2_state_M_6_1_1_ / River_2_state_V) );

  River_2_interface_Outflow_6_1_1_ = - River_2_state_C_6_1_1_ * River_2_state_Q_Out;

  River_2_state_FluxPerComponent_6_1_1_ = (River_2_interface_Inflow1_6_1_1_ + River_2_interface_Inflow2_6_1_1_) + (River_2_interface_Outflow_6_1_1_);

  River_1_state_C_7_1_1_ = ( (River_1_state_V == 0) ? (0) : (River_1_state_M_7_1_1_ / River_1_state_V) );

  River_1_interface_Outflow_7_1_1_ = - River_1_state_C_7_1_1_ * River_1_state_Q_Out;

  River_2_interface_Inflow1_7_1_1_ = - River_1_interface_Outflow_7_1_1_;

  Urban_InputEmulator_interface_Outflow_7_1_1_ = - Urban_InputEmulator_parameters_yesno * ((1 - Urban_InputEmulator_parameters_fBOD1_BOD) * Urban_InputEmulator_parameters_fBOD2p_BODs * Urban_InputEmulator_parameters_Mult_BOD * Urban_InputEmulator_interface_U_BOD_in + Urban_InputEmulator_parameters_fBOD2_CODmBOD * (Urban_InputEmulator_parameters_Mult_COD * Urban_InputEmulator_interface_U_COD_in - Urban_InputEmulator_parameters_Mult_BOD * Urban_InputEmulator_interface_U_BOD_in)) * Urban_InputEmulator_state_Q * (1 - Urban_InputEmulator_parameters_settling);

  River_2_interface_Inflow2_7_1_1_ = - Urban_InputEmulator_interface_Outflow_7_1_1_;

  River_2_state_C_7_1_1_ = ( (River_2_state_V == 0) ? (0) : (River_2_state_M_7_1_1_ / River_2_state_V) );

  River_2_interface_Outflow_7_1_1_ = - River_2_state_C_7_1_1_ * River_2_state_Q_Out;

  River_2_state_FluxPerComponent_7_1_1_ = (River_2_interface_Inflow1_7_1_1_ + River_2_interface_Inflow2_7_1_1_) + (River_2_interface_Outflow_7_1_1_);

  River_1_interface_Outflow_8_1_1_ = 0;

  River_2_interface_Inflow1_8_1_1_ = - River_1_interface_Outflow_8_1_1_;

  River_2_interface_Inflow2_8_1_1_ = - Urban_InputEmulator_interface_Outflow_8_1_1_;

  River_2_interface_Outflow_8_1_1_ = 0;

  River_2_state_FluxPerComponent_8_1_1_ = (River_2_interface_Inflow1_8_1_1_ + River_2_interface_Inflow2_8_1_1_) + (River_2_interface_Outflow_8_1_1_);

  River_2_state_InFluxPerComponent_2_1_1_ = (River_2_interface_Inflow1_2_1_1_) + (River_2_interface_Inflow2_2_1_1_);

  River_2_state_InFluxPerComponent_3_1_1_ = (River_2_interface_Inflow1_3_1_1_) + (River_2_interface_Inflow2_3_1_1_);

  River_2_state_InFluxPerComponent_4_1_1_ = (River_2_interface_Inflow1_4_1_1_) + (River_2_interface_Inflow2_4_1_1_);

  River_2_state_InFluxPerComponent_5_1_1_ = (River_2_interface_Inflow1_5_1_1_) + (River_2_interface_Inflow2_5_1_1_);

  River_2_state_InFluxPerComponent_6_1_1_ = (River_2_interface_Inflow1_6_1_1_) + (River_2_interface_Inflow2_6_1_1_);

  River_2_state_InFluxPerComponent_7_1_1_ = (River_2_interface_Inflow1_7_1_1_) + (River_2_interface_Inflow2_7_1_1_);

  River_2_state_InFluxPerComponent_8_1_1_ = (River_2_interface_Inflow1_8_1_1_) + (River_2_interface_Inflow2_8_1_1_);

  River_2_state_InFluxPerComponent_1_1_1_ = (River_2_interface_Inflow1_1_1_1_) + (River_2_interface_Inflow2_1_1_1_);

  River_2_state_Q_In = (1e-006 * River_2_state_InFluxPerComponent_1_1_1_);

  River_2_interface_T = Temperature_water;

  River_2_state_T_wat_help = River_2_interface_T + (River_2_parameters_T_ref - River_2_interface_T) / River_2_parameters_T_par;

  River_2_state_T_wat = ( (River_2_state_T_wat_help > 0) ? (River_2_state_T_wat_help) : (0) );

  River_2_state_CS = 14.652 - 0.41022 * River_2_state_T_wat + 0.007991 * pow(River_2_state_T_wat, 2.000000) - 7.7774e-005 * pow(River_2_state_T_wat, 3.000000);

  River_2_state_OTR = River_2_interface_kLa * (River_2_state_CS - River_2_state_C_2_1_1_) * River_2_state_V;

  River_2_state_SOTR = River_2_state_OTR * River_2_state_CS / (River_2_state_CS - River_2_state_C_2_1_1_) / River_2_parameters_alpha;

  River_2_state_BOD = River_2_state_C_3_1_1_ + River_2_state_C_4_1_1_ + River_2_state_C_6_1_1_ + River_2_state_C_7_1_1_;

  River_2_state_vel_water = River_2_state_Q_Out / River_2_state_A;

  River_2_state_KL20_help = River_2_parameters_VKL * pow((River_2_state_vel_water / 3600 / 24), 0.67) * pow(River_2_state_d, -0.85);

  River_2_state_KL20 = ( (River_2_state_KL20_help < River_2_parameters_KLmin) ? (River_2_parameters_KLmin) : (River_2_state_KL20_help) );

  River_2_state_KLT = River_2_state_KL20 * pow(River_2_parameters_TKL, (River_2_state_T_wat - 20));

  River_2_state_REAR = (River_2_state_KLT / River_2_state_d + River_2_interface_kLa) * (River_2_state_CS - River_2_state_C_2_1_1_);

  River_2_interface_I0 = Solar_Radiation;

  River_2_state_PO2M = (River_2_parameters_ProdM * River_2_interface_I0 - River_2_parameters_ResM) * River_2_parameters_MB / River_2_state_d * pow(River_2_parameters_TKp, (River_2_state_T_wat - 20));

  River_2_state_SedO2 = (- River_2_parameters_SOD / River_2_state_d) * pow(River_2_parameters_TSOD, (River_2_state_T_wat - 20)) * River_2_state_C_2_1_1_ / (River_2_state_C_2_1_1_ + River_2_parameters_KSO2);

  River_2_state_BODox = (- River_2_parameters_Kd1 * (River_2_state_C_3_1_1_ + River_2_state_C_6_1_1_) - River_2_parameters_Kd2 * (River_2_state_C_4_1_1_ + River_2_state_C_7_1_1_)) * pow(River_2_parameters_TKd, (River_2_state_T_wat - 20)) * River_2_state_C_2_1_1_ / (River_2_state_C_2_1_1_ + River_2_parameters_KO2);

  River_2_state_Nitrif = -4.57 * River_2_parameters_Knit * River_2_state_C_5_1_1_ * pow(River_2_parameters_TKnit, (River_2_state_T_wat - 20)) * River_2_state_C_2_1_1_ / (River_2_state_C_2_1_1_ + River_2_parameters_KNO2);

  River_2_state_C_8_1_1_ = ( (River_2_state_V == 0) ? (0) : (River_2_state_M_8_1_1_ / River_2_state_V) );

  River_2_state_SODT = - River_2_state_C_8_1_1_ * River_2_parameters_KBODs * pow(River_2_parameters_TSOD, (River_2_state_T_wat - 20)) * River_2_state_C_2_1_1_ / (River_2_state_C_2_1_1_ + River_2_parameters_KSO2);

  River_2_state_ConversionTermPerComponent_2_1_1_ = (River_2_state_REAR + River_2_state_PO2M + River_2_state_SedO2 + River_2_state_BODox + River_2_state_Nitrif + River_2_state_SODT / River_2_state_d) * River_2_state_V;

  River_2_state_ConversionTermPerComponent_3_1_1_ = (- River_2_parameters_Kd1 * River_2_state_C_3_1_1_ * pow(River_2_parameters_TKd, (River_2_state_T_wat - 20)) * River_2_state_C_2_1_1_ / (River_2_state_C_2_1_1_ + River_2_parameters_KO2) + River_2_parameters_SBOD1 / River_2_state_d) * River_2_state_V;

  River_2_state_ConversionTermPerComponent_4_1_1_ = (- River_2_parameters_Kd2 * River_2_state_C_4_1_1_ * pow(River_2_parameters_TKd, (River_2_state_T_wat - 20)) * River_2_state_C_2_1_1_ / (River_2_state_C_2_1_1_ + River_2_parameters_KO2) + River_2_parameters_SBOD2 / River_2_state_d) * River_2_state_V;

  River_2_state_ConversionTermPerComponent_6_1_1_ = (- River_2_parameters_Vs1 / River_2_state_d - River_2_parameters_Kd1 * pow(River_2_parameters_TKd, (River_2_state_T_wat - 20)) * River_2_state_C_2_1_1_ / (River_2_state_C_2_1_1_ + River_2_parameters_KO2)) * River_2_state_C_6_1_1_ * River_2_state_V;

  River_2_state_ConversionTermPerComponent_7_1_1_ = (- River_2_parameters_Vs2 / River_2_state_d - River_2_parameters_Kd2 * pow(River_2_parameters_TKd, (River_2_state_T_wat - 20)) * River_2_state_C_2_1_1_ / (River_2_state_C_2_1_1_ + River_2_parameters_KO2)) * River_2_state_C_7_1_1_ * River_2_state_V;

  River_2_state_ConversionTermPerComponent_5_1_1_ = (- River_2_parameters_Knit * River_2_state_C_5_1_1_ * pow(River_2_parameters_TKnit, (River_2_state_T_wat - 20)) * River_2_state_C_2_1_1_ / (River_2_state_C_2_1_1_ + River_2_parameters_KNO2) + River_2_parameters_SNH4 / River_2_state_d) * River_2_state_V;

  River_2_state_ConversionTermPerComponent_8_1_1_ = (River_2_parameters_Vs1 * River_2_state_C_6_1_1_ + River_2_parameters_Vs2 * River_2_state_C_7_1_1_ + River_2_state_SODT) / River_2_state_d * River_2_state_V;

  River_2_interface_DO = River_2_state_C_2_1_1_;

  River_2_interface_NH4 = River_2_state_C_5_1_1_;

  River_2_interface_Q = River_2_state_Q_Out;

  River_2_state_DO_sat_perc = River_2_state_C_2_1_1_ / River_2_state_CS;

  River_2_state_UIamm = River_2_state_C_5_1_1_ * 1 / (pow(10, (0.090182 + 2729.92 / (273.15 + River_2_state_T_wat) - River_2_parameters_pH)) + 1);

  River_2_state_UIamm_corr = ( (River_2_state_C_2_1_1_ >= 5) ? (River_2_state_UIamm) : (River_2_state_UIamm * 2) );

  River_2_state_DO_corr = ( (River_2_state_UIamm < 0.02) ? (River_2_state_C_2_1_1_) : (( (River_2_state_UIamm <= 0.15) ? (River_2_state_C_2_1_1_ - 0.97 * log(River_2_state_UIamm) - 3.8) : (River_2_state_C_2_1_1_ - 2) )) );

  River_3_interface_Inflow1_1_1_1_ = - River_2_interface_Outflow_1_1_1_;

  River_3_state_V_help = ((1e-006 * River_3_state_M_1_1_1_) + (1e-006 * River_3_state_M_2_1_1_) + (1e-006 * River_3_state_M_3_1_1_) + (1e-006 * River_3_state_M_4_1_1_) + (1e-006 * River_3_state_M_5_1_1_) + (1e-006 * River_3_state_M_6_1_1_) + (1e-006 * River_3_state_M_7_1_1_) + (1e-006 * River_3_state_M_8_1_1_));

  River_3_state_V = ( (River_3_state_V_help <= River_3_parameters_Vol_min) ? (River_3_parameters_Vol_min) : (River_3_state_V_help) );

  River_3_state_C_1_1_1_ = ( (River_3_state_V == 0) ? (0) : (River_3_state_M_1_1_1_ / River_3_state_V) );

  River_3_state_A_man = (River_3_state_V - River_3_parameters_Vol_min) / River_3_parameters_L;

  River_3_state_A = River_3_state_V / River_3_parameters_L;

  River_3_state_d = ( (River_3_parameters_z > 0) ? (sqrt(River_3_state_A / River_3_parameters_z + pow((River_3_parameters_W_b / 2 / River_3_parameters_z), 2)) - (River_3_parameters_W_b / 2 / River_3_parameters_z)) : (River_3_state_A / River_3_parameters_W_b) );

  River_3_state_P = River_3_parameters_W_b + 2 * (River_3_state_d - River_3_parameters_d_min) * sqrt(1 + pow(River_3_parameters_z, 2));

  River_3_state_R = River_3_state_A_man / River_3_state_P;

  River_3_state_Q_Out = 60 * 60 * 24 * River_3_state_A_man * pow(River_3_state_R, (2.000000 / 3.000000)) * pow(River_3_parameters_slp, 0.5) / River_3_parameters_n;

  River_3_interface_Outflow_1_1_1_ = - River_3_state_C_1_1_1_ * River_3_state_Q_Out;

  River_3_state_FluxPerComponent_1_1_1_ = (River_3_interface_Inflow1_1_1_1_ + River_3_interface_Inflow2_1_1_1_) + (River_3_interface_Outflow_1_1_1_);

  River_3_interface_Inflow1_2_1_1_ = - River_2_interface_Outflow_2_1_1_;

  River_3_state_C_2_1_1_ = ( (River_3_state_V == 0) ? (0) : (River_3_state_M_2_1_1_ / River_3_state_V) );

  River_3_interface_Outflow_2_1_1_ = - River_3_state_C_2_1_1_ * River_3_state_Q_Out;

  River_3_state_FluxPerComponent_2_1_1_ = (River_3_interface_Inflow1_2_1_1_ + River_3_interface_Inflow2_2_1_1_) + (River_3_interface_Outflow_2_1_1_);

  River_3_interface_Inflow1_3_1_1_ = - River_2_interface_Outflow_3_1_1_;

  River_3_state_C_3_1_1_ = ( (River_3_state_V == 0) ? (0) : (River_3_state_M_3_1_1_ / River_3_state_V) );

  River_3_interface_Outflow_3_1_1_ = - River_3_state_C_3_1_1_ * River_3_state_Q_Out;

  River_3_state_FluxPerComponent_3_1_1_ = (River_3_interface_Inflow1_3_1_1_ + River_3_interface_Inflow2_3_1_1_) + (River_3_interface_Outflow_3_1_1_);

  River_3_interface_Inflow1_4_1_1_ = - River_2_interface_Outflow_4_1_1_;

  River_3_state_C_4_1_1_ = ( (River_3_state_V == 0) ? (0) : (River_3_state_M_4_1_1_ / River_3_state_V) );

  River_3_interface_Outflow_4_1_1_ = - River_3_state_C_4_1_1_ * River_3_state_Q_Out;

  River_3_state_FluxPerComponent_4_1_1_ = (River_3_interface_Inflow1_4_1_1_ + River_3_interface_Inflow2_4_1_1_) + (River_3_interface_Outflow_4_1_1_);

  River_3_interface_Inflow1_5_1_1_ = - River_2_interface_Outflow_5_1_1_;

  River_3_state_C_5_1_1_ = ( (River_3_state_V == 0) ? (0) : (River_3_state_M_5_1_1_ / River_3_state_V) );

  River_3_interface_Outflow_5_1_1_ = - River_3_state_C_5_1_1_ * River_3_state_Q_Out;

  River_3_state_FluxPerComponent_5_1_1_ = (River_3_interface_Inflow1_5_1_1_ + River_3_interface_Inflow2_5_1_1_) + (River_3_interface_Outflow_5_1_1_);

  River_3_interface_Inflow1_6_1_1_ = - River_2_interface_Outflow_6_1_1_;

  River_3_state_C_6_1_1_ = ( (River_3_state_V == 0) ? (0) : (River_3_state_M_6_1_1_ / River_3_state_V) );

  River_3_interface_Outflow_6_1_1_ = - River_3_state_C_6_1_1_ * River_3_state_Q_Out;

  River_3_state_FluxPerComponent_6_1_1_ = (River_3_interface_Inflow1_6_1_1_ + River_3_interface_Inflow2_6_1_1_) + (River_3_interface_Outflow_6_1_1_);

  River_3_interface_Inflow1_7_1_1_ = - River_2_interface_Outflow_7_1_1_;

  River_3_state_C_7_1_1_ = ( (River_3_state_V == 0) ? (0) : (River_3_state_M_7_1_1_ / River_3_state_V) );

  River_3_interface_Outflow_7_1_1_ = - River_3_state_C_7_1_1_ * River_3_state_Q_Out;

  River_3_state_FluxPerComponent_7_1_1_ = (River_3_interface_Inflow1_7_1_1_ + River_3_interface_Inflow2_7_1_1_) + (River_3_interface_Outflow_7_1_1_);

  River_3_interface_Inflow1_8_1_1_ = - River_2_interface_Outflow_8_1_1_;

  River_3_interface_Outflow_8_1_1_ = 0;

  River_3_state_FluxPerComponent_8_1_1_ = (River_3_interface_Inflow1_8_1_1_ + River_3_interface_Inflow2_8_1_1_) + (River_3_interface_Outflow_8_1_1_);

  River_3_state_InFluxPerComponent_2_1_1_ = (River_3_interface_Inflow1_2_1_1_) + (River_3_interface_Inflow2_2_1_1_);

  River_3_state_InFluxPerComponent_3_1_1_ = (River_3_interface_Inflow1_3_1_1_) + (River_3_interface_Inflow2_3_1_1_);

  River_3_state_InFluxPerComponent_4_1_1_ = (River_3_interface_Inflow1_4_1_1_) + (River_3_interface_Inflow2_4_1_1_);

  River_3_state_InFluxPerComponent_5_1_1_ = (River_3_interface_Inflow1_5_1_1_) + (River_3_interface_Inflow2_5_1_1_);

  River_3_state_InFluxPerComponent_6_1_1_ = (River_3_interface_Inflow1_6_1_1_) + (River_3_interface_Inflow2_6_1_1_);

  River_3_state_InFluxPerComponent_7_1_1_ = (River_3_interface_Inflow1_7_1_1_) + (River_3_interface_Inflow2_7_1_1_);

  River_3_state_InFluxPerComponent_8_1_1_ = (River_3_interface_Inflow1_8_1_1_) + (River_3_interface_Inflow2_8_1_1_);

  River_3_state_InFluxPerComponent_1_1_1_ = (River_3_interface_Inflow1_1_1_1_) + (River_3_interface_Inflow2_1_1_1_);

  River_3_state_Q_In = (1e-006 * River_3_state_InFluxPerComponent_1_1_1_);

  River_3_interface_T = Temperature_water;

  River_3_state_T_wat_help = River_3_interface_T + (River_3_parameters_T_ref - River_3_interface_T) / River_3_parameters_T_par;

  River_3_state_T_wat = ( (River_3_state_T_wat_help > 0) ? (River_3_state_T_wat_help) : (0) );

  River_3_state_CS = 14.652 - 0.41022 * River_3_state_T_wat + 0.007991 * pow(River_3_state_T_wat, 2.000000) - 7.7774e-005 * pow(River_3_state_T_wat, 3.000000);

  River_3_state_OTR = River_3_interface_kLa * (River_3_state_CS - River_3_state_C_2_1_1_) * River_3_state_V;

  River_3_state_SOTR = River_3_state_OTR * River_3_state_CS / (River_3_state_CS - River_3_state_C_2_1_1_) / River_3_parameters_alpha;

  River_3_state_BOD = River_3_state_C_3_1_1_ + River_3_state_C_4_1_1_ + River_3_state_C_6_1_1_ + River_3_state_C_7_1_1_;

  River_3_state_vel_water = River_3_state_Q_Out / River_3_state_A;

  River_3_state_KL20_help = River_3_parameters_VKL * pow((River_3_state_vel_water / 3600 / 24), 0.67) * pow(River_3_state_d, -0.85);

  River_3_state_KL20 = ( (River_3_state_KL20_help < River_3_parameters_KLmin) ? (River_3_parameters_KLmin) : (River_3_state_KL20_help) );

  River_3_state_KLT = River_3_state_KL20 * pow(River_3_parameters_TKL, (River_3_state_T_wat - 20));

  River_3_state_REAR = (River_3_state_KLT / River_3_state_d + River_3_interface_kLa) * (River_3_state_CS - River_3_state_C_2_1_1_);

  River_3_interface_I0 = Solar_Radiation;

  River_3_state_PO2M = (River_3_parameters_ProdM * River_3_interface_I0 - River_3_parameters_ResM) * River_3_parameters_MB / River_3_state_d * pow(River_3_parameters_TKp, (River_3_state_T_wat - 20));

  River_3_state_SedO2 = (- River_3_parameters_SOD / River_3_state_d) * pow(River_3_parameters_TSOD, (River_3_state_T_wat - 20)) * River_3_state_C_2_1_1_ / (River_3_state_C_2_1_1_ + River_3_parameters_KSO2);

  River_3_state_BODox = (- River_3_parameters_Kd1 * (River_3_state_C_3_1_1_ + River_3_state_C_6_1_1_) - River_3_parameters_Kd2 * (River_3_state_C_4_1_1_ + River_3_state_C_7_1_1_)) * pow(River_3_parameters_TKd, (River_3_state_T_wat - 20)) * River_3_state_C_2_1_1_ / (River_3_state_C_2_1_1_ + River_3_parameters_KO2);

  River_3_state_Nitrif = -4.57 * River_3_parameters_Knit * River_3_state_C_5_1_1_ * pow(River_3_parameters_TKnit, (River_3_state_T_wat - 20)) * River_3_state_C_2_1_1_ / (River_3_state_C_2_1_1_ + River_3_parameters_KNO2);

  River_3_state_C_8_1_1_ = ( (River_3_state_V == 0) ? (0) : (River_3_state_M_8_1_1_ / River_3_state_V) );

  River_3_state_SODT = - River_3_state_C_8_1_1_ * River_3_parameters_KBODs * pow(River_3_parameters_TSOD, (River_3_state_T_wat - 20)) * River_3_state_C_2_1_1_ / (River_3_state_C_2_1_1_ + River_3_parameters_KSO2);

  River_3_state_ConversionTermPerComponent_2_1_1_ = (River_3_state_REAR + River_3_state_PO2M + River_3_state_SedO2 + River_3_state_BODox + River_3_state_Nitrif + River_3_state_SODT / River_3_state_d) * River_3_state_V;

  River_3_state_ConversionTermPerComponent_3_1_1_ = (- River_3_parameters_Kd1 * River_3_state_C_3_1_1_ * pow(River_3_parameters_TKd, (River_3_state_T_wat - 20)) * River_3_state_C_2_1_1_ / (River_3_state_C_2_1_1_ + River_3_parameters_KO2) + River_3_parameters_SBOD1 / River_3_state_d) * River_3_state_V;

  River_3_state_ConversionTermPerComponent_4_1_1_ = (- River_3_parameters_Kd2 * River_3_state_C_4_1_1_ * pow(River_3_parameters_TKd, (River_3_state_T_wat - 20)) * River_3_state_C_2_1_1_ / (River_3_state_C_2_1_1_ + River_3_parameters_KO2) + River_3_parameters_SBOD2 / River_3_state_d) * River_3_state_V;

  River_3_state_ConversionTermPerComponent_6_1_1_ = (- River_3_parameters_Vs1 / River_3_state_d - River_3_parameters_Kd1 * pow(River_3_parameters_TKd, (River_3_state_T_wat - 20)) * River_3_state_C_2_1_1_ / (River_3_state_C_2_1_1_ + River_3_parameters_KO2)) * River_3_state_C_6_1_1_ * River_3_state_V;

  River_3_state_ConversionTermPerComponent_7_1_1_ = (- River_3_parameters_Vs2 / River_3_state_d - River_3_parameters_Kd2 * pow(River_3_parameters_TKd, (River_3_state_T_wat - 20)) * River_3_state_C_2_1_1_ / (River_3_state_C_2_1_1_ + River_3_parameters_KO2)) * River_3_state_C_7_1_1_ * River_3_state_V;

  River_3_state_ConversionTermPerComponent_5_1_1_ = (- River_3_parameters_Knit * River_3_state_C_5_1_1_ * pow(River_3_parameters_TKnit, (River_3_state_T_wat - 20)) * River_3_state_C_2_1_1_ / (River_3_state_C_2_1_1_ + River_3_parameters_KNO2) + River_3_parameters_SNH4 / River_3_state_d) * River_3_state_V;

  River_3_state_ConversionTermPerComponent_8_1_1_ = (River_3_parameters_Vs1 * River_3_state_C_6_1_1_ + River_3_parameters_Vs2 * River_3_state_C_7_1_1_ + River_3_state_SODT) / River_3_state_d * River_3_state_V;

  River_3_interface_DO = River_3_state_C_2_1_1_;

  River_3_interface_NH4 = River_3_state_C_5_1_1_;

  River_3_interface_Q = River_3_state_Q_Out;

  River_3_state_DO_sat_perc = River_3_state_C_2_1_1_ / River_3_state_CS;

  River_3_state_UIamm = River_3_state_C_5_1_1_ * 1 / (pow(10, (0.090182 + 2729.92 / (273.15 + River_3_state_T_wat) - River_3_parameters_pH)) + 1);

  River_3_state_UIamm_corr = ( (River_3_state_C_2_1_1_ >= 5) ? (River_3_state_UIamm) : (River_3_state_UIamm * 2) );

  River_3_state_DO_corr = ( (River_3_state_UIamm < 0.02) ? (River_3_state_C_2_1_1_) : (( (River_3_state_UIamm <= 0.15) ? (River_3_state_C_2_1_1_ - 0.97 * log(River_3_state_UIamm) - 3.8) : (River_3_state_C_2_1_1_ - 2) )) );

  River_4_interface_Inflow1_1_1_1_ = - River_3_interface_Outflow_1_1_1_;

  River_4_state_V_help = ((1e-006 * River_4_state_M_1_1_1_) + (1e-006 * River_4_state_M_2_1_1_) + (1e-006 * River_4_state_M_3_1_1_) + (1e-006 * River_4_state_M_4_1_1_) + (1e-006 * River_4_state_M_5_1_1_) + (1e-006 * River_4_state_M_6_1_1_) + (1e-006 * River_4_state_M_7_1_1_) + (1e-006 * River_4_state_M_8_1_1_));

  River_4_state_V = ( (River_4_state_V_help <= River_4_parameters_Vol_min) ? (River_4_parameters_Vol_min) : (River_4_state_V_help) );

  River_4_state_C_1_1_1_ = ( (River_4_state_V == 0) ? (0) : (River_4_state_M_1_1_1_ / River_4_state_V) );

  River_4_state_A_man = (River_4_state_V - River_4_parameters_Vol_min) / River_4_parameters_L;

  River_4_state_A = River_4_state_V / River_4_parameters_L;

  River_4_state_d = ( (River_4_parameters_z > 0) ? (sqrt(River_4_state_A / River_4_parameters_z + pow((River_4_parameters_W_b / 2 / River_4_parameters_z), 2)) - (River_4_parameters_W_b / 2 / River_4_parameters_z)) : (River_4_state_A / River_4_parameters_W_b) );

  River_4_state_P = River_4_parameters_W_b + 2 * (River_4_state_d - River_4_parameters_d_min) * sqrt(1 + pow(River_4_parameters_z, 2));

  River_4_state_R = River_4_state_A_man / River_4_state_P;

  River_4_state_Q_Out = 60 * 60 * 24 * River_4_state_A_man * pow(River_4_state_R, (2.000000 / 3.000000)) * pow(River_4_parameters_slp, 0.5) / River_4_parameters_n;

  River_4_interface_Outflow_1_1_1_ = - River_4_state_C_1_1_1_ * River_4_state_Q_Out;

  River_4_state_FluxPerComponent_1_1_1_ = (River_4_interface_Inflow1_1_1_1_ + River_4_interface_Inflow2_1_1_1_) + (River_4_interface_Outflow_1_1_1_);

  River_4_interface_Inflow1_2_1_1_ = - River_3_interface_Outflow_2_1_1_;

  River_4_state_C_2_1_1_ = ( (River_4_state_V == 0) ? (0) : (River_4_state_M_2_1_1_ / River_4_state_V) );

  River_4_interface_Outflow_2_1_1_ = - River_4_state_C_2_1_1_ * River_4_state_Q_Out;

  River_4_state_FluxPerComponent_2_1_1_ = (River_4_interface_Inflow1_2_1_1_ + River_4_interface_Inflow2_2_1_1_) + (River_4_interface_Outflow_2_1_1_);

  River_4_interface_Inflow1_3_1_1_ = - River_3_interface_Outflow_3_1_1_;

  River_4_state_C_3_1_1_ = ( (River_4_state_V == 0) ? (0) : (River_4_state_M_3_1_1_ / River_4_state_V) );

  River_4_interface_Outflow_3_1_1_ = - River_4_state_C_3_1_1_ * River_4_state_Q_Out;

  River_4_state_FluxPerComponent_3_1_1_ = (River_4_interface_Inflow1_3_1_1_ + River_4_interface_Inflow2_3_1_1_) + (River_4_interface_Outflow_3_1_1_);

  River_4_interface_Inflow1_4_1_1_ = - River_3_interface_Outflow_4_1_1_;

  River_4_state_C_4_1_1_ = ( (River_4_state_V == 0) ? (0) : (River_4_state_M_4_1_1_ / River_4_state_V) );

  River_4_interface_Outflow_4_1_1_ = - River_4_state_C_4_1_1_ * River_4_state_Q_Out;

  River_4_state_FluxPerComponent_4_1_1_ = (River_4_interface_Inflow1_4_1_1_ + River_4_interface_Inflow2_4_1_1_) + (River_4_interface_Outflow_4_1_1_);

  River_4_interface_Inflow1_5_1_1_ = - River_3_interface_Outflow_5_1_1_;

  River_4_state_C_5_1_1_ = ( (River_4_state_V == 0) ? (0) : (River_4_state_M_5_1_1_ / River_4_state_V) );

  River_4_interface_Outflow_5_1_1_ = - River_4_state_C_5_1_1_ * River_4_state_Q_Out;

  River_4_state_FluxPerComponent_5_1_1_ = (River_4_interface_Inflow1_5_1_1_ + River_4_interface_Inflow2_5_1_1_) + (River_4_interface_Outflow_5_1_1_);

  River_4_interface_Inflow1_6_1_1_ = - River_3_interface_Outflow_6_1_1_;

  River_4_state_C_6_1_1_ = ( (River_4_state_V == 0) ? (0) : (River_4_state_M_6_1_1_ / River_4_state_V) );

  River_4_interface_Outflow_6_1_1_ = - River_4_state_C_6_1_1_ * River_4_state_Q_Out;

  River_4_state_FluxPerComponent_6_1_1_ = (River_4_interface_Inflow1_6_1_1_ + River_4_interface_Inflow2_6_1_1_) + (River_4_interface_Outflow_6_1_1_);

  River_4_interface_Inflow1_7_1_1_ = - River_3_interface_Outflow_7_1_1_;

  River_4_state_C_7_1_1_ = ( (River_4_state_V == 0) ? (0) : (River_4_state_M_7_1_1_ / River_4_state_V) );

  River_4_interface_Outflow_7_1_1_ = - River_4_state_C_7_1_1_ * River_4_state_Q_Out;

  River_4_state_FluxPerComponent_7_1_1_ = (River_4_interface_Inflow1_7_1_1_ + River_4_interface_Inflow2_7_1_1_) + (River_4_interface_Outflow_7_1_1_);

  River_4_interface_Inflow1_8_1_1_ = - River_3_interface_Outflow_8_1_1_;

  River_4_interface_Outflow_8_1_1_ = 0;

  River_4_state_FluxPerComponent_8_1_1_ = (River_4_interface_Inflow1_8_1_1_ + River_4_interface_Inflow2_8_1_1_) + (River_4_interface_Outflow_8_1_1_);

  River_4_state_InFluxPerComponent_2_1_1_ = (River_4_interface_Inflow1_2_1_1_) + (River_4_interface_Inflow2_2_1_1_);

  River_4_state_InFluxPerComponent_3_1_1_ = (River_4_interface_Inflow1_3_1_1_) + (River_4_interface_Inflow2_3_1_1_);

  River_4_state_InFluxPerComponent_4_1_1_ = (River_4_interface_Inflow1_4_1_1_) + (River_4_interface_Inflow2_4_1_1_);

  River_4_state_InFluxPerComponent_5_1_1_ = (River_4_interface_Inflow1_5_1_1_) + (River_4_interface_Inflow2_5_1_1_);

  River_4_state_InFluxPerComponent_6_1_1_ = (River_4_interface_Inflow1_6_1_1_) + (River_4_interface_Inflow2_6_1_1_);

  River_4_state_InFluxPerComponent_7_1_1_ = (River_4_interface_Inflow1_7_1_1_) + (River_4_interface_Inflow2_7_1_1_);

  River_4_state_InFluxPerComponent_8_1_1_ = (River_4_interface_Inflow1_8_1_1_) + (River_4_interface_Inflow2_8_1_1_);

  River_4_state_InFluxPerComponent_1_1_1_ = (River_4_interface_Inflow1_1_1_1_) + (River_4_interface_Inflow2_1_1_1_);

  River_4_state_Q_In = (1e-006 * River_4_state_InFluxPerComponent_1_1_1_);

  River_4_interface_T = Temperature_water;

  River_4_state_T_wat_help = River_4_interface_T + (River_4_parameters_T_ref - River_4_interface_T) / River_4_parameters_T_par;

  River_4_state_T_wat = ( (River_4_state_T_wat_help > 0) ? (River_4_state_T_wat_help) : (0) );

  River_4_state_CS = 14.652 - 0.41022 * River_4_state_T_wat + 0.007991 * pow(River_4_state_T_wat, 2.000000) - 7.7774e-005 * pow(River_4_state_T_wat, 3.000000);

  River_4_state_OTR = River_4_interface_kLa * (River_4_state_CS - River_4_state_C_2_1_1_) * River_4_state_V;

  River_4_state_SOTR = River_4_state_OTR * River_4_state_CS / (River_4_state_CS - River_4_state_C_2_1_1_) / River_4_parameters_alpha;

  River_4_state_BOD = River_4_state_C_3_1_1_ + River_4_state_C_4_1_1_ + River_4_state_C_6_1_1_ + River_4_state_C_7_1_1_;

  River_4_state_vel_water = River_4_state_Q_Out / River_4_state_A;

  River_4_state_KL20_help = River_4_parameters_VKL * pow((River_4_state_vel_water / 3600 / 24), 0.67) * pow(River_4_state_d, -0.85);

  River_4_state_KL20 = ( (River_4_state_KL20_help < River_4_parameters_KLmin) ? (River_4_parameters_KLmin) : (River_4_state_KL20_help) );

  River_4_state_KLT = River_4_state_KL20 * pow(River_4_parameters_TKL, (River_4_state_T_wat - 20));

  River_4_state_REAR = (River_4_state_KLT / River_4_state_d + River_4_interface_kLa) * (River_4_state_CS - River_4_state_C_2_1_1_);

  River_4_interface_I0 = Solar_Radiation;

  River_4_state_PO2M = (River_4_parameters_ProdM * River_4_interface_I0 - River_4_parameters_ResM) * River_4_parameters_MB / River_4_state_d * pow(River_4_parameters_TKp, (River_4_state_T_wat - 20));

  River_4_state_SedO2 = (- River_4_parameters_SOD / River_4_state_d) * pow(River_4_parameters_TSOD, (River_4_state_T_wat - 20)) * River_4_state_C_2_1_1_ / (River_4_state_C_2_1_1_ + River_4_parameters_KSO2);

  River_4_state_BODox = (- River_4_parameters_Kd1 * (River_4_state_C_3_1_1_ + River_4_state_C_6_1_1_) - River_4_parameters_Kd2 * (River_4_state_C_4_1_1_ + River_4_state_C_7_1_1_)) * pow(River_4_parameters_TKd, (River_4_state_T_wat - 20)) * River_4_state_C_2_1_1_ / (River_4_state_C_2_1_1_ + River_4_parameters_KO2);

  River_4_state_Nitrif = -4.57 * River_4_parameters_Knit * River_4_state_C_5_1_1_ * pow(River_4_parameters_TKnit, (River_4_state_T_wat - 20)) * River_4_state_C_2_1_1_ / (River_4_state_C_2_1_1_ + River_4_parameters_KNO2);

  River_4_state_C_8_1_1_ = ( (River_4_state_V == 0) ? (0) : (River_4_state_M_8_1_1_ / River_4_state_V) );

  River_4_state_SODT = - River_4_state_C_8_1_1_ * River_4_parameters_KBODs * pow(River_4_parameters_TSOD, (River_4_state_T_wat - 20)) * River_4_state_C_2_1_1_ / (River_4_state_C_2_1_1_ + River_4_parameters_KSO2);

  River_4_state_ConversionTermPerComponent_2_1_1_ = (River_4_state_REAR + River_4_state_PO2M + River_4_state_SedO2 + River_4_state_BODox + River_4_state_Nitrif + River_4_state_SODT / River_4_state_d) * River_4_state_V;

  River_4_state_ConversionTermPerComponent_3_1_1_ = (- River_4_parameters_Kd1 * River_4_state_C_3_1_1_ * pow(River_4_parameters_TKd, (River_4_state_T_wat - 20)) * River_4_state_C_2_1_1_ / (River_4_state_C_2_1_1_ + River_4_parameters_KO2) + River_4_parameters_SBOD1 / River_4_state_d) * River_4_state_V;

  River_4_state_ConversionTermPerComponent_4_1_1_ = (- River_4_parameters_Kd2 * River_4_state_C_4_1_1_ * pow(River_4_parameters_TKd, (River_4_state_T_wat - 20)) * River_4_state_C_2_1_1_ / (River_4_state_C_2_1_1_ + River_4_parameters_KO2) + River_4_parameters_SBOD2 / River_4_state_d) * River_4_state_V;

  River_4_state_ConversionTermPerComponent_6_1_1_ = (- River_4_parameters_Vs1 / River_4_state_d - River_4_parameters_Kd1 * pow(River_4_parameters_TKd, (River_4_state_T_wat - 20)) * River_4_state_C_2_1_1_ / (River_4_state_C_2_1_1_ + River_4_parameters_KO2)) * River_4_state_C_6_1_1_ * River_4_state_V;

  River_4_state_ConversionTermPerComponent_7_1_1_ = (- River_4_parameters_Vs2 / River_4_state_d - River_4_parameters_Kd2 * pow(River_4_parameters_TKd, (River_4_state_T_wat - 20)) * River_4_state_C_2_1_1_ / (River_4_state_C_2_1_1_ + River_4_parameters_KO2)) * River_4_state_C_7_1_1_ * River_4_state_V;

  River_4_state_ConversionTermPerComponent_5_1_1_ = (- River_4_parameters_Knit * River_4_state_C_5_1_1_ * pow(River_4_parameters_TKnit, (River_4_state_T_wat - 20)) * River_4_state_C_2_1_1_ / (River_4_state_C_2_1_1_ + River_4_parameters_KNO2) + River_4_parameters_SNH4 / River_4_state_d) * River_4_state_V;

  River_4_state_ConversionTermPerComponent_8_1_1_ = (River_4_parameters_Vs1 * River_4_state_C_6_1_1_ + River_4_parameters_Vs2 * River_4_state_C_7_1_1_ + River_4_state_SODT) / River_4_state_d * River_4_state_V;

  River_4_interface_DO = River_4_state_C_2_1_1_;

  River_4_interface_NH4 = River_4_state_C_5_1_1_;

  River_4_interface_Q = River_4_state_Q_Out;

  River_4_state_DO_sat_perc = River_4_state_C_2_1_1_ / River_4_state_CS;

  River_4_state_UIamm = River_4_state_C_5_1_1_ * 1 / (pow(10, (0.090182 + 2729.92 / (273.15 + River_4_state_T_wat) - River_4_parameters_pH)) + 1);

  River_4_state_UIamm_corr = ( (River_4_state_C_2_1_1_ >= 5) ? (River_4_state_UIamm) : (River_4_state_UIamm * 2) );

  River_4_state_DO_corr = ( (River_4_state_UIamm < 0.02) ? (River_4_state_C_2_1_1_) : (( (River_4_state_UIamm <= 0.15) ? (River_4_state_C_2_1_1_ - 0.97 * log(River_4_state_UIamm) - 3.8) : (River_4_state_C_2_1_1_ - 2) )) );

  River_5_interface_Inflow1_1_1_1_ = - River_4_interface_Outflow_1_1_1_;

  River_5_state_V_help = ((1e-006 * River_5_state_M_1_1_1_) + (1e-006 * River_5_state_M_2_1_1_) + (1e-006 * River_5_state_M_3_1_1_) + (1e-006 * River_5_state_M_4_1_1_) + (1e-006 * River_5_state_M_5_1_1_) + (1e-006 * River_5_state_M_6_1_1_) + (1e-006 * River_5_state_M_7_1_1_) + (1e-006 * River_5_state_M_8_1_1_));

  River_5_state_V = ( (River_5_state_V_help <= River_5_parameters_Vol_min) ? (River_5_parameters_Vol_min) : (River_5_state_V_help) );

  River_5_state_C_1_1_1_ = ( (River_5_state_V == 0) ? (0) : (River_5_state_M_1_1_1_ / River_5_state_V) );

  River_5_state_A_man = (River_5_state_V - River_5_parameters_Vol_min) / River_5_parameters_L;

  River_5_state_A = River_5_state_V / River_5_parameters_L;

  River_5_state_d = ( (River_5_parameters_z > 0) ? (sqrt(River_5_state_A / River_5_parameters_z + pow((River_5_parameters_W_b / 2 / River_5_parameters_z), 2)) - (River_5_parameters_W_b / 2 / River_5_parameters_z)) : (River_5_state_A / River_5_parameters_W_b) );

  River_5_state_P = River_5_parameters_W_b + 2 * (River_5_state_d - River_5_parameters_d_min) * sqrt(1 + pow(River_5_parameters_z, 2));

  River_5_state_R = River_5_state_A_man / River_5_state_P;

  River_5_state_Q_Out = 60 * 60 * 24 * River_5_state_A_man * pow(River_5_state_R, (2.000000 / 3.000000)) * pow(River_5_parameters_slp, 0.5) / River_5_parameters_n;

  River_5_interface_Outflow_1_1_1_ = - River_5_state_C_1_1_1_ * River_5_state_Q_Out;

  River_5_state_FluxPerComponent_1_1_1_ = (River_5_interface_Inflow1_1_1_1_ + River_5_interface_Inflow2_1_1_1_) + (River_5_interface_Outflow_1_1_1_);

  River_5_interface_Inflow1_2_1_1_ = - River_4_interface_Outflow_2_1_1_;

  River_5_state_C_2_1_1_ = ( (River_5_state_V == 0) ? (0) : (River_5_state_M_2_1_1_ / River_5_state_V) );

  River_5_interface_Outflow_2_1_1_ = - River_5_state_C_2_1_1_ * River_5_state_Q_Out;

  River_5_state_FluxPerComponent_2_1_1_ = (River_5_interface_Inflow1_2_1_1_ + River_5_interface_Inflow2_2_1_1_) + (River_5_interface_Outflow_2_1_1_);

  River_5_interface_Inflow1_3_1_1_ = - River_4_interface_Outflow_3_1_1_;

  River_5_state_C_3_1_1_ = ( (River_5_state_V == 0) ? (0) : (River_5_state_M_3_1_1_ / River_5_state_V) );

  River_5_interface_Outflow_3_1_1_ = - River_5_state_C_3_1_1_ * River_5_state_Q_Out;

  River_5_state_FluxPerComponent_3_1_1_ = (River_5_interface_Inflow1_3_1_1_ + River_5_interface_Inflow2_3_1_1_) + (River_5_interface_Outflow_3_1_1_);

  River_5_interface_Inflow1_4_1_1_ = - River_4_interface_Outflow_4_1_1_;

  River_5_state_C_4_1_1_ = ( (River_5_state_V == 0) ? (0) : (River_5_state_M_4_1_1_ / River_5_state_V) );

  River_5_interface_Outflow_4_1_1_ = - River_5_state_C_4_1_1_ * River_5_state_Q_Out;

  River_5_state_FluxPerComponent_4_1_1_ = (River_5_interface_Inflow1_4_1_1_ + River_5_interface_Inflow2_4_1_1_) + (River_5_interface_Outflow_4_1_1_);

  River_5_interface_Inflow1_5_1_1_ = - River_4_interface_Outflow_5_1_1_;

  River_5_state_C_5_1_1_ = ( (River_5_state_V == 0) ? (0) : (River_5_state_M_5_1_1_ / River_5_state_V) );

  River_5_interface_Outflow_5_1_1_ = - River_5_state_C_5_1_1_ * River_5_state_Q_Out;

  River_5_state_FluxPerComponent_5_1_1_ = (River_5_interface_Inflow1_5_1_1_ + River_5_interface_Inflow2_5_1_1_) + (River_5_interface_Outflow_5_1_1_);

  River_5_interface_Inflow1_6_1_1_ = - River_4_interface_Outflow_6_1_1_;

  River_5_state_C_6_1_1_ = ( (River_5_state_V == 0) ? (0) : (River_5_state_M_6_1_1_ / River_5_state_V) );

  River_5_interface_Outflow_6_1_1_ = - River_5_state_C_6_1_1_ * River_5_state_Q_Out;

  River_5_state_FluxPerComponent_6_1_1_ = (River_5_interface_Inflow1_6_1_1_ + River_5_interface_Inflow2_6_1_1_) + (River_5_interface_Outflow_6_1_1_);

  River_5_interface_Inflow1_7_1_1_ = - River_4_interface_Outflow_7_1_1_;

  River_5_state_C_7_1_1_ = ( (River_5_state_V == 0) ? (0) : (River_5_state_M_7_1_1_ / River_5_state_V) );

  River_5_interface_Outflow_7_1_1_ = - River_5_state_C_7_1_1_ * River_5_state_Q_Out;

  River_5_state_FluxPerComponent_7_1_1_ = (River_5_interface_Inflow1_7_1_1_ + River_5_interface_Inflow2_7_1_1_) + (River_5_interface_Outflow_7_1_1_);

  River_5_interface_Inflow1_8_1_1_ = - River_4_interface_Outflow_8_1_1_;

  River_5_interface_Outflow_8_1_1_ = 0;

  River_5_state_FluxPerComponent_8_1_1_ = (River_5_interface_Inflow1_8_1_1_ + River_5_interface_Inflow2_8_1_1_) + (River_5_interface_Outflow_8_1_1_);

  River_5_state_InFluxPerComponent_2_1_1_ = (River_5_interface_Inflow1_2_1_1_) + (River_5_interface_Inflow2_2_1_1_);

  River_5_state_InFluxPerComponent_3_1_1_ = (River_5_interface_Inflow1_3_1_1_) + (River_5_interface_Inflow2_3_1_1_);

  River_5_state_InFluxPerComponent_4_1_1_ = (River_5_interface_Inflow1_4_1_1_) + (River_5_interface_Inflow2_4_1_1_);

  River_5_state_InFluxPerComponent_5_1_1_ = (River_5_interface_Inflow1_5_1_1_) + (River_5_interface_Inflow2_5_1_1_);

  River_5_state_InFluxPerComponent_6_1_1_ = (River_5_interface_Inflow1_6_1_1_) + (River_5_interface_Inflow2_6_1_1_);

  River_5_state_InFluxPerComponent_7_1_1_ = (River_5_interface_Inflow1_7_1_1_) + (River_5_interface_Inflow2_7_1_1_);

  River_5_state_InFluxPerComponent_8_1_1_ = (River_5_interface_Inflow1_8_1_1_) + (River_5_interface_Inflow2_8_1_1_);

  River_5_state_InFluxPerComponent_1_1_1_ = (River_5_interface_Inflow1_1_1_1_) + (River_5_interface_Inflow2_1_1_1_);

  River_5_state_Q_In = (1e-006 * River_5_state_InFluxPerComponent_1_1_1_);

  River_5_interface_T = Temperature_water;

  River_5_state_T_wat_help = River_5_interface_T + (River_5_parameters_T_ref - River_5_interface_T) / River_5_parameters_T_par;

  River_5_state_T_wat = ( (River_5_state_T_wat_help > 0) ? (River_5_state_T_wat_help) : (0) );

  River_5_state_CS = 14.652 - 0.41022 * River_5_state_T_wat + 0.007991 * pow(River_5_state_T_wat, 2.000000) - 7.7774e-005 * pow(River_5_state_T_wat, 3.000000);

  River_5_state_OTR = River_5_interface_kLa * (River_5_state_CS - River_5_state_C_2_1_1_) * River_5_state_V;

  River_5_state_SOTR = River_5_state_OTR * River_5_state_CS / (River_5_state_CS - River_5_state_C_2_1_1_) / River_5_parameters_alpha;

  River_5_state_BOD = River_5_state_C_3_1_1_ + River_5_state_C_4_1_1_ + River_5_state_C_6_1_1_ + River_5_state_C_7_1_1_;

  River_5_state_vel_water = River_5_state_Q_Out / River_5_state_A;

  River_5_state_KL20_help = River_5_parameters_VKL * pow((River_5_state_vel_water / 3600 / 24), 0.67) * pow(River_5_state_d, -0.85);

  River_5_state_KL20 = ( (River_5_state_KL20_help < River_5_parameters_KLmin) ? (River_5_parameters_KLmin) : (River_5_state_KL20_help) );

  River_5_state_KLT = River_5_state_KL20 * pow(River_5_parameters_TKL, (River_5_state_T_wat - 20));

  River_5_state_REAR = (River_5_state_KLT / River_5_state_d + River_5_interface_kLa) * (River_5_state_CS - River_5_state_C_2_1_1_);

  River_5_interface_I0 = Solar_Radiation;

  River_5_state_PO2M = (River_5_parameters_ProdM * River_5_interface_I0 - River_5_parameters_ResM) * River_5_parameters_MB / River_5_state_d * pow(River_5_parameters_TKp, (River_5_state_T_wat - 20));

  River_5_state_SedO2 = (- River_5_parameters_SOD / River_5_state_d) * pow(River_5_parameters_TSOD, (River_5_state_T_wat - 20)) * River_5_state_C_2_1_1_ / (River_5_state_C_2_1_1_ + River_5_parameters_KSO2);

  River_5_state_BODox = (- River_5_parameters_Kd1 * (River_5_state_C_3_1_1_ + River_5_state_C_6_1_1_) - River_5_parameters_Kd2 * (River_5_state_C_4_1_1_ + River_5_state_C_7_1_1_)) * pow(River_5_parameters_TKd, (River_5_state_T_wat - 20)) * River_5_state_C_2_1_1_ / (River_5_state_C_2_1_1_ + River_5_parameters_KO2);

  River_5_state_Nitrif = -4.57 * River_5_parameters_Knit * River_5_state_C_5_1_1_ * pow(River_5_parameters_TKnit, (River_5_state_T_wat - 20)) * River_5_state_C_2_1_1_ / (River_5_state_C_2_1_1_ + River_5_parameters_KNO2);

  River_5_state_C_8_1_1_ = ( (River_5_state_V == 0) ? (0) : (River_5_state_M_8_1_1_ / River_5_state_V) );

  River_5_state_SODT = - River_5_state_C_8_1_1_ * River_5_parameters_KBODs * pow(River_5_parameters_TSOD, (River_5_state_T_wat - 20)) * River_5_state_C_2_1_1_ / (River_5_state_C_2_1_1_ + River_5_parameters_KSO2);

  River_5_state_ConversionTermPerComponent_2_1_1_ = (River_5_state_REAR + River_5_state_PO2M + River_5_state_SedO2 + River_5_state_BODox + River_5_state_Nitrif + River_5_state_SODT / River_5_state_d) * River_5_state_V;

  River_5_state_ConversionTermPerComponent_3_1_1_ = (- River_5_parameters_Kd1 * River_5_state_C_3_1_1_ * pow(River_5_parameters_TKd, (River_5_state_T_wat - 20)) * River_5_state_C_2_1_1_ / (River_5_state_C_2_1_1_ + River_5_parameters_KO2) + River_5_parameters_SBOD1 / River_5_state_d) * River_5_state_V;

  River_5_state_ConversionTermPerComponent_4_1_1_ = (- River_5_parameters_Kd2 * River_5_state_C_4_1_1_ * pow(River_5_parameters_TKd, (River_5_state_T_wat - 20)) * River_5_state_C_2_1_1_ / (River_5_state_C_2_1_1_ + River_5_parameters_KO2) + River_5_parameters_SBOD2 / River_5_state_d) * River_5_state_V;

  River_5_state_ConversionTermPerComponent_6_1_1_ = (- River_5_parameters_Vs1 / River_5_state_d - River_5_parameters_Kd1 * pow(River_5_parameters_TKd, (River_5_state_T_wat - 20)) * River_5_state_C_2_1_1_ / (River_5_state_C_2_1_1_ + River_5_parameters_KO2)) * River_5_state_C_6_1_1_ * River_5_state_V;

  River_5_state_ConversionTermPerComponent_7_1_1_ = (- River_5_parameters_Vs2 / River_5_state_d - River_5_parameters_Kd2 * pow(River_5_parameters_TKd, (River_5_state_T_wat - 20)) * River_5_state_C_2_1_1_ / (River_5_state_C_2_1_1_ + River_5_parameters_KO2)) * River_5_state_C_7_1_1_ * River_5_state_V;

  River_5_state_ConversionTermPerComponent_5_1_1_ = (- River_5_parameters_Knit * River_5_state_C_5_1_1_ * pow(River_5_parameters_TKnit, (River_5_state_T_wat - 20)) * River_5_state_C_2_1_1_ / (River_5_state_C_2_1_1_ + River_5_parameters_KNO2) + River_5_parameters_SNH4 / River_5_state_d) * River_5_state_V;

  River_5_state_ConversionTermPerComponent_8_1_1_ = (River_5_parameters_Vs1 * River_5_state_C_6_1_1_ + River_5_parameters_Vs2 * River_5_state_C_7_1_1_ + River_5_state_SODT) / River_5_state_d * River_5_state_V;

  River_5_interface_DO = River_5_state_C_2_1_1_;

  River_5_interface_NH4 = River_5_state_C_5_1_1_;

  River_5_interface_Q = River_5_state_Q_Out;

  River_5_state_DO_sat_perc = River_5_state_C_2_1_1_ / River_5_state_CS;

  River_5_state_UIamm = River_5_state_C_5_1_1_ * 1 / (pow(10, (0.090182 + 2729.92 / (273.15 + River_5_state_T_wat) - River_5_parameters_pH)) + 1);

  River_5_state_UIamm_corr = ( (River_5_state_C_2_1_1_ >= 5) ? (River_5_state_UIamm) : (River_5_state_UIamm * 2) );

  River_5_state_DO_corr = ( (River_5_state_UIamm < 0.02) ? (River_5_state_C_2_1_1_) : (( (River_5_state_UIamm <= 0.15) ? (River_5_state_C_2_1_1_ - 0.97 * log(River_5_state_UIamm) - 3.8) : (River_5_state_C_2_1_1_ - 2) )) );

  Rural_inflow_interface_rainfall = Rural_baseflow;

  Rural_inflow_interface_Outflow_1_1_1_ = - Rural_inflow_interface_rainfall * Rural_inflow_parameters_surface * 1000000;

  River_1_interface_Inflow1_1_1_1_ = - Rural_inflow_interface_Outflow_1_1_1_;

  River_1_state_FluxPerComponent_1_1_1_ = (River_1_interface_Inflow1_1_1_1_ + River_1_interface_Inflow2_1_1_1_) + (River_1_interface_Outflow_1_1_1_);

  Rural_inflow_state_Q = - Rural_inflow_interface_Outflow_1_1_1_ / 1000000;

  Rural_inflow_interface_Outflow_2_1_1_ = - Rural_inflow_parameters_O2_in * Rural_inflow_state_Q;

  River_1_interface_Inflow1_2_1_1_ = - Rural_inflow_interface_Outflow_2_1_1_;

  River_1_state_FluxPerComponent_2_1_1_ = (River_1_interface_Inflow1_2_1_1_ + River_1_interface_Inflow2_2_1_1_) + (River_1_interface_Outflow_2_1_1_);

  Rural_inflow_interface_Outflow_3_1_1_ = - Rural_inflow_parameters_BOD1_in * Rural_inflow_state_Q;

  River_1_interface_Inflow1_3_1_1_ = - Rural_inflow_interface_Outflow_3_1_1_;

  River_1_state_FluxPerComponent_3_1_1_ = (River_1_interface_Inflow1_3_1_1_ + River_1_interface_Inflow2_3_1_1_) + (River_1_interface_Outflow_3_1_1_);

  Rural_inflow_interface_Outflow_4_1_1_ = - Rural_inflow_parameters_BOD2_in * Rural_inflow_state_Q;

  River_1_interface_Inflow1_4_1_1_ = - Rural_inflow_interface_Outflow_4_1_1_;

  River_1_state_FluxPerComponent_4_1_1_ = (River_1_interface_Inflow1_4_1_1_ + River_1_interface_Inflow2_4_1_1_) + (River_1_interface_Outflow_4_1_1_);

  Rural_inflow_interface_Outflow_5_1_1_ = - Rural_inflow_interface_NH4_in * Rural_inflow_state_Q;

  River_1_interface_Inflow1_5_1_1_ = - Rural_inflow_interface_Outflow_5_1_1_;

  River_1_state_FluxPerComponent_5_1_1_ = (River_1_interface_Inflow1_5_1_1_ + River_1_interface_Inflow2_5_1_1_) + (River_1_interface_Outflow_5_1_1_);

  Rural_inflow_interface_Outflow_6_1_1_ = - Rural_inflow_parameters_BOD1p_in * Rural_inflow_state_Q;

  River_1_interface_Inflow1_6_1_1_ = - Rural_inflow_interface_Outflow_6_1_1_;

  River_1_state_FluxPerComponent_6_1_1_ = (River_1_interface_Inflow1_6_1_1_ + River_1_interface_Inflow2_6_1_1_) + (River_1_interface_Outflow_6_1_1_);

  Rural_inflow_interface_Outflow_7_1_1_ = - Rural_inflow_parameters_BOD2p_in * Rural_inflow_state_Q;

  River_1_interface_Inflow1_7_1_1_ = - Rural_inflow_interface_Outflow_7_1_1_;

  River_1_state_FluxPerComponent_7_1_1_ = (River_1_interface_Inflow1_7_1_1_ + River_1_interface_Inflow2_7_1_1_) + (River_1_interface_Outflow_7_1_1_);

  Rural_inflow_interface_Outflow_8_1_1_ = - Rural_inflow_parameters_BODs_in * Rural_inflow_state_Q;

  River_1_interface_Inflow1_8_1_1_ = - Rural_inflow_interface_Outflow_8_1_1_;

  River_1_state_FluxPerComponent_8_1_1_ = (River_1_interface_Inflow1_8_1_1_ + River_1_interface_Inflow2_8_1_1_) + (River_1_interface_Outflow_8_1_1_);

  River_1_state_InFluxPerComponent_2_1_1_ = (River_1_interface_Inflow1_2_1_1_) + (River_1_interface_Inflow2_2_1_1_);

  River_1_state_InFluxPerComponent_3_1_1_ = (River_1_interface_Inflow1_3_1_1_) + (River_1_interface_Inflow2_3_1_1_);

  River_1_state_InFluxPerComponent_4_1_1_ = (River_1_interface_Inflow1_4_1_1_) + (River_1_interface_Inflow2_4_1_1_);

  River_1_state_InFluxPerComponent_5_1_1_ = (River_1_interface_Inflow1_5_1_1_) + (River_1_interface_Inflow2_5_1_1_);

  River_1_state_InFluxPerComponent_6_1_1_ = (River_1_interface_Inflow1_6_1_1_) + (River_1_interface_Inflow2_6_1_1_);

  River_1_state_InFluxPerComponent_7_1_1_ = (River_1_interface_Inflow1_7_1_1_) + (River_1_interface_Inflow2_7_1_1_);

  River_1_state_InFluxPerComponent_8_1_1_ = (River_1_interface_Inflow1_8_1_1_) + (River_1_interface_Inflow2_8_1_1_);

  River_1_state_InFluxPerComponent_1_1_1_ = (River_1_interface_Inflow1_1_1_1_) + (River_1_interface_Inflow2_1_1_1_);

  River_1_state_Q_In = (1e-006 * River_1_state_InFluxPerComponent_1_1_1_);

  River_1_interface_T = Temperature_water;

  River_1_state_T_wat_help = River_1_interface_T + (River_1_parameters_T_ref - River_1_interface_T) / River_1_parameters_T_par;

  River_1_state_T_wat = ( (River_1_state_T_wat_help > 0) ? (River_1_state_T_wat_help) : (0) );

  River_1_state_CS = 14.652 - 0.41022 * River_1_state_T_wat + 0.007991 * pow(River_1_state_T_wat, 2.000000) - 7.7774e-005 * pow(River_1_state_T_wat, 3.000000);

  River_1_state_OTR = River_1_interface_kLa * (River_1_state_CS - River_1_state_C_2_1_1_) * River_1_state_V;

  River_1_state_SOTR = River_1_state_OTR * River_1_state_CS / (River_1_state_CS - River_1_state_C_2_1_1_) / River_1_parameters_alpha;

  River_1_state_BOD = River_1_state_C_3_1_1_ + River_1_state_C_4_1_1_ + River_1_state_C_6_1_1_ + River_1_state_C_7_1_1_;

  River_1_state_vel_water = River_1_state_Q_Out / River_1_state_A;

  River_1_state_KL20_help = River_1_parameters_VKL * pow((River_1_state_vel_water / 3600 / 24), 0.67) * pow(River_1_state_d, -0.85);

  River_1_state_KL20 = ( (River_1_state_KL20_help < River_1_parameters_KLmin) ? (River_1_parameters_KLmin) : (River_1_state_KL20_help) );

  River_1_state_KLT = River_1_state_KL20 * pow(River_1_parameters_TKL, (River_1_state_T_wat - 20));

  River_1_state_REAR = (River_1_state_KLT / River_1_state_d + River_1_interface_kLa) * (River_1_state_CS - River_1_state_C_2_1_1_);

  River_1_interface_I0 = Solar_Radiation;

  River_1_state_PO2M = (River_1_parameters_ProdM * River_1_interface_I0 - River_1_parameters_ResM) * River_1_parameters_MB / River_1_state_d * pow(River_1_parameters_TKp, (River_1_state_T_wat - 20));

  River_1_state_SedO2 = (- River_1_parameters_SOD / River_1_state_d) * pow(River_1_parameters_TSOD, (River_1_state_T_wat - 20)) * River_1_state_C_2_1_1_ / (River_1_state_C_2_1_1_ + River_1_parameters_KSO2);

  River_1_state_BODox = (- River_1_parameters_Kd1 * (River_1_state_C_3_1_1_ + River_1_state_C_6_1_1_) - River_1_parameters_Kd2 * (River_1_state_C_4_1_1_ + River_1_state_C_7_1_1_)) * pow(River_1_parameters_TKd, (River_1_state_T_wat - 20)) * River_1_state_C_2_1_1_ / (River_1_state_C_2_1_1_ + River_1_parameters_KO2);

  River_1_state_Nitrif = -4.57 * River_1_parameters_Knit * River_1_state_C_5_1_1_ * pow(River_1_parameters_TKnit, (River_1_state_T_wat - 20)) * River_1_state_C_2_1_1_ / (River_1_state_C_2_1_1_ + River_1_parameters_KNO2);

  River_1_state_C_8_1_1_ = ( (River_1_state_V == 0) ? (0) : (River_1_state_M_8_1_1_ / River_1_state_V) );

  River_1_state_SODT = - River_1_state_C_8_1_1_ * River_1_parameters_KBODs * pow(River_1_parameters_TSOD, (River_1_state_T_wat - 20)) * River_1_state_C_2_1_1_ / (River_1_state_C_2_1_1_ + River_1_parameters_KSO2);

  River_1_state_ConversionTermPerComponent_2_1_1_ = (River_1_state_REAR + River_1_state_PO2M + River_1_state_SedO2 + River_1_state_BODox + River_1_state_Nitrif + River_1_state_SODT / River_1_state_d) * River_1_state_V;

  River_1_state_ConversionTermPerComponent_3_1_1_ = (- River_1_parameters_Kd1 * River_1_state_C_3_1_1_ * pow(River_1_parameters_TKd, (River_1_state_T_wat - 20)) * River_1_state_C_2_1_1_ / (River_1_state_C_2_1_1_ + River_1_parameters_KO2) + River_1_parameters_SBOD1 / River_1_state_d) * River_1_state_V;

  River_1_state_ConversionTermPerComponent_4_1_1_ = (- River_1_parameters_Kd2 * River_1_state_C_4_1_1_ * pow(River_1_parameters_TKd, (River_1_state_T_wat - 20)) * River_1_state_C_2_1_1_ / (River_1_state_C_2_1_1_ + River_1_parameters_KO2) + River_1_parameters_SBOD2 / River_1_state_d) * River_1_state_V;

  River_1_state_ConversionTermPerComponent_6_1_1_ = (- River_1_parameters_Vs1 / River_1_state_d - River_1_parameters_Kd1 * pow(River_1_parameters_TKd, (River_1_state_T_wat - 20)) * River_1_state_C_2_1_1_ / (River_1_state_C_2_1_1_ + River_1_parameters_KO2)) * River_1_state_C_6_1_1_ * River_1_state_V;

  River_1_state_ConversionTermPerComponent_7_1_1_ = (- River_1_parameters_Vs2 / River_1_state_d - River_1_parameters_Kd2 * pow(River_1_parameters_TKd, (River_1_state_T_wat - 20)) * River_1_state_C_2_1_1_ / (River_1_state_C_2_1_1_ + River_1_parameters_KO2)) * River_1_state_C_7_1_1_ * River_1_state_V;

  River_1_state_ConversionTermPerComponent_5_1_1_ = (- River_1_parameters_Knit * River_1_state_C_5_1_1_ * pow(River_1_parameters_TKnit, (River_1_state_T_wat - 20)) * River_1_state_C_2_1_1_ / (River_1_state_C_2_1_1_ + River_1_parameters_KNO2) + River_1_parameters_SNH4 / River_1_state_d) * River_1_state_V;

  River_1_state_ConversionTermPerComponent_8_1_1_ = (River_1_parameters_Vs1 * River_1_state_C_6_1_1_ + River_1_parameters_Vs2 * River_1_state_C_7_1_1_ + River_1_state_SODT) / River_1_state_d * River_1_state_V;

  River_1_interface_DO = River_1_state_C_2_1_1_;

  River_1_interface_NH4 = River_1_state_C_5_1_1_;

  River_1_interface_Q = River_1_state_Q_Out;

  River_1_state_DO_sat_perc = River_1_state_C_2_1_1_ / River_1_state_CS;

  River_1_state_UIamm = River_1_state_C_5_1_1_ * 1 / (pow(10, (0.090182 + 2729.92 / (273.15 + River_1_state_T_wat) - River_1_parameters_pH)) + 1);

  River_1_state_UIamm_corr = ( (River_1_state_C_2_1_1_ >= 5) ? (River_1_state_UIamm) : (River_1_state_UIamm * 2) );

  River_1_state_DO_corr = ( (River_1_state_UIamm < 0.02) ? (River_1_state_C_2_1_1_) : (( (River_1_state_UIamm <= 0.15) ? (River_1_state_C_2_1_1_ - 0.97 * log(River_1_state_UIamm) - 3.8) : (River_1_state_C_2_1_1_ - 2) )) );

  _D_River_2_state_M_1_1_1_ = River_2_state_FluxPerComponent_1_1_1_ + River_2_state_ConversionTermPerComponent_1_1_1_;

  _D_River_2_state_M_2_1_1_ = River_2_state_FluxPerComponent_2_1_1_ + River_2_state_ConversionTermPerComponent_2_1_1_;

  _D_River_2_state_M_3_1_1_ = River_2_state_FluxPerComponent_3_1_1_ + River_2_state_ConversionTermPerComponent_3_1_1_;

  _D_River_2_state_M_4_1_1_ = River_2_state_FluxPerComponent_4_1_1_ + River_2_state_ConversionTermPerComponent_4_1_1_;

  _D_River_2_state_M_5_1_1_ = River_2_state_FluxPerComponent_5_1_1_ + River_2_state_ConversionTermPerComponent_5_1_1_;

  _D_River_2_state_M_6_1_1_ = River_2_state_FluxPerComponent_6_1_1_ + River_2_state_ConversionTermPerComponent_6_1_1_;

  _D_River_2_state_M_7_1_1_ = River_2_state_FluxPerComponent_7_1_1_ + River_2_state_ConversionTermPerComponent_7_1_1_;

  _D_River_2_state_M_8_1_1_ = River_2_state_FluxPerComponent_8_1_1_ + River_2_state_ConversionTermPerComponent_8_1_1_;

  _D_River_3_state_M_1_1_1_ = River_3_state_FluxPerComponent_1_1_1_ + River_3_state_ConversionTermPerComponent_1_1_1_;

  _D_River_3_state_M_2_1_1_ = River_3_state_FluxPerComponent_2_1_1_ + River_3_state_ConversionTermPerComponent_2_1_1_;

  _D_River_3_state_M_3_1_1_ = River_3_state_FluxPerComponent_3_1_1_ + River_3_state_ConversionTermPerComponent_3_1_1_;

  _D_River_3_state_M_4_1_1_ = River_3_state_FluxPerComponent_4_1_1_ + River_3_state_ConversionTermPerComponent_4_1_1_;

  _D_River_3_state_M_5_1_1_ = River_3_state_FluxPerComponent_5_1_1_ + River_3_state_ConversionTermPerComponent_5_1_1_;

  _D_River_3_state_M_6_1_1_ = River_3_state_FluxPerComponent_6_1_1_ + River_3_state_ConversionTermPerComponent_6_1_1_;

  _D_River_3_state_M_7_1_1_ = River_3_state_FluxPerComponent_7_1_1_ + River_3_state_ConversionTermPerComponent_7_1_1_;

  _D_River_3_state_M_8_1_1_ = River_3_state_FluxPerComponent_8_1_1_ + River_3_state_ConversionTermPerComponent_8_1_1_;

  _D_River_4_state_M_1_1_1_ = River_4_state_FluxPerComponent_1_1_1_ + River_4_state_ConversionTermPerComponent_1_1_1_;

  _D_River_4_state_M_2_1_1_ = River_4_state_FluxPerComponent_2_1_1_ + River_4_state_ConversionTermPerComponent_2_1_1_;

  _D_River_4_state_M_3_1_1_ = River_4_state_FluxPerComponent_3_1_1_ + River_4_state_ConversionTermPerComponent_3_1_1_;

  _D_River_4_state_M_4_1_1_ = River_4_state_FluxPerComponent_4_1_1_ + River_4_state_ConversionTermPerComponent_4_1_1_;

  _D_River_4_state_M_5_1_1_ = River_4_state_FluxPerComponent_5_1_1_ + River_4_state_ConversionTermPerComponent_5_1_1_;

  _D_River_4_state_M_6_1_1_ = River_4_state_FluxPerComponent_6_1_1_ + River_4_state_ConversionTermPerComponent_6_1_1_;

  _D_River_4_state_M_7_1_1_ = River_4_state_FluxPerComponent_7_1_1_ + River_4_state_ConversionTermPerComponent_7_1_1_;

  _D_River_4_state_M_8_1_1_ = River_4_state_FluxPerComponent_8_1_1_ + River_4_state_ConversionTermPerComponent_8_1_1_;

  _D_River_5_state_M_1_1_1_ = River_5_state_FluxPerComponent_1_1_1_ + River_5_state_ConversionTermPerComponent_1_1_1_;

  _D_River_5_state_M_2_1_1_ = River_5_state_FluxPerComponent_2_1_1_ + River_5_state_ConversionTermPerComponent_2_1_1_;

  _D_River_5_state_M_3_1_1_ = River_5_state_FluxPerComponent_3_1_1_ + River_5_state_ConversionTermPerComponent_3_1_1_;

  _D_River_5_state_M_4_1_1_ = River_5_state_FluxPerComponent_4_1_1_ + River_5_state_ConversionTermPerComponent_4_1_1_;

  _D_River_5_state_M_5_1_1_ = River_5_state_FluxPerComponent_5_1_1_ + River_5_state_ConversionTermPerComponent_5_1_1_;

  _D_River_5_state_M_6_1_1_ = River_5_state_FluxPerComponent_6_1_1_ + River_5_state_ConversionTermPerComponent_6_1_1_;

  _D_River_5_state_M_7_1_1_ = River_5_state_FluxPerComponent_7_1_1_ + River_5_state_ConversionTermPerComponent_7_1_1_;

  _D_River_5_state_M_8_1_1_ = River_5_state_FluxPerComponent_8_1_1_ + River_5_state_ConversionTermPerComponent_8_1_1_;

  _D_River_1_state_M_1_1_1_ = River_1_state_FluxPerComponent_1_1_1_ + River_1_state_ConversionTermPerComponent_1_1_1_;

  _D_River_1_state_M_2_1_1_ = River_1_state_FluxPerComponent_2_1_1_ + River_1_state_ConversionTermPerComponent_2_1_1_;

  _D_River_1_state_M_3_1_1_ = River_1_state_FluxPerComponent_3_1_1_ + River_1_state_ConversionTermPerComponent_3_1_1_;

  _D_River_1_state_M_4_1_1_ = River_1_state_FluxPerComponent_4_1_1_ + River_1_state_ConversionTermPerComponent_4_1_1_;

  _D_River_1_state_M_5_1_1_ = River_1_state_FluxPerComponent_5_1_1_ + River_1_state_ConversionTermPerComponent_5_1_1_;

  _D_River_1_state_M_6_1_1_ = River_1_state_FluxPerComponent_6_1_1_ + River_1_state_ConversionTermPerComponent_6_1_1_;

  _D_River_1_state_M_7_1_1_ = River_1_state_FluxPerComponent_7_1_1_ + River_1_state_ConversionTermPerComponent_7_1_1_;

  _D_River_1_state_M_8_1_1_ = River_1_state_FluxPerComponent_8_1_1_ + River_1_state_ConversionTermPerComponent_8_1_1_;


  return 0;
}


int
ComputeOutput(struct TModel* pModel)
{
  return 0;
}


int
ComputeFinal(struct TModel* pModel)
{
  MSLUBufferRemoveAll();
  MSLUMarkovRemoveAll();
  MSLUMatrixRemoveAll();
  MSLUPhreeqcRemoveAll();
  MSLURandRemoveAll();
  MSLUTimerRemoveAll();
  return 0;
}


void*
GetID()
{
  return (void*)L"Tornado.MSLE.Model._Model_dummy_1_";
}


void*
Create()
{
  struct TModel* pModel;

#ifndef _WIN32
  _LIB_VERSION = _SVID_;
#endif
  pModel = (struct TModel*)malloc(sizeof(struct TModel));
  memset(pModel, 0x0, sizeof(struct TModel));

  pModel->pVersion = wcsdup(L"2016 ");
  pModel->pType = wcsdup(L"ODE");

  pModel->NoParams = 204;
  pModel->NoIndepVars = 1;
  pModel->NoInputVars = 4;
  pModel->NoOutputVars = 0;
  pModel->NoAlgVars = 480;
  pModel->NoDerVars = 40;
  pModel->NoDerivatives = 40;
  pModel->NoPrevious = 0;
  pModel->NoResidues = 0;
  pModel->NoSolveSets = 0;
  pModel->NoEvents = 0;

  pModel->Params = (double*)malloc(sizeof(double) * pModel->NoParams);
  pModel->IndepVars = (double*)malloc(sizeof(double) * pModel->NoIndepVars);
  pModel->InputVars = (double*)malloc(sizeof(double) * pModel->NoInputVars);
  pModel->OutputVars = (double*)malloc(sizeof(double) * pModel->NoOutputVars);
  pModel->AlgVars = (double*)malloc(sizeof(double) * pModel->NoAlgVars);
  pModel->DerVars = (double*)malloc(sizeof(double) * pModel->NoDerVars);
  pModel->Derivatives = (double*)malloc(sizeof(double) * pModel->NoDerivatives);
  pModel->Previous = (double*)malloc(sizeof(double) * pModel->NoPrevious);
  pModel->Residues = (double*)malloc(sizeof(double) * pModel->NoResidues);
  pModel->SolveSets = (TSolveSetP)malloc(sizeof(struct TSolveSet) * pModel->NoSolveSets);
  pModel->Events = (TEventP)malloc(sizeof(struct TEvent) * pModel->NoEvents);

  pModel->ComputeInitial = ComputeInitial;
  pModel->ComputeState = ComputeState;
  pModel->ComputeOutput = ComputeOutput;
  pModel->ComputeFinal = ComputeFinal;

  return (void*)pModel;
}


#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"filter.h"
#define pi 3.142857143
#define rt2 1.414213562

void display(void){
    printf("******************************WELCOME******************************\n\n");
    printf("This is a project that will give you the parameters to design different active filters.\n");
    printf("Refer the below chart to choose your filter\n");
    printf("A - First order low pass filter\nB - First order high pass filter\nC - Second order low pass filter\n");
    printf("D - Second order high pass filter\nE - Bandpass filter\n");
    printf("Note : The operating frequency range is 0.1kHz to 250kHz and pass band gain is between 1 to 100 dB\n");
    printf("\nEnter the code of the filter of your choice\n");
}

condition check_code(char c){
    if (c=='A' || c=='B' || c=='C' || c=='D' || c=='E') return Success;
    else return code_error;
}

condition choose_filter(char c){
    input_val params;
    int flag=1;
    
    if (c=='A' || c=='B' || c=='C' || c=='D'){
        printf("\nEnter the cutoff frequency in kHz: ");
        scanf("%f",&params.freq);
        printf("\nEnter the pass band gain in dB: ");
        scanf("%f",&params.Av);
        flag=1;
    }

    else if (c=='E')
    {
        printf("\nEnter the lower cutoff frequency in kHz: ");
        scanf("%f",&params.l_freq);
        printf("\nEnter the upper cutoff frequency in kHz: ");
        scanf("%f",&params.u_freq);
        printf("\nEnter the pass band gain in dB: ");
        scanf("%f",&params.Av);
        flag=1;
        }

    else {
        printf("\n!!! Enter the correct alphabet !!! \n");
        printf("\nRefer the below chart to choose your filter\n");
        printf("A - First order low pass filter\nB - First order high pass filter\nC - Second order low pass filter\n");
        printf("D - Second order high pass filter\nE - Bandpass filter\n");
        flag=-1;
        }
    
      

    if (c=='A'){
        FLP(&params);
    }
    else if (c=='B'){
        FHP(&params);
    }
    else if (c=='C'){
        SLP(&params);
    }
    else if (c=='D'){
        SHP(&params);
    }
    else if(c=='E'){
        BPF(&params);
    }
    else flag=-1;

    if (flag==1) return Success;
    else if (flag==-1) return code_error; 
    else return Failure;


}

condition FLP(input_val* params)
{
    if (params==NULL){
        return Failure;
    }

    if (params->freq<0.1 || params->freq>250 || params->Av<1 || params->Av>100){
            printf("\nLimits violated.Check again");
            printf("\n !!! Note : The operating frequency range is 0.1kHz to 250kHz and pass band gain is between 1 to 100 dB !!!\n");
            return Limit_error;
    }

    output_val* FLP_result1=malloc(sizeof(output_val));
    output_val* FLP_result2=malloc(sizeof(output_val));

    FLP_result1->R1=1;
    FLP_result1->R2=(params->Av-1)*FLP_result1->R1;
    FLP_result1->R=10;
    FLP_result1->C=((1/ (2 * pi * FLP_result1->R * params->freq)) * 1000);

    FLP_result2->R1=10;
    FLP_result2->R2=(FLP_result2->R1)*(params->Av);
    FLP_result2->C=((1/ (2 * pi * FLP_result2->R2 * params->freq)) * 1000);

    printf("\nThe design parameters for a first order low pass non inverting filter are:\n");
    printf("R1=%.3f k-ohm\nR2=%.3f k-ohm\nR=%.3f k-ohm\nC=%.3f nF\n",FLP_result1->R1,FLP_result1->R2,FLP_result1->R,FLP_result1->C);

    printf("\nThe design parameters for a first order low pass inverting filter are:\n");
    printf("R1=%.3f k-ohm\nR2=%.3f k-ohm\nC=%.3f nF\n",FLP_result2->R1,FLP_result2->R2,FLP_result2->C);

    printf("\n\nRefer the images and videos or readme section for circuit diagram\n");

    free(FLP_result1);
    free(FLP_result2);

    return Success;
    
}

condition FHP(input_val* params)
{
    if (params==NULL){
        return Failure;
    }

    if (params->freq<0.1 || params->freq>250 || params->Av<1 || params->Av>100){
            printf("\nLimits violated.Check again");
            printf("\n !!! Note : The operating frequency range is 0.1kHz to 250kHz and pass band gain is between 1 to 100 dB !!!\n");
            return Limit_error;
    }

    output_val* FHP_result1=malloc(sizeof(output_val));
    output_val* FHP_result2=malloc(sizeof(output_val));

    FHP_result1->C=10;
    FHP_result1->R1=10;
    FHP_result1->R2=(params->Av-1)*FHP_result1->R1;
    FHP_result1->R=((1/ (2 * pi * FHP_result1->C * params->freq)) * 1000);

    FHP_result2->C=10;
    FHP_result2->R1=((1/ (2 * pi * FHP_result2->C * params->freq)) * 1000);
    FHP_result2->R2=(FHP_result2->R1)*(params->Av);

    printf("\nThe design parameters for a first order high pass non inverting filter are:\n");
    printf("R1=%.3f k-ohm\nR2=%.3f k-ohm\nR=%.3f k-ohm\nC=%.3f nF\n",FHP_result1->R1,FHP_result1->R2,FHP_result1->R,FHP_result1->C);

    printf("\nThe design parameters for a first order high pass inverting filter are:\n");
    printf("R1=%.3f k-ohm\nR2=%.3f k-ohm\nC=%.3f nF\n",FHP_result2->R1,FHP_result2->R2,FHP_result2->C);

    printf("\n\nRefer the images and videos or readme section for circuit diagram\n");

    free(FHP_result1);
    free(FHP_result2);

    return Success;

}

condition SLP(input_val* params)
{
    if (params==NULL){
        return Failure;
    }

    if (params->freq<0.1 || params->freq>250 || params->Av<1 || params->Av>100){
            printf("\nLimits violated.Check again");
            printf("\n !!! Note : The operating frequency range is 0.1kHz to 250kHz and pass band gain is between 1 to 100 dB !!!\n");
            return Limit_error;
    }

    output_val* SLP_result=malloc(sizeof(output_val));

    SLP_result->C1=1;
    SLP_result->C2=2*SLP_result->C1;
    SLP_result->R4=((1/ (2 * pi * rt2 * SLP_result->C1 * params->freq)) * 1000);
    SLP_result->R3=SLP_result->R4;
    SLP_result->R1=1;
    SLP_result->R2=(params->Av-1)*SLP_result->R1;

    printf("\nThe design parameters for a second order low pass non inverting filter are:\n");
    printf("R1=%.3f k-ohm\nR2=%.3f k-ohm\nR3=%.3f k-ohm\nR4=%.3f k-ohm\n",SLP_result->R1,SLP_result->R2,SLP_result->R3,SLP_result->R4);
    printf("C1=%.3f nF\nC2=%.3f nF\n",SLP_result->C1,SLP_result->C2);

    printf("\n\nRefer the images and videos or readme section for circuit diagram\n");

    free(SLP_result);

    return Success;
}

condition SHP(input_val* params)
{
    if (params==NULL){
        return Failure;
    }

    if (params->freq<0.1 || params->freq>250 || params->Av<1 || params->Av>100){
            printf("\nLimits violated.Check again");
            printf("\n !!! Note : The operating frequency range is 0.1kHz to 250kHz and pass band gain is between 1 to 100 dB !!!\n");
            return Limit_error;
    }

    output_val* SHP_result=malloc(sizeof(output_val));

    SHP_result->C1=1;
    SHP_result->C2=SHP_result->C1;
    SHP_result->R4=((rt2/ (2 * pi * SHP_result->C1 * params->freq)) * 1000);
    SHP_result->R3=0.5 * SHP_result->R4;
    SHP_result->R1=10;
    SHP_result->R2=(params->Av-1)*SHP_result->R1;

    printf("\nThe design parameters for a second order high pass non inverting filter are:\n");
    printf("R1=%.3f k-ohm\nR2=%.3f k-ohm\nR3=%.3f k-ohm\nR4=%.3f k-ohm\n",SHP_result->R1,SHP_result->R2,SHP_result->R3,SHP_result->R4);
    printf("C1=%.3f nF\nC2=%.3f nF\n",SHP_result->C1,SHP_result->C2);

    printf("\n\nRefer the images and videos or readme section for circuit diagram\n");

    free(SHP_result);

    return Success;
}

condition BPF(input_val* params)
{
   if (params==NULL){
        return Failure;
    }

    if (params->l_freq<0.1 || params->l_freq>params->u_freq || params->u_freq>250 || params->Av<1 || params->Av>100){
            printf("\nLimits violated.Check again");
            printf("\n !!! Note : The operating frequency range is 0.1kHz to 250kHz and pass band gain is between 1 to 100 dB !!!\n");
            return Limit_error;
    } 

    output_val* BPF_result=malloc(sizeof(output_val));

    BPF_result->C2=1;
    BPF_result->R2=((1/ (2 * pi * BPF_result->C2 * params->u_freq)) * 1000);
    BPF_result->R1=(BPF_result->R2/params->Av);
    BPF_result->C1=((1/ (2 * pi * BPF_result->R1 * params->l_freq)) * 1000);
    BPF_result->R3=BPF_result->R2;

    printf("\nThe design parameters for a Band pass  inverting filter are:\n");
    printf("R1=%.3f k-ohm\nR2=%.3f k-ohm\nR3=%.3f k-ohm\n",BPF_result->R1,BPF_result->R2,BPF_result->R3);
    printf("C1=%.3f nF\nC2=%.3f nF\n",BPF_result->C1,BPF_result->C2);

    printf("\n\nRefer the images and videos or readme section for circuit diagram\n");

    free(BPF_result);

    return Success;
}


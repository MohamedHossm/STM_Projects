#ifndef _STMF103C8_MMAP_H_
#define _STMF103C8_MMAP_H_
/*********************************************************/
/*******************RCC Registers************************/
/*********************************************************/
#define RCC_u32BASE_ADDRESS 0x40021000
typedef struct {
	u32 RCC_CR;
	u32 RCC_CFGR;
	u32 RCC_CIR;
	u32 RCC_APB2RSTR;
	u32 RCC_APB1RSTR;
	u32 RCC_AHBENR;
	u32 RCC_APB2ENR;
	u32 RCC_APB1ENR;
	u32 RCC_BDCR;
	u32 RCC_CSR;

} RCC_REG_DEF_t;

#define RCC ((RCC_REG_DEF_t*)RCC_u32BASE_ADDRESS)

/*********************************************************/
/*******************GPIO Registers************************/
/*********************************************************/
#define GPIO_C_u32BASE_ADDRESS 0x40011000
#define GPIO_B_u32BASE_ADDRESS 0x40010C00
#define GPIO_A_u32BASE_ADDRESS 0x40010800

typedef struct {
	u32 GPIO_CRL;
	u32 GPIO_CRH;
	u32 GPIO_IDR;
	u32 GPIO_ODR;
	u32 GPIO_BSRR;
	u32 GPIO_BRR;
	u32 GPIO_LCKR;

} GPIO_REG_DEF_t;

#define GPIO_C ((GPIO_REG_DEF_t*)GPIO_C_u32BASE_ADDRESS)
#define GPIO_B ((GPIO_REG_DEF_t*)GPIO_B_u32BASE_ADDRESS)
#define GPIO_A ((GPIO_REG_DEF_t*)GPIO_A_u32BASE_ADDRESS)
/*********************************************************/
/*******************NVIC Registers************************/
/*********************************************************/
#define NVIC_u32BASE_ADDRESS 0xE000E100
#define NVIC_res 29
#define NVIC_RES2 61
#define NCIC_NVIC_IPR_SIZE 84
#define NVIC_SIZE 3
typedef struct {
	u32 NVIC_ISER[NVIC_SIZE];
	u32 NVIC_ISER_RES[NVIC_res];

	u32 NVIC_ICER[NVIC_SIZE];
	u32 NVIC_ICER_RES[NVIC_res];

	u32 NVIC_ISPR[NVIC_SIZE];
	u32 NVIC_ISPR_RES[NVIC_res];

	u32 NVIC_ICPR[NVIC_SIZE];
	u32 NVIC_ICPR_RES[NVIC_res];

	u32 NVIC_IABR[NVIC_SIZE];
	u32 NVIC_IABR_RES[NVIC_RES2];
	volatile u8 NVIC_IPR[NCIC_NVIC_IPR_SIZE];
} NVIC_REG_DEF_t;

#define NVIC ((NVIC_REG_DEF_t*)NVIC_u32BASE_ADDRESS)
/*********************************************************/
/*******************SYS Registers************************/
/*********************************************************/
#define SCB_AIRCR (*(u32*)(0xE000ED00 +0x0C))

/*********************************************************/
/*******************EXTI Registers************************/
/*********************************************************/

#define EXTI_u32BASE_ADDRESS  0x40010400

typedef struct {
	u32 EXTI_IMR;
	u32 EXTI_EMR;
	u32 EXTI_RTSR;
	u32 EXTI_FTSR;
	u32 EXTI_SWIER;
	u32 EXTI_PR;

} EXTI_REG_DEF_t;

#define EXTI ((EXTI_REG_DEF_t*)EXTI_u32BASE_ADDRESS)

/*********************************************************/
/*******************AFIO Registers************************/
/*********************************************************/
#define AFIO_u32BASE_ADDRESS  0x40010000
#define AFIO_EXTICRSIZE 4
typedef struct {
	u32 AFIO_EVCR;
	u32 AFIO_MAPR;
	u32 AFIO_EXTICR[AFIO_EXTICRSIZE];
	u32 AFIO_MAPR2;
} AFIO_REG_DEF_t;

#define AFIO ((AFIO_REG_DEF_t*)AFIO_u32BASE_ADDRESS)

/*************************************************************/
/*******************SYSTICK Registers*************************/
/*************************************************************/

#define SYSTICK_u32BASE_ADDRESS  0xE000E010

typedef struct {
	volatile u32 STK_CTRL;
	volatile u32 STK_LOAD;
	volatile u32 STK_VAL;
	volatile u32 STK_CALIB;
} SYSTICK_REG_DEF_t;

#define SYSTICK ((SYSTICK_REG_DEF_t*)SYSTICK_u32BASE_ADDRESS)

#endif //_STMF103C8_MMAP_H_

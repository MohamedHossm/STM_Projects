/*****************************************************************************/
/* Auther         : Mohamed Hoasm                                                    */
/* Date           : 31/7/2023                                                        */
/* Version        : 1.0                                                              */
/*sw              : DMA                                                             */
/*****************************************************************************/
#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_
typedef enum {
	DMA_PLOW,
	DMA_PMEDIUM,
	DMA_PHIGH ,
	DMA_PVERYHIGH
}DMA_P_t ;

typedef struct {
	u16 DMA_EN :1;
	u16 DMA_TCIE :1;
	u16 DMA_HTIE :1;
	u16 DMA_TEIE :1;
	u16 DMA_DIR :1;
	u16 DMA_CIRC :1;
	u16 DMA_PINC :1;
	u16 DMA_MINC :1;
	u16 DMA_PSIZE :2;
	u16 DMA_MSIZE :2;
	u16 DMA_PL :2;
	u16 DMA_MEM2MEM :1;
	u16 DMA_RESERV :1;
} DMA_SITTING_t;
typedef enum {
	DMA_8_BIT,
	DMA_16_BIT,
	DMA_32_BIT ,
}DMA_SiZE_t ;

#define DMA_ENABLE  1
#define DMA_DISABLE 0


typedef enum {
	DMA_CH1, DMA_CH2, DMA_CH3, DMA_CH4, DMA_CH5, DMA_CH6, DMA_CH7
} DMA_Channels;

void DMA_VoidInit(void);
Error_t DMA_u8ChannelConfig(DMA_Channels Copy_DMAChannel,
		DMA_SITTING_t Copy_u32conf);
Error_t DMA_u8ChannelEN(DMA_Channels Copy_DMAChannel) ;
Error_t DMA_u8ChannelDS(DMA_Channels Copy_DMAChannel) ;
Error_t DMA_u8ChannelSource_Distination(DMA_Channels Copy_DMAChannel,
		u32 *PTR_DMASource, u32 *PTR_DMADistination, u16 Copy_u16DMA_size);
#endif //DMA_INTERFACE_H_


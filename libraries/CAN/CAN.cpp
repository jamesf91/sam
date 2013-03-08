#include "CAN.h"

CANClass::CANClass(Can *_can, uint32_t _id, void(*_initCb)(void)) :
	can(_can), id(_id), initCb(_initCb)
{
	initCb();

	//SPI_Configure(spi, id, SPI_MR_MSTR | SPI_MR_PS | SPI_MR_MODFDIS);
	//SPI_Enable(spi);
}


#if CAN_INTERFACES_COUNT > 0
static void CAN_0_Init(void) {
	PIO_Configure(
			g_APinDescription[PIN_CAN_RX].pPort,
			g_APinDescription[PIN_CAN_RX].ulPinType,
			g_APinDescription[PIN_CAN_RX].ulPin,
			g_APinDescription[PIN_CAN_RX].ulPinConfiguration);
	PIO_Configure(
			g_APinDescription[PIN_CAN_TX].pPort,
			g_APinDescription[PIN_CAN_TX].ulPinType,
			g_APinDescription[PIN_CAN_TX].ulPin,
			g_APinDescription[PIN_CAN_TX].ulPinConfiguration);
}

CANClass CAN(CAN_INTERFACE, CAN_INTERFACE_ID, CAN_0_Init);
#endif
/*******************************************************************************
  * Company: Wang Electronic Technology Co., Ltd.
  ******************************************************************************
  * �ļ����ƣ�main.c
  * ����˵��������USB HID����
  * ��    ����V1.1
	* ��    �ߣ�0915	
  * ��    �ڣ�2014-04-22
********************************************************************************
  * �ļ����ƣ�main.c
  * ����˵����������
  * ��    ����
	* ��������:	
  * ��    �ڣ�
	* ����ԭ��
********************************************************************************/
#include "lpc17xx.h"
#include "main.h"
#include "usb.h"
#include "usbcfg.h"
#include "usbhw.h"

unsigned char InReport;   // �����˰�����ֵ
unsigned char OutReport;  // ��ȡ��LED�Ŀ���ֵ                              
     
/*********************************************************************************************************
** Function name:       void GetInReport (void)
** Descriptions:        ������ݻ�ú���
** input parameters:    ��
** output parameters:   ���������:InReport
** Returned value:      ��
*********************************************************************************************************/
void GetInReport (void) {
  uint32_t kbd_val;

  kbd_val = (LPC_GPIO1->FIOPIN >> 25) & KBD_MASK; 
    
  InReport = 0x00;
  if ((kbd_val & KBD_UP)     == 0) InReport |= 0x01;  /* up     pressed means 0 */
  if ((kbd_val & KBD_LEFT)   == 0) InReport |= 0x02;  /* left   pressed means 0 */
  if ((kbd_val & KBD_RIGHT)  == 0) InReport |= 0x04;  /* right  pressed means 0 */
  if ((kbd_val & KBD_SELECT) == 0) InReport |= 0x08;  /* select pressed means 0 */
  if ((kbd_val & KBD_DOWN)   == 0) InReport |= 0x10;  /* down   pressed means 0 */
}

/*********************************************************************************************************
** Function name:       void SetOutReport (void)
** Descriptions:        ���ݽ��մ�����
** input parameters:    ��
** output parameters:   ��
** Returned value:      ��
*********************************************************************************************************/
void SetOutReport (void) {
  static unsigned long led_mask[] = { 1<<0, 1<<1, 1<<2, 1<<3, 1<<4, 1<<5, 1<<6, 1<<7 };
  int i;

  for (i = 0; i < LED_NUM; i++) {
    if (OutReport & (1<<i)) {
			// OutReport��ʾ��������ֵ����iλΪ1��������λ��Ӧ��LED
      LPC_GPIO2->FIOPIN |= led_mask[i];
    } else {
			// ��iλΪ0��Ϩ���Ӧ��LED
      LPC_GPIO2->FIOPIN &= ~led_mask[i];
    }
  }
}

/*********************************************************************************************************
** Function name:       int main (void)
** Descriptions:        ������
** input parameters:    ��
** output parameters:   ��
** Returned value:      ��
*********************************************************************************************************/
int main (void) {

	// ����GPIO2.0~7Ϊ�������
  LPC_GPIO2->FIODIR   |= ((1UL<< 0)|(1UL<< 1)|
													(1UL<< 2)|(1UL<< 3)|
                          (1UL<< 4)|(1UL<< 5)|
                          (1UL<< 6)|(1UL<< 7)) ; /* P2.0��P2.7ΪLED�ƽӿ� */

  // ����GPIO1.25~29Ϊ��������
  LPC_GPIO1->FIODIR   &= ~((1<<25)|(1<<26)|
                           (1<<27)|(1<<28)|
                           (1<<29)         ); /* P1.25��P1.29�����򰴼������� */

  LPC_GPIO0->FIODIR = 0x00200000; 
  LPC_GPIO0->FIOPIN |= 0x00200000; 

  USB_Init();                                 /* USB��ʼ�� */
  USB_Connect(__TRUE);                        /* USB ���� */

  while (1);                                  
}
/******************************************************************************
**                            End Of File
******************************************************************************/

/****************************************Copyright (c)****************************************************
**                                 
**--------------File Info---------------------------------------------------------------------------------
** File name:           error.h
** Last modified Date:  2018-10-16
** Last Version:        V1.00
** Descriptions:        
**
**--------------------------------------------------------------------------------------------------------
** Created by:          letheascetic
** Created date:        2018-10-16
** Version:             V1.00
** Descriptions:        USB-CAN-II Error Descriptions
**
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#ifndef _ERROR_H_
#define _ERROR_H_

/*****************************************CAN 错误码********************************************************/
#define		ERR_CAN_OVERFLOW		0x00000001		//CAN 控制器内部 FIFO溢出
#define		ERR_CAN_ERRALARM		0x00000002		//CAN 控制器错误报警
#define		ERR_CAN_PASSIVE			0x00000004		//CAN 控制器消极错误
#define		ERR_CAN_LOSE			0x00000008		//CAN 控制器仲裁丢失
#define		ERR_CAN_BUSERR			0x00000010		//CAN 控制器总线错误
#define		ERR_CAN_BUSOFF			0x00000020		//CAN 控制器总线关闭

/*****************************************ͨ通用错误码*****************************************************/
#define		ERR_DEVICEOPENED		0x00000100		//�豸�Ѵ�
#define		ERR_DEVICEOPEN			0x00000200		//���豸����
#define		ERR_DEVICENOTOPEN		0x00000400		//�豸û�д�
#define		ERR_BUFFEROVERFLOW	0x00000800		//���������
#define		ERR_DEVICENOTEXIST	0x00001000		//���豸������
#define		ERR_LOADKERNELDLL		0x00002000		//װ�ض�̬��ʧ��
#define		ERR_CMDFAILED				0x00004000		//ִ������ʧ�ܴ�����
#define		ERR_BUFFERCREATE		0x00008000		//�ڴ治��

/****************************************CANET������*****************************************************/
#define		ERR_CANETE_PORTOPENED		0x00010000		//�˿��Ѿ�����
#define		ERR_CANETE_INDEXUSED		0x00020000		//�豸�������Ѿ���ʹ��
#define		ERR_REF_TYPE_ID					0x00030001		//SetReference��GetReference���ݵ�RefType������
#define		ERR_CREATE_SOCKET				0x00030002		//����Socketʱʧ��
#define		ERR_OPEN_CONNECT				0x00030003		//��Socket����ʱʧ�ܣ������豸�����Ѿ�����
#define		ERR_NO_STARTUP					0x00030004		//�豸û������
#define		ERR_NO_CONNECTED				0x00030005		//�豸������
#define		ERR_SEND_PARTIAL				0x00030006		//ֻ�����˲���CAN֡
#define		ERR_SEND_TOO_FAST				0x00030007		//���ݷ���̫�� Socket����������

#endif 
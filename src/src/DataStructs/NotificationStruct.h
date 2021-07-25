#ifndef DATASTRUCTS_NOTIFICATIONSTRUCT_H
#define DATASTRUCTS_NOTIFICATIONSTRUCT_H


/*********************************************************************************************\
* NotificationStruct
\*********************************************************************************************/
struct NotificationStruct
{
  NotificationStruct() :
    Number(0), usesGPIO(0), usesMessaging(false) {}

  uint8_t Number;
  uint8_t usesGPIO;
  bool usesMessaging;
};


#endif // DATASTRUCTS_NOTIFICATIONSTRUCT_H

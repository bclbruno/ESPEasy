#ifndef ESPEASYSERIAL_ESPEASYSERIAL_USBCDC_H
#define ESPEASYSERIAL_ESPEASYSERIAL_USBCDC_H

#ifndef DISABLE_SC16IS752_Serial
# include <ESPEasySC16IS752_Serial.h>


# include "ESPEasySerial_Port.h"

# include <Arduino.h>
# include <inttypes.h>
# include <Stream.h>


class ESPEasySerial_I2C_SC16IS752 : public ESPEasySerial_Port {
public:

  //       ESPEasySC16IS752_Serial::I2C_address addr     = static_cast<ESPEasySC16IS752_Serial::I2C_address>(receivePin);
  //       ESPEasySC16IS752_Serial::SC16IS752_channel ch = static_cast<ESPEasySC16IS752_Serial::SC16IS752_channel>(transmitPin);


  ESPEasySerial_I2C_SC16IS752(ESPEasySC16IS752_Serial::I2C_address       addr,
                              ESPEasySC16IS752_Serial::SC16IS752_channel ch);

  virtual ~ESPEasySerial_I2C_SC16IS752();

  void   begin(unsigned long baud);

  void   end();
  int    available(void);
  int    availableForWrite(void);
  int    peek(void);
  int    read(void);
  size_t read(uint8_t *buffer,
              size_t   size);

  void   flush(void);
  void   flush(bool txOnly);
  size_t write(uint8_t);
  size_t write(const uint8_t *buffer,
               size_t         size);

  operator bool() const;

  void   setDebugOutput(bool);

  size_t setRxBufferSize(size_t new_size);
  size_t setTxBufferSize(size_t new_size);

private:

  ESPEasySC16IS752_Serial *_i2cserial = nullptr;
};


#endif // if USES_HWCDC


#endif // ifndef ESPEASYSERIAL_ESPEASYSERIAL_USBCDC_H

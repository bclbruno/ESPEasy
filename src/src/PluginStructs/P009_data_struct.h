#ifndef PLUGINSTRUCTS_P009_DATA_STRUCT_H
#define PLUGINSTRUCTS_P009_DATA_STRUCT_H

#include "../../_Plugin_Helper.h"

#ifdef USES_P009


/**************************************************\
   CONFIG
   TaskDevicePluginConfig settings:
   0: send boot state (true,false)
   1:
   2:
   3:
   4: use doubleclick (0,1,2,3)
   5: use longpress (0,1,2,3)
   6: LP fired (true,false)
   7: doubleclick counter (=0,1,2,3)

   TaskDevicePluginConfigFloat settings:
   0: debounce interval ms
   1: doubleclick interval ms
   2: longpress interval ms
   3: use safebutton (=0,1)

   TaskDevicePluginConfigLong settings:
   0: clickTime debounce ms
   1: clickTime doubleclick ms
   2: clickTime longpress ms
   3: safebutton counter (=0,1)
\**************************************************/

# define P009_BOOTSTATE     PCONFIG(0)
# define P009_DEBOUNCE      PCONFIG_FLOAT(0)
# define P009_DOUBLECLICK   PCONFIG(4)
# define P009_DC_MAX_INT    PCONFIG_FLOAT(1)
# define P009_LONGPRESS     PCONFIG(5)
# define P009_LP_MIN_INT    PCONFIG_FLOAT(2)
# define P009_SAFE_BTN      PCONFIG_FLOAT(3)


struct P009_data_struct : public PluginTaskData_base {
  P009_data_struct() = delete;

  P009_data_struct(struct EventStruct *event);
  ~P009_data_struct();

  void tenPerSecond(struct EventStruct *event);

private:

  uint32_t       _portStatus_key;
  uint32_t       _debounceTimer;
  const uint32_t _debounceInterval_ms;
  uint32_t       _doubleClickTimer;
  const uint32_t _doubleClickMaxInterval_ms;
  uint32_t       _longpressTimer;
  const uint32_t _longpressMinInterval_ms;

  int16_t _doubleClickCounter;
  int16_t _safeButtonCounter;

  const int8_t  _mcpPin;
  const uint8_t _dcMode; // use doubleclick (0,1,2,3)

# if FEATURE_I2C_DEVICE_CHECK
  const uint8_t _address;
#endif

  const bool    _safeButton;
  bool          _longpressFired;
};

#endif // ifdef USES_P009
#endif // ifndef PLUGINSTRUCTS_P009_DATA_STRUCT_H

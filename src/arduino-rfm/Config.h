#ifndef _CONFIG_H_
#define _CONFIG_H_

// Board definition
#define BOARD_DRAGINO_SHIELD
// #define BOARD_CYTRON_SHIELD
// #define CUSTOM_BOARD


// Your custom pins
#ifdef CUSTOM_BOARD
#if defined(ESP8266)    // for ESP based board
    #define DIO0    2
    #define DIO1    6
    #define DIO5    8
    #define DIO2    7
    #define CS      10
    #define RFM_RST 9        
#else                   // for Arduino board
    #define DIO0    2
    #define DIO1    6
    #define DIO5    8
    #define DIO2    7
    #define CS      10
    #define RFM_RST 9        
#endif  
#endif // _CUSTOM_BOARD_


// LoRaWAN freq. band
#define AS_923
// #define EU_868

#endif
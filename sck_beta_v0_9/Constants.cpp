#include "Constants.h"

#if (networks > 0)

const char* mySSID[networks]      = { 
    "SSID1",
    "SSID2"
};

const char* myPassword[networks]  = { 
    "PASS1",
    "PASS2"
};

const char* wifiEncript[networks] = { 
  WPA2,
  WPA2
};

const char* antennaExt[networks]  = { 
  INT_ANT,
  INT_ANT
};

#endif      

char buffer[buffer_length];

const char* WEB[8]={
  "data.smartcitizen.me",
  "PUT /add HTTP/1.1\n", 
  "Host: data.smartcitizen.me \n", 
  "User-Agent: SmartCitizen \n", 
  "X-SmartCitizenMacADDR: ", 
  "X-SmartCitizenApiKey: ", 
  "X-SmartCitizenVersion: ",  
  "X-SmartCitizenData: "
};

const char* WEBTIME [3]={                  
    /*Servidor de tiempo*/
    "GET /datetime HTTP/1.1\n",
    "Host: data.smartcitizen.me \n",
    "User-Agent: SmartCitizen \n\n"  
};

// Data JSON structure                  
const char* SERVER[11]={
    "{\"temp\":\"",
    "\",\"hum\":\"", 
    "\",\"light\":\"",
    "\",\"bat\":\"",
    "\",\"panel\":\"",
    "\",\"co\":\"", 
    "\",\"no2\":\"", 
    "\",\"noise\":\"", 
    "\",\"nets\":\"", 
    "\",\"timestamp\":\"", 
    "\"}"
};

const char* SENSOR[10]={
    "Temperature: ",
    "Humidity: ",
    "Light: ",
    "Battery: ",
    "Solar Panel: ",
    "Carbon Monxide: ",
    "Nitrogen Dioxide: ",
    "Noise: ",
    "Wifi Spots: ",
    "UTC: " 
};

const char* UNITS[9]={
    #if F_CPU == 8000000 
        " C RAW",
        " % RAW",
    #else
        " C",
        " %",
    #endif
    #if F_CPU == 8000000 
        " lx",
    #else
        " %",
    #endif

    " %",
    " mV",
    " kOhm",
    " kOhm",
    " mV",
    "",
};  

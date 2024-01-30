#ifndef MAIN_WIFI_APP_H
#define MAIN_WIFI_APP_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"

#include "esp_netif.h"

// WiFi application settings
#define WIFI_AP_SSID "ESP32_AP"          // AP name
#define WIFI_AP_PASSWORD "password"     // AP password
#define WIFI_AP_CHANNEL 1                // AP channel
#define WIFI_AP_SSID_HIDDEN 0            // AP visibility
#define WIFI_AP_MAX_CONNECTIONS 0        // AP max connections
#define WIFI_AP_BEACON_INTERVAL 100      // AP beacon: 100 milliseconds recommend
#define WIFI_AP_IP "192.168.0.1"         // AP default IP
#define WIFI_AP_GATEWAY "192.168.0.1"    // AP default Gateway (shold be the same as the IP)
#define WIFI_AP_NETMASK "255.255.255.0"  // AP netmask
#define WIFI_AP_BANDWIDTH WIFI_BW_HT20   // AP bandwidth 20 MHz (40 MHz is the other option)
#define WIFI_STA_POWER_SAVE WIFI_PS_NONE // Power save not used
#define MAX_SSID_LENGTH 32               // IEEE standard maximum
#define MAX_PASSWORD_LENGTH 32           // IEEE standard maximum
#define MAX_CONNECTION_RETRIES 10         // Retry number on disconnect

// netif object for the Station and Access Point
extern esp_netif_t *esp_netif_sta;
extern esp_netif_t *esp_netif_ap;

/**
 * Structure for the WiFi application task
 * @note Expand this based on application requirements
 */
typedef enum wifi_app_message
{
    WIFI_APP_MSG_START_HTTP_SERVER = 0,
    WIFI_APP_MSG_CONNECTING_FROM_HTTP_SERVER,
    WIFI_APP_MSG_STA_CONNECTED_GOT_IP,
} wifi_app_message_e;

/**
 * Structure for the message queue
 * @note Expand this based on application requirements e.g. add another type and parameter as required
 */
typedef struct wifi_app_queue_message
{
    wifi_app_message_e msgID;
} wifi_app_queue_message_t;

/**
 * Sends a message to the queue
 * @param msgID message ID from the wifi_app_message_e enum.
 * @return pdTRUE if an item was successfully sent to the queue, otherwise pdFALSE.
 * @note Expand the parameter list based on your requirements e.g. how you've expanded the wifi_app_queue_message_t
 */
BaseType_t wifi_app_send_message(wifi_app_message_e msgID);

/**
 * Structure for the message queue
 * @note Expand this based on application requirements e.g. add another type and parameter as required
 */
void wifi_app_start(void);

#endif
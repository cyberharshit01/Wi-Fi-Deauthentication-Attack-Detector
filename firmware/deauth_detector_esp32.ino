#include <WiFi.h>
#include "esp_wifi.h"

#define LED_PIN 5            // GPIO5  (D5)
#define BUZZER_PIN 4         // GPIO4  (D4)

volatile unsigned int deauth_count = 0;
unsigned long last_reset_time = 0;
const int ATTACK_THRESHOLD = 5;   // frames per second

// ESP32 promiscuous callback (runs in the Wi-Fi task, keep it short)
void sniffer(void *buf, wifi_promiscuous_pkt_type_t type) {
  if (type != WIFI_PKT_MGMT) return;                 // only management frames
  wifi_promiscuous_pkt_t *pkt = (wifi_promiscuous_pkt_t *)buf;
  uint8_t frame_ctrl = pkt->payload[0];              // type/subtype byte
  if (frame_ctrl == 0xC0 || frame_ctrl == 0xA0) {    // Deauth or Disassoc
    deauth_count++;
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  esp_wifi_set_promiscuous_rx_cb(&sniffer);
  esp_wifi_set_promiscuous(true);
  esp_wifi_set_channel(1, WIFI_SECOND_CHAN_NONE);    // change to your lab network channel
  Serial.println("ESP32 Deauth Detector Active. Sniffing...");
}

void loop() {
  if (millis() - last_reset_time >= 1000) {
    unsigned int count = deauth_count;
    deauth_count = 0;
    last_reset_time = millis();
    if (count >= ATTACK_THRESHOLD) {
      Serial.printf("ALERT: Deauth attack detected! Frames: %u/s\n", count);
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(BUZZER_PIN, HIGH);
    } else {
      digitalWrite(LED_PIN, LOW);
      digitalWrite(BUZZER_PIN, LOW);
    }
  }
}

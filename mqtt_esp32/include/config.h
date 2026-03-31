#ifndef CONFIG_H
#define CONFIG_H

struct WifiConfig {
  const char* ssid;
  const char* password;
};

struct HiveConfig {
  const char* broker_url;
  int port;
  const char* username;
  const char* password;
  const char* topic;
};

#endif
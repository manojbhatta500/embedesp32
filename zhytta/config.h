#ifndef CONFIG_H
#define CONFIG_H

struct Config{
  String w_ssid;
  String w_password;
};
struct AppState {
  bool isRunning;
  int ledPin;
};



#endif
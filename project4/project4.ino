#define LED_PIN 2
#define PR_PIN 36  // GPIO 36 = VP = ADC1_CH0 (use the actual GPIO number, not the ADC constant)

const int threshold = 3900;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  // No pinMode needed for analog input on ESP32
  Serial.begin(115200);
}

void loop() {
  int pr_value = read_pr_value(PR_PIN);
  Serial.println(pr_value);
  delay(500); // small delay to avoid flooding serial
}

int read_pr_value(int pin_No) {
  int pr_value = analogRead(pin_No);
  return pr_value;
}

void display_pr_value(int value) {
  Serial.printf("the current value is : %d\n", value);  // removed & (that was a pointer bug)

  if (value < threshold) {
    digitalWrite(LED_PIN, HIGH);  // dark = LED on
    Serial.println("Dark - LED ON");
  } else {
    digitalWrite(LED_PIN, LOW);   // bright = LED off
    Serial.println("Bright - LED OFF");
  }
}
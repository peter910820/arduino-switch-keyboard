const int buttonPin = 2;
int buttonState = HIGH;         // 當前按鍵狀態
int lastButtonState = HIGH;     // 上一個按鍵狀態
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 1;    // 防抖動延遲

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600); 
}

void loop() {
  int reading = digitalRead(buttonPin); // 讀取當前按鍵狀態
  // 檢查按鍵狀態是否有變化
  if (reading != lastButtonState) {
    lastDebounceTime = millis(); // 更新最後一次變化的時間
  }

  // 如果狀態在一定時間內穩定，則更新按鍵狀態
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // 更新按鍵狀態
    if (reading != buttonState) {
      buttonState = reading;

      // 檢查按鍵按下
      if (buttonState == LOW) {
        Serial.println("enter");
      }
    }
  }

  lastButtonState = reading; // 更新上一次的按鍵狀態
}
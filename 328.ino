// 定義腳位
const int BUZZER_PIN = 8;    // 蜂鳴器腳位
const int LED_PIN = 13;      // LED腳位
const int SWITCH_PIN = 2;    // 開關腳位

void setup() {
  // 初始化腳位
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(SWITCH_PIN, INPUT_PULLUP);  // 使用內部上拉電阻
  
  // 初始化序列通訊，用於除錯
  Serial.begin(9600);
}

void loop() {
  // 讀取開關狀態
  int switchState = digitalRead(SWITCH_PIN);
  
  if (switchState == LOW) {  // 當開關被按下時
    // 點亮LED
    digitalWrite(LED_PIN, HIGH);
    
    // 蜂鳴器發出聲音
    tone(BUZZER_PIN, 1000);  // 1000Hz
    delay(500);              // 持續500毫秒
    noTone(BUZZER_PIN);      // 停止蜂鳴器
    
    // 關閉LED
    digitalWrite(LED_PIN, LOW);
    
    // 等待一段時間避免重複觸發
    delay(1000);
  }
}

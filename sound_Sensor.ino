const int mic_analog_pin = A0;
const int mic_digital_pin = 3;

int outpins[8] = {6,7,8,9,10,11,12,13};

void setup() {
  Serial.begin(9600);
  pinMode(mic_analog_pin, INPUT);
  pinMode(mic_digital_pin, INPUT);
  for (int index = 0; index < 8; index++){
    pinMode(outpins[index], OUTPUT);
  }
}

void loop() {
   byte res = analogRead(mic_analog_pin);
   Serial.print("Analog: ");
   Serial.print(res);
   Serial.print("  ");
   byte res_d = digitalRead(mic_digital_pin);
   Serial.print("Digital: ");
   Serial.print(res_d);
   Serial.println("  ");
   delay(100);
    
    if(res>=35 && res <=26){
      digitalWrite(outpins[0], HIGH);
      for (int index = 1; index < 8; index++){
        digitalWrite(outpins[index], LOW);
        delay(10);
      }
    }else if(res>26){
      int modRe = res / 25;
      if(modRe>=8){
        modRe = 7;
      }
      for (int index = 0; index <= modRe; index++){
        digitalWrite(outpins[index], HIGH);
        delay(10);
      }

      for (int index = modRe; index <= 7; index++){
        digitalWrite(outpins[index], LOW);
        delay(10);
      }
    }else{
       for (int index = 0; index <= 7; index++){
        digitalWrite(outpins[index], LOW);
        delay(10);
      }
    }

    delay(100);


}

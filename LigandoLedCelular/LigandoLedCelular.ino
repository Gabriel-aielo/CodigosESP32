#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;


char valorRecebido;




void setup() {
Serial.begin(115200);

SerialBT.begin("Bluetooth LED");
Serial.println("Dispositivo Visivel");


pinMode(13, OUTPUT);
}

void loop() {
  valorRecebido = (char)SerialBT.read();

  if(Serial.available()){
    SerialBT.write(Serial.read());

  }

  if(SerialBT.available()) {

    if(valorRecebido == '2'){
      SerialBT.println("LED: Desligado");
      digitalWrite(13, HIGH);

    }

    else if(valorRecebido == '1'){
      SerialBT.println("LED: Ligado");
      digitalWrite(13, LOW);

    }else if(valorRecebido > '2'){

      SerialBT.println("LED: piscando");
      
        digitalWrite(13, HIGH);
        delay(300);

        digitalWrite(13, LOW);
        delay(300);
      
    }

  }

  delay(50);

}

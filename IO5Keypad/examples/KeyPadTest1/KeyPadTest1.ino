#include <IO5Keypad.h>

IO5KeyPad myKeyPad;

// Variable zum Speichern der Position
int pos = 0;
int  PrevKey = 0;   // Vor neuem KeyScann speichern des vorherigen Wertes

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  int result = myKeyPad.GetKey;
  if (result > 0)
  {
    if (PrevKey != result)
    {
      // Key pressed  
      Serial.println(result);
    }
  }
  PrevKey = result;

}

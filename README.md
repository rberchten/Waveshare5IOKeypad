# Waveshare 5IO Keypad
Arduino Library to access easy the Waveshare-Keypad with 10 buttons and joystick

Author: rene berchten www.amosmarine.de created : 20.1.2016

Public classes class IO5KeyPad { public: IO5KeyPad(pinIo1,pinIo2,pinIo3,pinIo4,pinIo5); 
int GetKey();
     Result is the pressed KeyValue, as long as it is pressed the value will be returned  
int GetKeyChanged();
    gives as result the pressed KeyValue once, until it is released 


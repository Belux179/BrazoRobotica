
class joystick{
 private:
    int pin_joyY;
    int pin_joyX;
    int pin_joyZ;
    int valorY;
    int valorX;
    int valorZ;
    
 public:
   void _ini(int pin_x, int pin_y, int pin_z){
      pin_joyZ=pin_z;
      pin_joyX=pin_x;  
      pin_joyY=pin_y;
      
    }
    void _ini(int pin_x, int pin_y){
      pin_joyY=pin_y;
      pin_joyX=pin_x;  
    }
    int X_VR(){
      valorX = analogRead(pin_joyX);
      return valorX;
    }
    int Y_VR(){
      valorY = analogRead(pin_joyY);
      return valorY;
    }
    int Z_VR(){
      valorZ = analogRead(pin_joyZ);
      return valorZ;
    }
    void leer(){
      valorY = analogRead(pin_joyY);
      valorX = analogRead(pin_joyX);
    }
    void leerz(){
      valorY = analogRead(pin_joyY);
      valorX = analogRead(pin_joyX);
      valorZ = analogRead(pin_joyZ);
    }
    int valuex(){
      return valorX;
    }
    int valuey(){
      return valorY;
    }
    int valuez(){
      return valorZ;
    }
    
};
  

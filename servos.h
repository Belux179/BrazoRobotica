#include <Servo.h>

class servos {
 private:
    int pin_b;
    int pos_b;
    int esc_b;
    int temp;
    int lim_me;
    int lim_ma;
    
    Servo servo_b;
 public:
   void servos_ini(int pin_bb, int posixion, int escalar,int limite_menor,int limite_mayor){
      if(limite_menor>posixion) posixion=limite_menor;
      if(limite_mayor<posixion) posixion=limite_mayor;
      temp=posixion;
      lim_me=limite_menor;
      lim_ma=limite_mayor;
      pin_b = pin_bb;
      pos_b = posixion;
      esc_b = escalar;
      servo_b.attach(pin_b);
    }
    void servo_ma(){
        temp+=esc_b;
        if(temp<=lim_ma){ 
          pos_b+=esc_b;
        }else{
          temp=pos_b;  
        }
        servo_b.write(pos_b);
    }
    void servo_me(){
        temp-=esc_b;
        if(temp>=lim_me){ 
          pos_b-=esc_b;
        }else{
          temp=pos_b;  
        }
        servo_b.write(pos_b);
    }
    void mostrar(){
      servo_b.write(pos_b);  
    }
};
  
  

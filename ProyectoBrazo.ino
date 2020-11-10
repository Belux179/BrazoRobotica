#include "servos.h"
#include "joystick.h"
#include <Stepper.h> 

int stepIN1Pin = 8;         
int stepIN2Pin = 9;
int stepIN3Pin = 10;
int stepIN4Pin = 11;
int stepsPerRevolution = 2048; 
const int button1Pin = 12; 
const int button2Pin = 13; 
Stepper myStepper(stepsPerRevolution, stepIN1Pin, stepIN3Pin, stepIN2Pin, stepIN4Pin);
servos base, bajad_iz, bajad_de, mano;

joystick jyy;
 
void setup() {
  //servos_ini(int pin, int posixion_inicial, int escalar,int limite_menor,int limite_mayor){
  bajad_iz.servos_ini(5, 0, 1,0,180);;
  bajad_de.servos_ini(6, 180, 1,0,180);;
  jyy._ini(A0,A1);
  base.servos_ini(3, 0, 10,0,180);
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  myStepper.setSpeed(15);
  Serial.begin(9600);

  
}

void loop() {
  //inicio de todos
  base.mostrar();
  bajad_de.mostrar();
  bajad_iz.mostrar();
  SteppMotor();
  
  //este es para movimiento de la base
  if(jyy.X_VR()>1000) base.servo_ma();
  if(jyy.X_VR()<100)  base.servo_me();
  
  //para bajada
  if(jyy.Y_VR()>1000){ 
    bajad_iz.servo_ma();
    bajad_de.servo_me();
  }
  if(jyy.Y_VR()<100){  
    bajad_de.servo_ma();
    bajad_iz.servo_me();
  }

  //mano

  
  Serial.print(jyy.valuex());
  Serial.print("\t");
  Serial.println(jyy.valuey());

}

void SteppMotor(){
  int button1State, button2State;
  
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);
  
  if (((button1State == LOW) && !(button2State == LOW)))  
    myStepper.step(stepsPerRevolution/20);
  if (((button2State == LOW) && !(button1State == LOW)))  
    myStepper.step(-stepsPerRevolution/20);
}


#define STOP_MOTOR 0

class Motor {

  // These functions are visible to anyone using this class
  public:
  
    Motor(uint8_t pin1, uint8_t pin2) {
      this->pin1 = pin1;
      this->pin2 = pin2;
    } 
    
    // Writes a value to the motor to change the speed
    void driveMotor(int8_t speeed) { // Speed: [-128..127]
      if (speeed > STOP_MOTOR) {
        digitalWrite(pin1, LOW);
        analogWrite(pin2, speeed << 1); // 
      } else if (speeed < STOP_MOTOR) {
        digitalWrite(pin2, LOW);
        analogWrite(pin1, ((speeed - 1) ^ 0xff) << 1); // Convert 2's complement negative number to positive
      } else { // speeed = STOP_MOTOR
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, LOW); 
      }
    }

    void stopMotor() {
      driveMotor(STOP_MOTOR);
    }

  // These functions/vars are only accessible from within the class itself
  private:
    
    uint8_t pin1, pin2;
};

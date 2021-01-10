String pin = "RGBBR";
String input = "";
String combinations[6] = {"RGB","GRB","GBR","BGR","RBG","BRG"};
int index = 0;
boolean isButtonPressed = false;

void setup() {
  Serial.begin(9600);
  // Buttons
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  // LED 1
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  // LED 2
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  // LED 3
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  // Transistors Base
  pinMode(A2,OUTPUT);
}

void loop() {
  
  input = "";
  
  for (int j = 0; j < pin.length(); j++)
  {
    for (int i = 0; i < 10; i++)
    {
      index = rand() % 6;
      
      if (index == 0)
      {
        // LED 1
        digitalWrite(13,1);
        digitalWrite(12,0);
        digitalWrite(11,0);
        // LED 2
        digitalWrite(10,0);
        digitalWrite(9,1);
        digitalWrite(8,0);
        // LED 3
        digitalWrite(7,0);
        digitalWrite(6,0);
        digitalWrite(5,1);
      }
      else if (index == 1)
      {
        // LED 1
        digitalWrite(13,0);
        digitalWrite(12,1);
        digitalWrite(11,0);
        // LED 2
        digitalWrite(10,1);
        digitalWrite(9,0);
        digitalWrite(8,0);
        // LED 3
        digitalWrite(7,0);
        digitalWrite(6,0);
        digitalWrite(5,1);
      }
      else if (index == 2)
      {
        // LED 1
        digitalWrite(13,0);
        digitalWrite(12,1);
        digitalWrite(11,0);
        // LED 2
        digitalWrite(10,0);
        digitalWrite(9,0);
        digitalWrite(8,1);
        // LED 3
        digitalWrite(7,1);
        digitalWrite(6,0);
        digitalWrite(5,0);
      }
      else if (index == 3)
      {
        // LED 1
        digitalWrite(13,0);
        digitalWrite(12,0);
        digitalWrite(11,1);
        // LED 2
        digitalWrite(10,0);
        digitalWrite(9,1);
        digitalWrite(8,0);
        // LED 3
        digitalWrite(7,1);
        digitalWrite(6,0);
        digitalWrite(5,0);
      }
      else if (index == 4)
      {
        // LED 1
        digitalWrite(13,1);
        digitalWrite(12,0);
        digitalWrite(11,0);
        // LED 2
        digitalWrite(10,0);
        digitalWrite(9,0);
        digitalWrite(8,1);
        // LED 3
        digitalWrite(7,0);
        digitalWrite(6,1);
        digitalWrite(5,0);
      }
      else if (index == 5)
      {
        // LED 1
        digitalWrite(13,0);
        digitalWrite(12,0);
        digitalWrite(11,1);
        // LED 2
        digitalWrite(10,1);
        digitalWrite(9,0);
        digitalWrite(8,0);
        // LED 3
        digitalWrite(7,0);
        digitalWrite(6,1);
        digitalWrite(5,0);
      }
      
      delay(250);
    }
    
    Serial.println("");
    Serial.println(combinations[index]);
    Serial.println("");
    
    while (!isButtonPressed)
    {
      // Button 1
      if (digitalRead(4) == 1)
      {
        input += combinations[index][0];
        isButtonPressed = true;
      }
      // Button 2
      else if (digitalRead(3)==1)
      {
        input += combinations[index][1];
        isButtonPressed = true;
      }
      // Button 3
      else if (digitalRead(2)==1)
      {
        input += combinations[index][2];
        isButtonPressed = true;
      }
    }
    isButtonPressed = false;
  
    Serial.println("");
    Serial.print("User Typed: ");
    Serial.println(input);
    Serial.println("");
  }

  if (input == pin) // Flash GREEN
  {
    Serial.println("");
    Serial.println("PIN CORRECT! ");
    Serial.println("");
    for (int k = 0; k < 4; k++)
    {
      digitalWrite(13,0);
      digitalWrite(12,1);
      digitalWrite(11,0);
      digitalWrite(10,0);
      digitalWrite(9,1);
      digitalWrite(8,0);
      digitalWrite(7,0);
      digitalWrite(6,1);
      digitalWrite(5,0);
      delay(250);
      digitalWrite(13,0);
      digitalWrite(12,0);
      digitalWrite(11,0);
      digitalWrite(10,0);
      digitalWrite(9,0);
      digitalWrite(8,0);
      digitalWrite(7,0);
      digitalWrite(6,0);
      digitalWrite(5,0);
      delay(250);
    }
    
    digitalWrite(13,0);
    digitalWrite(12,1);
    digitalWrite(11,0);
    digitalWrite(10,0);
    digitalWrite(9,1);
    digitalWrite(8,0);
    digitalWrite(7,0);
    digitalWrite(6,1);
    digitalWrite(5,0);
    delay(250);
    // Turn on motor
    digitalWrite(A2,1);
    delay(1500);
    digitalWrite(A2,0);
  }
  else // Flash RED
  {
    Serial.println("");
    Serial.println("PIN INCORRECT! ");
    Serial.println("");
    for (int k = 0; k < 5; k++)
    {
      digitalWrite(13,1);
      digitalWrite(12,0);
      digitalWrite(11,0);
      digitalWrite(10,1);
      digitalWrite(9,0);
      digitalWrite(8,0);
      digitalWrite(7,1);
      digitalWrite(6,0);
      digitalWrite(5,0);
      delay(250);
      digitalWrite(13,0);
      digitalWrite(12,0);
      digitalWrite(11,0);
      digitalWrite(10,0);
      digitalWrite(9,0);
      digitalWrite(8,0);
      digitalWrite(7,0);
      digitalWrite(6,0);
      digitalWrite(5,0);
      delay(250);
    }
  }
    
}

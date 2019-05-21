int sensorA=A0;
int buzzer=8;
int sensorValue=0;
int esikDegeri=400;
int alarm=800;

void setup()
{
  pinMode(sensorA,INPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  sensorValue=analogRead(sensorA);
  Serial.println(sensorValue);
  delay(1);
  if(sensorValue>alarm)
  {
    Serial.println("Toprak nemi kritik sinirda");
    delay(100);
    digitalWrite(buzzer,HIGH);
    delay(100);
    digitalWrite(buzzer,LOW);
    delay(100);
  }
  else if(sensorValue<alarm&&sensorValue>esikDegeri)
  {
    Serial.println("Toprak nemi olmasi gereken degerin altinda");
    delay(100);
    digitalWrite(buzzer,HIGH);
    delay(1000);
    digitalWrite(buzzer,LOW);
    delay(1000);
  }
  else{
    Serial.println("Toprak nemi olmasi gereken degerde");
    delay(100);
    digitalWrite(buzzer,LOW);
  }
}


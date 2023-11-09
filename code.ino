#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 2, 3, 4, 5);

int tmp = 0;
int ventilador = 12;

int hmd = 2;
int riego = 13;

int lmd = 1;
int led = 11;

void setup()
{
  lcd.begin(16, 2);

  pinMode(ventilador, OUTPUT);
  pinMode(riego, OUTPUT);
  pinMode(led, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  lcd.setCursor(0, 0);

  // Temperatura
  float valorLeido0 = analogRead(tmp);
  int voltaje = map(valorLeido0, 20, 358, 0, 5);
  float temperatura = ((5 * valorLeido0 * 100) / 1024) - 50;
  lcd.print("TEMP: ");
  lcd.print(temperatura);

  if (temperatura >= 30)
  {
    digitalWrite(ventilador, HIGH);
  }
  else
  {
    digitalWrite(ventilador, LOW);
  }

  // Humedad
  int valorLeido1 = analogRead(hmd);
  int humedad = map(valorLeido1, 0, 876, 0, 100);
  lcd.setCursor(0, 1);
  lcd.print("HUMEDAD: ");
  lcd.print(humedad);
  lcd.print("%");

  if (humedad < 80)
  {
    digitalWrite(riego, HIGH);
  }
  else
  {
    digitalWrite(riego, LOW);
  }

  // Luminosidad
  int valorLeido2 = analogRead(lmd);
  int luminosidad = map(valorLeido2, 6, 679, 0, 100);

  if (luminosidad < 50)
  {
    digitalWrite(led, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
  }
}

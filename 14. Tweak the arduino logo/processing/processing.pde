import processing.serial.*;
Serial myPort;

PImage logo;

int bgcolor = 0;

void setup(){
  colorMode(HSB, 255);
  logo = loadImage("https://cdn.arduino.cc/header-footer/prod/assets/favicon-arduino/apple-touch-icon-114x114.png"); //Replaced url with newer link to the logo
  //size(logo.width, logo.height);
  size(200, 200); //Fixes bug with the books code
  
  println("Available serial ports: ");
  println(Serial.list());
  
  myPort = new Serial(this, Serial.list()[1], 9600);
}
void draw(){
  if (myPort.available() > 0) {
    bgcolor = myPort.read();
    println(bgcolor);
  }
  background(bgcolor, 255, 255);
  image(logo, 0, 0);
}

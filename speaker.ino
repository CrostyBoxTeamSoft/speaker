//www.idehack.com
#include <SPI.h>
#include <SD.h> // Inclure la librairie SD
#define SDPIN 10 // Chip Select du lecteur SD
#include <TMRpcm.h> 

File myFile;
TMRpcm tmrpcm;
const int speakerPin=9;//47
char* CroquetteSound = (char*)"sounds/hey.WAV";
char caractere; // Définition du caractère pour la gestion dans le moniteur série

void setup(){
  Serial.begin(9600); //début de la communication série

   // Initialisation de la carte SD
  if (!SD.begin(SDPIN)) { 
    Serial.println("initialization failed!"); //  S'il y a un soucis "initialization failed!" s'affichera au moniteur
    return;
  }

  //Init speaker
  tmrpcm.speakerPin = speakerPin; // Speaker sur la pin 9
  tmrpcm.setVolume(7); // gestion du volume de 0 à 7
  tmrpcm.quality(1); // qualitée audio 0 ou 1
  
  Serial.println("tapez un caractere -> a");
}

void loop(){
    if(Serial.available()){
      caractere = Serial.read();
      if(caractere == 'a') { // Si le caractère recu dans le moniteur série est "a"
        Serial.println("Lecture"); // Ecrit dans le moniteur série 
        tmrpcm.play(CroquetteSound); // Joue le son "son8bit.wav"
          if(tmrpcm.isPlaying())
          {
            Serial.println("Fichier en cours de lecture");
          }
          else
          {
            Serial.println("Fichier pas lu");
          }
      }
    }
}
 
void playSound(char *file)
{
 tmrpcm.play(file);
 return; 
}

int snelheid = 200;
int debug = 400;
const int start = 13;
int PWM1 = 5;
int PWM2 = 6;
int richting1 = 4;
int richting2 = 7;
int sensor1 = A0;
int sensor2 = A1;
int sensor3 = A2;
int huidigeLetter = 0;
int getal[7]={1,2,3,8,9,10,11,12};

void setup() {
  for(int x=0; x<7; x++){
    pinMode(getal[x], OUTPUT);
  }
  pinMode(start, INPUT);
}

void loop() {
  if(digitalRead(start)){
//    schrijfLetterS();
//    delay(500);
//    schrijfLetterO();
//    delay(500);
//    schrijfLetterE();
//    delay(500);
    schrijfLetterP();
      
//    roteerLinksom(snelheid, 1000);
//    delay(debug);
//    roteerRechtsom(snelheid, 1000);
//    delay(debug);
//    roteerLinksom(snelheid, 2000);
//    delay(debug);
//    roteerRechtsom(snelheid, 2000);
//    delay(10000);
  }
}

void schrijfLetterE(){    //klaar
  rijd10cmVooruit();
  delay(debug);
  rijdVooruit(snelheid, 1300);
  delay(debug);
  roteerRechtsom(snelheid, 1100);
  delay(debug);
  rijdVooruit(snelheid, 700);
  delay(debug);
  rijdAchteruit(snelheid, 700);
  delay(debug);
  roteerLinksom(snelheid, 1050);
  delay(debug);
  rijdAchteruit(snelheid, 650);
  delay(debug);
  roteerRechtsom(snelheid, 1100);
  delay(debug);
  rijdVooruit(snelheid, 700);
  delay(debug);
  rijdAchteruit(snelheid, 700);
  delay(debug);
  roteerLinksom(snelheid, 1050);
  delay(debug);
  rijdAchteruit(snelheid, 650);
  delay(debug);
  roteerRechtsom(snelheid, 1100);
  delay(debug);
  rijdVooruit(snelheid, 700);
  delay(debug);
  rijdAchteruit(snelheid, 700);
  delay(debug);
  roteerRechtsom(snelheid, 1050); 
  delay(debug);
  rijdNaarReferentielijn();
  delay(debug);
  roteerLinksom(snelheid, 1100);
  delay(debug);
  rijdVooruit(snelheid, 1500);
  delay(debug);
  roteerLinksom(snelheid, 1100);
  delay(debug);
  
}

void schrijfLetterO(){    //klaar
  rijd10cmVooruit();
  delay(debug);
  rijdVooruit(snelheid, 300);
  delay(debug);
  draaiRechtsomVooruit(snelheid, 4300);
  delay(debug);
  rijdVooruit(snelheid, 300);
  delay(debug);
  draaiRechtsomVooruit(snelheid, 4300);
  delay(debug);
  roteerLinksom(snelheid, 2000);
  delay(debug);
  rijdNaarReferentielijn();
  delay(debug);
  roteerLinksom(snelheid, 1000);
  delay(debug);
  rijdVooruit(snelheid, 1500);
  delay(debug);
  roteerLinksom(snelheid, 1000);
   
}

void schrijfLetterP(){    //klaar
  rijd10cmVooruit();
  delay(debug);
  rijdVooruit(snelheid, 1300);
  delay(debug); 
  roteerRechtsom(snelheid,1100);
  delay(debug);
  rijdVooruit(snelheid, 200);
  delay(debug);
//  draaiRechtsomVooruit(snelheid, 4200);
  draaiRechtsomVooruitCirkelKlein(3500);
  delay(debug);
  rijdVooruit(snelheid, 220);
  delay(debug);
  roteerLinksom(snelheid, 1050);
  delay(debug);
  rijdNaarReferentielijn();
  delay(debug);
  roteerLinksom(snelheid, 1100);
  delay(debug);
  rijdVooruit(snelheid, 1500);
  delay(debug);
  roteerLinksom(snelheid, 1100);
    
}

void schrijfLetterS(){    //klaar
  rijd10cmVooruit();
  delay(debug);
  roteerRechtsom(snelheid, 1100);
  delay(debug);
  rijdVooruit(snelheid, 250);
  delay(debug);
  draaiLinksomVooruitCirkelKlein(3200);
  delay(debug);
  draaiRechtsomVooruitCirkelKlein(3350);
  delay(debug);
  rijdVooruit(snelheid, 500);
  delay(debug);
  roteerRechtsom(snelheid, 1000);
  delay(debug);
  rijdNaarReferentielijn();
  delay(debug);
  rijdNaarReferentielijn();
  roteerLinksom(snelheid, 1000); 
  delay(500);
  rijdVooruit(snelheid, 360); 
  delay(500);
  roteerLinksom(snelheid, 1000);
  
}

void rijdVooruit(int snelheid, int rijtijd)
{
  digitalWrite(richting1, LOW);
  digitalWrite(richting2, HIGH);
  analogWrite(PWM1, snelheid);
  analogWrite(PWM2, snelheid);
  delay(rijtijd);
  analogWrite(PWM1, 0);
  analogWrite(PWM2, 0);
}

void rijd10cmVooruit()
{
  digitalWrite(richting1, LOW);
  digitalWrite(richting2, HIGH);
  analogWrite(PWM1, 200);
  analogWrite(PWM2, 200);
  delay(850);
  analogWrite(PWM1, 0);
  analogWrite(PWM2, 0);
}

void rijdAchteruit(int snelheid, int rijtijd)
{
  digitalWrite(richting1, HIGH);
  digitalWrite(richting2, LOW);
  analogWrite(PWM1, snelheid);
  analogWrite(PWM2, snelheid);
  delay(rijtijd);
  analogWrite(PWM1, 0);
  analogWrite(PWM2, 0);
}

void draaiLinksomVooruit(int snelheid, int draaitijd)
{
  digitalWrite(richting1, LOW);
  analogWrite(PWM1, snelheid);
  delay(draaitijd);
  analogWrite(PWM1, 0); 
}

void draaiLinksomAchteruit(int snelheid, int draaitijd)
{
  digitalWrite(richting1, HIGH);
  analogWrite(PWM1, snelheid);
  delay(draaitijd);
  analogWrite(PWM1, 0); 
}

void draaiLinksomVooruitCirkelKlein(int draaitijd)
{
  digitalWrite(richting1, LOW);
  digitalWrite(richting2, LOW);
  analogWrite(PWM1, 240);
  analogWrite(PWM2, 90);
  delay(draaitijd);
  analogWrite(PWM1, 0); 
  analogWrite(PWM2, 0);
}

void draaiRechtsomVooruitCirkelKlein(int draaitijd)
{
  digitalWrite(richting1, HIGH);
  digitalWrite(richting2, HIGH);
  analogWrite(PWM1, 90);
  analogWrite(PWM2, 240);
  delay(draaitijd);
  analogWrite(PWM1, 0); 
  analogWrite(PWM2, 0);
}

void roteerLinksom(int snelheid, int draaitijd)
{
  digitalWrite(richting1, LOW);
  digitalWrite(richting2, LOW);
  analogWrite(PWM1, snelheid);
  analogWrite(PWM2, snelheid);
  delay(draaitijd);
  analogWrite(PWM1, 0);
  analogWrite(PWM2, 0); 
}

void draaiRechtsomVooruit(int snelheid, int draaitijd)
{
  digitalWrite(richting2, HIGH);
  analogWrite(PWM2, snelheid);
  delay(draaitijd);
  analogWrite(PWM2, 0); 
}

void draaiRechtsomAchteruit(int snelheid, int draaitijd)
{
  digitalWrite(richting2, LOW);
  analogWrite(PWM2, snelheid);
  delay(draaitijd);
  analogWrite(PWM2, 0); 
}

void roteerRechtsom(int snelheid, int draaitijd)
{
  digitalWrite(richting1, HIGH);
  digitalWrite(richting2, HIGH);
  analogWrite(PWM1, snelheid);
  analogWrite(PWM2, snelheid);
  delay(draaitijd);
  analogWrite(PWM1, 0);
  analogWrite(PWM2, 0);  
}

boolean detecteerKaderlijn(){
  int waarde = 750;
  if(analogRead(sensor1) <= waarde && analogRead(sensor2) <= waarde && analogRead(sensor3) <= waarde){        //als sensor 1, 2 & 3 'aan' staan
    return false;                                                                                             //FALSE
  }else if(analogRead(sensor1) >= waarde && analogRead(sensor2) >= waarde && analogRead(sensor3) >= waarde){  //als sensor 1, 2 en 3 'uit' staan
    return true;                                                                                              //TRUE
  }else{
    return false;                                                                                             //anders FALSE
  }
}

void rijdNaarReferentielijn(){
  int waarde = 750;
  while(!(analogRead(A0) > waarde && analogRead(A1) < waarde && analogRead(A2) > waarde)){   //alleen sensor 2 detecteert een lijn
    rijdVooruit(100, 10);
  }
}

void beginProgramma(){
  /*
   * Draai naar links
   * rijd naar kaderlijn
   * draai links
   * rijd naar kaderlijn
   * nu in linksonder hoek
   * draai naar rechts
   * rijd stukje vooruit
   * draai links
   * rijd naar referentielijn
   */
  roteerLinksom(snelheid, 1100);    //roteer richting linker kaderlijn
  delay(debug);
  while(!(detecteerKaderlijn())){
    rijdVooruit(snelheid, 10);      //rijd naar kaderlijn
  }
  delay(debug);
  rijdAchteruit(snelheid, 40);      //achteruit
  delay(debug);
  roteerLinksom(snelheid, 1100);    //roteer richting onderste kaderlijn
  delay(debug);
  while(!(detecteerKaderlijn())){
    rijdVooruit(snelheid, 10);      //rijd naar onderste kaderlijn
  }
  delay(debug);
  rijdAchteruit(snelheid, 40);      //achteruit
  delay(debug);
  roteerLinksom(snelheid, 1100);    //roteer naar links
  delay(debug);
  rijdVooruit(snelheid, 360);       //vooruit
  delay(debug);
  roteerLinksom(snelheid, 1100);    //roteer richting referentie lijn
  delay(debug);
  rijdNaarReferentielijn();         //rijd naar referentie lijn
}

void eindeProgramma(){
  /*
   * 180 graden roteren
   * rijdt tot aan de kaderlijn
   * iets naar achteren rijden
   * roteer 90 graden links
   * rijdt tot aan de kaderlijn
   * roteer 90 graden rechts
   * rijd iets vooruit
   */
   roteerLinksom(snelheid, 2000);   //roteer 180 graden
   delay(debug);
   while(!(detecteerKaderlijn)){
    rijdVooruit(snelheid, 10);      //rijd tot aan kaderlijn
   }
   delay(debug);
   rijdAchteruit(snelheid, 100);     //rijd achteruit
   delay(debug);  
   roteerLinksom(snelheid, 1100);   //roteer linksom 90 graden
   delay(debug);
   while(!(detecteerKaderlijn)){
    rijdVooruit(snelheid, 10);      //rijd tot aan kaderlijn
   }
   delay(debug);
   roteerRechtsom(snelheid, 1100);  //roteer 90 graden rechtsom
   delay(debug);
   rijdVooruit(snelheid, 100);      //rijd vooruit
   //klaar
}

void toonLetter(int c, int y){

  // Met de x-waarde kan het gewenste cijfer gekozen worden.
  // Middels de y-waarde word aangegeven hoelang het character zichbaar moet zijn.
  for(int x =0; x < y; x++){

    //Letter L op het eerste 11-segmenten-display
    
    //pinMode(9, OUTPUT);
    digitalWrite(3, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    delay(1);
    digitalWrite(3, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    //pinMode(9, INPUT);


  
    //Schakel naar de juiste letter
    switch (c){

      case 1:
      //Cijfer 1 op het tweede 11-segmenten-display
        pinMode(12, OUTPUT);
        digitalWrite(9, HIGH);
        digitalWrite(12, HIGH);
        delay(1);
        digitalWrite(9, LOW);
        digitalWrite(12, LOW);
        pinMode(12, INPUT);
       break;

      case 2:
      //Cijfer 2 op het tweede 11-segmenten-display
        pinMode(12, OUTPUT);
        digitalWrite(2, HIGH);
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(11, HIGH);
        delay(1);
        digitalWrite(2, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        pinMode(12, INPUT);
       break;

      case 3:
      //Cijfer 3 op het tweede 11-segmenten-display
        pinMode(12, OUTPUT);
        digitalWrite(2, HIGH);
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        digitalWrite(11, HIGH);
        digitalWrite(12, HIGH);
        delay(1);
        digitalWrite(2, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        pinMode(12, INPUT);
       break;

      case 4:
      //Cijfer 4 op het tweede 11-segmenten-display
        pinMode(12, OUTPUT);
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(9, HIGH);
        digitalWrite(12, HIGH);
        delay(1);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(9, LOW);
        digitalWrite(12, LOW);
        pinMode(12, INPUT);
       break;

      case 5:
      //Cijfer 5 op het tweede 11-segmenten-display
        pinMode(12, OUTPUT);
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(8, HIGH);
        digitalWrite(11, HIGH);
        digitalWrite(12, HIGH);
        delay(1);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(8, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        pinMode(12, INPUT);
       break;

      case 6:
      //Cijfer 10 op het tweede 11-segmenten-display
        pinMode(12, OUTPUT);
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(8, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(11, HIGH);
        digitalWrite(12, HIGH);
        delay(1);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(8, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        pinMode(12, INPUT);
       break;

       default:
        pinMode(12, OUTPUT);
        digitalWrite(2, HIGH);
        delay(1);
        digitalWrite(2, LOW);
        pinMode(12, INPUT);

      
      }// </switch>
      
    }// </for>
 
}// </toonLetter>



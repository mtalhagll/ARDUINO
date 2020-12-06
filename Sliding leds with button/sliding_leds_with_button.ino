/*
   MUSTAFA TALHA GÜLLÜ

   Açıklama : Sağdan sola kayan ledler ile kolayca yapılabilen karaşimşek projesinin üstüne
   sadece iki buton ekleyerek basitçe bir butona basınca ledin sağa diğer bir butona basınca
   ledin sola kaymasını sağlayan bir devre ve kodu.
   
*/
 

#define shift_right_button 12             
#define shift_left_button 13               


int indis = -1;                       
int status_right ;          
int status_left ;           

int ledler[] = {2,3,4,5,6,7,8,9,10,11};

void setup()
{
  
  
  Serial.begin(9600);                
  
  pinMode(shift_right_button, INPUT);    
  pinMode(shift_left_button, INPUT);     

  
  int i;
  for(i=0; i<10; i++)
  {
    pinMode(ledler[i], OUTPUT);
  }
 

}

void loop() 
{
  
  status_right = digitalRead(shift_right_button);   
  status_left = digitalRead(shift_left_button);     
  
  if(status_right == 1 && indis < 9)           
                                                         
  {
    indis = indis+1;         
    Serial.println(indis);    
    digitalWrite(ledler[indis],HIGH);
    digitalWrite(ledler[indis-1],LOW);
    
   

      while(status_right == 1)                             
      {                                                             
       delay(10);                                                   
       status_right = digitalRead(shift_right_button);         
      }
  }

  
  if (status_left == 1 && indis > 0)          
  {
    indis = indis-1;                                   
    Serial.println(indis);                             
    digitalWrite(ledler[indis],HIGH);
    digitalWrite(ledler[indis+1],LOW);

       while(status_left == 1)                             
      {                                                            
      delay(10);                                                   
       status_left = digitalRead(shift_left_button);          
      }
  }
  
}

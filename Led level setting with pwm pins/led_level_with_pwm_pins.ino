/*
   Mustafa Talha Güllü
   
   Açıklama : PWM pinlerini kullanarak sanki bir potansiyometre ile ledin parlaklığını ayarlıyormuş gibi 
   ledi istediğimiz parlaklık şiddetinde yakabileceğiz. 

*/

#define led 3                //ledi hangi pine bağladığımızı tanımlıyoruz

void setup() {
  pinMode(led, OUTPUT);      //ledin kontrolü için tanımladığımız pini, output olarak tanımlıyoruz
  Serial.begin(9600);        //serial ekranı pwm değerlerini görmek adına başlatıyoruz
}

void loop() 
{

    for(int pwm_level=0; pwm_level<255; pwm_level++)   //for döngüsü ile 0-255 arası değer alan PWM pinini 0 dan başlatıp 255 değerine kadar birer birer arttırıyoruz
    {
 
    analogWrite(led,pwm_level);                        //ledin parlaklık seviyesi i sayısının değerine bağlı olarak artacağından i değeri ile parlaklık kontrolü yapıyoruz
    delay(10);                                         //bu değişimi gözle görebilmek için 10 milisaniyelik bir delay ekliyoruz, bu kişisel olarak ayarlanabilir
    Serial.print("PWM LEVEL : ");
    Serial.println(pwm_level);                         //serial ekranda PWM değerinin hangi değerde olduğunu takip edebiliriz
    }
    
    for(int pwm_level=255; pwm_level>0; pwm_level--)   //for döngüsü ile 0-255 arası değer alan PWM pinini 255 den başlatıp 0 değerine kadar birer birer azaltıyoruz
    {
  
    analogWrite(led,pwm_level);                        //ledin parlaklık seviyesi i sayısının değerine bağlı olarak azalacağından i değeri ile parlaklık kontrolü yapıyoruz
    delay(10);                                         //bu değişimi gözle görebilmek için 10 milisaniyelik bir delay ekliyoruz, bu kişisel olarak ayarlanabilir
    Serial.print("PWM LEVEL : ");
    Serial.println(pwm_level);                         //serial ekranda PWM değerinin hangi değerde olduğunu takip edebiliriz
    }
   
   
   /*  
       //İstenen parlaklıkta sabit kalmasını için
        
      analogWrite(led, 50);           // buradaki 50 ve 255 değerleri yerine 0-255 arası pwm değeri verilerek fark açık bir şekilde gözlenebilir.
      delay(500);
      analogWrite(led, 255);
      delay(500);
   
   */
   
 
}

/*
   MUSTAFA TALHA GÜLLÜ
   
   Açıklama : Sağdan sola kayan ledler ile kolayca yapılabilen karaşimşek projesinin üstüne sadece iki buton ekleyerek
   basitçe bir butona basıldığında ledin sağa, diğer bir butona basıldığında ise ledin sola kaymasını sağlayan bir devre ve kodu.
   
*/
 

#define shift_right_button 12    //kaydırma için kullanacağımız butonu tanımlıyoruz         
#define shift_left_button 13     //kaydırma için kullanacağımız ikinci butonu tanımlıyoruz          

int indis = -1;                  //led dizininde hangi ledin yanması gerektiğini belirlemek için indis isimli değişkeni tanımlıyoruz
                                 //indisler 0'dan saymaya başladığı için ilk değer olarak -1 veriyoruz ki ilk indisin bağlı olduğu ledi yakmadan geçmeyelim :)   

int status_right ;               //sağ butonun durumunu(0 veya 1, yani basılıp basılmadığı) tutan değişken            
int status_left ;                //sol butonun durumunu(0 veya 1, yani basılıp basılmadığı) tutan değişken  

int ledler[] = {2,3,4,5,6,7,8,9,10,11};      //dizi şeklinde ledlerin bağlı olduğu pinleri tanımlıyoruz

void setup()
{
  
  
  Serial.begin(9600);                    //serial ekranı başlatıyoruz    
  
  pinMode(shift_right_button, INPUT);    //bağladığımız butonları ınput olarak tanımlıyoruz
  pinMode(shift_left_button, INPUT);     //bağladığımız butonları ınput olarak tanımlıyoruz

  
  
  for(int i=0; i<10; i++)                //ledleri tek tek çıkış olarak tanımlamak yerine for döngüsü ile daha hızlı ve kolay şekilde yapıyoruz 
  {
    pinMode(ledler[i], OUTPUT);
  }
 

}

void loop() 
{
  
  status_right = digitalRead(shift_right_button);    //butonlara digitalRead komutu ile basılıp basılmadığını okuyoruz ve durum değişkenine atıyoruz
  status_left = digitalRead(shift_left_button);      //butonlara digitalRead komutu ile basılıp basılmadığını okuyoruz ve durum değişkenine atıyoruz
  
  if(status_right == 1 && indis < 9)                 //sağa kaydırma butonuna basıldığı ve indisimiz dokuzuncu indisden küçük
                                                     //ise şartı ile sağa kaydırması ile ilgili şartı yazıyoruz                                                    
  {
    indis = indis+1;                                 //indisi yukarıda -1 olarak tanımlamıştık ve bir arttırarak ilk başlanğıçta sıfırıncı indisi yakıyoruz
    Serial.println(indis);                           //hangi indisdeki ledin yandığını görmek için serial ekrana yazdırıyoruz 
    digitalWrite(ledler[indis],HIGH);                //indis durumuna göre hangi indisdeki ledin yanması ile ilgili komutumuz 
    digitalWrite(ledler[indis-1],LOW);               //burada sonraki indisler için sağa kayarken bir önceki indisi söndürmesi ile ilgili komutumuz
    
   

      while(status_right == 1)                        //butona sürekli basılması veya basılı kalması durumunda sürekli basıldı komutu gitmesini    
      {                                               //önlemek için while yapısı ile kontrol altına alıyoruz            
       delay(10);                                                   
       status_right = digitalRead(shift_right_button);         
      }
  }

  
  if (status_left == 1 && indis > 0)                  //sola kaydırma butonuna basıldığı ve indisimiz sıfırıncı indisden büyük
  {                                                   //ise şartı ile sola kaydırması ile ilgili şartı yazıyoruz     
     
    indis = indis-1;                                  //ledler en sağa geldiğinde artık sola kayması için indisi azaltmamız gerekiyor  
    Serial.println(indis);                            //hangi indisdeki ledin yandığını görmek için serial ekrana yazdırıyoruz
    digitalWrite(ledler[indis],HIGH);                 //indis durumuna göre hangi indisdeki ledin yanması ile ilgili komutumuz
    digitalWrite(ledler[indis+1],LOW);                //indisi azalttığımız için bu sefer bir önceki indisde (yani bir üst indis) yanan ledi söndürüyoruz.

       while(status_left == 1)                        //butona sürekli basılması veya basılı kalması durumunda sürekli basıldı komutu gitmesini    
      {                                               //önlemek için while yapısı ile kontrol altına alıyoruz              
      delay(10);                                                   
       status_left = digitalRead(shift_left_button);          
      }
  }
  
}

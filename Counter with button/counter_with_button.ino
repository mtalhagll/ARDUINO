/*

  Mustafa Talha Güllü

  Açıklama : Sistem sıfırdan başlayan bir sayacın bir butona basılması ile sayı değerini artırırken, diğer bir buton ile sayı değerini azaltmaktadır.
  Sınıra geldiği zaman kırmızı led yanıcaktır.
  Sistemde iki adet sıfırlama (resetleme) mantığı bulunmaktadır. Biri manuel olarak butona basılması durumunda gerçekleşirken diğeri software reset (yazılımsal reset)
  olarak gerçekleşmektedir.

  Manuel reset; Arduino üzerindeki reset pini GND hattına arada bir buton olacak şekilde bağlanmıştır.
  Butona basıldığında reset pini GND üzerinden LOW konumuna düşerek Arduinoya reset atmakta ve sayac baştan başlamaktadır.

  Sofware reset; Arduino üzerinde bulunan yazılımsal reset özelliği kullanılarak,
  sınır değerine geldiğinde otomatik resetleme fonksiyonu isteğe bağlı olarak kullanılabilir.

*/

#define arttirmabutonu 6             //basıldığı zaman sayacı arttıracak olan butonu tanımlıyoruz
#define azaltmabutonu 7              //basıldığı zaman sayacı azaltacak olan butonu tanımlıyoruz
#define led 8                        //sınır değerine gelince yanacak ledi tanımlıyoruz

int sayac = 0;                       //0'dan başlayarak sürekli değişken barındıracak olan sayac değişkenini tanımlıyoruz
int arttirma_buton_durumu ;          //arttırma butonunun 1 veya 0 olduğu durumu tutacak olan değişkeni tanımlıyoruz
int azaltma_buton_durumu ;           //azaltma butonunun 1 veya 0 olduğu durumu tutacak olan değişkeni tanımlıyoruz

void (* ResetFunc) (void) = 0;       //sayacı sıfırlamak için software reset fonksiyonunu tanımlıyoruz bunu isteğe göre çağırabileceğiz

void setup()
{
  Serial.begin(9600);                //Serial ekranı sayac değerini ve mesajları görebilmek adına başlatıyoruz

  pinMode(arttirmabutonu, INPUT);    //arttırma butonunundaki değeri okumak istediğimiz için ınput olarak tanımlıyoruz
  pinMode(azaltmabutonu, INPUT);     //azaltma butonunundaki değeri okumak istediğimiz için ınput olarak tanımlıyoruz
  pinMode(led, OUTPUT);              //ledi yakmak için output olarak tanımlıyoruz

  Serial.print("Sayac Basliyor ");   //
  delay(300);                        //
  Serial.print(".");                 //
  delay(300);                        //
  Serial.print(".");                 //   Sayacın başlangıç mesajını ekrana yazdırıyoruz ve başlangıç değerini görüyoruz
  delay(300);                        //
  Serial.println(".");               //
  delay(300);                        //
  Serial.println(sayac);             //

}

void loop()
{

  arttirma_buton_durumu = digitalRead(arttirmabutonu);   //arttırma butonuna basılıp basılmadığını kontrol etmek için bu pini digitalRead komutu ile okuyoruz ve değişkene atıyoruz
  azaltma_buton_durumu = digitalRead(azaltmabutonu);     //azaltma butonuna basılıp basılmadığını kontrol etmek için bu pini digitalRead komutu ile okuyoruz ve değişkene atıyoruz

  if (arttirma_buton_durumu == 1 && sayac < 10)          //if fonksiyonu ile arttırma butonu 1 olduğunda ve
                                                         //sayaç üst sınıra ulaşmadığında şartı sağlanıyorsa sayacın +1 olmasını tanımlıyoruz
  {
    sayac = sayac + 1;             //yukarıdaki şartın sağlanması halinde sayac değeri +1 artıyor
    Serial.println(sayac);         //sayacın yeni değeri ekrana yazdırılıyor
    digitalWrite(led, LOW);        //Ledin burda yanmasını istemiyoruz

    if (arttirma_buton_durumu == 1 && sayac > 9)                                //if fonksiyonu ile arttırma butonu 1 olduğunda ve sayaç üst sınıra ulaştığında şartı sağlanıyorsa
                                                                                //sayac artık arttırılmıyor ve sınıra gelindiği mesajı ekranda beliriyor
    {
      Serial.println("Ust sinira ulastiniz, daha fazla arttiramazsiniz !");     //ekranda görünecek sınır mesajını oluşturduk
      digitalWrite(led, HIGH);                                                  //sınıra ulaştığımızda kırmızı uyarı ledi yanıcak

      /*
        bu kısım yorum satırı olarak bırakılmış olup isteğe bağlı koda dahil edilmesi halinde
        sayac sınır değerine ulaştığında 26. satırdaki fonksiyon çağırılarak kendini otomatik olarak sıfırlayacaktır.
        delay(2000);
        ResetFunc();
      */

    }

    while (arttirma_buton_durumu == 1)                            //
    {                                                             // while fonksiyonu ile buton durumunun durumunu kontrol ediyoruz ve sürekli 1 olması durumunda
      delay(10);                                                  // sayacın sürekli +1 döngüsüne girmesinin önüne geçmiş oluyoruz
      arttirma_buton_durumu = digitalRead(arttirmabutonu);        // yani diğer bi değişle sayac her bir basış ve çekişte artıcak
    }
  }


  if (azaltma_buton_durumu == 1 && sayac > 0)                     //if fonksiyonu ile azaltma butonu durumu 1 ve sayac değeri alt sınır olan 0'dan büyükse azaltmaya devam edicek
  {
    sayac = sayac - 1;                                            //yukarıdaki şartın sağlanması halinde sayac değerini -1 azaltıcak
    Serial.println(sayac);                                        //sayacın yeni değeri ekrana yazdırılıyor
    digitalWrite(led, LOW);                                       //Ledin burda yanmasını istemiyoruz

    while (azaltma_buton_durumu == 1)                             //
    {                                                             // while fonksiyonu ile buton durumunun durumunu kontrol ediyoruz ve sürekli 1 olması durumunda
      delay(10);                                                  // sayacın sürekli -1 döngüsüne girmesinin önüne geçmiş oluyoruz
      azaltma_buton_durumu = digitalRead(azaltmabutonu);          // yani diğer bi değişle sayac her bir basış ve çekişte azalıcak
    }
  }

}

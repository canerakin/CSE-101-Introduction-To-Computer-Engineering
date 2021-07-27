//Caner AKIN
//151044066
#include <stdio.h>

int arkadasSayi(int sayi , int toplam , int istenilen_sayi )
{
	int  i , l  , k , z , m , t;
	toplam = 0;
	for ( i = 1; i < sayi; ++i) //burada kullanıcıdan alınan sayının bölenlerini toplamak için for döngüsü kullanılmıştır.
  	{
  			
  		l = sayi % i; //sayıyı sırayla kendine kadar her sayıyla modunu aldım.
  		if ( l == 0 ) //sayıyla modu 0 çıkan sayılar buraya girer.
  		{
  			toplam = toplam + i ; //buraya giren sayı kullanıcıdan alınan sayının bölenidir ve toplam değişkeninin içinde toplanır.
  		}
  		l = 0;
  	}
  	k = 0;
  	istenilen_sayi = 1;
  	while (toplam > istenilen_sayi ) //bir döngü olması için while kullandım.
  	{	
  		for ( z = 1; z < istenilen_sayi; ++z) //burada arkadaş sayıyı bulmak için her seferinde 1 arttırarak her sayı denenir.
  		{
  			m = istenilen_sayi % z ; //arkadaş sayıyı sırayla kendine kadar her sayıyla modunu aldım.
  			if (m == 0) //arkadaş sayıyla modu 0 çıkan sayılar buraya girer.
  			{
  				k = k + z ; //burada döngüde arkadaş sayıya geldiği zaman bölenlerinin toplanması için k ya toplanır.
  			}
  		} 
  		istenilen_sayi = istenilen_sayi + 1; //her seferinde sayacı 1 arttırarak arkadaş sayımı diye denedim
 	}
 	t = 0;
 	for ( i = 1; i < istenilen_sayi; ++i)//burada arkadaş  sayının bölenlerini toplamak için for döngüsü kullanılmıştır.
  	{
  			
  		l = istenilen_sayi % i;//arkadaş sayıyı sırayla kendine kadar her sayıyla modunu aldım.
  		if ( l == 0 )//arkadaş sayıyla modu 0 çıkan sayılar buraya girer.
  		{
  			t = t + i ; //buraya giren sayı arkadaş  sayının bölenidir ve t değişkeninin içinde toplanır.
  		}
  		l = 0;
  	}
    if (sayi != t ) //eğer kullanıcıdan alınan sayının arkadaş sayısı yoksa sistem -1 return eder ve çıkar.
  {
    toplam = -1;
    return toplam ;
	}
  return toplam; // kullanıcıdan alının sayının arkadaş sayısı varsa toplamı return ler.
}
int main(void)
{ 
  	int sayi ,  toplam , istenilen_sayi  ;
  	printf("Arkadasini bulmak istediginiz sayiyi giriniz:");//burada scanf ile kullanıcıdan bir sayı aldım
  	scanf("%d" , &sayi);
    toplam = arkadasSayi(sayi , toplam , istenilen_sayi ); //toplamı fonksiyona eşitlememin nedeni fonksiyondan istenilen dönerse 1 diğer durumda -1 değerini alması.
    if (toplam != -1) // eğer toplam -1 e eşit değilse sayinin arkadaş sayısı vardır ve ekrana yazar.
    {
       printf("\n%d 'nin arkadas sayisi : %d", sayi , toplam  );
    }
    
    else //toplam -1 ise sayının arkadaş sayısı yoktur ve ekrana yazar.
    {

      printf("\n%d 'nin arkadas sayisi bulunmamaktadır.", sayi  );
    }



return 0;
}
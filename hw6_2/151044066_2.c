//Caner AKIN
//151044066
#include <stdio.h>

int main()
{
	int secim = 4 ;
	int yukseklik , ikinci_piramit , ilk_piramit ;
	int i , j , k , z , l , m , n , x ;
	while(secim != 0) //0 değeri girildiğinde çıkış yapsın diye koşul böyle kullanıldı.
	{
		printf("--MENU--\n1.Yıldızlardan elmas çiz\n2.Ogrenci belgesini göster\n0.Cikis\n"); /*her seferinde ekrana yazılacak olan menü*/
		printf("Seceneginiz:" );
		scanf ("%d" , &secim);
		if (secim == 1) //menüde 1'i seçtiğiniz zaman sizi buradaki elmas fonksiyonuna atar. 
		{
			printf("\nyukseklik giriniz"); //elmasın yüksekliğini aldım.
			scanf ("%d" , &yukseklik );
			ikinci_piramit = yukseklik / 2 ; /*burada kullandığım mantık elması 2 piramit olarak almak ve alttaki piramitin yüksekliği üsttekine göre 1 azdır.*/
			ilk_piramit = yukseklik - ikinci_piramit ; //yükseklikten küçük piramitin yüksekliği çıkarıldığında büyük pramitin yüksekliği kalır.
			for (i = 1; i <= ilk_piramit ; ++i)
			{
				for (j = 1; j <= ilk_piramit - i ; ++j) /*üst piramitin en üst kısmından aşağıya doğru her seferinde boşluk sayısı azalır*/
				{
					printf(" ");
				}
				
				for (k = 1; k <= 2 * z + 1 ; ++k)//üst piramitte en tepeden en alta doğru giderken yıldız sayısı 2 şer olarak artar.
				{
					printf("*");

				}
				z = i ;
				printf("\n");
			}
			z = 0 ;
			x = ikinci_piramit ;
			for ( l = 1; l <= ikinci_piramit ; ++l)
			{
				for (m = 1 ; m <  l + 1  ; ++m)/*üst piramitin en üst kısmından aşağıya doğru her seferinde boşluk sayısı artar*/
				{
					printf(" ");
				}
				
				for (n = 1; n <= 2 * x -1 ; ++n )//alt piramitte en üstten en alta doğru giderken yıldız sayısı 2 şer olarak azalır.
				{
					printf("*");
				}
				x = x - 1 ;
				printf("\n");
			}
			x = 0;
		}
		
		else if (secim == 2) /*kullanıcıdan 2 değeri girildiği zaman ilk fonksiyona girmez ve buraya girer.ekrana bilgileri yansıttıktan sonra tekrar menüye döner*/
		{
			printf("\nAd:Caner\n" );
			printf("Soyad:AKIN\n" );
			printf("Ogrenci No:151044066\n\n" );

		}

		else //secim 1 veya 2 olmadığı zamanlarda buraya girecektir.
		{
			if (secim != 0) /* menüde bulunan 1 , 2 ve 0 değeri dışında bir değer girdiğinde yanlış girdiniz der ve menüye geri döner.*/
			{
				printf("Yanlış girdiniz\n\n");			
			}
			
		}


	}


	return 0;
}
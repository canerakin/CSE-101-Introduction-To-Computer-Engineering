#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define cikolatasayisi 6
void deger_atama(int cikolata[cikolatasayisi]); /*rastkele değer atama fonksiyonu tanımladım*/
void ekrana_yazma(int cikolata[cikolatasayisi]); /*atanan değerleri ekrana yazmak için kullanılan fonksiyonu tanımladım*/
void islem(int cikolata[cikolatasayisi]);/*kazananı bulmak için kullanılan fonksiyonu tanımladım*/
void test();/*test kodunu tanımladım*/
int main()
{
    int cikolata[cikolatasayisi] ; /*ilk olarak elimdeki  arrayi için */
    deger_atama(cikolata);/*rastkele değer atama için fonksiyona gönderdim*/
    ekrana_yazma(cikolata);/*ekrana yazmak için fonksiyona gönderdim*/
    islem(cikolata);/*kazananı belirleyen fonksiyona gönderdim.*/
    test();
}
void deger_atama(int cikolata[cikolatasayisi])/*rastkele değer atama fonksiyonu*/
{
    int r ,i ;
    srand(time(NULL));  /*rastgele değerler atamak için kullandım*/
    for (i = 0; i < cikolatasayisi; ++i)
    {
        r = rand() % 11 ; /*sayılar 0 ile 10 arasında olması istendiği için 10'a göre modunu aldım*/
        cikolata[i] = r ;
        cikolata[i] = cikolata[i] + 1;/*bir sonraki değere geçmek için kullandım*/
    }  
}
void ekrana_yazma(int cikolata[cikolatasayisi])/*atanan değerleri ekrana yazmak için kullanılan fonksiyon*/
{
    int i ;
    for (i = 0; i < cikolatasayisi; ++i)
    {
        printf(" %d", cikolata[i]);  /*ekrana sırasıyla çikolata boylarını yazmak için kullandım*/
    }
}
void islem(int cikolata[cikolatasayisi])/*kazananı bulmak için kullanılan fonksiyon*/
{
    int i = 0 ,k = cikolatasayisi - 1 ,mehmet = 0,ayse = 0;
    while(i<=k)/*sistemin bir yerde durması için kullandım*/
    {
        if (cikolata[i] > 2 )/*mehmetin ısırığında çikolata bitmeyecekse buraya girer.*/
        {
            cikolata[i] = cikolata[i] - 2; /*mehmetin ısırığını uyguladım*/          
        }
        else if (cikolata[i] == 2)/*mehmetin ısırığı ile biten çikolata için tanımladım*/
        {
            cikolata[i] = cikolata[i] - 2; /*mehmet ısırığını alır.*/
            if ( i + 2 == k ) /*bu anda ortadaki çikolata için yaptım bu işlemleri*/
            {
            mehmet = mehmet + 2;
            ayse = ayse + 1;
            break;/*ortadaki çikolatadan sonra sistemi durdurdum*/
            }
            i = i + 1;
            mehmet = mehmet + 1;
        }
        else if (cikolata[i] == 1) /*birim zamanda mehmetin iki çikolatadanda ısırık alma durumu alma için kullandım*/
        {
            cikolata[i] = cikolata[i] - 1;
            if (i + 2 == k && cikolata[k] > 0) /*bu anda ortadaki çikolata için yaptım bu işlemleri*/
            {
            mehmet = mehmet + 2;
            ayse = ayse + 1;
            break;/*ortadaki çikolatadan sonra sistemi durdurdum*/
            }
            if (cikolata[i + 1] == 1)/*bir sonraki çikolatanın yarım ısırıkta*/
            {
            	cikolata[i+1] = cikolata[i+1] - 1;
            	i = i + 2;
            	mehmet = mehmet + 2;
            }
            else if (cikolata[i + 1] > 1) /*aynı anda ısırılacak iki farklı çikolatanın 1 den uzun olması durumunu açıkladım.*/
            {
            	cikolata[i+1] = cikolata[i+1] - 1;
            	i = i + 1;
            	mehmet = mehmet + 1;
            }            
        }   
        if (i + 1 == k)/*birbirinin çikolatasına geçmemesi için kullandım*/
        {
            mehmet = mehmet + 1;
            ayse = ayse + 1;
            break;
        }
        if (cikolata[k] == 1) /*ayşenin çikolatanın son ısırığını alması alma durumu için kullandım*/
        {
            cikolata[k] = cikolata[k] - 1;
            k = k - 1;
            ayse = ayse + 1;
        }
        else if (cikolata[k] > 1 ) /*ayşenin ısırdığı çikolatanın bitmemesi durumlar için kullandım. */
        {
            cikolata[k] = cikolata[k] - 1;
        }
    }
    printf("\nmehmet=%d\n",mehmet );/*mehmetin kaç çikolata yediğini yazdım*/
    printf("ayse=%d\n",ayse );/*ayşenin kaç çikolata yediğini yazdım*/
    if (mehmet < ayse)/*aysenin daha fazla çikolata yeediği durumlarda girer*/
    {
    	printf("kazanan=ayse\n\n");
    }
    else if (mehmet > ayse)/*mehmetin daha fazla yediği zamanlarda kullanılır*/
    {
    	printf("kazanan=mehmet\n\n");
    }
    else if (mehmet == ayse)/*eşit çikolata yediği durumlarda girer.*/
    {
    	printf("kazanan=ikiside eşit yemiştir.\n\n");
    }
}
void test()/*test kodu*/
{
	int dizi1[6] = {3,2,8,6,7,1};
	int dizi2[6] = {10,1,1,1,1,1};
	int dizi3[6] = {6,8,10,4,3,5};
	int dizi4[6] = {8,4,6,1,4,5};
	printf("\n\nörnek ekran çıktıları:\n\n");
    ekrana_yazma(dizi1);/*dizi1 i ekrana yazar*/
    islem(dizi1);/*kazananı ekrana yazar */
    ekrana_yazma(dizi2);/*dizi2 yiekrana yazar*/
    islem(dizi2);/*kazananı ekrana yazar*/
    ekrana_yazma(dizi3);/*dizi3 ü ekrana yazar*/
    islem(dizi3);/*kazananı ekrana yazar*/
    ekrana_yazma(dizi4);/*dizi4 ü ekrana yazar*/
    islem(dizi4);/*kazananı ekrana yazar*/
}
/*Caner AKIN*/
/*151044066*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	int r1_array[20] ,r2_array[20] ,r3_array[20] ,norm1 = 0,norm2 = 0,r ,i; /*ilk olarak elimdeki 3 array ve sayaçları tanımladım*/
	int Dot_Prodact = 0,ara_toplam1 = 0,ara_toplam2 = 0;
	double Cosine_Similarity = 0 ,bolum = 0;/*köklü ve bölümlü ifadeleri double olarak tanımladım*/
	printf("Vektörler:\n");
	srand(time(NULL));	/*rastgele değerler atamak için kullandım*/
	for (i = 0; i <= 19; ++i)
	{
	  	r = rand() % 10; /*sayılar 0 ile 10 arasında olması istendiği için 10'a göre modunu aldım*/
	  	r1_array[i] = r;
    }
    for (i = 0; i <=19; ++i)
    {
    	if (r1_array[i] != 0) /*0 dışındaki tüm sayılar için geçerli bir şekilde fonksiyona girer.*/
    	{
    		norm1 = norm1 + 1; /*sayı sıfıra eşit olmadığında bu fonksiyona girer ve sayaç 1 artar.bu sayede norm1 bulunur.*/
    	}
    }
    for (i = 0; i <= 19; ++i)
	{
	  	r = rand() % 10;/*sayılar 0 ile 10 arasında olması istendiği için 10'a göre modunu aldım*/
	  	r2_array[i] = r;
    }
    for (i = 0; i <= 19; ++i)
    {
    	if (r2_array[i] != 0)
    	{
    		norm2 = norm2 + 1; /*aynı şekilde burdada norm2'yi bulmak için sayaç kullandım. */
    	}
    }
    printf("v1:"); /*v1 arrayinin değerlerini ekrana yazarken böyle bir başlangıç yaptım*/
    for (i = 0; i <= 19; ++i)
    {
    	printf("%d",r1_array[i]);/*r1 içinher array elemanını sırayla yazması için kullandım*/
    	if (i < 19)
    	{
    		printf(",");/*r1 için ilk elemandan sonra ve son elemandan önce her eleman arasında virgül kullanmak için bu şekilde kullandım*/
    	}
    }
    printf("\nv2:");/*v2 arrayinin değerlerini ekrana yazarken böyle bir başlangıç yaptım*/
    for (i = 0; i <= 19; ++i)
    {
    	printf("%d",r2_array[i] );/*r2 için her array elemanını sırayla yazması için kullandım*/
    	if (i < 19)
    	{
    		printf(",");/*r2 için ilk elemandan sonra ve son elemandan önce her eleman arasında virgül kullanmak için bu şekilde kullandım*/
    	}
    }
    printf("\n\n");
    printf("v1 L0 norm:%d\n",norm1 );  
    printf("v2 L0 norm:%d\n\n",norm2);
    for (i = 0; i <= 19; ++i)
    {
    	r3_array[i] = r1_array[i] + r2_array[i] ; /*sırasıyla r1'in ilk elemanı ile r2'nin ilk elemanı toplanır diğer arrayin ilk elemanı olarak atanır.bu böyle devam eder.*/
    	r3_array[i] = r3_array[i] % 10 ; /*yeni arrayinde tüm elemanları 0 ile 10 arasında olması için mod10 aldım.*/
    }
    printf("v1 + v2 =");
    for (i = 0; i <= 19; ++i)
    {
    	printf("%d",r3_array[i]);/*r3 için her array elemanını sırayla yazması için kullandım*/
    	if (i < 19)
    	{
    		printf(",");/*r3 için ilk elemandan sonra ve son elemandan önce her eleman arasında virgül kullanmak için bu şekilde kullandım*/
    	}
    }
    printf("\n\n");
    for (int i = 0; i <= 19; ++i)
    {
    	Dot_Prodact = r1_array[i] * r2_array[i] + Dot_Prodact ;	/*istenilen değerin üst kısmındaki vektörel çarpımı bulmak için arraylerin elemanlarını sırayla çarptım*/
    }
    for (int i = 0; i <= 19; ++i)
    {
    	ara_toplam1 = ara_toplam1 + pow(r1_array[i],2);/*r1 arrayinin her elemanın karelerinin toplanmasını sağladım.*/
    	ara_toplam2 = ara_toplam2 + pow(r2_array[i],2);/*r2 arrayinin her elemanın karelerinin toplanmasını sağladım.*/
    }
    bolum = sqrt(ara_toplam1) * sqrt(ara_toplam2) ;/*r1 ve r2 arraylerinin toplanmış elemanlarının kareköklerini alıp birbiriyle çarptım ve kesirin alt kısmını buldum.*/
    Cosine_Similarity = Dot_Prodact / bolum;/*kesirin alt kısmını üst kısma bölerek istenilen değeri buldum.*/

    printf("sim(v1,v2):%.6lf",Cosine_Similarity);
    printf("\n");

	return 0;
}
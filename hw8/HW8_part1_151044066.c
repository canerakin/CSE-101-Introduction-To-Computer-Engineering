/* Caner AKIN */
/* 151044066 */
#include <stdio.h>

int factorial (int n);
double power (double x , int n);
double sin (double x);

int main(void)
{ 
	int x;
  double son;

  printf("bulmak istediginiz sin(x) giriniz:");/*burada scanf ile kullanıcıdan bir açı aldım.*/
	scanf("%d" , &x);
  x = x % 360; /*kullanıcının girmiş olduğu açının modunu alarak sayıyı 0 ile 360 arasında olmasını sağladım.*/
  if (x >= 180)
  {
    x = (x % 180) * -1;/*daha sonra 180 e görede modunu alarak dereceyi doğruladım.*/
  }

  son = sin(x) ; /*sin(x) fonksiyonunu bir değere atıyarak ekrana yazdım.*/
  printf("sin: %.3f\n", son) ;

  return 0 ;
}


int factorial(int n) /*ilk fonksiyon olan faktöriyel alma fonsiyonu*/
{
  int i, factoriyal = 1;

  for ( i = 1; i <= n; ++i) 
    factoriyal = factoriyal * i; /*her döngüde sayıya sıradaki sayıyla çarpılıp atanır*/

  return factoriyal ;
}

double power(double x ,int n)/*ikinci fonksiyon olan pow fonksiyonu*/
{
  int i;
  double uslu = 1;

  for ( i = 1; i <= n ; ++i )/*sayı her seferinde kendiyle bidaha usluyla çarpılarak usluya atanır.*/

    uslu = uslu * x;

  return uslu;
}

double sin(double x)/*son fonsiyon olan sin fonksiyonu*/
{

  int i, n;
  double sonuc, y, artilar = 0, eksiler = 0, ust;

  printf("n değerini giriniz:");//burada scanf ile kullanıcıdan bir hassasiyet aldım.
  scanf("%d" , &n);
  y = x * 3.14 / 180 ; /*burada kullanıcıdan alınmış olan dereceyi bu işlemlerle radyana çevirdim*/

  i = 1;
  while (i <= n)  /*ilk olarak formül içindeki + işaretlileri bir döngüde topladım*/
  { 
    artilar = ((factorial(n) * power (y, i)) / factorial(i)) + artilar; /*her seferinde çağırılan fonksiyonlarla bulununan değerler artilarda toplanır*/
    i = i + 4 ;
  }
  
  i = 3;
  while (i <= n) /*ikinci döngü ise - işaretli olan değerleri toplamaktadır.*/
  {  
    eksiler = ((factorial(n) * power (y, i)) / factorial(i)) + eksiler;  /*her seferinde çağırılan fonksiyonlarla bulununan değerler eksilerde toplanır*/

    i = i + 4;
  }
  ust = artilar - eksiler; /*iki döngüden çıkan değerleri kullanarak fonksiyonun + ve - işaretlilerini bir yerde topladım*/
  sonuc = ust / factorial(n); 

  return sonuc;
}

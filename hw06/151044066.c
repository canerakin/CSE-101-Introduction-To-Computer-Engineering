// Caner AKIN
 /*151044066*/
#include <stdio.h>

int main()
{
	int anlik , hedef ; //Burada kullanıcıdan alınacak güncel ve hedef hızı tanımladım.

	printf("anlik hızı giriniz:\n" ); /*Burada ise kullanıcıdan anlık hızı istedim*/
	scanf("%d" , &anlik);
	printf("hedef hızı giriniz:\n" ); /*Burada ise kullanıcıdan hedef hızı istedim*/
	scanf("%d" , &hedef);

	if (anlik == hedef ) /*Burada güncel hızın hedef hıza eşit olduğu durumlar için ayırdım*/
	{
		printf("anlık hız hedefe eşittir\n"); // Ekrana eşit oldukları yazılsın diye kullandım.
	}

	else if (anlik > hedef ) /*Burada güncel hızın hedef hızdan büyük olduğu durumlar için ayırdım ve bu durumda büyüktür yazması gerekir*/
	{
		printf("anlık hız hedeften büyüktür\n"); // Ekrana anlık hızın hedeften  büyük olduğu yazılsın diye kullandım.
	}

	else // Burada ise anlık hızın hedef hızdan büyük ve eşit olmadığı durumlarda bu fonksiyona girsin  için  kullandım.
	{
		 while (anlik < hedef) /*Burada güncel hızın hedef hızdan küçük olduğu durumlar için ayırdım ve bu kısımda anlık hızı hedef hıza eşit olana kadar yüksetecek.*/
	
		{

			printf("anlık hız:%d\n", anlik ); // Ekrana anlık hızın ve hedef hıza eşit olana kadar ekrana yazılsın diye kullandım.
			anlik = anlik + 1;

		}
		if (anlik == hedef) /*Bu kısımı ise anlık hızın hedef hıza eşit olduktan sonra ekrana yazsın diye kullandım.*/
			{
				printf("hedefe ulaştınız:%d\n" , anlik); // Ekrana hedef hıza ulaşıldığı  yazılsın diye kullandım.
			}
	}	



	
	return 0;
}
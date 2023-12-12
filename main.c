#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Naz�m �imen
/*
-projede hem tokenizer hem parser bulunmaktadir.tokenizer ve parser kodlar�n�n nerden ba�lad���n� kodda belirttim.
-if, else ve else if yap�lar� ile olu�turulan basit kodlar, �nce tokenizer i�lemi ile kelimelerine ayr��t�r�l�r.
-daha sonra girilen kaynak kodun syntax kural�na g�re hatal� olup olmad��� tespit edilir.hatan�n sebebi a��klan�r ve syntax� bozan ifade tespit edilip ekranda g�sterilir.
-projeyi her kelime farkl� bir sat�rda olacak �ekilde 2 boyutlu dizi ile ger�ekle�tirdim. 
-parser b�l�m�nde noktali virg�l� de kontrol ettim.
-bir d�ng� kulland�m ve bu d�ng�de her sat�r i�in olmas� gereken kelimenin do�ru olup olmad���n� kontrol ettim.hatayi g�r�nce hatay� ve hatali kelimeyi yazdirdim.
-else if veya else geldi�inde d�ng�y� ilgili kelimeyi kontrol etmesi i�in gerekli yerden tekrar ba�latt�m.�rne�in else if gelirse �arttan.else gelirse c�mleden.
-main in �zerindeki t�m fonksiyonlar parse ye aittir.
-fonksiyonlar�n ve main i�indeki b�l�mlerin a��klamalar�n� a��klama sat�rlar�nda belirttim.
-proje klas�r�n�n i�erisinde do�ru ve yanl�� sytaxta ait 2 adet txt dosya olu�turdum.projeyi �al��t�r�p test edebilirsiniz.
*/
int ifkontrolu(char *kelime) //fonksiyona ilgili sat�r� g�nderdim.sat�rdaki kelime if ise return 1 de�ilse 0 de�erini d�nd�rd�m.
{
	int z;
	int bosluksayaci = 0;
	for (z = 2; z < 1000; z++)
	{
		if (kelime[z] == NULL)
		{
			bosluksayaci = bosluksayaci + 1;
		}
	}

	if (bosluksayaci == 998 && kelime[0] == 'i' && kelime[1] == 'f')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int acilanparantez(char *kelime) //fonksiyona ilgili sat�r� g�nderdim.sat�rdaki kelime '('  return 1 de�ilse 0 de�erini d�nd�rd�m.
{
	int bosluksayaci = 0;
	int karaktersay = 0;
	int z;
	if (kelime[0] == '(')
	{
		karaktersay = 1;
		for (z = 1; z < 1000; z++)
		{
			if (kelime[z] == NULL)
			{
				bosluksayaci = bosluksayaci + 1;
			}
			else
			{
				karaktersay += 1;
			}
		}
	}

	if (bosluksayaci == 1000 - karaktersay)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int id(char *kelime) //fonksiyona ilgili sat�r� g�nderdim.sat�rdaki kelime <id> ise return 1 de�ilse 0 de�erini d�nd�rd�m.
{
	int testharf = 0;
	int testsayi = 0;
	int z;
	int sayisay;
	int bosluksayaci = 0;
	if (kelime[0] == 'a' || kelime[0] == 'b' || kelime[0] == 'c' || kelime[0] == 'd' || kelime[0] == 'e' || kelime[0] == 'f')
	{
		testharf = 1;
		for (z = 0; z < 1000; z++)
		{
			if (kelime[z] == NULL)
			{
				bosluksayaci = bosluksayaci + 1;
			}
		}
		if (bosluksayaci == 1000 - testharf)
		{
			testharf = 1;
		}
		else
		{
			testharf = 2;
		}
	}
	else if (kelime[0] == '0' || kelime[0] == '1' || kelime[0] == '2' || kelime[0] == '3' || kelime[0] == '4' || kelime[0] == '5' || kelime[0] == '6' ||
			 kelime[0] == '7' || kelime[0] == '8' || kelime[0] == '9')
	{
		sayisay = 1;
		z = 1;
		while (z < 1000)
		{
			if (kelime[z] == '0' || kelime[z] == '1' || kelime[z] == '2' || kelime[z] == '3' || kelime[z] == '4' || kelime[z] == '5' || kelime[z] == '6' ||
				kelime[z] == '7' || kelime[z] == '8' || kelime[z] == '9')
			{
				sayisay = sayisay + 1;
			}
			if (kelime[z] == NULL)
			{
				bosluksayaci = bosluksayaci + 1;
			}
			z = z + 1;
		}
		if (bosluksayaci == 1000 - sayisay)
		{
			testsayi = 1;
		}
		else
		{
			testsayi = 2;
		}
	}
	if (testharf == 1 || testsayi == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int operand(char *kelime) //fonksiyona ilgili sat�r� g�nderdim.sat�rdaki kelime <op> ise return 1 de�ilse 0 de�erini d�nd�rd�m.
{
	int bosluksayaci = 0;
	int z;
	int karaktersay = 0;
	if (kelime[0] == '=' && kelime[1] == '=' || kelime[0] == '<' && kelime[1] == '=' || kelime[0] == '>' && kelime[1] == '=')
	{
		karaktersay = 2;
		for (z = 2; z < 1000; z++)
		{
			if (kelime[z] == NULL)
			{
				bosluksayaci = bosluksayaci + 1;
			}
			else
			{
				karaktersay = karaktersay + 1;
			}
		}
	}
	else if (kelime[0] == '<' || kelime[0] == '>' && kelime[1] != '=')
	{
		karaktersay = 1;
		for (z = 1; z < 1000; z++)
		{
			if (kelime[z] == NULL)
			{
				bosluksayaci = bosluksayaci + 1;
			}
			else
			{
				karaktersay = karaktersay + 1;
			}
		}
	}
	if (bosluksayaci == 1000 - karaktersay)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int kapananparantez(char *kelime) //fonksiyona ilgili sat�r� g�nderdim.sat�rdaki kelime ') ise return 1 de�ilse 0 de�erini d�nd�rd�m.
{
	int bosluksayaci = 0;
	int karaktersay = 0;
	int z;
	if (kelime[0] == ')')
	{
		karaktersay = 1;
		for (z = 1; z < 1000; z++)
		{
			if (kelime[z] == NULL)
			{
				bosluksayaci = bosluksayaci + 1;
			}
			else
			{
				karaktersay += 1;
			}
		}
	}

	if (bosluksayaci == 999)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int asusluparantez(char *kelime) //fonksiyona ilgili sat�r� g�nderdim.sat�rdaki kelime '{ ise return 1 de�ilse 0 de�erini d�nd�rd�m.
{
	int bosluksayaci = 0;
	int karaktersay = 0;
	int z;
	if (kelime[0] == '{')
	{
		karaktersay = 1;
		for (z = 1; z < 1000; z++)
		{
			if (kelime[z] == NULL)
			{
				bosluksayaci = bosluksayaci + 1;
			}
			else
			{
				karaktersay += 1;
			}
		}
	}

	if (bosluksayaci == 999)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int esittir(char *kelime) //fonksiyona ilgili sat�r� g�nderdim.sat�rdaki kelime '= ise return 1 de�ilse 0 de�erini d�nd�rd�m..
{
	int bosluksayaci = 0;
	int karaktersay = 0;
	int z;
	if (kelime[0] == '=' && kelime[1] != '=')
	{
		karaktersay = 1;
		for (z = 1; z < 1000; z++)
		{
			if (kelime[z] == NULL)
			{
				bosluksayaci = bosluksayaci + 1;
			}
			else
			{
				karaktersay += 1;
			}
		}
	}

	if (bosluksayaci == 999)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int ksusluparantez(char *kelime) //fonksiyona ilgili sat�r� g�nderdim.sat�rdaki kelime '} ise return 1 de�ilse 0 de�erini d�nd�rd�m.
{
	int bosluksayaci = 0;
	int karaktersay = 0;
	int z;
	if (kelime[0] == '}')
	{
		karaktersay = 1;
		for (z = 1; z < 1000; z++)
		{
			if (kelime[z] == NULL)
			{
				bosluksayaci = bosluksayaci + 1;
			}
			else
			{
				karaktersay += 1;
			}
		}
	}

	if (bosluksayaci == 999)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int islem(char *kelime) //fonksiyona ilgili sat�r� g�nderdim.sat�rdaki kelime '(+||-||||/) ise return 1 de�ilse 0 de�erini d�nd�rd�m.
{
	int bosluksayaci = 0;
	int karaktersay = 0;
	int z;
	if (kelime[0] == '+' || kelime[0] == '-' || kelime[0] == '/' || kelime[0] == '*')
	{
		karaktersay = 1;
		for (z = 1; z < 1000; z++)
		{
			if (kelime[z] == NULL)
			{
				bosluksayaci = bosluksayaci + 1;
			}
			else
			{
				karaktersay += 1;
			}
		}
	}

	if (bosluksayaci == 999)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int noktalivirgul(char *kelime) //fonksiyona ilgili sat�r� g�nderdim.sat�rdaki kelime '; ise return 1 de�ilse 0 de�erini d�nd�rd�m.
{
	int bosluksayaci = 0;
	int karaktersay = 0;
	int z;
	if (kelime[0] == ';')
	{
		karaktersay = 1;
		for (z = 1; z < 1000; z++)
		{
			if (kelime[z] == NULL)
			{
				bosluksayaci = bosluksayaci + 1;
			}
			else
			{
				karaktersay += 1;
			}
		}
	}

	if (bosluksayaci == 999)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int elseifkontrolu(char *kelime) //fonksiyona ilgili sat�r� g�nderdim.sat�rdaki kelime else if ise return 1 de�ilse 0 de�erini d�nd�rd�m.
{
	int bosluksayaci = 0;
	int elseifsay = 1;
	int z;
	for (z = 0; z < 1000; z++)
	{
		if (kelime[0] == 'e' && kelime[1] == 'l' && kelime[2] == 's' && kelime[3] == 'e' && kelime[4] == 'i' && kelime[5] == 'f')
		{
			elseifsay = 6;
		}
		if (kelime[z] == NULL)
		{
			bosluksayaci = bosluksayaci + 1;
		}
	}
	if (bosluksayaci == 1000 - elseifsay)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int elsekontrolu(char *kelime) //fonksiyona ilgili sat�r� g�nderdim.sat�rdaki kelime else ise return 1 de�ilse 0 de�erini d�nd�rd�m.
{
	int bosluksayaci = 0;
	int elsesay = 1;
	int z;
	for (z = 0; z < 1000; z++)
	{
		if (kelime[0] == 'e' && kelime[1] == 'l' && kelime[2] == 's' && kelime[3] == 'e')
		{
			elsesay = 4;
		}
		if (kelime[z] == NULL)
		{
			bosluksayaci = bosluksayaci + 1;
		}
	}
	if (bosluksayaci == 1000 - elsesay)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int dizisonu(char *kelime) //fonksiyona ilgili sat�r� g�nderdim.sat�r bo� ise return 1 de�ilse 0 de�erini d�nd�rd�m.
{
	int bosluksayaci = 0;
	int z;
	for (z = 0; z < 1000; z++)
	{
		if (kelime[z] == NULL)
		{
			bosluksayaci = bosluksayaci + 1;
		}
	}
	if (bosluksayaci == 1000)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main(int argc, char *argv[])
{
	FILE *dosya;
	char karakter;
	char dizin[10000];
	printf("===========================TOKENIZER VE PARSER================================\n\n");
tekrar:
	printf(".txt uzantili dosya dizinini giriniz:");
	scanf("%s", &dizin);
	printf("\n");
	printf("==============================================================================\n\n");
	dosya = fopen(dizin, "r"); //dosyay� a�t�m
	char dizi[100000];
	char harfler[100000];
	if (dosya == NULL) //dosyan�n bulunup bulunmad���n�n kontrol�n� yapt�m
	{
		printf("dosya bulunamadi..\n\n");
		goto tekrar;
	}
	else //e�er dosya var ise else parantezleri i�indeki ad�mlara ge�tim
	{
		karakter = fgetc(dosya); //fgetc ile dosyadaki ilk karakteri karakter char�na att�m
		int i = 0;
		int a = 0;
		while (karakter != EOF) // EOF ile dosya i�indeki karakterlerin sonuna gelinmedi�i m�ddet�e d�ng�ye soktum ve karakterleri tek tek okudum ve indis char�na s�ras�yla atad�m
		{
			dizi[i] = karakter;
			karakter = fgetc(dosya);
			if (dizi[i] != 32 && dizi[i] != 10 && dizi[i] != 9) //e�er dizi[i] bo� de�ilse onu harfler e att�m.
			{
				harfler[a] = dizi[i];
				a = a + 1;
			}
			i = i + 1;
		}
		int q = 1;
		while (dizi[(i + 1) - q] == NULL) //kaynak kodu yazd�rmak i�in dizideki bo� olmayan en son elemanin adresini buldum.
		{
			q = q + 1;
		}
		int sonelemaninadresi;
		sonelemaninadresi = i - q + 1;
		printf("Text deki kaynak kodunuz:\n \n");
		for (i = 0; i < sonelemaninadresi; i++) //text te ki kaynak kodu yazd�rd�m.
		{
			printf("%c", dizi[i]);
		}
		printf("\n\n================================TOKENIZER=====================================\n\n");
		printf("Kaynak kodunuzun kelimelestirilmis hali: \n\n");
	}
	char kelimeler[1000][1000]; //her satirda bir kelimeyi tutmak i�in iki boyutlu dizi tan�mlad�m.
	int satir = 0;
	int sutun = 0;
	int m;
	for (m = 0; m < 1000; m++) //for i�inde harfler isimli tek boyutlu dizideki karakterleri kelimele�tirerek her kelimeyi farkli bir satira alt alta ekledim.
	{
		if (harfler[m] == '+' && harfler[m + 1] == '+' || harfler[m] == '-' && harfler[m + 1] == '-' || harfler[m] == '=' && harfler[m + 1] == '=' || harfler[m] == '+' && harfler[m + 1] == '=' || harfler[m] == '-' && harfler[m + 1] == '=' ||
			harfler[m] == '/' && harfler[m + 1] == '=' || harfler[m] == '*' && harfler[m + 1] == '=' || harfler[m] == '<' && harfler[m + 1] == '=' || harfler[m] == '>' && harfler[m + 1] == '=' || harfler[m] == '|' && harfler[m + 1] == '|' ||
			harfler[m] == '&' && harfler[m + 1] == '&' || harfler[m] == '!' && harfler[m + 1] == '=' || harfler[m] == '%' && harfler[m + 1] == '=' || harfler[m] == '?' && harfler[m + 1] == '=')
		{
			kelimeler[satir][sutun] = harfler[m];
			kelimeler[satir][sutun + 1] = harfler[m + 1];
			satir++;
			sutun = 0;
			m++;
		}
		else if (harfler[m] == 33 || harfler[m] == 34 || harfler[m] == 35 || harfler[m] == 36 || harfler[m] == 37 || harfler[m] == 38 || harfler[m] == 39 || harfler[m] == 40 || harfler[m] == 41 || harfler[m] == 42 || harfler[m] == 43 ||
				 harfler[m] == 44 || harfler[m] == 45 || harfler[m] == 46 || harfler[m] == 47 || harfler[m] == 58 || harfler[m] == 59 || harfler[m] == 60 || harfler[m] == 61 || harfler[m] == 62 || harfler[m] == 63 || harfler[m] == 91 || harfler[m] == 92 ||
				 harfler[m] == 93 || harfler[m] == 94 || harfler[m] == 95 || harfler[m] == 96 || harfler[m] == 123 || harfler[m] == 124 || harfler[m] == 125 || harfler[m] == 126)
		{
			kelimeler[satir][sutun] = harfler[m];
			satir++;
			sutun = 0;
		}
		else
		{
			if (harfler[m + 1] == 33 || harfler[m + 1] == 34 || harfler[m + 1] == 35 || harfler[m + 1] == 36 || harfler[m + 1] == 37 || harfler[m + 1] == 38 || harfler[m + 1] == 39 || harfler[m + 1] == 40 || harfler[m + 1] == 41 || harfler[m + 1] == 42 || harfler[m + 1] == 43 ||
				harfler[m + 1] == 44 || harfler[m + 1] == 45 || harfler[m + 1] == 46 || harfler[m + 1] == 47 || harfler[m + 1] == 58 || harfler[m + 1] == 59 || harfler[m + 1] == 60 || harfler[m + 1] == 61 || harfler[m + 1] == 62 || harfler[m + 1] == 63 || harfler[m + 1] == 91 || harfler[m + 1] == 92 ||
				harfler[m + 1] == 93 || harfler[m + 1] == 94 || harfler[m + 1] == 95 || harfler[m + 1] == 96 || harfler[m + 1] == 123 || harfler[m + 1] == 124 || harfler[m + 1] == 125 || harfler[m + 1] == 126)
			{
				kelimeler[satir][sutun] = harfler[m];
				satir++;
				sutun = 0;
			}
			else
			{
				kelimeler[satir][sutun] = harfler[m];
				sutun = sutun + 1;
			}
		}
	}
	printf("{"); //her bir kelimeyi { } arasina aralar�nda virg�l olacak �ekilde yazd�rd�m.
	for (m = 0; m < satir + 1; m++)
	{
		printf("%s ", kelimeler[m]);
		if (m == satir)
		{
			printf("}");
		}
		else
		{
			printf(",");
		}
	}
	printf("\n\n================================PARSER========================================\n\n");
	int elsesayisi = 0; //gramere g�re else bir defa gelebilir.o y�zden else sayisi kontrol edebilmek i�in bu de�i�keni tan�mlad�m.
	satir = 0;
	sutun = 0;
	int i;
	for (i = 0; i < 11; i++) //For blo�unun i�inde her bir kelimenin gramer kuralina uyup uymad��n� kontrol ettim
	{
		if (i == 0) //if mi? konttrol�
		{
			char kontroldizisi[1000];
			for (sutun = 0; sutun < 1000; sutun++)
			{
				kontroldizisi[sutun] = kelimeler[satir][sutun];
			}
			if (ifkontrolu(kontroldizisi))
			{
				satir = satir + 1;
			}
			else
			{
				if (dizisonu(kontroldizisi))
				{
					printf("Girilen kaynak kodunuz hatalidir..\n\n");
					printf("kaynak kodunuz if ile baslamak zorundadir. ");
				}
				else
				{
					printf("Girilen kaynak kodunuz hatalidir..\n\n");
					printf("kaynak kodunuz if ile baslamak zorundadir.\n\nbu ifade ile baslayamaz: ");
					for (sutun = 0; sutun < 1000; sutun++)
					{
						if (kontroldizisi[sutun] != NULL)
						{
							printf("%c", kontroldizisi[sutun]);
						}
					}
				}

				printf("\n\n==============================================================================\n");
				break;
			}
		}
		if (i == 1) // '(' mi? kontrol�
		{
			char kontroldizisi[1000];
			for (sutun = 0; sutun < 1000; sutun++)
			{
				kontroldizisi[sutun] = kelimeler[satir][sutun];
			}
			if (acilanparantez(kontroldizisi))
			{
				satir = satir + 1;
			}
			else
			{
				if (dizisonu(kontroldizisi))
				{
					printf("Girilen kaynak kodunuz hatalidir..\n\n");
					printf("\nif veya else iften  ten sonra '(' kullanilmalidir.. ");
				}
				else
				{
					printf("Girilen kaynak kodunuz hatalidir..\n\n");
					printf("if veya else if ten sonra parantez acilip <sart> tanimlanmalidir.\n\nbu ifade dilin kuralina uymamaktadir: ");
					for (sutun = 0; sutun < 1000; sutun++)
					{
						if (kontroldizisi[sutun] != NULL)
						{
							printf("%c", kontroldizisi[sutun]);
						}
					}
				}
				printf("\n\n==============================================================================\n");
				break;
			}
		}

		if (i == 2) //<id> mi? kontrol�
		{
			char kontroldizisi[1000];
			for (sutun = 0; sutun < 1000; sutun++)
			{
				kontroldizisi[sutun] = kelimeler[satir][sutun];
			}
			if (id(kontroldizisi))
			{
				satir = satir + 1;
			}
			else
			{
				if (dizisonu(kontroldizisi))
				{
					printf("Girilen kaynak kodunuz hatalidir..\n\n");
					printf("'('den sonra id tanimlanmalidir");
				}
				else
				{
					printf("Girilen kaynak kodunuz hatalidir..\n\n");
					printf("'('den sonra <id> tanimlamaniz gerekmektedir.\n\nBu ifade dilin kuralina uymamaktadir: ");
					for (sutun = 0; sutun < 1000; sutun++)
					{
						if (kontroldizisi[sutun] != NULL)
						{
							printf("%c", kontroldizisi[sutun]);
						}
					}
				}
				printf("\n\n==============================================================================\n");
				break;
			}
		}
		if (i == 3) //<op> mu? kontrol�
		{
			char kontroldizisi[1000];
			for (sutun = 0; sutun < 1000; sutun++)
			{
				kontroldizisi[sutun] = kelimeler[satir][sutun];
			}
			if (operand(kontroldizisi))
			{
				satir = satir + 1;
			}
			else
			{
				if (dizisonu(kontroldizisi))
				{
					printf("Girilen kaynak kodunuz hatalidir..\n\n");
					printf("<id> den sonra <op> tanimlanmalidir");
				}
				else
				{
					printf("Girilen kaynak kodunuz hatalidir..\n\n");
					printf("<id> den sonra <op> tanimlanmalidir.\n\nBu ifade dilin kuralina uymamaktadir: ");
					for (sutun = 0; sutun < 1000; sutun++)
					{
						if (kontroldizisi[sutun] != NULL)
						{
							printf("%c", kontroldizisi[sutun]);
						}
					}
				}
				printf("\n\n==============================================================================\n");
				break;
			}
		}
		if (i == 4) //<id> mi? kontrol�
		{
			char kontroldizisi[1000];
			for (sutun = 0; sutun < 1000; sutun++)
			{
				kontroldizisi[sutun] = kelimeler[satir][sutun];
			}
			if (id(kontroldizisi))
			{
				satir = satir + 1;
			}
			else
			{
				if (dizisonu(kontroldizisi))
				{
					printf("Girilen kaynak kodunuz hatalidir..\n\n");
					printf("<op> dan sonra <id> tanimlanmalidir");
				}
				else
				{
					printf("Girilen kaynak kodunuz hatalidir..\n\n");
					printf("<op> dan sonra <id> tanimlanmalidir.\n\nBu ifade dilin kuralina uymamaktadir: ");
					for (sutun = 0; sutun < 1000; sutun++)
					{
						if (kontroldizisi[sutun] != NULL)
						{
							printf("%c", kontroldizisi[sutun]);
						}
					}
					printf("\n\n==============================================================================\n");
					break;
				}
			}
		}
		if (i == 5) // ')' mi? kontrol�
		{
			char kontroldizisi[1000];
			for (sutun = 0; sutun < 1000; sutun++)
			{
				kontroldizisi[sutun] = kelimeler[satir][sutun];
			}
			if (kapananparantez(kontroldizisi))
			{
				satir = satir + 1;
			}
			else
			{
				if (dizisonu(kontroldizisi))
				{
					printf("Girilen kaynak kodunuz hatalidir..\n\n");
					printf("<id> den sonra ')' gelmelidir.\n\n");
				}
				else
				{
					printf("Girilen kaynak kodunuz hatalidir..\n\n");
					printf("<id> den sonra ')' gelmelidir.\n\nBu ifade dilin kuralina uymamaktadir: ");
					for (sutun = 0; sutun < 1000; sutun++)
					{
						if (kontroldizisi[sutun] != NULL)
						{
							printf("%c", kontroldizisi[sutun]);
						}
					}
				}

				printf("\n\n==============================================================================\n");
				break;
			}
		} //burdan itibaren c�mleyi kontrol etmeye baslad�m. '{' mi? kontrol�
		if (i == 6)
		{
			char kontroldizisi[1000];
			for (sutun = 0; sutun < 1000; sutun++)
			{
				kontroldizisi[sutun] = kelimeler[satir][sutun];
			}
			if (asusluparantez(kontroldizisi))
			{
				satir = satir + 1;
			}
			else
			{
				if (dizisonu(kontroldizisi))
				{
					printf("Girilen kaynak kodunuz hatalidir..\n\n");
					printf("<sart> veya else den sonra '{' gelmelidir.\n\n");
				}
				else
				{
					printf("Girilen kaynak kodunuz hatalidir..\n\n");
					printf("')' den sonra '{' gelmelidir.\n\nBu ifade dilin kuralina uymamaktadir: ");
					for (sutun = 0; sutun < 1000; sutun++)
					{
						if (kontroldizisi[sutun] != NULL)
						{
							printf("%c", kontroldizisi[sutun]);
						}
					}
				}

				printf("\n\n==============================================================================\n");
				break;
			}
		}
		if (i == 7) //<id> mi? kontrol�
		{
			char kontroldizisi[1000];
			for (sutun = 0; sutun < 1000; sutun++)
			{
				kontroldizisi[sutun] = kelimeler[satir][sutun];
			}
			if (id(kontroldizisi))
			{
				satir = satir + 1;
			}
			else
			{
				if (dizisonu(kontroldizisi))
				{
					printf("Girilen kaynak kodunuz hatalidir..\n\n");
					printf("'{' den sonra <id> tanimlanmalidir.\n\n");
				}
				else
				{
					printf("Girilen kaynak kodunuz hatalidir..\n\n");
					printf("'{' den sonra <id> tanimlanmalidir.\n\nBu ifade dilin kuralina uymamaktadir: ");
					for (sutun = 0; sutun < 1000; sutun++)
					{
						if (kontroldizisi[sutun] != NULL)
						{
							printf("%c", kontroldizisi[sutun]);
						}
					}
				}

				printf("\n\n==============================================================================\n");
				break;
			}
		}
		if (i == 8) // '=' mi kotrol�
		{
			char kontroldizisi[1000];
			for (sutun = 0; sutun < 1000; sutun++)
			{
				kontroldizisi[sutun] = kelimeler[satir][sutun];
			}
			if (esittir(kontroldizisi))
			{
				satir = satir + 1;
			}
			else
			{
				if (dizisonu(kontroldizisi))
				{
					printf("Girilen kaynak kodunuz hatalidir..\n\n");
					printf("<id> den sonra '=' tanimlanmalidir.\n\n");
				}
				else
				{
					printf("Girilen kaynak kodunuz hatalidir..\n\n");
					printf("<id> den sonra '=' tanimlanmalidir.\n\nBu ifade dilin kuralina uymamaktadir: ");
					for (sutun = 0; sutun < 1000; sutun++)
					{
						if (kontroldizisi[sutun])
						{
							printf("%c", kontroldizisi[sutun]);
						}
					}
				}

				printf("\n\n==============================================================================\n");
				break;
			}
		}
		if (i == 9) //<id> mi? kontrol�
		{
			char kontroldizisi[1000];
			for (sutun = 0; sutun < 1000; sutun++)
			{
				kontroldizisi[sutun] = kelimeler[satir][sutun];
			}
			if (id(kontroldizisi))
			{
				satir = satir + 1;
			}
			else
			{
				if (dizisonu(kontroldizisi))
				{
					printf("Girilen kaynak kodunuz hatalidir..\n\n");
					printf("'=' den sonra <id> tanimlanmalidir.\n\n");
				}
				else
				{
					printf("Girilen kaynak kodunuz hatalidir..\n\n");
					printf("'=' den sonra <id> tanimlanmalidir.\n\nBu ifade dilin kuralina uymamaktadir: ");
					for (sutun = 0; sutun < 1000; sutun++)
					{
						if (kontroldizisi[sutun] != NULL)
						{
							printf("%c", kontroldizisi[sutun]);
						}
					}
				}

				printf("\n\n==============================================================================\n");
				break;
			}
		}
		if (i == 10)
		{
			char kontroldizisi[1000];
			for (sutun = 0; sutun < 1000; sutun++)
			{
				kontroldizisi[sutun] = kelimeler[satir][sutun];
			}
			if (noktalivirgul(kontroldizisi)) //c�mle--> <id>=<id> ve ';' m�? kontrol�
			{
				satir = satir + 1;
				char kontroldizisi[1000];
				for (sutun = 0; sutun < 1000; sutun++)
				{
					kontroldizisi[sutun] = kelimeler[satir][sutun];
				}
				if (ksusluparantez(kontroldizisi)) // '}' mi? kontrol�
				{
					satir = satir + 1;
					char kontroldizisi[1000];
					for (sutun = 0; sutun < 1000; sutun++)
					{
						kontroldizisi[sutun] = kelimeler[satir][sutun];
					}
					if (elseifkontrolu(kontroldizisi) == 1 && elsekontrolu(kontroldizisi) == 0) //c�mle bittikten sonra else if mi? kontrol�
					{
						if (elsesayisi > 0)
						{
							printf("Girilen kaynak kodunuz hatalidir..\n\n");
							printf("Dilin kuralina gore else blogundan sonra hicbir ifade gelemez..\n\n");
							printf("Bu ifadenin kullanimi yanlistir: ");
							for (sutun = 0; sutun < 1000; sutun++)
							{
								if (kontroldizisi[sutun] != NULL)
								{
									printf("%c", kontroldizisi[sutun]);
								}
							}
							printf("\n\n==============================================================================\n");
							break;
						}
						else //e�er else if ise bir di�er satira ge�tim ve �arttan itibaren kontrol edebilmek i�in i=0 yapt�m ve bu sayede else if i�in �art ve c�mleyi konttol ettim.
						{
							satir = satir + 1;
							i = 0;
						}
					}
					else if (elseifkontrolu(kontroldizisi) == 0 && elsekontrolu(kontroldizisi) == 1) //c�mleden sonra else mi?kontrol�
					{
						if (elsesayisi == 0) //e�er else ise bir di�er satira ge�tim ve c�mleden itibaren kontrol edebilmek i�in i=5 yapt�m ve bu sayede else i�in  c�mleyi konttol ettim.
						{
							elsesayisi = elsesayisi + 1;
							satir = satir + 1;
							i = 5;
						}
						else
						{
							printf("Girilen kaynak kodunuz hatalidir..\n\n");
							printf("Dilin kuralina gore else blogundan sonra hicbir ifade gelemez..\n\n");
							printf("Bu ifadenin kullanimi yanlistir: ");
							for (sutun = 0; sutun < 1000; sutun++)
							{
								if (kontroldizisi[sutun] != NULL)
								{
									printf("%c", kontroldizisi[sutun]);
								}
							}
							printf("\n\n==============================================================================\n");
							break;
						}
					}
					else
					{
						if (dizisonu(kontroldizisi)) //kod do�ru ise bu blo�a d���yor.
						{
							printf("Girilen kaynak kodunuz dogrudur.\n\n");
							printf("\n\n==============================================================================\n");
						}
						else if (elsesayisi != 0)
						{
							printf("Girilen kaynak kodunuz hatalidir..\n\n");
							printf("Dilin kuralina gore else blogundan sonra hicbir ifade gelemez..\n\n");
							printf("Bu ifadenin kullanimi yanlistir: ");
							for (sutun = 0; sutun < 1000; sutun++)
							{
								if (kontroldizisi[sutun] != NULL)
								{
									printf("%c", kontroldizisi[sutun]);
								}
							}
							printf("\n\n==============================================================================\n");
							break;
						}

						else
						{
							printf("Girilen kaynak kodunuz hatalidir..\n\n");
							printf("Bu ifadenin kullanimi yanlistir: ");
							for (sutun = 0; sutun < 1000; sutun++)
							{
								if (kontroldizisi[sutun] != NULL)
								{
									printf("%c", kontroldizisi[sutun]);
								}
							}

							printf("\n\n==============================================================================\n");
							break;
						}
					}
				}

				else
				{
					if (dizisonu(kontroldizisi))
					{
						printf("Girilen kaynak kodunuz hatalidir..\n\n");
						printf("';' den sonra '}' gelmelidir.\n\n");
					}
					else
					{
						printf("Girilen kaynak kodunuz hatalidir..\n\n");
						printf("';' den sonra '}' gelmelidir.\n\nBu ifade dilin kuralina uymamaktadir: ");
						for (sutun = 0; sutun < 1000; sutun++)
						{
							if (kontroldizisi[sutun] != NULL)
							{
								printf("%c", kontroldizisi[sutun]);
							}
						}
					}

					printf("\n\n==============================================================================\n");
					break;
				}
			}
			else
			{
				if (islem(kontroldizisi)) //c�mle <id>=<id>(+||-||||/)<id>; �eklinde ise (+||-||||/) mi? kontrol�
				{
					satir = satir + 1;
					char kontroldizisi[1000];
					for (sutun = 0; sutun < 1000; sutun++)
					{
						kontroldizisi[sutun] = kelimeler[satir][sutun];
					}
					if (id(kontroldizisi)) //id mi? kontrol�
					{
						satir = satir + 1;
						char kontroldizisi[1000];
						for (sutun = 0; sutun < 1000; sutun++)
						{
							kontroldizisi[sutun] = kelimeler[satir][sutun];
						}
						if (noktalivirgul(kontroldizisi)) // ';'m�? kontrol�
						{
							satir = satir + 1;
							char kontroldizisi[1000];
							for (sutun = 0; sutun < 1000; sutun++)
							{
								kontroldizisi[sutun] = kelimeler[satir][sutun];
							}
							if (ksusluparantez(kontroldizisi)) // '{'mi? kontrol�
							{
								satir = satir + 1;
								char kontroldizisi[1000];
								for (sutun = 0; sutun < 1000; sutun++)
								{
									kontroldizisi[sutun] = kelimeler[satir][sutun];
								}
								if (elseifkontrolu(kontroldizisi) == 1 && elsekontrolu(kontroldizisi) == 0) //else if mi? kontrol�
								{
									if (elsesayisi > 0)
									{
										printf("Girilen kaynak kodunuz hatalidir..\n\n");
										printf("Dilin kuralina gore else blogundan sonra hicbir ifade gelemez..\n\n");
										printf("Bu ifadenin kullanimi yanlistir: ");
										for (sutun = 0; sutun < 1000; sutun++)
										{
											if (kontroldizisi[sutun] != NULL)
											{
												printf("%c", kontroldizisi[sutun]);
											}
										}
										printf("\n\n==============================================================================\n");
										break;
									}
									else //e�er else if ise bir di�er satira ge�tim ve �arttan itibaren kontrol edebilmek i�in i=0 yapt�m ve bu sayede else if i�in �art ve c�mleyi konttol ettim.
									{
										satir = satir + 1;
										i = 0;
									}
								}
								else if (elseifkontrolu(kontroldizisi) == 0 && elsekontrolu(kontroldizisi) == 1) //else mi? kontrol�
								{
									if (elsesayisi == 0) //e�er else ise bir di�er satira ge�tim ve c�mleden itibaren kontrol edebilmek i�in i=5 yapt�m ve bu sayede else i�in c�mleyi konttol ettim.
									{
										elsesayisi = elsesayisi + 1;
										satir = satir + 1;
										i = 5;
									}
									else
									{
										printf("Girilen kaynak kodunuz hatalidir..\n\n");
										printf("Dilin kuralina gore else blogundan sonra hicbir ifade gelemez..\n\n");
										printf("Bu ifadenin kullanimi yanlistir: ");
										for (sutun = 0; sutun < 1000; sutun++)
										{
											if (kontroldizisi[sutun] != NULL)
											{
												printf("%c", kontroldizisi[sutun]);
											}
										}
										printf("\n\n==============================================================================\n");
										break;
									}
								}
								else
								{
									if (dizisonu(kontroldizisi)) //kod do�ru ise bu blo�a d���yor.
									{
										printf("Girilen kaynak kodunuz dogrudur.\n\n");
										printf("\n\n==============================================================================\n");
									}
									else if (elsesayisi != 0)
									{
										printf("Girilen kaynak kodunuz hatalidir..\n\n");
										printf("Dilin kuralina gore else blogundan sonra hicbir ifade gelemez..\n\n");
										printf("Bu ifadenin kullanimi yanlistir: ");
										for (sutun = 0; sutun < 1000; sutun++)
										{
											if (kontroldizisi[sutun] != NULL)
											{
												printf("%c", kontroldizisi[sutun]);
											}
										}
										printf("\n\n==============================================================================\n");
										break;
									}
									else
									{
										printf("Girilen kaynak kodunuz hatalidir..\n\n");
										printf("Bu ifadenin kullanimi yanlistir: ");
										for (sutun = 0; sutun < 1000; sutun++)
										{
											if (kontroldizisi[sutun] != NULL)
											{
												printf("%c", kontroldizisi[sutun]);
											}
										}
										printf("\n\n==============================================================================\n");
										break;
									}
								}
							}
							else
							{
								if (dizisonu(kontroldizisi))
								{
									printf("Girilen kaynak kodunuz hatalidir..\n\n");
									printf("';' den sonra '}' gelmelidir.\n\n");
								}
								else
								{
									printf("Girilen kaynak kodunuz hatalidir..\n\n");
									printf("';' den sonra '}' gelmelidir.\n\nBu ifade dilin kuralina uymamaktadir: ");
									for (sutun = 0; sutun < 1000; sutun++)
									{
										if (kontroldizisi[sutun] != NULL)
										{
											printf("%c", kontroldizisi[sutun]);
										}
									}
								}

								printf("\n\n==============================================================================\n");
								break;
							}
						}
						else
						{
							if (dizisonu(kontroldizisi))
							{
								printf("Girilen kaynak kodunuz hatalidir..\n\n");
								printf("<id> den sonra ';' gelmelidir.\n\n");
							}
							else
							{
								printf("Girilen kaynak kodunuz hatalidir..\n\n");
								printf("<id> den sonra ';' gelmelidir.\n\n");
								printf("Bu ifade dilin kuralina uymamaktadir: ");
								for (sutun = 0; sutun < 1000; sutun++)
								{
									if (kontroldizisi[sutun] != NULL)
									{
										printf("%c", kontroldizisi[sutun]);
									}
								}
							}

							printf("\n\n==============================================================================\n");
							break;
						}
					}
					else
					{
						if (dizisonu(kontroldizisi))
						{
							printf("Girilen kaynak kodunuz hatalidir..\n\n");
							printf("islemden (+,-,*,/) sonra <id> tanimlanmalidir.\n\n");
						}
						else
						{
							printf("Girilen kaynak kodunuz hatalidir..\n\n");
							printf("islemden (+,-,*,/) sonra <id> tanimlanmalidir.\n\nBu ifade dilin kuralina uymamaktadir: ");
							for (sutun = 0; sutun < 1000; sutun++)
							{
								if (kontroldizisi[sutun] != NULL)
								{
									printf("%c", kontroldizisi[sutun]);
								}
							}
						}

						printf("\n\n==============================================================================\n");
						break;
					}
				}
				else
				{
					if (dizisonu(kontroldizisi))
					{
						printf("Girilen kaynak kodunuz hatalidir..\n\n");
						printf("<id> den sonra ';' veya (+,-,*,/) gelmelidir.\n\n");
					}
					else
					{
						printf("Girilen kaynak kodunuz hatalidir..\n\n");
						printf("<id> den sonra ';' veya (+,-,*,/) gelmelidir.\n\nBu ifade dilin kuralina uymamaktadir: ");
						for (sutun = 0; sutun < 1000; sutun++)
						{
							if (kontroldizisi[sutun] != NULL)
							{
								printf("%c", kontroldizisi[sutun]);
							}
						}
					}

					printf("\n\n==============================================================================\n");
					break;
				}
			}
		}
	}
	fclose(dosya);
	return 0;
}

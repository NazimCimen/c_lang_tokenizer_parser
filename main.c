#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Nazým Çimen
/*
-projede hem tokenizer hem parser bulunmaktadir.tokenizer ve parser kodlarýnýn nerden baþladýðýný kodda belirttim.
-if, else ve else if yapýlarý ile oluþturulan basit kodlar, önce tokenizer iþlemi ile kelimelerine ayrýþtýrýlýr.
-daha sonra girilen kaynak kodun syntax kuralýna göre hatalý olup olmadýðý tespit edilir.hatanýn sebebi açýklanýr ve syntaxý bozan ifade tespit edilip ekranda gösterilir.
-projeyi her kelime farklý bir satýrda olacak þekilde 2 boyutlu dizi ile gerçekleþtirdim. 
-parser bölümünde noktali virgülü de kontrol ettim.
-bir döngü kullandým ve bu döngüde her satýr için olmasý gereken kelimenin doðru olup olmadýðýný kontrol ettim.hatayi görünce hatayý ve hatali kelimeyi yazdirdim.
-else if veya else geldiðinde döngüyü ilgili kelimeyi kontrol etmesi için gerekli yerden tekrar baþlattým.örneðin else if gelirse þarttan.else gelirse cümleden.
-main in üzerindeki tüm fonksiyonlar parse ye aittir.
-fonksiyonlarýn ve main içindeki bölümlerin açýklamalarýný açýklama satýrlarýnda belirttim.
-proje klasörünün içerisinde doðru ve yanlýþ sytaxta ait 2 adet txt dosya oluþturdum.projeyi çalýþtýrýp test edebilirsiniz.
*/
int ifkontrolu(char *kelime) //fonksiyona ilgili satýrý gönderdim.satýrdaki kelime if ise return 1 deðilse 0 deðerini döndürdüm.
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
int acilanparantez(char *kelime) //fonksiyona ilgili satýrý gönderdim.satýrdaki kelime '('  return 1 deðilse 0 deðerini döndürdüm.
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
int id(char *kelime) //fonksiyona ilgili satýrý gönderdim.satýrdaki kelime <id> ise return 1 deðilse 0 deðerini döndürdüm.
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
int operand(char *kelime) //fonksiyona ilgili satýrý gönderdim.satýrdaki kelime <op> ise return 1 deðilse 0 deðerini döndürdüm.
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
int kapananparantez(char *kelime) //fonksiyona ilgili satýrý gönderdim.satýrdaki kelime ') ise return 1 deðilse 0 deðerini döndürdüm.
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
int asusluparantez(char *kelime) //fonksiyona ilgili satýrý gönderdim.satýrdaki kelime '{ ise return 1 deðilse 0 deðerini döndürdüm.
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
int esittir(char *kelime) //fonksiyona ilgili satýrý gönderdim.satýrdaki kelime '= ise return 1 deðilse 0 deðerini döndürdüm..
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
int ksusluparantez(char *kelime) //fonksiyona ilgili satýrý gönderdim.satýrdaki kelime '} ise return 1 deðilse 0 deðerini döndürdüm.
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
int islem(char *kelime) //fonksiyona ilgili satýrý gönderdim.satýrdaki kelime '(+||-||||/) ise return 1 deðilse 0 deðerini döndürdüm.
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
int noktalivirgul(char *kelime) //fonksiyona ilgili satýrý gönderdim.satýrdaki kelime '; ise return 1 deðilse 0 deðerini döndürdüm.
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
int elseifkontrolu(char *kelime) //fonksiyona ilgili satýrý gönderdim.satýrdaki kelime else if ise return 1 deðilse 0 deðerini döndürdüm.
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
int elsekontrolu(char *kelime) //fonksiyona ilgili satýrý gönderdim.satýrdaki kelime else ise return 1 deðilse 0 deðerini döndürdüm.
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
int dizisonu(char *kelime) //fonksiyona ilgili satýrý gönderdim.satýr boþ ise return 1 deðilse 0 deðerini döndürdüm.
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
	dosya = fopen(dizin, "r"); //dosyayý açtým
	char dizi[100000];
	char harfler[100000];
	if (dosya == NULL) //dosyanýn bulunup bulunmadýðýnýn kontrolünü yaptým
	{
		printf("dosya bulunamadi..\n\n");
		goto tekrar;
	}
	else //eðer dosya var ise else parantezleri içindeki adýmlara geçtim
	{
		karakter = fgetc(dosya); //fgetc ile dosyadaki ilk karakteri karakter charýna attým
		int i = 0;
		int a = 0;
		while (karakter != EOF) // EOF ile dosya içindeki karakterlerin sonuna gelinmediði müddetçe döngüye soktum ve karakterleri tek tek okudum ve indis charýna sýrasýyla atadým
		{
			dizi[i] = karakter;
			karakter = fgetc(dosya);
			if (dizi[i] != 32 && dizi[i] != 10 && dizi[i] != 9) //eðer dizi[i] boþ deðilse onu harfler e attým.
			{
				harfler[a] = dizi[i];
				a = a + 1;
			}
			i = i + 1;
		}
		int q = 1;
		while (dizi[(i + 1) - q] == NULL) //kaynak kodu yazdýrmak için dizideki boþ olmayan en son elemanin adresini buldum.
		{
			q = q + 1;
		}
		int sonelemaninadresi;
		sonelemaninadresi = i - q + 1;
		printf("Text deki kaynak kodunuz:\n \n");
		for (i = 0; i < sonelemaninadresi; i++) //text te ki kaynak kodu yazdýrdým.
		{
			printf("%c", dizi[i]);
		}
		printf("\n\n================================TOKENIZER=====================================\n\n");
		printf("Kaynak kodunuzun kelimelestirilmis hali: \n\n");
	}
	char kelimeler[1000][1000]; //her satirda bir kelimeyi tutmak için iki boyutlu dizi tanýmladým.
	int satir = 0;
	int sutun = 0;
	int m;
	for (m = 0; m < 1000; m++) //for içinde harfler isimli tek boyutlu dizideki karakterleri kelimeleþtirerek her kelimeyi farkli bir satira alt alta ekledim.
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
	printf("{"); //her bir kelimeyi { } arasina aralarýnda virgül olacak þekilde yazdýrdým.
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
	int elsesayisi = 0; //gramere göre else bir defa gelebilir.o yüzden else sayisi kontrol edebilmek için bu deðiþkeni tanýmladým.
	satir = 0;
	sutun = 0;
	int i;
	for (i = 0; i < 11; i++) //For bloðunun içinde her bir kelimenin gramer kuralina uyup uymadýðný kontrol ettim
	{
		if (i == 0) //if mi? konttrolü
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
		if (i == 1) // '(' mi? kontrolü
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

		if (i == 2) //<id> mi? kontrolü
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
		if (i == 3) //<op> mu? kontrolü
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
		if (i == 4) //<id> mi? kontrolü
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
		if (i == 5) // ')' mi? kontrolü
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
		} //burdan itibaren cümleyi kontrol etmeye basladým. '{' mi? kontrolü
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
		if (i == 7) //<id> mi? kontrolü
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
		if (i == 8) // '=' mi kotrolü
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
		if (i == 9) //<id> mi? kontrolü
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
			if (noktalivirgul(kontroldizisi)) //cümle--> <id>=<id> ve ';' mü? kontrolü
			{
				satir = satir + 1;
				char kontroldizisi[1000];
				for (sutun = 0; sutun < 1000; sutun++)
				{
					kontroldizisi[sutun] = kelimeler[satir][sutun];
				}
				if (ksusluparantez(kontroldizisi)) // '}' mi? kontrolü
				{
					satir = satir + 1;
					char kontroldizisi[1000];
					for (sutun = 0; sutun < 1000; sutun++)
					{
						kontroldizisi[sutun] = kelimeler[satir][sutun];
					}
					if (elseifkontrolu(kontroldizisi) == 1 && elsekontrolu(kontroldizisi) == 0) //cümle bittikten sonra else if mi? kontrolü
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
						else //eðer else if ise bir diðer satira geçtim ve þarttan itibaren kontrol edebilmek için i=0 yaptým ve bu sayede else if için þart ve cümleyi konttol ettim.
						{
							satir = satir + 1;
							i = 0;
						}
					}
					else if (elseifkontrolu(kontroldizisi) == 0 && elsekontrolu(kontroldizisi) == 1) //cümleden sonra else mi?kontrolü
					{
						if (elsesayisi == 0) //eðer else ise bir diðer satira geçtim ve cümleden itibaren kontrol edebilmek için i=5 yaptým ve bu sayede else için  cümleyi konttol ettim.
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
						if (dizisonu(kontroldizisi)) //kod doðru ise bu bloða düþüyor.
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
				if (islem(kontroldizisi)) //cümle <id>=<id>(+||-||||/)<id>; þeklinde ise (+||-||||/) mi? kontrolü
				{
					satir = satir + 1;
					char kontroldizisi[1000];
					for (sutun = 0; sutun < 1000; sutun++)
					{
						kontroldizisi[sutun] = kelimeler[satir][sutun];
					}
					if (id(kontroldizisi)) //id mi? kontrolü
					{
						satir = satir + 1;
						char kontroldizisi[1000];
						for (sutun = 0; sutun < 1000; sutun++)
						{
							kontroldizisi[sutun] = kelimeler[satir][sutun];
						}
						if (noktalivirgul(kontroldizisi)) // ';'mü? kontrolü
						{
							satir = satir + 1;
							char kontroldizisi[1000];
							for (sutun = 0; sutun < 1000; sutun++)
							{
								kontroldizisi[sutun] = kelimeler[satir][sutun];
							}
							if (ksusluparantez(kontroldizisi)) // '{'mi? kontrolü
							{
								satir = satir + 1;
								char kontroldizisi[1000];
								for (sutun = 0; sutun < 1000; sutun++)
								{
									kontroldizisi[sutun] = kelimeler[satir][sutun];
								}
								if (elseifkontrolu(kontroldizisi) == 1 && elsekontrolu(kontroldizisi) == 0) //else if mi? kontrolü
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
									else //eðer else if ise bir diðer satira geçtim ve þarttan itibaren kontrol edebilmek için i=0 yaptým ve bu sayede else if için þart ve cümleyi konttol ettim.
									{
										satir = satir + 1;
										i = 0;
									}
								}
								else if (elseifkontrolu(kontroldizisi) == 0 && elsekontrolu(kontroldizisi) == 1) //else mi? kontrolü
								{
									if (elsesayisi == 0) //eðer else ise bir diðer satira geçtim ve cümleden itibaren kontrol edebilmek için i=5 yaptým ve bu sayede else için cümleyi konttol ettim.
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
									if (dizisonu(kontroldizisi)) //kod doðru ise bu bloða düþüyor.
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

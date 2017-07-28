#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// burada matrix dizisinin gonderdik
// ikinci paremetre ise toplan�cak faturan�n tipi burada matrixin ikinci
// boyutunun index de�eri kadar de�er gelebilir
// (min=0  || max=3) index oldu�u i�in 0 dan ba�lar verilen adetin -1 kadar�d�r
float getBillTypeOfTotalPrice(float matrix[12][4], int invoiceType)
{
	float _results = 0;
	int firstIndex; // d�ng�lerimizin de�i�kenlerini tan�mlad�k kendi i�inde de tan�mlana bilir
	for (firstIndex = 0; firstIndex < 12; firstIndex++)
	{ // faturalar matrix'inin ilk boyutu kadar d�ng� a�t�k

		_results += matrix[firstIndex][invoiceType]; // her a�n gonderilen fatura tipine gore de�erlerini al�p _result de�eri ile toplad�k
	}

	return _results; // func yonumuz geri g�n��l� tip oldu�u i�in ��kan sonucu (_result de�i�keni) geri d�nd�k
}

// burada matrix dizisinin gonderdik
// ikinci paremetre ise toplan�cak fatura ay�n� g�nderdik
// boyutunun index de�eri kadar de�er gelebilir
// (min=0  || max=11) index oldu�u i�in 0 dan ba�lar verilen adetin -1 kadar�d�r
float getMountOfTotalPrice(float matrix[12][4], int mount)
{
	float _results = 0;
	int firstIndex; // d�ng�lerimizin de�i�kenlerini tan�mlad�k kendi i�inde de tan�mlana bilir
	for (firstIndex = 0; firstIndex < 4; firstIndex++)
	{ // faturalar matrix'inin ikinci boyutu kadar d�ng� a�t�k

		_results += matrix[mount][firstIndex]; // istenilen ay�n fatura de�erlerini al�p _result de�eri ile toplad�k
	}

	return _results; // func yonumuz geri g�n��l� tip oldu�u i�in ��kan sonucu (_result de�i�keni) geri d�nd�k
}

int main(int argc, char *argv[])
{
	char _char = 'e';

	while (_char == 'e' || _char == 'E')
	{ // program e harfine bas�ld��� s�rece tekrar tekrar �al��acakt�r taki ba�ka harfe basana kadar

		float invoices[12][4];	// 12 aya g�re 4 fatura (2 boyutlu float cinsinden (k�s�rl� say�lar� tutabilmek i�in) matrix dizisi)
		int firstIndex, secIndex; // d�ng�lerimizin de�i�kenlerini tan�mlad�k kendi i�inde de tan�mlana bilir

		srand((unsigned int)time(NULL)); // random say� uretilmesi i�in gerekli kapat�ld��� zaman funcion h�zl� i�ledi�inden hep ayn� de�er gelir

		for (firstIndex = 0; firstIndex < 12; firstIndex++)
		{ // faturalar matrix'inin ilk boyutu kadar d�ng� a�t�k

			for (secIndex = 0; secIndex < 4; secIndex++)
			{   // faturalar matrix'inin ikinci boyutu kadar d�ng� a�t�k
				// sebebi ilk boyutu aylar ikinci boyutu ise 4 farkl� fatura olmas�
				//bir ay i�in 4 fatura fiyat� girmemizi sa�l�cak

				//((float)rand()/(float)(RAND_MAX)) * 250
				float _rndInvoicePrice = (float)(10 + rand() % 250); // 10 - 150 aras� rast gele fatura tutar� olu�turur
																	 //e�er daha fazla olu�tursun istersen de�eri artt�r
																	 //sadece ( _rndInvoicePrice=10+rand() ) yaz 10 dan fazla fiyat olu�turur

				invoices[firstIndex][secIndex] = _rndInvoicePrice; // faturalar matrix'ine random �retti�imiz fatura fiyatlar�n� set ettik
			}
		}

		printf("Toplanilmasi istenilen fatura tipini giriniz [0,1,2,3] \n");
		_char = getch();
		while (_char != '0' && _char != '1' && _char != '2' && _char != '3')
		{
			printf("Yanlis fatura tipi girdiniz l�tfen ayndaki degerleden birini giriniz [0,1,2,3] \n");
			_char = getch();
		}

		float totalBillResults = getBillTypeOfTotalPrice(invoices, (_char - '0')); // yazd���m�z func yunu �a��r�p belirlenen fatura tipinin toplan
																				   // faturra tutar�n� ald�k de�i�kene set ettik

		printf("%c fatura tipinin 12 aylik fatura tutari = %f \n", _char, totalBillResults); // bulgu�umuz sonucu ekrana bast�rd�k

		totalBillResults = getMountOfTotalPrice(invoices, 0); // yazd���m�z func yunu �a��r�p belirlenen fatura tipinin toplan
															  // faturra tutar�n� ald�k de�i�kene set ettik

		printf("1. Ayin 4 faturasinin toplam tutari = %f \n", totalBillResults); // bulgu�umuz sonucu ekrana bast�rd�k
		printf("Tekrar baslasin mi? (e) \n");

		_char = getch(); // program�n kapanmamas� i�in bir tu� t�klama olay�
	}
	return 0;
}

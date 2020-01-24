#include <stdio.h>
#include <math.h>

// #define pi 3.14159265358979323846
double coordenadasToMeters(double c){
	double h = (int)c - ((int)c)%10000;
	double m = ((int)c - h) - ((int)c)%100;
	double s = (c - h - m)/60;
	h = h / 10000 *60;
	m = m / 100;
	return (h + m + s) * 1.852;    

}
//retorno em metros
double calculaDistancia(double lat1, double long1, double lat2, double long2){
	lat1 = coordenadasToMeters(lat1);
	long1 = coordenadasToMeters(long1);
	lat2 = coordenadasToMeters(lat2);
	long2 = coordenadasToMeters(long2);
	
	double x = long1 - long2;
	double y = lat1 - lat2;
	return sqrt((x*x)+(y*y))*1000;


}
//retorn em radianos
double angulo(double lat1, double long1, double lat2, double long2){
	lat1 = coordenadasToMeters(lat1);
	long1 = coordenadasToMeters(long1);
	lat2 = coordenadasToMeters(lat2);
	long2 = coordenadasToMeters(long2);
	
	double x = long1 - long2;
	double y = lat1 - lat2;
	return atan(x/y);

}
int main (){
	printf("Distancia = %lf\n", calculaDistancia(233036.50, 463832.90, 233029.93, 463753.01));
	printf("Angluo = %lf\n", angulo(233036.50, 463832.90, 233029.93, 463753.01));
	return 0;
}

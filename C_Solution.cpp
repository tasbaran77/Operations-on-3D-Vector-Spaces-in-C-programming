#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Baran{
	
double x;
double y;
double z;

} Vector;

void print_vector(const Vector v){
	
	printf("(%.2lf %.2lf %.2lf)\n",v.x, v.y, v.z);
	
}

Vector sum(const Vector v1, const Vector v2){
	
	struct Baran Vector1;
	Vector1 = {v1.x + v2.x , v1.y + v2.y , v1.z + v2.z}; 
	return Vector1;
	
}

Vector diff(const Vector v1, const Vector v2){
	
	struct Baran Vector1;
	Vector1 = {v1.x - v2.x , v1.y - v2.y , v1.z - v2.z};
	return Vector1 ;
	
}

Vector multiplyby_scalar(const Vector v1, const double c){
	
	struct Baran Vector1;
	Vector1 = {c*v1.x , c*v1.y , c*v1.z };
	return Vector1;
	
}

double dot_product(const Vector v1, const Vector v2){
	
	double Vector1;
	Vector1 = {(v1.x * v2.x) + (v1.y * v2.y )+ (v1.z * v2.z) };
	return Vector1;
		
}

Vector cross_product(const Vector v1, const Vector v2){
	
	struct Baran Vector1;
	Vector1 = { v1.y * v2.z - v1.z * v2.y , v1.z * v2.x - v1.x * v2.z , v1.x * v2.y - v1.y * v2.x };
	return Vector1;
	
}

double norm(const Vector v){
	
	double Vector1 = sqrt((pow(v.x,2)+pow(v.y,2)+pow(v.z,2)));
	return Vector1;
	
}

int is_unitvector(const Vector v){
	
	int Vector1 = norm (v);
	return Vector1;
	
}

Vector unit(const Vector v){
	
	struct Baran Vector1;
	Vector1 = {v.x / norm(v) , v.y / norm(v), v.z / norm(v)};
	return Vector1;
	
}

double angle(const Vector v1, const Vector v2){
	
	double teta;
	teta = acos(dot_product(v1,v2)/ (norm(v1) * norm(v2)));
	return teta;
	
}

double distance(const Vector v1, const Vector v2){
	
	double distance1 = norm(diff(v1,v2));
	return distance1;
		
}

int are_linearly_independent(const Vector v1, const Vector v2, const Vector v3){
	
	int det1, det2, det3;
	det1 = ( v1.x * (v2.y * v3.z - v2.z * v3.y ) );
	det2 = ( v2.x * (v1.y * v3.z - v1.z * v3.y ) );
	det3 = ( v3.x * (v1.y * v2.z - v1.z * v2.y ) );
	return det1 - det2 + det3 ;
	
}

int are_orthogonal(const Vector v1, const Vector v2, const Vector v3){
	
	int ortogonal1 = dot_product(v1,v2);
	int ortogonal2 = dot_product(v1,v3);
	int ortogonal3 = dot_product(v2,v3);
	if (ortogonal1 == 0 && ortogonal2 == 0 && ortogonal3 == 0)
	return ortogonal1 ;
	else return 1;
	
}

int are_orthonormal(const Vector v1, const Vector v2, const Vector v3){
	
	if (are_orthogonal(v1 , v2 , v3) == 0 && norm(v1)== 1 && norm (v2)== 1 && norm (v3)== 1 )
	return 1;
	
}

Vector projection(const Vector v1, const Vector v2){
	
	struct Baran Proj;
	Proj = multiplyby_scalar(v2, dot_product(v1,v2)/pow(norm(v2),2));
	return Proj;	
		
}

Vector orthogonal_projection(const Vector v1, const Vector v2){
	
	struct Baran Orto_Proj;
	Orto_Proj = diff(v1,projection(v1,v2) );
	return Orto_Proj;
		
}

int convert_2_orthogonal_basis(Vector *v1, Vector *v2, Vector *v3){
	
	struct Baran d1 = *v1  , d2 = *v2, d3 = *v3 ;
	if (are_linearly_independent(d1, d2, d3)!=0){
	*v2 = diff(d2, projection(d2,d1));
	d2 = *v2;
	*v3 = diff(diff(d3, projection(d3,d1)) , projection(d3,d2) );
	return 1;
	}
	    
}

char* vector2str(const Vector v){
	
	char *vectorstr ;
	vectorstr= (char *)malloc(30);
	sprintf(vectorstr,"(%.2lf %.2lf %.2lf)", v.x , v.y , v.z );
	return vectorstr;
	
}

 int main (){
 	
	Vector v1 = {1, 2, 2}, v2 = {-1, 0, 2}, v3 = {0, 0, 1};
	double k = 2;
	printf("v1 = ");
	print_vector(v1);
	printf("v2 = ");
	print_vector(v2);
	printf("v3 = ");
	print_vector(v3);
	printf("v1 + v2 = ");
	print_vector(sum(v1, v2));
	printf("v1 - v2 = ");
	print_vector(diff(v1, v2));
	printf("k * v1 = ");
	print_vector(multiplyby_scalar(v1, k));
	printf("v1 . v2 = %.2lf\n", dot_product(v1, v2));
	printf("v1 x v2 = ");
	print_vector(cross_product(v1, v2));
    printf("| v1 | = %.2lf\n", norm(v1));
	if(is_unitvector(v1) == 1)
	printf("v1 is a unit vector.\n");
	else
	printf("v1 is not unit vector.\n");
	printf("unit( v1 ) = ");
	print_vector(unit(v1));
    printf("angle(v1, v2) = %.2lf\n", angle(v1, v2));
    printf("distance(v1, v2) = %.2lf\n", distance(v1, v2));
    if(are_linearly_independent(v1, v2, v3) != 0)
	printf("Vectors are linearly independent.\n");
	else
	printf("Vectors are not linearly independent.\n");
    if(are_orthogonal(v1, v2, v3) == 0)
	printf("Vectors are orthogonal.\n");
	else
	printf("Vectors are not orthogonal.\n");
    if(are_orthonormal(v1, v2, v3)==1)
	printf("Vectors are orthonormal.\n");
	else
	printf("Vectors are not orthonormal.\n");
    printf("Projection of v1 onto v2 is = ");
	print_vector(projection(v1, v2));
	printf("Orthogonal projection of v1 onto v2 is = ");
	print_vector(orthogonal_projection(v1, v2));
	if(convert_2_orthogonal_basis(&v1, &v2, &v3) == 1){
	printf("Orthogonalization of vectors:\n");
	printf("v1 = ");
	print_vector(v1);
	printf("v2 = ");
	print_vector(v2);
	printf("v3 = ");
	print_vector(v3); }
	puts(vector2str(v1));
    
    
	return 0;
 }

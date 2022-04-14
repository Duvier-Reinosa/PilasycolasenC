
//buenas buenas
#include<stdio.h>
#include<stdlib.h>

typedef struct nodo_pila{ 
    int dato;
    struct nodo_pila *siguiente; 
}nodoP; 

typedef nodoP *Pila, *Lista;


///////////////////////////////////
void menu(){
printf("%s","BIENVENIDO AL MUNDO DE LAS PILAS\n");
printf("%s","1. PUSH\n");
printf("%s","2. POP\n");
printf("%s","3.  MOSTRAR PILA\n");
printf("%s","4. MOSTRAR EL NUMERO DISPONIBLE EN EL TOPE DE LA PILA\n");
printf("%s","5. Mostrar numeros amigos");

printf("%s","8. SALIR: ");
}
//////////////////////////////////////////////////////////////////////////////////////
////////////////////Funci�n push///////////////////
void Push(Pila *Pilainicial, int valor){
    Pila nuevo_nodo; 
    nuevo_nodo = (Pila)malloc(sizeof(nodoP)); 
    nuevo_nodo->dato = valor; 
    nuevo_nodo->siguiente = *Pilainicial; 
    *Pilainicial = nuevo_nodo; 
}
////////////////////////////////funci�n pop////////////////////////////
int Pop(Pila *Pilainicial){
Pila nodo_eliminar;
int elemento_retornado;
nodo_eliminar=*Pilainicial;
elemento_retornado=nodo_eliminar->dato;
*Pilainicial=(*Pilainicial)->siguiente;
free(nodo_eliminar);
return(elemento_retornado);
}
//////////////////////////////stackempty: verifica si la pila est� vacia//////////////
int stackempty(Pila Pilainicial){
int vacia=0; // vacia es 0 la pila est� vacia, si es 1 la pila tiene elementos
if (Pilainicial==NULL){
	return vacia;
	 }
else
{
 vacia=1;
 return vacia;
 }
}
/////////////////////stacktop(S): determina cual es el elemento disponible de la pila///
int stacktop(Pila Pilainicial){
    return Pilainicial->dato;
}
//////////////////////////////////////////mostrar pila/////////////////////////////////
 void mostrar_pila(Pila Pilainicial){
    while(Pilainicial != NULL){ 
        printf("%d",Pilainicial->dato); 
        printf("%s","\n");
		Pilainicial = Pilainicial->siguiente; 
    }
}
//////////////////////////////////////////////////////////////////////////////////////////
//funcion para sumar divisores de un numero
int sumaDivisores(int numero)
{
	int suma=0;
	int i=1;
		while(i<=numero/2)
		{
			if(numero%i==0)
			{
				suma=suma+i;
			}
		i++;
		}
	return suma;
}
//////////////////////////////////////////////////////////////////////////////
//funcion para determinar si dos numeros son amigos
int sonamigos(int a,int b)
{	
	int son=0;
	if(sumaDivisores(a)==b && sumaDivisores(b)==a)
	{
		son=1;					
	}else
	{
		son=0;
	}
	return son;
}
//////////////////////////////////////////////////////////////////////////////
//funcion para mostrar numeros amigos
void MostrarAmigos(Pila pilainicial)
{
	Pila actual;
	while (pilainicial!=NULL)
	{	
		actual=pilainicial->siguiente;
		while(actual!=NULL)
		{
			if(sonamigos(pilainicial->dato,actual->dato)==1)
			{
				printf("%d es amigo de  %d\n", pilainicial->dato,actual->dato);
	
			}
		actual=actual->siguiente;
		}
	pilainicial=pilainicial->siguiente;
	}
	
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
int buscarenpila(Pila Pilainicial, int valor)
{	
	int encontrado_en_pila=0;
	while(Pilainicial!=NULL)
	{
		if(Pilainicial->dato==valor)
		{
			encontrado_en_pila=1;
			return encontrado_en_pila;
		}
	Pilainicial=Pilainicial->siguiente;
	}
	return encontrado_en_pila;
}
///////////////////////////////////////////////////////////////////////////////
int main(){
Pila mi_pila;
int x;
mi_pila=NULL;
int valor,opc=0;
int num_cambiar;
while(opc!=8){
 system("cls");
 menu();
 printf("escoja su opcion: ");
 scanf("%d",&opc);
 switch(opc){
   case 1: system("cls");
        printf("ingrese numeros diferente a -1: ");
        scanf("%d",&valor);
        while(valor!=-1){
		Push(&mi_pila,valor);
		printf("ingrese numeros diferente a -1: ");
        scanf("%d",&valor);
		}
        break;
    case 2: system("cls");
           if(stackempty(mi_pila)==1){
            x=Pop(&mi_pila);
            printf("%s""%d","El elemento retirado de la pila es: ",x);
            printf("\n");
        }else{
        	printf("La pila esta vacia");
		}
            break;
    case 3: system("cls");
            mostrar_pila(mi_pila);
			  
			break;
		case 4: 
		    system("cls");
            printf("%s""%d","El elemento en la cima es: ",stacktop(mi_pila));

			break;
			
			case 5:
			system ("cls");
			MostrarAmigos(mi_pila);
			break;
			}      
  printf("ingrese un valor diferente de 8 para volver al menu: ");
  scanf("%d",&opc); 
 }

return 0;
}


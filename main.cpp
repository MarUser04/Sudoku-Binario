#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

struct Mapa{
	int **matriz;
	int filas, columnas;
};

void cargarmatriz(Mapa *mapa);
void mover(Mapa *mapa);

int main(int argc, char** argv) {
	
	system("color b");
	srand(time(0));
	
	Mapa mapa;
	
	cargarmatriz(&mapa);
	printf("\n\n");
	mover(&mapa);
	
	system("pause>null");
	return 0;
}

void cargarmatriz(Mapa *mapa)
{
	char opc; 
	int aux;
	do{
	system("cls");
	printf("-------BIENVENIDO---------\n");
	printf("1.---------4x4------------\n");
	printf("2.---------6x6------------\n");
	printf("3.---------8x8------------\n");
	printf("4.---------10x10------------\n");
    printf("-------ELIGA UNA OPCION.---------\n");
    
    fflush(stdin);
    opc= getch();
    
    aux=opc-48;
	}while(aux<1 || aux>4);
	
	switch(aux)
	{
		case 1:
			mapa->filas=4;
			mapa->columnas=4;
			break;
		case 2:
			mapa->filas=6;
			mapa->columnas=6;
			break;
		case 3:
			mapa->filas=8;
			mapa->columnas=8;
			break;
		case 4: 
			mapa->filas=10;
			mapa->columnas=10;
			break;
	}
	
	mapa->matriz= new int *[mapa->filas];
	for(int i=0; i<mapa->filas; i++)
	{
		mapa->matriz[i]=new int [mapa->columnas];
	}
	
	for(int i=0;i<mapa->filas;i++){
		for(int j=0;j<mapa->columnas;j++){
			mapa->matriz[i][j]=rand()%9;
		}
	}
	
	for(int i=0;i<mapa->filas;i++){
		printf("\n");
		for(int j=0;j<mapa->columnas;j++){
			if(mapa->matriz[i][j]==0 || mapa->matriz[i][j]==1 )
			{
				printf(" %d ",mapa->matriz[i][j]);
			
			}
			else
			{
				printf(" - ");
			}
			
		}
	}
	
}

void mover(Mapa *mapa)
{
	char tecla;


	int x=0, y=0;
	
	while(1)
	{
		
	for(int i=0; i<mapa->filas; i++)
	{
		printf("\n");
		for(int j=0; j<mapa->columnas; j++)
		{
		
			if(x==j && y==i)
			{
			  if(mapa->matriz[i][j]==0 || mapa->matriz[i][j]==1)
				{
				   printf("[%d]", mapa->matriz[i][j]);
				}
				else
				{
					printf("[-]", mapa->matriz[i][j]);
				}
			}
			else{
				if(mapa->matriz[i][j]==0 || mapa->matriz[i][j]==1)
				{
				   printf(" %d ", mapa->matriz[i][j]);
				}
				else
				{
					printf(" - ", mapa->matriz[i][j]);
				}
			}
		
		}//for j
	
	}//for i
		tecla=getch();
		
		if(tecla=='a' && x>0 )
			x--;
		else if(tecla== 'd'  && x<mapa->filas-1 )
			x++;
		else if(tecla=='s'  && y<mapa->columnas-1)
			y++;
		else if( tecla== 'w'  && y>0)
			y--;
			
		
		system("cls");	
	}//while
	
}

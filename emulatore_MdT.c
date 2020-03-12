#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

main()
{
	int n_cin,i,tot=0,cella,stato=0,j;
	char str[100],spostamento,leggi,scrivi;
	
	do{
		printf("Inserisci il numero degli stati: ");
		scanf("%d",&n_cin); 
	}while(n_cin<1);
	
	int pos[n_cin];
	
	for(i=0;i<n_cin;i++)
	{
		do{
			printf("Inserisci il numero di input per lo stato '%d': ",i);
			scanf("%d",&pos[i]);
		}while(pos[i]<1);
		tot+=pos[i];
	}
	char comandi[tot][10];
	
	
	printf("\nInserisci i comandi (stato-leggi-scrivi-posizione):\n"); //0-2-4-6
	for(i=0;i<tot;i++)
	{
		scanf("%s",comandi[i]);
	}
	
	system("cls");
	printf("Inserisci la stringa tra due #:\n");
	scanf("%s",str);
	
	system("cls");
	printf("%s\n\n",str);
	do{
		printf("Inserisci il numero di cella da cui partire: ");
		scanf("%d",&cella);
	}while(cella<1 || cella>strlen(str)-1);
	
	system("cls");
	printf("%s\n",str);
	for(i=0;i<cella;i++)
	{
		printf(" ");
	}
	printf("|");
	
	do{
		Sleep(100);
		tot=0;
		for(i=0; i<=stato ; i++)
		{
			tot+=pos[i];
		}
		
		//tot=2+3=5
		//	i=3 ; 5>5-3 ; i--
		for(i=pos[stato] ; tot>tot-i ; i--)
		{
			if(comandi[tot-i][2] == str[cella])
			{
				str[cella]=comandi[tot-i][4];
				//mostra
				system("cls");
				printf("%s\n",str);
				for(j=0;j<cella;j++)
				{
					printf(" ");
				}
				printf("|");
				//mostra
				if(comandi[tot-i][6] == 'D')
				{
					cella++;
					stato=comandi[tot-i][0]-48;
					break;
				}
				else if(comandi[tot-i][6] == 'S')
				{
					cella--;
					stato=comandi[tot-i][0]-48;
					break;
				}
				else
				{
					spostamento='F';
					break;
				}
			}
		}
	}while(spostamento!='F');
	
	
	system("cls");
	printf("%s\n",str);
	for(i=0;i<cella;i++)
	{
		printf(" ");
	}
	printf("|\n\n");
	system("pause");
}

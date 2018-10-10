#include <stdio.h>
#include <string.h>

int main(void)
{
	system("title Gestion de repertoire");
	FILE *fp, *fptmp, *fpo;
	char choix, nom[50], prenom[50], am[50], c, name[50], lname[50], adr[50];
	int id[10], tel[10], i, x=0, z;

	fp = fopen("ID.txt", "r");
	fptmp = fopen("base-tmp.txt", "w+");
	fscanf(fp, "%d", &z);
	fclose(fp);
	puts("(a) Ajouter une personne dans le repertoire");
	puts("(b) Afficher le r�pertoire");
	puts("(c) Recherche d'une personne (id)");
	puts("(d) Supprimer personne du repertoire");
	puts("(e) Supprimer le repertoire entier");
	choix = getchar();
	getchar();

	switch(choix)
	{
		case 'a':
				system("title Ajout d'une personne");
				system("cls");
				system("echo.");
				fp = fopen("base.txt", "a");
				fprintf(fp, "%d ", z+1);
				puts("Nom: ");
				scanf("%s", &c);
				fprintf(fp, "%s ", &c);
				puts("Prenom: ");
				scanf("%s", &c);
				fprintf(fp, "%s ", &c);
				puts("Telephone: ");
				scanf("%d", &i);
				fprintf(fp, "%d ", i);
				puts("Adresse mail: ");
				scanf("%s", &c);
				fprintf(fp, "%s \n", &c);
				fclose(fp);
				fp = fopen("ID.txt", "w+");
				fscanf(fp, "%d", &z);
				z = z+1;
				fprintf(fp, "%d", z);
				fclose(fp);
				break;

		case 'b':
				system("cls");
				system("title Affichage du repertoire");
				system("echo.");
				system("echo ----- Repertoire -----");
				system("echo.");
				fp = fopen("base.txt", "r");
				i=0;
				printf("	id	|");
				printf("	Nom	|");
				printf("	prenom	|");
				printf("	numero		|");
				printf("	mail	\n");
				puts("-----------------------------------------------------------------------------------------------------------");
				for (i=0; i<z; i++)
				{
					fscanf(fp, "%d", &id[i]);
					fscanf(fp, "%s", &name);
					fscanf(fp, "%s", &lname);
					fscanf(fp, "%d", &tel[i]);
					fscanf(fp, "%s", &adr);
					nom[i]=name;
					prenom[i]=lname;
					am[i]=adr;
					printf("	%d	|", id[i]);
					printf("	%s	|", name);
					printf("	%s	|", lname);
					printf("	0%d	|", tel[i]);
					printf("	%s	\n", adr);
					puts("-----------------------------------------------------------------------------------------------------------");
				}
				fclose(fp);
				break;

		case 'c':
				system("cls");
				system("title Supprimer un utilisateur");
				system("color c");
				fp = fopen("base.txt", "r");
				i=0;
				puts("donnez un entr�e");
				scanf("%d", &x);
				printf("	id	|");
				printf("	Nom	|");
				printf("	prenom	|");
				printf("	numero		|");
				printf("	mail	\n");
				puts("-----------------------------------------------------------------------------------------------------------");
				for (i=0; i<x; i++)
				{
					fscanf(fp, "%d", &id[i]);
					fscanf(fp, "%s", &name);
					fscanf(fp, "%s", &lname);
					fscanf(fp, "%d", &tel[i]);
					fscanf(fp, "%s", &adr);
					nom[i]=name;
					prenom[i]=lname;
					am[i]=adr;
				}
				printf("	%d	|", id[x]);
				printf("	%s	|", name);
				printf("	%s	|", lname);
				printf("	%d	|", tel[x]);
				printf("	%s	\n", adr);
				fclose(fp);
				break;
		case 'd':
				system("cls");
				system("title Supprimer un contact");
				system("echo.");
				fp = fopen("base.txt", "r");
				fpo = fopen("ID.txt", "r");
				fscanf(fpo, "%d", &z);
				fclose(fpo);
				i=0;
				puts("donnez un entrée");
				scanf("%d", &x);
				for(i=0; i<z; i++)
				{
					fscanf(fp, "%d", &id[i]);
					fscanf(fp, "%s", &name);
					fscanf(fp, "%s", &lname);
					fscanf(fp, "%d", &tel[i]);
					fscanf(fp, "%s", &adr);
					nom[i]=name;
					prenom[i]=lname;
					am[i]=adr;
				}
				puts("-----------------------------------------------------------------------------------------------------------");
				for (i=0; i<x-1; i++)
				{
					fprintf(fptmp, "%d ", id[i]);
					fprintf(fptmp, "%s ", nom[i]);
					fprintf(fptmp, "%s ", prenom[i]);
					fprintf(fptmp, "%d ", tel[i]);
					fprintf(fptmp, "%s \n", am[i]);
				}
				for (i=x; i<z; i++)
				{
					fprintf(fptmp, "%d ", id[i]);
					fprintf(fptmp, "%s ", nom[i]);
					fprintf(fptmp, "%s ", prenom[i]);
					fprintf(fptmp, "%d ", tel[i]);
					fprintf(fptmp, "%s \n", am[i]);
				}
				fclose(fp);
				fpo = fopen("ID.txt", "w+");
				fscanf(fpo, "%d", &z);
				z = z - 1;
				fprintf(fpo, "%d", z);
				fclose(fpo);
				break;

		case 'e':
				system("cls");
				system("color c");
				system("title Supression du repertoire ENTIER");
				system("echo SI c'est une erreur fermez cette fenetre, sinon appuyer sur entree");
				system("pause");
				fp = fopen("base.txt", "w");
				fprintf(fp, " ");
				printf("R�pertoire supprim� !");
				fclose(fp);
				fp = fopen("ID.txt", "w");
				fprintf(fp, "0");
				fclose(fp);
				break;
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
struct premier_annee {
    float algo;
    float langage_c;
    float math;
    float proba;
    float electro;
    float tec;
    float anglais;
    float archi;
};

struct deuxieme_annee {
    float Algo;
    float Prog_c_II;
    float Math;
    float Stat;
    float Base_donnee;
    float Tec;
    float Anglais;
    float Python;
    float Technology_de_web;
};

struct troisieme_annee {
    float system_information;
    float Prog_c;
    float reseaux_system;
    float unix;
    float UML;
    float java;
    float tec_anglais;
    float analyse_num;
};

struct gestion_note {
    int annee;
    struct premier_annee a1;
    struct deuxieme_annee a2;
    struct troisieme_annee a3;
};

struct etudiant 
{
	int nu;
	char nomfam[10];
	int age;
	struct date
		{
			int jour;
			int mois;
			int annee;
		}date;
	struct gestion_note gestion_note;		
	float note;
};
void menu()
{
	printf("menu\n 1:gestion d etudiant \n 2:fichier \n 3:quitter \n");
}
void menu_gestion_etudiant()
{
	printf("menu\n 1:ajouter \n 2:modifier \n 3:supprimer \n 4:lister \n 5:gestion de note \n 6:lister_gestion_note\n 7:retour \n");
}
void ajouter(struct etudiant *&t,int &nbr)
{
	
	if(nbr==0)
	{
		t=(etudiant*)malloc(sizeof(etudiant));
		
	}
	else
	{
		   realloc(t,(nbr+1)*sizeof(etudiant));	
	}
	
	printf("veuillez saisir le numero unique:");
	scanf("%d", &t[nbr].nu);	 
	printf("veuillez saisir le nom d'etudiant :");
	scanf("%s",t[nbr].nomfam);
	printf("veuillez saisir l'age d'etudiant:");
	scanf("%d", &t[nbr].age);
	
		
do {
        printf("Date de naissance (jj / mm / aaaa): ");
        scanf("%d %d %d", &t[nbr].date.jour, &t[nbr].date.mois, &t[nbr].date.annee);

        if (t[nbr].date.jour < 1 || t[nbr].date.jour > 31 ||
            t[nbr].date.mois < 1 || t[nbr].date.mois > 12 ||
            t[nbr].date.annee <= 1900 || t[nbr].date.annee >= 2030) 	
			{
           	  printf("Veuillez reessayer la date\n");
       					 }
       					 
       					 
    } while (t[nbr].date.jour < 1 || t[nbr].date.jour > 31 ||
             t[nbr].date.mois < 1 || t[nbr].date.mois > 12 ||
             t[nbr].date.annee <= 1900 || t[nbr].date.annee >= 2030);

   			 
	
		
	nbr++;
			 	
	
 	
}
void supprimer_etudiant(etudiant *&t, int &nbr)
 {
 	int num;
    int pos = -1; 
    int i;
     printf("Donner le numero unique de l'etudiant a supprimer: ");
    scanf("%d", &num);
    
    if(nbr==0)
	{
		printf("aucun etudiant a supprimer !");
	}
	
	else
	{
   
                    
    for (i=0;i<nbr;i++) 
	{
        if (t[i].nu ==num) 
		{
            pos = i;
        }
        	
        
    }
    
    if (pos!=-1) 
	{
        for (i=pos;i<nbr-1;i++)
		 {
            t[i]=t[i+1];
        }
        
		nbr=nbr-1;
		realloc(t,nbr*sizeof(etudiant));	
	 printf("etudiant est supprime avec succee.\n");
    } 
    else{
    	printf("le num que vous avez entrer est introuvable");
	}
    
	}


}
    
  

    

void lister(struct etudiant *t, int nbr) 
{
	 if(nbr==0)
    {
    	printf("aucun etudiant a lister \n");
	}
	
    for(int i=0;i<nbr;i++)
	{
        printf("Etudiant %d:\n", i+1);
        printf("numero unique: %d\n", t[i].nu);
        printf("le nom est : %s\n", t[i].nomfam);
        printf("l'age est: %d\n", t[i].age);
        printf("la date de naissance est : (jj / mm / aaaa): %d/%d/%d\n", t[i].date.jour, t[i].date.mois, t[i].date.annee);      
    }
   
   
}
void modifier(struct etudiant *t, int nbr) 
{
    int num, i;
   		printf("donner le numero unique a modifier: ");
    	scanf("%d", &num);
    	for(i=0;i<nbr;i++)
 {
    if(t[i].nu==num) 
		{
            printf("Entrer les nouveaux valeurs:\n");
            printf("veuillez saisir le nouveax nom: ");
            scanf("%s", t[i].nomfam);
            printf("veuillez saisir le nouveax age: ");
            scanf("%d", &t[i].age);
            printf("veuillez saisir la nouvelle date de naissance (jj mm aaaa): ");
            scanf("%d %d %d", &t[i].date.jour, &t[i].date.mois, &t[i].date.annee);
            printf("etudiant est modifie avec succee.\n");
        } else {
        		printf("etudiant introuvable .\n"); 
		}
       
        
		
         
   }
    
}
float calculer_moyenne(struct etudiant *t, int i) 
{
    float sum = (t[i].gestion_note.a1.algo )*5  +
                (t[i].gestion_note.a1.langage_c)*5 +
                (t[i].gestion_note.a1.math)*4 +
                (t[i].gestion_note.a1.proba)*3+
                (t[i].gestion_note.a1.electro)*3 +
                (t[i].gestion_note.a1.tec)*2 +
                (t[i].gestion_note.a1.anglais)*2 +
                (t[i].gestion_note.a1.archi)*3;
                
             t[i].note=sum/27;   
    return t[i].note; 
}
float calculer_moyenne2(struct etudiant *t, int i) 
{
    float sum = (t[i].gestion_note.a2.Algo )*5  +
                (t[i].gestion_note.a2.Anglais)*2 +
                (t[i].gestion_note.a2.Base_donnee)*3 +
                (t[i].gestion_note.a2.Math)*4+
                (t[i].gestion_note.a2.Prog_c_II)*5 +
                (t[i].gestion_note.a2.Python)*3 +
                (t[i].gestion_note.a2.Stat)*3 +
                (t[i].gestion_note.a2.Tec)*2+
                (t[i].gestion_note.a2.Technology_de_web)*2;
                
             t[i].note=sum/29;   
   			 return t[i].note; 
}

float calculer_moyenne3(struct etudiant *t, int i) 
{
    float sum = (t[i].gestion_note.a3.analyse_num )*3  +
                (t[i].gestion_note.a3.java)*5 +
                (t[i].gestion_note.a3.Prog_c)*5 +
                (t[i].gestion_note.a3.reseaux_system)*4+
                (t[i].gestion_note.a3.system_information)*3 +
                (t[i].gestion_note.a3.tec_anglais)*2 +
                (t[i].gestion_note.a3.UML)*3 +
                (t[i].gestion_note.a3.unix)*3;
        t[i].note=sum/28; 
    return t[i].note;
}

void premier_annee(struct etudiant *t, int i) 
{
    printf("les Notes d'etudiant: %d\n",i+1);
    printf("veuillez saisir la note d'Algorithmique: ");
    scanf("%f", &t[i].gestion_note.a1.algo);
    printf("veuillez saisir la note de Programmation en C/C++: ");
    scanf("%f", &t[i].gestion_note.a1.langage_c);
    printf("veuillez saisir la note de Mathematiques: ");
    scanf("%f", &t[i].gestion_note.a1.math);
    printf("veuillez saisir la note de Probabilites: ");
    scanf("%f", &t[i].gestion_note.a1.proba);
    printf("veuillez saisir la note d'Electronique: ");
    scanf("%f", &t[i].gestion_note.a1.electro);
    printf("veuillez saisir la note de TEC: ");
    scanf("%f", &t[i].gestion_note.a1.tec);
    printf("veuillez saisir la note d'Anglais: ");
    scanf("%f", &t[i].gestion_note.a1.anglais);
    printf("veuillez saisir la note d'Architecture: ");
    scanf("%f", &t[i].gestion_note.a1.archi);
    printf("voila la moyenne : %.2f \n",calculer_moyenne(t,i));
    
}

void deuxieme_annee(struct etudiant *t, int i) {
    printf("Les Notes d'etudiant %d:\n", i + 1);
    printf("veuillez saisir la Note d'Algorithmique: ");
    scanf("%f", &t[i].gestion_note.a2.Algo);
    printf("veuillez saisir la Note de Programmation en C++: ");
    scanf("%f", &t[i].gestion_note.a2.Prog_c_II);
    printf("veuillez saisir la Note de Mathematiques: ");
    scanf("%f", &t[i].gestion_note.a2.Math);
    printf("veuillez saisir la Note de Statistiques: ");
    scanf("%f", &t[i].gestion_note.a2.Stat);
    printf("veuillez saisir la Note de Bases de Donnees: ");
    scanf("%f", &t[i].gestion_note.a2.Base_donnee);
    printf("veuillez saisir la Note de TEC: ");
    scanf("%f", &t[i].gestion_note.a2.Tec);
    printf("veuillez saisir la Note d'Anglais: ");
    scanf("%f", &t[i].gestion_note.a2.Anglais);
    printf("veuillez saisir la Note de Python: ");
    scanf("%f", &t[i].gestion_note.a2.Python);
    printf("veuillez saisir la Note de Technologie de Web: ");
    scanf("%f", &t[i].gestion_note.a2.Technology_de_web);
    
    printf("voila la moyenne : %.2f \n",calculer_moyenne2(t,i));
}
void troisieme_annee(struct etudiant *t, int i) {
    printf("les Notes d'etudiant: %d\n",i+1);
    printf("veuillez saisir la note system_information: ");
    scanf("%f", &t[i].gestion_note.a3.system_information);
    printf("veuillez saisir la note Prog_c_#: ");
    scanf("%f", &t[i].gestion_note.a3.Prog_c);
    printf("veuillez saisir la Note de unix: ");
    scanf("%f", &t[i].gestion_note.a3.unix);
    printf("veuillez saisir la Note de UML: ");
    scanf("%f", &t[i].gestion_note.a3.UML);
    printf("veuillez saisir la Note java: ");
    scanf("%f", &t[i].gestion_note.a3.java);
    printf("veuillez saisir la Note de TEC & ANGLAIS: ");
    scanf("%f", &t[i].gestion_note.a3.tec_anglais);
    printf("veuillez saisir la Note analyse num: ");
    scanf("%f", &t[i].gestion_note.a3.analyse_num);
     printf("veuillez saisir la Note reseau system: ");
    scanf("%f", &t[i].gestion_note.a3.reseaux_system);  
    printf("voila la moyenne : %.2f \n",calculer_moyenne3(t,i));
	}

void gestion_note(struct etudiant *t, int nbr) {
    int num, i;
    printf("Entrez le numero unique de l'etudiant: ");
    scanf("%d", &num);
    for (i=0;i<nbr;i++) 
	{
        if (t[i].nu == num) 
		{ 
			if (i == nbr) 
			{
       			 printf("Etudiant non trouve\n");
   			}
    printf("Entrez l'annee (1 pour premier annee, 2 pour deuxieme annee, 3 pour troisieme annee ): ");
    int annee;
    scanf("%d", &t[i].gestion_note.annee);
    if (t[i].gestion_note.annee == 1) 
	{
        premier_annee(t, i);
    } 
	else if (t[i].gestion_note.annee == 2) 
	{
        deuxieme_annee(t, i);       
    } 
	else if (t[i].gestion_note.annee == 3)
    {
    	troisieme_annee(t, i);
	}
	
	else {
        printf("Annee invalide\n");
    }
            
        }
    }
   
}

void lister_gestion_note(struct etudiant *t,int nbr)
{
	for(int i=0;i<nbr;i++)
	{
			if (t[i].gestion_note.annee == 1) 
		{
      
    printf("les Notes d'etudiant:%d \n", i + 1);
    printf("Note d'Algorithmique est:%.2f \n",t[i].gestion_note.a1.algo);
    printf("Note de Programmation en C/C++ est:%.2f \n ",t[i].gestion_note.a1.langage_c);    
    printf("Note de Mathematiques est: %.2f \n",t[i].gestion_note.a1.math);   
    printf("Note de Probabilites est: %.2f \n",t[i].gestion_note.a1.proba);   
    printf("Note d'Electronique est:%.2f \n",t[i].gestion_note.a1.electro);    
    printf("Note de TEC est :%.2f \n",t[i].gestion_note.a1.tec); 
    printf("Note d'Anglais est:%.2f \n",t[i].gestion_note.a1.anglais);   
    printf("Note d'Architecture est:%.2f \n",t[i].gestion_note.a1.archi);    
    printf(" la moyenne est : %.2f \n",calculer_moyenne(t,i));
    } 
	else if (t[i].gestion_note.annee == 2) 
	{
    printf("Les Notes d'etudiant %d : \n", i + 1);
    printf("Note d'Algorithmique est: %.2f \n",t[i].gestion_note.a2.Algo); 
    printf("Note de Programmation en C++ est:%.2f \n",t[i].gestion_note.a2.Prog_c_II);   
    printf("Note de Mathematiques est: %.2f \n",t[i].gestion_note.a2.Math);  
    printf("Note de Statistiques est: %.2f \n",t[i].gestion_note.a2.Stat);  
    printf("Note de Bases de Donnees est:%.2f \n",t[i].gestion_note.a2.Base_donnee);   
    printf("Note de TEC est:%.2f \n",t[i].gestion_note.a2.Tec);  
    printf("Note d'Anglais est: %.2f \n",t[i].gestion_note.a2.Anglais);  
    printf("Note de Python est: %.2f \n",t[i].gestion_note.a2.Python);   
    printf("Note de Technologie de Web est:%.2f \n",t[i].gestion_note.a2.Technology_de_web);
   
    printf("voila la moyenne : %.2f \n",calculer_moyenne2(t,i));
    } 
	else if (t[i].gestion_note.annee == 3)
    {
    printf("les Notes d'etudiant: %d\n",i+1);
    printf("note system_information est:%.2f \n",t[i].gestion_note.a3.system_information);
    printf("note Prog_c_# est: %.2f \n",t[i].gestion_note.a3.Prog_c);
    printf("Note de unix est: %.2f \n",t[i].gestion_note.a3.unix);   
    printf("Note de UML est: %.2f \n",t[i].gestion_note.a3.UML); 
    printf("Note java est: %.2f \n",t[i].gestion_note.a3.java); 
    printf("Note de TEC & ANGLAIS est: %.2f \n",t[i].gestion_note.a3.tec_anglais);
    printf("Note analyse num est: %.2f \n",t[i].gestion_note.a3.analyse_num);   
     printf("Note reseau system est: %.2f \n",t[i].gestion_note.a3.reseaux_system);
   
    printf("voila la moyenne est: %.2f \n",calculer_moyenne3(t,i));
	}
	}

}

void retour()
{
	
}

void menu_fichier()
{
	printf("menu\n 1:save text \n 2:load text \n 3:save binaire \n 4:load binaire \n 5:retour ");
}
void save_text(struct etudiant t[], int nbr) {
    FILE *infos = NULL;

    infos = fopen("binome.txt","w");
    if (infos == NULL)
	{
        printf("Erreur lors de l'ouverture du fichier.");
    } else {
        for(int i=0;i<nbr;i++) {
        	if(t[i].gestion_note.annee==1)
        	{ 
			fprintf(infos,"le nom est :%s \n  l'age est :%d \n Date de naissance (jj / mm / aaaa): %d / %d / %d \n  la note d  l'algorithme est : %f \n  la note de langage C est : %f \n  la note du math est : %f \n  la note du probabilite est : %f \n  la note du elctronique est : %f \n  la note de tec est : %f \n  la note d'anglais est : %f \n  la note de l'architecture est : %f \n  la note generale est : %f \n",
		   t[i].nomfam,
		   t[i].age,
		   t[i].date.jour,
		   t[i].date.mois,
		   t[i].date.annee,
		   
		   t[i].gestion_note.a1.algo,
		   t[i].gestion_note.a1.langage_c,
		   t[i].gestion_note.a1.math,
		   t[i].gestion_note.a1.proba,
		   t[i].gestion_note.a1.electro,
		   t[i].gestion_note.a1.tec,
		   t[i].gestion_note.a1.anglais,
		   t[i].gestion_note.a1.archi,		   
		   
		   t[i].note
		   );
		   
		   
		   
			
        }
        else if(t[i].gestion_note.annee==2)
        	{ 
			fprintf(infos," le nom est :%s \n l'age est: %d \n Date de naissance (jj / mm / aaaa): %d / %d / %d \n  la note d'algorithme est : %f \n la note de langage C_II est %f \n la note du math est %f \n la note de statistique est %f \n la note du base de donnee est %f \n la note du tec est %f \n la note d'anglais est %f \n la note de python est %f \n la note de tech de web est %f \n la note general est %f \n ",
		   t[i].nomfam,
		   t[i].age,
		   t[i].date.jour,
		   t[i].date.mois,
		   t[i].date.annee,
		   

		   t[i].gestion_note.a2.Algo,
		   t[i].gestion_note.a2.Prog_c_II,
		   t[i].gestion_note.a2.Math,
		   t[i].gestion_note.a2.Stat,
		   t[i].gestion_note.a2.Base_donnee,
		   t[i].gestion_note.a2.Tec,
		   t[i].gestion_note.a2.Anglais,
		   t[i].gestion_note.a2.Python, 
		   t[i].gestion_note.a2.Technology_de_web,
		   
		   t[i].note
		   );
			
        }
        		
        else if(t[i].gestion_note.annee==3)
        	{ 
			fprintf(infos,"le nom est :%s \n L'age est: %d\n Date de naissance (jj / mm / aaaa): %d / %d / %d \n la note du sytstem information est : %f \n la note du prg_C est : %f \n la note du UNIX est : %f \n la note du UML est  %f \n la note du JAVA est : %f \n la note du TEC_anglais est : %f \n la note du analyse_num est : %f \n la note du resaux_sytseme est : %f \n la not generale est : %f \n ",
		   t[i].nomfam,
		   t[i].age,
		   t[i].date.jour,
		   t[i].date.mois,
		   t[i].date.annee,

		   
		   t[i].gestion_note.a3.system_information,
		   t[i].gestion_note.a3.Prog_c,		  
		    t[i].gestion_note.a3.unix ,
		   t[i].gestion_note.a3.UML,		  
		   t[i].gestion_note.a3.java,
		   t[i].gestion_note.a3.tec_anglais,
		   t[i].gestion_note.a3.analyse_num,
		   t[i].gestion_note.a3.reseaux_system,
		   
		   t[i].note
		   );
			
        }		
			}
        
          
    fclose(infos);
        
    }
}


void load_text(struct etudiant t[])

{
	int i=0;
	FILE *infos;
	infos=fopen("binome.txt","r");
	if(infos==NULL)
	{
		printf("Erreur d ouverture du fichier ");
	}
  else 
	{
		while(!feof(infos))
		
	       
		{
		if(t[i].gestion_note.annee==1)
		{
		
		fscanf(infos,"%s \n %d \n %d \n %d \n %d \n  %f \n  %f \n  %f \n  %f \n  %f \n  %f \n  %f \n  %f \n  %f \n ",
	    	t[i].nomfam,
	       &t[i].age,
		   &t[i].date.jour,
		   &t[i].date.mois,
		   &t[i].date.annee,
		   
		   &t[i].gestion_note.a1.algo,
		   &t[i].gestion_note.a1.langage_c,
		   &t[i].gestion_note.a1.math,
		   &t[i].gestion_note.a1.proba,
		   &t[i].gestion_note.a1.electro,
		   &t[i].gestion_note.a1.tec,
		   &t[i].gestion_note.a1.anglais,
		   &t[i].gestion_note.a1.archi,
		   &t[i].note);
		
			}
			else if(t[i].gestion_note.annee==2)
		{
		
			fscanf(infos,"%s \n %d \n  %d \n  %d \n  %d \n  %f \n  %f \n  %f \n  %f \n  %f \n  %f \n  %f \n  %f \n  %f \n  %f \n ", 
			t[i].nomfam,
		   &t[i].age,
		   &t[i].date.jour,
		   &t[i].date.mois,
		   &t[i].date.annee,
		   
		   
		   &t[i].note,t[i].gestion_note.a2.Algo,
		   &t[i].gestion_note.a2.Prog_c_II,
		   &t[i].gestion_note.a2.Math,
		   &t[i].gestion_note.a2.Stat,
		   &t[i].gestion_note.a2.Base_donnee,
		   &t[i].gestion_note.a2.Tec,
		   &t[i].gestion_note.a2.Anglais,
		   &t[i].gestion_note.a2.Python,
		   &t[i].gestion_note.a2.Technology_de_web,

		   &t[i].note);
		
		}
		else if(t[i].gestion_note.annee==3)
		{
		
			fscanf(infos,"%s \n  %d \n  %d \n  %d \n  %d \n  %f \n %f \n  %f \n  %f \n  %f \n  %f \n  %f \n  %f \n  %f \n ",
		   t[i].nomfam,
		   &t[i].age,
		   &t[i].date.jour,
		   &t[i].date.mois,
		   &t[i].date.annee,

		   &t[i].gestion_note.a3.system_information,
		   &t[i].gestion_note.a3.Prog_c,
		   &t[i].gestion_note.a3.unix,
		   &t[i].gestion_note.a3.UML,
		   &t[i].gestion_note.a3.java,
		   &t[i].gestion_note.a3.tec_anglais,
		   &t[i].gestion_note.a3.analyse_num,		   
		   &t[i].gestion_note.a3.reseaux_system,		    
		   
		   &t[i].note );
		  
		
		}
		}
		fclose(infos);
	}


}
save_binaire(struct etudiant t[],int nbr)
{
 FILE *infos=NULL;
 
 infos=fopen("binome.bin","wb");
 if(infos==NULL)
 {
 	printf("error");
 }
 else
 {
 	 for (int i = 0; i < nbr; i++)
    {
    	if(t[i].gestion_note.annee==1)
	{
    		
		
        fwrite(&t[i].nu, sizeof(int), 1, infos); 
        fwrite(t[i].nomfam, sizeof(char), 10, infos); 
        fwrite(&t[i].age, sizeof(int), 1, infos);
        fwrite(&t[i].date.jour, sizeof(int), 1, infos); 
        fwrite(&t[i].date.mois, sizeof(int), 1, infos);
        fwrite(&t[i].date.annee, sizeof(int), 1, infos); 
        
         
        fwrite(&t[i].gestion_note.a1.algo, sizeof(float), 1, infos); 
        fwrite(&t[i].gestion_note.a1.langage_c, sizeof(float), 1, infos); 
        fwrite(&t[i].gestion_note.a1.math, sizeof(float), 1, infos); 
        fwrite(&t[i].gestion_note.a1.proba, sizeof(float), 1, infos); 
        fwrite(&t[i].gestion_note.a1.electro, sizeof(float), 1, infos); 
        fwrite(&t[i].gestion_note.a1.tec, sizeof(float), 1, infos); 
        fwrite(&t[i].gestion_note.a1.anglais, sizeof(float), 1, infos); 
        fwrite(&t[i].gestion_note.a1.archi, sizeof(float), 1, infos); 
        
        
        fwrite(&t[i].note, sizeof(float), 1, infos); 
        
    }
    	else if(t[i].gestion_note.annee==2)
	{
    		
		
        fwrite(&t[i].nu, sizeof(int), 1, infos); 
        fwrite(t[i].nomfam, sizeof(char), 10, infos); 
        fwrite(&t[i].age, sizeof(int), 1, infos);
        fwrite(&t[i].date.jour, sizeof(int), 1, infos); 
        fwrite(&t[i].date.mois, sizeof(int), 1, infos);
        fwrite(&t[i].date.annee, sizeof(int), 1, infos); 
        

        fwrite(&t[i].gestion_note.a2.Algo, sizeof(float), 1, infos); 
        fwrite(&t[i].gestion_note.a2.Anglais, sizeof(float), 1, infos); 
        fwrite(&t[i].gestion_note.a2.Base_donnee, sizeof(float), 1, infos); 
        fwrite(&t[i].gestion_note.a2.Math, sizeof(float), 1, infos); 
        fwrite(&t[i].gestion_note.a2.Prog_c_II, sizeof(float), 1, infos); 
        fwrite(&t[i].gestion_note.a2.Python, sizeof(float), 1, infos); 
        fwrite(&t[i].gestion_note.a2.Stat, sizeof(float), 1, infos); 
        fwrite(&t[i].gestion_note.a2.Tec, sizeof(float), 1, infos); 
        fwrite(&t[i].gestion_note.a2.Technology_de_web, sizeof(float), 1, infos); 
        
        fwrite(&t[i].note, sizeof(float), 1, infos); 
    }
    else if(t[i].gestion_note.annee==3){
        fwrite(&t[i].nu, sizeof(int), 1, infos); 
        fwrite(t[i].nomfam, sizeof(char), 10, infos); 
        fwrite(&t[i].age, sizeof(int), 1, infos);
        fwrite(&t[i].date.jour, sizeof(int), 1, infos); 
        fwrite(&t[i].date.mois, sizeof(int), 1, infos);
        fwrite(&t[i].date.annee, sizeof(int), 1, infos); 
        
        fwrite(&t[i].gestion_note.a3.analyse_num, sizeof(float), 1, infos); 
        fwrite(&t[i].gestion_note.a3.java, sizeof(float), 1, infos); 
        fwrite(&t[i].gestion_note.a3.Prog_c, sizeof(float), 1, infos); 
        fwrite(&t[i].gestion_note.a3.reseaux_system, sizeof(float), 1, infos); 
        fwrite(&t[i].gestion_note.a3.system_information, sizeof(float), 1, infos); 
        fwrite(&t[i].gestion_note.a3.tec_anglais, sizeof(float), 1, infos); 
        fwrite(&t[i].gestion_note.a3.UML, sizeof(float), 1, infos); 
        fwrite(&t[i].gestion_note.a3.unix, sizeof(float), 1, infos);         
        fwrite(&t[i].note, sizeof(float), 1, infos); 
    }
	}
		 	
		 fclose(infos);	
	 
 } 	
}


void load_binaire(struct etudiant t[])

{
	int i=0;
	FILE *infos;
	infos=fopen("binome.bin","rb");
	if(infos==NULL)
	{
		printf("Erreur d ouverture du fichier ");
	}
	else
	{
		
		while(!feof(infos))		
	{

  	  {
    	if(t[i].gestion_note.annee==1){
    		
		
        fread(&t[i].nu, sizeof(int), 1, infos); 
        fread(t[i].nomfam, sizeof(char), 10, infos); 
        fread(&t[i].age, sizeof(int), 1, infos);
        fread(&t[i].date.jour, sizeof(int), 1, infos); 
        fread(&t[i].date.mois, sizeof(int), 1, infos);
        fread(&t[i].date.annee, sizeof(int), 1, infos); 
        fread(&t[i].note, sizeof(float), 1, infos); 
        fread(&t[i].gestion_note.a1.algo, sizeof(float), 1, infos); 
        fread(&t[i].gestion_note.a1.langage_c, sizeof(float), 1, infos); 
        fread(&t[i].gestion_note.a1.math, sizeof(float), 1, infos); 
        fread(&t[i].gestion_note.a1.proba, sizeof(float), 1, infos); 
        fread(&t[i].gestion_note.a1.electro, sizeof(float), 1, infos); 
        fread(&t[i].gestion_note.a1.tec, sizeof(float), 1, infos); 
        fread(&t[i].gestion_note.a1.anglais, sizeof(float), 1, infos); 
        fread(&t[i].gestion_note.a1.archi, sizeof(float), 1, infos); 
      
    }
    	else if(t[i].gestion_note.annee==2)
	{
    		
		
        fread(&t[i].nu, sizeof(int), 1, infos); 
        fread(t[i].nomfam, sizeof(char), 10, infos); 
        fread(&t[i].age, sizeof(int), 1, infos);
        fread(&t[i].date.jour, sizeof(int), 1, infos); 
        fread(&t[i].date.mois, sizeof(int), 1, infos);
        fread(&t[i].date.annee, sizeof(int), 1, infos); 
        fread(&t[i].note, sizeof(float), 1, infos); 
        fread(&t[i].gestion_note.a2.Algo, sizeof(float), 1, infos); 
        fread(&t[i].gestion_note.a2.Anglais, sizeof(float), 1, infos); 
        fread(&t[i].gestion_note.a2.Base_donnee, sizeof(float), 1, infos); 
        fread(&t[i].gestion_note.a2.Math, sizeof(float), 1, infos); 
        fread(&t[i].gestion_note.a2.Prog_c_II, sizeof(float), 1, infos); 
        fread(&t[i].gestion_note.a2.Python, sizeof(float), 1, infos); 
        fread(&t[i].gestion_note.a2.Stat, sizeof(float), 1, infos); 
        fread(&t[i].gestion_note.a2.Tec, sizeof(float), 1, infos); 
        fread(&t[i].gestion_note.a2.Technology_de_web, sizeof(float), 1, infos); 
     
    }
    else if(t[i].gestion_note.annee==3)
	{
        fread(&t[i].nu, sizeof(int), 1, infos); 
        fread(t[i].nomfam, sizeof(char), 10, infos); 
        fread(&t[i].age, sizeof(int), 1, infos);
        fread(&t[i].date.jour, sizeof(int), 1, infos); 
        fread(&t[i].date.mois, sizeof(int), 1, infos);
        fread(&t[i].date.annee, sizeof(int), 1, infos); 
        fread(&t[i].note, sizeof(float), 1, infos); 
        fread(&t[i].gestion_note.a3.analyse_num, sizeof(float), 1, infos); 
        fread(&t[i].gestion_note.a3.java, sizeof(float), 1, infos); 
        fread(&t[i].gestion_note.a3.Prog_c, sizeof(float), 1, infos); 
        fread(&t[i].gestion_note.a3.reseaux_system, sizeof(float), 1, infos); 
        fread(&t[i].gestion_note.a3.system_information, sizeof(float), 1, infos); 
        fread(&t[i].gestion_note.a3.tec_anglais, sizeof(float), 1, infos); 
        fread(&t[i].gestion_note.a3.UML, sizeof(float), 1, infos); 
        fread(&t[i].gestion_note.a3.unix, sizeof(float), 1, infos); 
        
    
           }
		
		
	    } 

     }			
	 fclose(infos);
   }
}
void quitter()
{
	exit(1);
}
main()
{
	int choix;
	struct etudiant *t = NULL;
	int nbr = 0;
	do {
		menu();
		scanf("%d", &choix);
		switch (choix) 
	{
		case 1: 
			do {
				menu_gestion_etudiant();
				scanf("%d", &choix);
			switch (choix) {
				case 1:
					ajouter(t,nbr);
					break;
				case 2:
					modifier(t,nbr);
					break;
				case 3:
					supprimer_etudiant(t,nbr);
					break;	
				case 4:	
					lister(t, nbr);
					break;
				case 5:
					gestion_note(t,nbr);	
					break;
				case 6:
					lister_gestion_note	(t,nbr);
					break;
				case 7:
					retour();
					break;				
				default:
            		printf("veuiller essayer une autre fois\n");
            		break;		
				}
				getch();
				system("cls");
			} while (choix != 7);
				break;
				
		case 2:
				do {
				menu_fichier();
				scanf("%d", &choix);
				switch (choix) 
				{
				case 1:
					save_text(t,nbr);
					break;
				case 2:
					load_text(t);
					break;
				case 3:
					save_binaire(t,nbr);
					break;
				case 4:
					load_binaire(t);
					break;
				case 5:
					retour();
					break;	
				default:
            		printf("veuiller essayer une autre fois\n");
            		break;			
				}	
				getch();
				system("cls");
				
			} 
			while (choix != 5);
			break;
		
		case 3:
			quitter();
			break;
			
		default:
           	printf("veuiller essayer une autre fois\n");
       		break;	
				
		}
		getch();
		system("cls");
 	 }	
	   while (choix != 3);
	
}
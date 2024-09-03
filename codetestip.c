#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 1000


void entry_save_ip(char *ip,FILE *file)
{
    
    printf("\t****IP TESTING PLATEFORM****\n");
    printf("Please enter your IP adress:\n");
    scanf("%s",ip);
    file=fopen("ip.txt","w");
    fprintf(file,"%s",ip);
    fclose(file);

}

void validity_test(char *ip,FILE *file,int *segment1,int *segment2,int *segment3,int *segment4)
{
    char data[MAX_LINE];
    char *token=NULL;
    char tok1[MAX_LINE];
    char tok2[MAX_LINE];
    char tok3[MAX_LINE];
    char tok4[MAX_LINE];
    file=fopen("ip.txt","r");
///On lit le fichier et separe l'ip par point via strtok et attribution aux variables via sscanf
    while(fgets(data,MAX_LINE,file)!=NULL)
    {
        token=strtok(data,".");
        if (token != NULL)
        {
            sscanf(token, "%d", segment1); // Premier segment
        } 
            

        token = strtok(NULL, ".");
        if (token != NULL)
        {
            sscanf(token, "%d", segment2); // Deuxième segment
        } 
            

        token = strtok(NULL, ".");
        if (token != NULL)
        {
            sscanf(token, "%d", segment3); // Troisième segment
        } 
           
        
        token = strtok(NULL, ".");
        if (token != NULL) 
        {
            sscanf(token, "%d", segment4); // Quatrième segment
        }
              
    }

    if((*segment1>=0 && *segment1<=255) &&  (*segment2>=0 && *segment2<=255) && (*segment3>=0 && *segment3<=255) && (*segment4>=0 && *segment4<=255)  )
    {
        printf("Your IP adress is valid\n");
    }
        
    else
    {
        printf("IP INVALID\n");
    }
    fclose(file);
}

void ip_class(char *ip,int *segment1,int *segment2,int *segment3,int *segment4)
{

    if(*segment1>=0 && *segment1<=126)
    {
        printf("Class A\n");
    }
    else if(*segment1>=128 && *segment1<=191)
    {
        printf("Class B\n");
    }
    else if(*segment1>=192 && *segment1<=223)
    {
        printf("Class C\n");
    }

    else
    {
        printf("Class specific\n");
    }
}

void entry_save_netmask(char *netmask,FILE *filebis)
{
    printf("Please enter your netmask:\n");
    scanf("%s",netmask);
    filebis=fopen("netmask.txt","w");
    fprintf(filebis,"%s",netmask);
    fclose(filebis);

}

void validity_net_test(char *netmask,FILE *filebis,int *net1,int *net2,int *net3,int *net4)
{
    char data[MAX_LINE];
    char *token=NULL;
    char tok1[MAX_LINE];
    char tok2[MAX_LINE];
    char tok3[MAX_LINE];
    char tok4[MAX_LINE];
    filebis=fopen("netmask.txt","r");
///On lit le fichier et separe le netmaskpar point via strtok et attribution aux variables via sscanf
    while(fgets(data,MAX_LINE,filebis)!=NULL)
    {
        token=strtok(data,".");
        if (token != NULL)
        {
            sscanf(token, "%d", net1); // Premier segment
        } 
            

        token = strtok(NULL, ".");
        if (token != NULL)
        {
            sscanf(token, "%d", net2); // Deuxième segment
        } 
            

        token = strtok(NULL, ".");
        if (token != NULL)
        {
            sscanf(token, "%d", net3); // Troisième segment
        } 
           
        
        token = strtok(NULL, ".");
        if (token != NULL) 
        {
            sscanf(token, "%d", net4); // Quatrième segment
        }
              
    }
    //printf("%d %d %d %d\n",*net1,*net2,*net3,*net4);

    if((*net1==255) &&  (*net2>=0 && *net2<=255) && (*net3>=0 && *net3<=255) && (*net4>=0 && *net4<=255)  )
    {
        printf("Your netmask is valid\n");
    }
        
    else
    {
        printf("IP INVALID\n");
    }
    fclose(filebis);
}

void calcul_network_address(int *segment1,int *segment2,int *segment3,int *segment4,int *net1,int *net2,int *net3,int *net4)
{
    int network_adress[4];
    
        network_adress[0] = *segment1 & *net1;
        network_adress[1] = *segment2 & *net2;
        network_adress[2] = *segment3 & *net3;
        network_adress[3] = *segment4 & *net4;

    printf("Network adress:%d.%d.%d.%d\n",network_adress[0],network_adress[1],network_adress[2],network_adress[3]);
    
}

void calcul_broadcast_address(int *segment1,int *segment2,int *segment3,int *segment4,int *net1,int *net2,int *net3,int *net4)
{
    int broadcast_adress[4];

    broadcast_adress[0]=*segment1 | ~*net1 & 255;
    broadcast_adress[1]=*segment2 | ~*net2 & 255;
    broadcast_adress[2]=*segment3 | ~*net2 & 255;
    broadcast_adress[3]=*segment4 | ~*net3 & 255;


     printf("Broadcast adress:%d.%d.%d.%d\n",broadcast_adress[0],broadcast_adress[1],broadcast_adress[2],broadcast_adress[3]);
}







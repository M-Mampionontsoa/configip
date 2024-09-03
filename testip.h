#include <stdio.h>


///Saisie de l'adresse ip
void entry_save_ip(char *ip,FILE *file);

///Test de validité de l'adresse Ip saisie
void validity_test(char *ip,FILE *file,int  *segment1,int *segment2,int  *segment3,int  *segment4);

///Détermination de la classe de l'adresse IP
void ip_class(char *ip,int *segment1,int *segment2,int *segment3,int *segment4);

///Saisie du masquedu sous réseau
void entry_save_netmask(char *netmask,FILE *file);

///Test de validité du masque de sous-réseau
void validity_net_test(char *netmask,FILE *filebis,int *net1,int *net2,int *net3,int *net4);

///Calcul de l'adresse réseau
void calcul_network_address(int *segment1,int *segment2,int *segment3,int *segment4,int *net1,int *net2,int *net3,int *net4);

///Calcul de l'adresse broadcast
void calcul_broadcast_address(int *segment1,int *segment2,int *segment3,int *segment4,int *net1,int *net2,int *net3,int *net4);

///Calcul du nombre de machine
void calcul_host();
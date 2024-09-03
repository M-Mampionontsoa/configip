#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "testip.h"
#include "codetestip.c"
#define MAX_LINE 1000

int main(int argc,char *argv[])
{

    FILE *file=NULL;
    FILE *filebis=NULL;
    int segment1;
    int segment2;
    int segment3;
    int segment4;
    int net1;
    int net2;
    int net3;
    int net4;
    char ip[MAX_LINE];
    char netmask[MAX_LINE];
    entry_save_ip(ip,file);
    entry_save_netmask(netmask,filebis);
    validity_test(ip,file,&segment1,&segment2,&segment3,&segment4);
    validity_net_test(netmask,filebis,&net1,&net2,&net3,&net4);
    ip_class(ip,&segment1,&segment2,&segment3,&segment4);
    calcul_network_address(&segment1,&segment2,&segment3,&segment4,&net1,&net2,&net3,&net4);  
    calcul_broadcast_address(&segment1,&segment2,&segment3,&segment4,&net1,&net2,&net3,&net4);  



    return (0);
}
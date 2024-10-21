#include <stdio.h>
#include "common.h"
#include "ip.h"

// Analyser entete IP
void analyserIP(char *trame, IP *ip) 
{
    ip->version = (trame[0] >> 4);
    //ip->IHL = ;                                               Pas trouvé
    ip->typeOfService = trame[1];
    ip->totalLength = MAKE_SHORT(trame[2], trame[3]);
    ip->identification = MAKE_SHORT(trame[4], trame[5]);
    //ip->flags = ;                                             Pas trouvé
    //ip->fragmentOffset = ;                                    Pas trouvé
    ip->timeToLive = trame[8];
    ip->protocol = trame[9];
    ip->HeaderChecksum = MAKE_SHORT(trame[10], trame[11]);
    ip->sourceIP = MAKE_INT(trame[12], trame[13], trame[14], trame[15]);
    ip->destinationIP = MAKE_INT(trame[16], trame[17], trame[18], trame[19]);
    
    //error_exit("Fonction analyserIP() non implémentée");
}

// Afficher une adresse IP
void afficherIPAddress(unsigned int address)
{
    printf("%d.%d.%d.%d", (address >> 24) & 0xFF, (address >> 16) & 0xFF, (address >> 8) & 0xFF, address & 0xFF);
    
    //error_exit("Fonction afficherIPAddress() non implémentée");
}

// Afficher entete IP
void afficherIP(IP ip)
{
    printf("IP:\n");
    printf("    version: %d\n", ip.version);
    printf("    IHL: %d\n", ip.IHL);
    printf("    typeOfService: %d\n", ip.typeOfService);
    printf("    totalLength: %d\n", ip.totalLength);
    printf("    identification: %d\n", ip.identification);
    printf("    flags: %d\n", ip.flags);
    printf("    fragmentOffset: %d\n", ip.fragmentOffset);
    printf("    timeToLive: %d\n", ip.timeToLive);
    printf("    protocol: %d\n", ip.protocol);
    printf("    HeaderChecksum: %d\n", ip.HeaderChecksum);
    printf("    sourceIP: ");
    afficherIPAddress(ip.sourceIP);
    printf("\n    destinationIP: ");
    afficherIPAddress(ip.destinationIP);
    printf("\n");
}
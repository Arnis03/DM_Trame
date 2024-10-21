#include <stdio.h>
#include "common.h"
#include "tcp.h"

// Analyser entete TCP
void analyserTCP(char *trame, TCP *tcp) 
{
    tcp->source_port = MAKE_SHORT(trame[0], trame[1]);
    tcp->destination_port = MAKE_SHORT(trame[2], trame[3]);
    tcp->sequence_number = MAKE_INT(trame[4], trame[5], trame[6], trame[7]);
    tcp->acknowledhment_number = MAKE_INT(trame[8], trame[9], trame[10], trame[11]);
    //tcp->data_offset = ;                                                                  Pas trouvé
    //tcp->reserved = ;                                                                     Pas trouvé
    //tcp->flags = ;                                                                        Pas trouvé
    tcp->window = MAKE_SHORT(trame[14], trame[15]);
    tcp->checksum = MAKE_SHORT(trame[16], trame[17]);
    tcp->urgent_pointer = MAKE_SHORT(trame[18], trame[19]);
    
    //error_exit("fonction analyserTCP() non implémentée");
}

// Afficher entete TCP
void afficherTCP(TCP tcp)
{
    printf("TCP:\n");
    printf("    source_port: %d\n", tcp.source_port);
    printf("    destination_port: %d\n", tcp.destination_port);
    printf("    sequence_number: %d\n", tcp.sequence_number);
    printf("    acknowledhment_number: %d\n", tcp.acknowledhment_number);
    printf("    data_offset: %d\n", tcp.data_offset);
    printf("    reserved: %d\n", tcp.reserved);
    printf("    flags: %d\n", tcp.flags);
    printf("    window: %d\n", tcp.window);
    printf("    checksum: %d\n", tcp.checksum);
    printf("    urgent_pointer: %d\n", tcp.urgent_pointer);
}

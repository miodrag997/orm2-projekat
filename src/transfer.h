#pragma once

#include <pcap.h>
#include <stdint.h>

#include "packet/packet.h"
#include "config.h"

int *received;
int all_received;
/*
void send_data(pcap_t *dev_handler[2], uint8_t* data, size_t len);

uint8_t *receive_data(pcap_t *dev_handler[2], uint8_t* data, size_t len);
*/

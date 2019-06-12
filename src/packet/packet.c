#include "packet.h"

packet* create_packet(ethernet_header eh, ip_header ih, udp_header uh, custom_header ch, unsigned char* data, size_t size) {
	packet *dp = (packet*) malloc(sizeof(packet));

	dp->eth_h = eh;
	dp->ip_h = ih;
	dp->udp_h = uh;
	dp->cus_h = ch;

	memcpy(dp->data, data, size);

	uint16_t checksum = calculate_udp_checksum(dp);
	set_udp_checksum(&(dp->udp_h), checksum);

	return dp;
}

u_int16_t calculate_udp_checksum(packet *p) {
	size_t data_size = p->udp_h.datagram_length - sizeof(udp_header);

	uint16_t checksum = 0;
	for (int i = 0; i < data_size; i++) {
		checksum += p->data[i];
	}

	return checksum;
}

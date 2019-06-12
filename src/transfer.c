#include "transfer.h"
/*
int *received;
int all_received;

static void send_handler(unsigned char *param, const struct pcap_pkthdr *packet_header, const unsigned char *packet_data);
static void rcv_handler(unsigned char *param, const struct pcap_pkthdr *packet_header, const unsigned char *packet_data);

void send_data(pcap_t *dev_handler[2], uint8_t* data, size_t len) {
	int packets = len / MAX_DATA_SIZE;
	int windows = packets / 2 * WINDOW_SIZE;
	received = malloc(packets * sizeof(int));

	for (int i = 0; i < windows; i++) {
		int n = i == (windows - 1) ? windows % (2 * WINDOW_SIZE) : (2 * WINDOW_SIZE);
		for (int j = 0; j < n; j++) {
			int seq_no = i * 2 * WINDOW_SIZE + j;
			received[seq_no] = 0;
		}

		all_received = 1;
		do {
			for (int j = 0; j < n; j++) {
				int seq_no = i * 2 * WINDOW_SIZE + j;
				if (!received[seq_no]) {
					int size;
					dcp_packet *packet;

					if (i == windows - 1 && j == n - 1) {
						size = len % MAX_DATA_SIZE;
					} else {
						size = MAX_DATA_SIZE;
					}

					packet = create_packet(data, size, i, 0);

					if (i % (2 * WINDOW_SIZE) < WINDOW_SIZE) {
						pcap_sendpacket(dev_handler[0], data, size);
					} else {
						pcap_sendpacket(dev_handler[1], data, size);
					}
				}
			}

			pcap_loop(dev_handler[0], WINDOW_SIZE, send_handler, NULL);
			pcap_loop(dev_handler[1], WINDOW_SIZE, send_handler, NULL);

			for (int j = 0; j < n; j++) {
				int seq_no = i * 2 * WINDOW_SIZE + j;
				all_received &= received[seq_no];
			}
		} while (!all_received);
	}

	free(received);
}

uint8_t *receive_data(pcap_t *dev_handler[2], uint8_t* data, size_t len) {
	int packets = len / MAX_DATA_SIZE;
	received = malloc(packets * sizeof(int));

	for (int i = 0; i < packets; i++) {
		received[i] = 0;
	}

	while (!all_received) {
		pcap_loop(dev_handler[0], 1, rcv_handler, (unsigned char*)&(dev_handler[0]));
		pcap_loop(dev_handler[1], 1, rcv_handler, (unsigned char*)&(dev_handler[1]));
		all_received = 1;
		for (int i = 0; i < packets; i++) {
			all_received &= received[i];
			if (!received[i]) {
				break;
			}
		}
	}

	return NULL;
}

static void send_handler(unsigned char *param, const struct pcap_pkthdr *packet_header, const unsigned char *packet_data) {
	dcp_packet *p = (dcp_packet *)packet_data;
	if (get_ack(&(p->dcp_h))) {
		received[p->dcp_h.seq_no] = 1;
	}
}

static void rcv_handler(unsigned char *param, const struct pcap_pkthdr *packet_header, const unsigned char *packet_data) {
	dcp_packet *p = (dcp_packet *)packet_data;
	pcap_t *dev_handler = (pcap_t *) param;
	int size = sizeof(ethernet_header) + sizeof(ip_header) + sizeof(udp_header) + sizeof(dcp_header);
	if (p->dcp_h.checksum == crc8(p->data, p->udp_h.datagram_length - sizeof(udp_header) - sizeof(dcp_header))) {
		// TODO: Write to memory
		received[p->dcp_h.seq_no] = 1;
		dcp_packet *packet = create_packet(NULL, 0, p->dcp_h.seq_no, 0);
		set_ack(&(packet->dcp_h), 1);
		pcap_sendpacket(dev_handler, (u_char*)packet, size);
		free(packet);
	} else {
		dcp_packet *packet = create_packet(NULL, 0, p->dcp_h.seq_no, 0);
		set_ack(&(packet->dcp_h), 0);
		set_cse(&(packet->dcp_h), 1);
		pcap_sendpacket(dev_handler, (u_char *)packet, size);
		free(packet);
		pcap_loop(dev_handler, 1, rcv_handler, (u_char *)&(dev_handler));
	}
}

*/

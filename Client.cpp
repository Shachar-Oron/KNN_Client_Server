//
// Created by shach on 29/12/2022.
//
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <vector>
#include <string.h>

#include "Helpers.h"
using namespace std;

int main(int argc, char** argv) {

    const char* ip_address = argv[1];
    const string port_no = argv[2];
    if (Helpers :: is_valid_ip(ip_address) && Helpers :: is_valid_port(port_no))
    {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("error creating socket");
        }
        struct sockaddr_in sin;
        memset(&sin, 0, sizeof(sin));
        sin.sin_family = AF_INET;
        sin.sin_addr.s_addr = inet_addr(ip_address);
        sin.sin_port = htons(stoi(port_no));
        if (connect(sock, (struct sockaddr*) & sin, sizeof(sin)) < 0) {
            perror("error connecting to server");
        }
        cout << "client connected to server\n";

    while (true) {
        string input_data;
        // the vector, metrics and k
        getline(cin, input_data);

            int data_len = input_data.size();
            if (input_data == "-1") {
                break;
            }

            char const *char_arr = input_data.data();
            // data_addr must be char*
            vector<string> splitted = Helpers::SplitStringToStringVector(char_arr);

            vector<string> input_vec;
            input_vec.assign(splitted.begin(), splitted.end() - 2);
            int n = splitted.size();
            string stringK = splitted[n - 1];
            string calc_input = splitted[n - 2];
            int sent_bytes = -1;

            if (Helpers::is_valid_k(stringK) && Helpers :: is_valid_CalculatorName(calc_input) && (Helpers :: is_float_vec(input_vec))) {
                sent_bytes = send(sock, char_arr, data_len, 0);
            }

            if (sent_bytes < 0) {
                cout << "invalid input." << endl;
                continue;
            }

            char buffer[4096];
            int expected_data_len = sizeof(buffer);

            int read_bytes = recv(sock, buffer, 50, 0);

            if (read_bytes == 0) {
                // connection is closed
            } else if (read_bytes < 0) {
                // error
            } else {
                cout << buffer << endl;
            }
        }
        close(sock);
        return 0;
    }

    else {
        cout << "invalid argument" << endl;
        return 0;
    }
}
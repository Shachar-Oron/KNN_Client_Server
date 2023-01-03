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

//get ip_address & port in args
int main(int argc, char** argv) {

    const char* ip_address = argv[1];
    const string port_no = argv[2];
    //       validate the args:

    if (Helpers :: is_valid_ip(ip_address) && Helpers :: is_valid_port(port_no))
    {
        //      create the socket
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("error creating socket");
        }
        //      create the connection with the server
        struct sockaddr_in sin;
        memset(&sin, 0, sizeof(sin));
        sin.sin_family = AF_INET;
        sin.sin_addr.s_addr = inet_addr(ip_address);
        sin.sin_port = htons(stoi(port_no));
        if (connect(sock, (struct sockaddr*) & sin, sizeof(sin)) < 0) {
            perror("error connecting to server");
        }

        //      endless loop for getting inputs from the user until (-1)
        while (true) {
            string input_data;
            // the vector, metrics and k
            getline(cin, input_data);

            //      close the socket
            if (input_data == "-1") {
                break;
            }
            int data_len = input_data.size();

            //      serve and client connection requires the use of char*
            char const *char_arr = input_data.data();

            //       validate the input from the user:
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
            //      if the input not valid
            if (sent_bytes < 0) {
                cout << "invalid input." << endl;
                continue;
            }

        char buffer[4096];
        int expected_data_len = sizeof(buffer);

        //       receive the result from the server into buffer
        int read_bytes = recv(sock, buffer, expected_data_len, 0);

        if (read_bytes == 0) {
            // connection is closed
            cout << "connection is closed." << endl;
            break;

        } else if (read_bytes < 0) {
            // error
            cout << "error." << endl;
            break;

            } else {
            //    print the result from server
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
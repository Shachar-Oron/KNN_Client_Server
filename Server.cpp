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

#include "DistancesCalcolators.h"
#include "Helpers.h"
#include "Knn.h"
#include "LoadData.h"

using namespace std;

//get csv_file, port in args
int main(int argc, char *argv[]) {
    cout << "in server, the massage from the client.\n";
    const char* filePath = argv[1];
    cout << "filePath: " << filePath << endl;
    LoadData data_set;
    data_set.read_file(filePath);

//    const int server_port = atoi(argv[2]);
    const int server_port = 5555;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);
    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
    }
    if (listen(sock, 5) < 0) {
        perror("error listening to a socket");
    }
    while (true) {
        struct sockaddr_in client_sin;
        unsigned int addr_len = sizeof(client_sin);
        //new client
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
        if (client_sock < 0) {
            perror("error accepting client");
        }
        while (true) {
            char buffer[4096];
            int expected_data_len = sizeof(buffer);
            int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
            string result;
            if (read_bytes == 0) {
                // connection is closed
                close(client_sock);
                break;
            }
            else if (read_bytes < 0) {
                // error TODO: print a message and break
            }

            else {
                vector<string> splited = Helpers::SplitStringToStringVector(buffer);

                vector<string> input_vec;
                input_vec.assign(splited.begin(), splited.end() - 2);
                int n = splited.size();
                string calc_input = splited[n - 2];
                string stringK = splited[n - 1];

                Knn obj = Knn(stringK, calc_input);
                result = obj.RunKnn(data_set.getSampVec(), input_vec);
            }
            int sent_bytes = send(client_sock, result.c_str(), read_bytes, 0);
            if (sent_bytes < 0) {
                cout << ("error sending to client") << endl;
            }
        }
    }

    close(sock);
    return 0;
}
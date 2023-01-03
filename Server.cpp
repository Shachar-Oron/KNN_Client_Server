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

//get csv_file & port in args
int main(int argc, char *argv[]) {
    const char *filePath = argv[1];
    const int server_port = atoi(argv[2]);

    //       validate the args:
    if (Helpers::is_valid_path(argv[1]) && Helpers::is_valid_port(argv[2])) {
        LoadData data_set;
        data_set.read_file(filePath);

        //      create the socket
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("error creating socket");
        }
        struct sockaddr_in sin;
        memset(&sin, 0, sizeof(sin));
        sin.sin_family = AF_INET;
        sin.sin_addr.s_addr = INADDR_ANY;
        sin.sin_port = htons(server_port);
        //        binding:
        if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
            perror("error binding socket");
        }
        if (listen(sock, 5) < 0) {
            perror("error listening to a socket");
        }
        //       keeps server always running
        while (true) {
            struct sockaddr_in client_sin;
            unsigned int addr_len = sizeof(client_sin);
            //new client
            int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
            if (client_sock < 0) {
                perror("error accepting client");
            }
            //      keeps the connection with specific client open until client closing
            while (true) {
                char buffer[4096];
                int expected_data_len = sizeof(buffer);
                int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
                string result;
                if (read_bytes == 0) {
                    // connection is closed
                    close(client_sock);
                    break;
                } else if (read_bytes < 0) {
                    // error
                    cout << ("error accepting client") << endl;
                } else {
                    vector<string> splited = Helpers::SplitStringToStringVector(buffer);

                    vector<string> input_vec;
                    input_vec.assign(splited.begin(), splited.end() - 2);
                    int n = splited.size();
                    string calc_input = splited[n - 2];
                    string stringK = splited[n - 1];

                    Knn obj = Knn(stringK, calc_input);
                    Helpers help;
                    // make sure the vector is in the correct length
                    bool vaildVectorLength = help.InputValidation(
                            help._convertToStringFromFloat(data_set.getSampVec()[0].vec),
                            help._convertToString(input_vec));
                    bool vaild_calc_metric = help.is_valid_CalculatorName(calc_input);
                    // make sure k is int
                    bool valid_k = help.is_valid_k(stringK);
                    // make sure that k is'nt bigger than the number of lines in the file
                    bool valid_k_length = help.IsKTooLarge(filePath, stoi(stringK));

                    if (!vaildVectorLength or !vaild_calc_metric or !valid_k or !valid_k_length) {
                        result = "invalid input";
                    } else { // success
                        result = obj.RunKnn(data_set.getSampVec(), input_vec);
                    }
                    int sent_bytes = send(client_sock, result.c_str(), read_bytes, 0);
                    if (sent_bytes < 0) {
                        cout << ("error sending to client") << endl;

                    }


                }
            }
        }

        close(sock);
    }
    else {
        cout << "invalid arguments" << endl;
    }
    return 0;
}
//
// Created by shach on 15/01/2023.
//

#ifndef AP_EX4_COMMAND_H
#define AP_EX4_COMMAND_H
#include<iostream>
#include <string.h>

#include <fstream>
#include <vector>
#include "Helpers.h"
#include "LoadData.h"
#include "StructHeader.h"

using namespace std;


class DefaultIO{
public:
    virtual string read()=0;
    virtual void write(string text)=0;
    virtual void write(float f)=0;
    virtual void read(string* f)=0;
    virtual ~DefaultIO(){}


    void readAndFile(string fileName){
        ofstream out(fileName);
        string s="";
        while((s=read())!="done\n"){
            out<<s<<endl;
        }
        out.close();
    }
};

struct InputData{
    string metric;
    vector<StructHeader :: Sample> classifiedVectors;
    vector<string> input_vec;
    int k;
};

class Command {
protected:
    DefaultIO* dio;

public:
    virtual void execute(InputData* inputdata) = 0;
    const string description;
    Command(DefaultIO* dio,const string description):dio(dio),description(description){}
    virtual ~Command(){}
};

class UploadCSV:public Command{
public:
    UploadCSV(DefaultIO* dio):Command(dio,"upload an unclassified csv data file"){}
    virtual void execute(InputData* inputdata){
        dio->write("Please upload your local train CSV file.\n");
        dio->readAndFile("KNNTrain.csv");
        dio->write("Upload complete.\n");
        dio->write("Please upload your local test CSV file.\n");
        dio->readAndFile("KNNTest.csv");
        dio->write("Upload complete.\n");
    }
};

class Parameters:public Command{
public:
    Parameters(DefaultIO* dio):Command(dio,"algorithm settings"){}
    virtual void execute(InputData* inputdata){
        dio->write("The current KNN parameters are: k = ");
        dio->write(inputdata->k);
        dio->write(", distance metric = ");
        dio->write(inputdata->metric);
        dio->write("\nYou can type new parameters:\n");
        string params;
        dio->read(&params);
        string delimiter = " ";
        string calc_input = params.substr(0, params.find(delimiter));
        string stringK =  params.substr(1, params.find(delimiter));
        bool valid_k = Helpers::is_valid_k(stringK);
        bool valid_metric = Helpers :: is_valid_CalculatorName(calc_input);

        if(valid_k && valid_metric){
            inputdata->k=stoi(stringK);
            inputdata->metric=calc_input;
        }
        if(!valid_k) {
            dio->write(" invalid value for K\n");
        }
        if(!valid_metric) {
            dio->write("invalid value for metric \n");
        }
    }
};
// RunCSV

class RunCSV:public Command{
public:
    RunCSV(DefaultIO* dio):Command(dio,"classify data"){}
    virtual void execute(InputData* inputdata){
        ifstream Trainfile;
        ifstream Testfile;
        Trainfile.open("KNNTrain.csv");
        Testfile.open("KNNTest.csv");
        LoadData data_set;
        // checking if the file opening was successful
        if (Trainfile && Testfile)
        {
//            LoadData::read_file("KNNTrain.csv")
            data_set.read_file("KNNTrain.csv");

            // TODO: implement a LoadData for test file
            data_set.read_file("KNNTest.csv");


//        inputdata->classifiedVectors = ?;


            dio->write("classifing data complete\n");
        }
        else
        {
            // printing the error message
            dio->write("please upload data\n");
        }


    }
};

class Results:public Command {
public:
    Results(DefaultIO *dio) : Command(dio, "display results") {}

    virtual void execute(InputData *inputdata) {
//        for_each(inputdata->classifiedVectors& getc){
//            // TODO get the vec line in the test file
////            dio->write(vec.line);
//            dio->write("\t"+vec.lable+"\n");
//        });
        dio->write("Done.\n");
    }
};

class ResultsFile:public Command{
    public:
        ResultsFile(DefaultIO* dio):Command(dio,"classify data"){}
        virtual void execute(InputData* inputdata){
            dio->write("Please add a path to the results file.\n");
            string inputPath;
            dio->read(&inputPath);
            ofstream file (inputPath);
            // TODO: do as the result function but turn them to a string
            string data ("the results");
            file << data;
            //TODO: run another thread that take me back to the menu while the data is loading
        }
    };

    // TODO: for future implementations of the exit option


class Exit:public Command{
public:
    Exit(DefaultIO* dio):Command(dio,"exit"){}
    virtual void execute(InputData* inputdata){
    }
};

#endif //AP_EX4_COMMAND_H



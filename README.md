# ap_ex3
## Description
project of the second exercise in ap course, implementation of the KNN learning machine algorithm.

 ## About the project
In this project we have implemented the previous exercises by adding them the server and the client functionallity. The client communicates with the server through the socket, with an IP adress and a port.
the server is responsiball to run the KNN algorithm and send to the client the labels to the samples. The client is respomsible of getting the input from the user and send it to the server. In return' the server send the client the correct label for the input/
The input the user is supposed to enter contains 3 arguments: "vector distance k".
'k' - in the knn algorythem, k is the number of neighbors we would like to calculate the distences from. it shuld be a positive int value.
'distance'- could be: AUC, MAN, CHB, CAN, MIN. Means the way the distance will be calulated.
'vector'- a string in a form of numbers that are separated by spaces.

In the previous exercise, we have created a class named DistancesCalcolators that has different functions that calculates the different distances.
  the types of distances are: 
  - Euclidean distance (AUC)
  - Manhattan distance (MAN)
  - Chebyshev distance (CHB)
  - Canberra distance (CAN)
  - Minkowski distance with const p = 2 (MIN)
  
   ## About the algorithm:
   The server and the client works due to TCP protocol.
   - The client is running in an endless loop, gets inputs from the user ann dents them to the server.
   - The server
   There are different ways to implement the KNN algorithm. in our code we make the next steps:
   - find the K nearest neighbors of the input by the Distances Calcolators functions.
   - find the common label of the input's neighbors.
   - now we know the common label, we will classify the input by this common lable.
    At first, the user will load a classified data set as an input and the algorithm will Calcolates the results of the K nearest neighbors.
    Then, the user will input a vector of features (in a forrm of numbers with spaces) and the output eould be the label of the input's vector.
    The lable is provide according to the k, file and distance the user has inserted.

 
 ## Getting Started
### Running  the app :
After you have download the attached files

 * open the terminal
 * run   ```make ```
 * run  ```server.out file port```
 * run  ```client.out ip port```
 * enter a vector in the form of "vector distance k" 

### New optimisations in the code:
- A load data class that reads the inputs value with the inserted path
- A Knn class that uses the Distances Calcolators class to find the common label of the input's nearest neighbors.

### A disclaimer:


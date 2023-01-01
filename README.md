# ap_ex3
## Description
project of the third exercise in ap course, implementation of client and server functionallity.

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
   - The server recives the input and clissified it accordenly to the demands via the KNN algorithm.
   The client gets inputs until the user enters '-1'. Then the endless loop of the clients breaks and the socket is closed.
   Meanwhile, the server is running in double endless loops,  the inner one gets the masseges from the client while the outer one opens the socket. When the user stops    the progrem the inner loop breaks and the outer loop never breaks. In that way the server never get closed and waits to the next connection with a client. 
 
 ## Getting Started
### Running  the app :
After you have download the files you want to train the KNN algorithm with:

 * open the terminal
 * run   ```make ```
 * run  ```./server.out file port &```
 * run  ```./client.out ip port```
 * enter an input in the form of "vector distance k" 
 * to stop enter ```-1```  


### New optimisations in the code:
- A CLient class 
- A Server that uses the KNN algorithm class to find the common label of the input's nearest neighbors. Finally the server class sends the label to the client.



